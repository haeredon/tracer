#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "stdlib.h"
#include <thread>
#include <atomic>
#include <array>

#include "Tracer.h"
#include "NodeFactory.h"
#include "Node.h"

std::string receiverPropertyFiles[] = {
    "receiver0_middle.properties",
    "receiver1_middle.properties",
    "receiver0_bottom.properties"
};

std::string requesterPropertyFiles[] = {
    "requester0.properties"
};

void run(Node* node) {
    node->start();
}

int main(int argc, char* argv[]) {
    NodeFactory nodeFactory;

    if(argc != 2) {
        std::cout << "Give a path to the config folder" << std::endl;
        throw;
    }

    std::string basePath { argv[1] };

    std::vector<Node*> receiverNodes;
    std::vector<std::thread> threads;

    for(std::size_t i = 0 ; i < std::size(receiverPropertyFiles) ; i++) {
        Node* node = nodeFactory.createNode(basePath + receiverPropertyFiles[i]);
        receiverNodes.push_back(node);
        threads.emplace_back(run, node);        
    }

    while(!std::all_of(receiverNodes.begin(), receiverNodes.end(), [](Node* node) { return node->hasStarted(); })) {}
    
    for(std::size_t i = 0 ; i < std::size(requesterPropertyFiles) ; i++) {
        threads.emplace_back(run, nodeFactory.createNode(basePath + requesterPropertyFiles[i]));                
    }

    // join all
    for(auto it = threads.begin() ; it != threads.end() ; it++) {
        it->join();
    }
}         


