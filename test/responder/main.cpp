
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <iostream>
#include <fstream>
#include <unordered_map>

class IpAddress {

    private:

        uint32_t ip;
        uint16_t port;

    public:

        IpAddress(uint32_t ip, uint16_t port) : ip(ip), port(port) {}

        uint32_t getIp() {
            return 0;
        }

        uint32_t getPort() {
            return 8080;
        }

};

class Config {

    protected: 

        std::string tag;

    public:

        Config(std::string tag) : tag(tag) {}

        std::string getTag() {
            return tag;
        }

        bool hasPeers() {
            return true;
        }

        IpAddress getNextRemoteAddress() {
            return IpAddress(inet_addr(0), 8080);
        }
};

class RequesterConfig : public Config {

    private: 

        int timeBetweenRequests;

    public:

        RequesterConfig(std::string tag, int timeBetweenRequests) : Config(tag), timeBetweenRequests(timeBetweenRequests) {}

        int getTimeBetweenRequests() {
            return 4;
        }    

};

class ReceiverConfig : public Config  {

    private:

        int listeningPort;
    
    public:

        ReceiverConfig(std::string tag, int listeningPort) : Config(tag), listeningPort(listeningPort) {}

        int getListeningPort() {
            return 8080;
        }
        
};


int getSocket() {
    int socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);

    if(socketDescriptor == -1) {
        printf("Failed to initialize socket: %d \n", errno);
        throw;
    }

    return socketDescriptor;
}

struct sockaddr_in getAddrSpec(uint32_t ip, uint16_t port) {
    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr = {
            .s_addr = ip
        }
    };    

    return addr;
}

void socketConnect(int socketDescriptor, const struct sockaddr *addr, socklen_t addrlen) {
    int ret = connect(socketDescriptor, addr, addrlen);

    if(ret == -1) {
        printf("Failed to connect to remote server: %d \n", errno);
        throw;
    }
}

void sendMessage(int socketDescriptor, IpAddress& address, std::string message) {
    const struct sockaddr_in addr = getAddrSpec(address.getIp(), address.getPort());
    socketConnect(socketDescriptor, (struct sockaddr*) &addr, sizeof(addr));

    // sending data    
    int ret = send(socketDescriptor, message.data(), message.size(), 0);
    
    // receiving data
    char buffer[1024] = { 0 };
    int receiveSize = recv(socketDescriptor, buffer, sizeof(buffer), 0);
    std::cout << "Message from server: " << buffer << std::endl;

    if(ret == -1) {
        printf("Failed to send data to remote server: %d \n", errno);
        throw;
    }
}


void startRequester(RequesterConfig& config) {  
    int socketDescriptor = getSocket();

    while(true) {        
        IpAddress address = config.getNextRemoteAddress();
        sendMessage(socketDescriptor, address, config.getTag().append(" calling.\n"));



        sleep(config.getTimeBetweenRequests());
    }

    close(socketDescriptor);
}


void startReceiver(ReceiverConfig& config) {  
    int socketDescriptor = getSocket();

    const struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_port = htons(config.getListeningPort()),
        .sin_addr = {
            .s_addr = INADDR_ANY
        }
    };    

    int ret = bind(socketDescriptor, (struct sockaddr*) &addr, sizeof(addr));

    if(ret == -1) {
        printf("Failed to bind socket: %d \n", errno);
        throw;;
    }

    ret = listen(socketDescriptor, 10 /* backlog */);

    if(ret == -1) {
        printf("Failed to listen on socket: %d \n", errno);
        throw;
    }

    while(true) {
        // Get data from client
        std::cout << "Listening on port " << config.getListeningPort() << std::endl; 
        int clientSocket = accept(socketDescriptor, nullptr, nullptr);

        char buffer[1024] = { 0 };
        int receiveSize = recv(clientSocket, buffer, sizeof(buffer), 0);
        std::cout << "Message from client: " << buffer << std::endl;
        
        // send request to next peer and get a response
        IpAddress address = config.getNextRemoteAddress();
        sendMessage(socketDescriptor, address, std::string { buffer, receiveSize });
        
        receiveSize = recv(socketDescriptor, buffer, sizeof(buffer), 0);
        std::cout << "Message from peer: " << buffer << std::endl;

        // send response back to the client and close socket
        sendMessage(clientSocket, address, std::string { buffer, receiveSize });

        close(clientSocket);
    }

    close(socketDescriptor);
}

std::unordered_map<std::string, std::string> getConfigs(std::string filePath) {
    std::unordered_map<std::string, std::string> configs;

    std::ifstream configFile(filePath);

    std::string configuration;

    while(configFile.good() && std::getline(configFile, configuration)) {
        std::cout << configuration << std::endl;
    }

    if(!configFile.eof()) {
        std::cout << "Failed to read config file" << std::endl;
        throw;
    }

    configFile.close(); 

    return configs;
}


// node ip port destinationIp[,destinationIp] active|passive 


RequesterConfig buildRequestConfig(std::unordered_map<std::string, std::string>& configs) {
    std::string tag = configs.contains("tag") ? configs.at("tag") : "";
    uint16_t timeBetweenRequests  = configs.contains("timeBetweenRequests") ? stoi(configs.at("timeBetweenRequests")) : 0;


    if(tag.size() == 0 || timeBetweenRequests == 0) {
        std::cout << "Invalid Receiver Configuration" << std::endl;
        throw;
    } 
    
    return RequesterConfig { tag, timeBetweenRequests };
}

ReceiverConfig buildReceiverConfig(std::unordered_map<std::string, std::string>& configs) {
    std::string tag = configs.contains("tag") ? configs.at("tag") : "";
    uint16_t listeningPort  = configs.contains("listeningPort") ? stoi(configs.at("listeningPort")) : 0;


    if(tag.size() == 0 || listeningPort == 0) {
        std::cout << "Invalid Receiver Configuration" << std::endl;
        throw;
    } 
    
    return ReceiverConfig { tag, listeningPort };
}


int main(int argc, char* argv[]) {

    if(argc == 2) {
        std::string configPath{ argv[1] };

        std::cout << "Reading config from: " << configPath << std::endl;

        std::unordered_map<std::string, std::string> configs = getConfigs(configPath);
        const std::string nodeTypeKey = "NODE_TYPE";

        if(configs.contains(nodeTypeKey)) {
            std::string nodeType = configs.at(nodeTypeKey);
            
            if(nodeType == "REQUESTER") {
                RequesterConfig config = buildRequestConfig(configs);
                startRequester(config);
            } else if(nodeType == "RECEIVER") {
                ReceiverConfig config = buildReceiverConfig(configs);
                startReceiver(config);
            } else {
                std::cout << "Invalid NODE_TYPE" << std::endl;
                return -1;
            }
        } else {
            std::cout << "NODE_TYPE not specified" << std::endl;
            return -1;
        }
        
    } else {
        std::cout << "Bad Arguments" << std::endl;
        return -1;
    }

    return 0;
    
}