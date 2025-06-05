#ifndef CLIENT_BST_H
#define CLIENT_BST_H

#include "ClientNode.h"
#include <string>

// Forward declaration for use in friend class
class Blockchain;

/**
 * @class ClientBST
 * @brief Binary search tree for managing clients, ordered by balance
 */
class ClientBST {
private:
    ClientNode* root;
    
    /**
     * @brief Recursively insert a client into the tree
     * @param node Current node in the recursion
     * @param client Client to insert
     * @return Updated node after insertion
     */
    ClientNode* insertRecursive(ClientNode* node, Client* client);
    
    /**
     * @brief Find the node with the minimum value in the tree
     * @param node Starting node
     * @return Node with minimum value
     */
    ClientNode* findMinNode(ClientNode* node);
    
    /**
     * @brief Recursively remove a client from the tree
     * @param node Current node in the recursion
     * @param id ID of the client to remove
     * @return Updated node after removal
     */
    ClientNode* removeRecursive(ClientNode* node, const std::string& id);
    
    /**
     * @brief Recursively find a client in the tree
     * @param node Current node in the recursion
     * @param id ID of the client to find
     * @return Pointer to the client if found, nullptr otherwise
     */
    Client* findRecursive(ClientNode* node, const std::string& id);
    
    /**
     * @brief Recursively display clients in-order
     * @param node Current node in the recursion
     */
    void displayInOrderRecursive(ClientNode* node) const;
    
    /**
     * @brief Recursively delete all nodes in the tree
     * @param node Current node in the recursion
     */
    void destroyRecursive(ClientNode* node);
    
    /**
     * @brief Recursively save clients to a file
     * @param file File pointer
     * @param node Current node in the recursion
     */
    void saveToFileRecursive(FILE* file, ClientNode* node) const;

public:
    /**
     * @brief Default constructor
     */
    ClientBST();
    
    /**
     * @brief Destructor - deletes all nodes but not the client data
     */
    ~ClientBST();
    
    /**
     * @brief Insert a client into the tree
     * @param client Pointer to the client to insert
     */
    void insert(Client* client);
    
    /**
     * @brief Remove a client by ID
     * @param id ID of the client to remove
     * @return true if client was found and removed, false otherwise
     */
    bool remove(const std::string& id);
    
    /**
     * @brief Find a client by ID
     * @param id ID of the client to find
     * @return Pointer to the client if found, nullptr otherwise
     */
    Client* find(const std::string& id);
    
    /**
     * @brief Display all clients in-order
     */
    void displayInOrder() const;
    
    /**
     * @brief Save clients to a file
     * @param filename Name of the file to save to
     * @return true if successful, false otherwise
     */
    bool saveToFile(const std::string& filename) const;
    
    /**
     * @brief Load clients from a file
     * @param filename Name of the file to load from
     * @return true if successful, false otherwise
     */
    bool loadFromFile(const std::string& filename);
    
    /**
     * @brief Get the root node of the tree
     * @return Pointer to the root node
     */
    ClientNode* getRoot() const;
    
    // Declare Blockchain as a friend class
    friend class Blockchain;
};

#endif // CLIENT_BST_H 