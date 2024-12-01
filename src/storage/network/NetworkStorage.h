#ifndef TRACE_STORAGE_NETWORK_NETWORK_STORAGE_H
#define TRACE_STORAGE_NETWORK_NETWORK_STORAGE_H

#include <chrono>
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string>
#include <vector>
#include <thread>

#include "utility/ProdConsQueue.h"

template <class QUEUE_T>
class NetworkStorage {

private:

  int socketDescriptor;

  uint16_t port;

  uint32_t ipv4;

  std::vector<std::string> toSend;

  QUEUE_T* queue;

  std::thread worker;

public:

  NetworkStorage() {
    
  }

  // only used for tcp, not udp
  void connect() {
    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_port = htons(this->port),
        .sin_addr = {
            .s_addr = this->ipv4}};

    int ret = connect(this->socketDescriptor, &addr, sizeof(addr));

    if (ret == -1) {
      throw;
    }
  }

  // may only be called once should not be called when there's pending IO.
  void close() {
    int ret = close(socketDescriptor);

    if (ret == -1) {
      throw;
    }
  }

  void open() {
    // could also be SOCK_DGRAM for udp
    this->socketDescriptor = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);

    if (this->socketDescriptor == -1) {
      throw;
    }

    connect();

    worker = std::thread { this->run };

    // need to set SO_KEEPALIVE on socket and handle broken connection

  }

  void run() {
    auto& ddd = queue->front();

    

  }

};

#endif // TRACE_STORAGE_NETWORK_NETWORK_STORAGE_H