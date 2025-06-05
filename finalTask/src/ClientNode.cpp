#include "../include/ClientNode.h"

ClientNode::ClientNode(Client* data)
    : data(data), left(nullptr), right(nullptr) {
    // Constructor implementation
}

ClientNode::~ClientNode() {
    // Destructor - does not delete client data
    // Only the node is deleted, not the client it points to
} 