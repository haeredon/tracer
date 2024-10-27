
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <iostream>
#include <string.h>


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

    int ret = connect(socket_descriptor, (struct sockaddr*) &addr, sizeof(addr));

    if(ret == -1) {
        printf("Failed to connect to remote server: %d \n", errno);
        return -1;
    }

    // sending data
    const char* message = "Happy Tracing!";
    ret = send(socket_descriptor, message, strlen(message), 0);
    
    if(ret == -1) {
        printf("Failed to send data to remote server: %d \n", errno);
        return -1;
    }

    close(socket_descriptor);

    return 0;
}