#ifndef CLIENT_NODE_H
#define CLIENT_NODE_H

#include "Client.h"

/**
 * @class ClientNode
 * @brief Node for the binary search tree of clients
 */
class ClientNode {
public:
    Client* data;
    ClientNode* left;
    ClientNode* right;
    
    /**
     * @brief Constructor
     * @param data Pointer to the client data
     */
    explicit ClientNode(Client* data);
    
    /**
     * @brief Destructor - does not delete client data
     */
    ~ClientNode();
};

#endif // CLIENT_NODE_H 