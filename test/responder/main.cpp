
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <iostream>



void init_tracing() {

}


int main(int argc, char* argv[]) {
    init_tracing();
    
    int port = 8080;

    const struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr = {
            .s_addr = INADDR_ANY
        }
    };    
 
    socklen_t addrlen;

    int socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);

    if(socket_descriptor == -1) {
        printf("Failed to initialize socket: %d \n", errno);
        return -1;
    }

    int ret = bind(socket_descriptor, (struct sockaddr*) &addr, sizeof(addr));

    if(ret == -1) {
        printf("Failed to bind socket: %d \n", errno);
        return -1;
    }

    ret = listen(socket_descriptor, 10 /* backlog */);

    if(ret == -1) {
        printf("Failed to listen on socket: %d \n", errno);
        return -1;
    }

    std::cout << "Listening on port " << port << std::endl; 
    int clientSocket = accept(socket_descriptor, nullptr, nullptr);

    // recieving data
    char buffer[1024] = { 0 };
    recv(clientSocket, buffer, sizeof(buffer), 0);
    std::cout << "Message from client: " << buffer << std::endl;

    
    close(socket_descriptor);

    return 0;
}