#include "../include/ClientBST.h"
#include "../include/GoldClient.h"
#include "../include/PlatinumClient.h"
#include "../include/StandardClient.h"
#include <iostream>
#include <cstdio>
#include <cstring>

ClientBST::ClientBST() : root(nullptr) {
    // Constructor implementation
}

ClientBST::~ClientBST() {
    destroyRecursive(root);
}

void ClientBST::destroyRecursive(ClientNode* node) {
    if (node == nullptr) {
        return;
    }
    
    destroyRecursive(node->left);
    destroyRecursive(node->right);
    delete node;
}

ClientNode* ClientBST::insertRecursive(ClientNode* node, Client* client) {
    if (node == nullptr) {
        return new ClientNode(client);
    }
    
    // Compare by total balance for ordering
    if (client->getTotalBalance() < node->data->getTotalBalance()) {
        node->left = insertRecursive(node->left, client);
    } else {
        node->right = insertRecursive(node->right, client);
    }
    
    return node;
}

void ClientBST::insert(Client* client) {
    if (client == nullptr) {
        return;
    }
    
    root = insertRecursive(root, client);
}

ClientNode* ClientBST::findMinNode(ClientNode* node) {
    ClientNode* current = node;
    
    // Find the leftmost leaf node
    while (current != nullptr && current->left != nullptr) {
        current = current->left;
    }
    
    return current;
}

ClientNode* ClientBST::removeRecursive(ClientNode* node, const std::string& id) {
    if (node == nullptr) {
        return nullptr;
    }
    
    // Find the node to remove
    if (id == node->data->getId()) {
        // Case 1: Leaf node (no children)
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }
        // Case 2: Node with only one child
        else if (node->left == nullptr) {
            ClientNode* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            ClientNode* temp = node->left;
            delete node;
            return temp;
        }
        // Case 3: Node with two children
        else {
            // Find in-order successor (smallest node in right subtree)
            ClientNode* temp = findMinNode(node->right);
            
            // Copy the successor's data to this node
            node->data = temp->data;
            
            // Delete the successor
            node->right = removeRecursive(node->right, temp->data->getId());
        }
    }
    else {
        // Recursively search for the node
        node->left = removeRecursive(node->left, id);
        node->right = removeRecursive(node->right, id);
    }
    
    return node;
}

bool ClientBST::remove(const std::string& id) {
    if (root == nullptr) {
        return false;
    }
    
    // Check if the client exists before trying to remove
    if (find(id) == nullptr) {
        return false;
    }
    
    root = removeRecursive(root, id);
    return true;
}

Client* ClientBST::findRecursive(ClientNode* node, const std::string& id) {
    if (node == nullptr) {
        return nullptr;
    }
    
    if (node->data->getId() == id) {
        return node->data;
    }
    
    // Search in both subtrees since we're ordering by balance, not ID
    Client* leftResult = findRecursive(node->left, id);
    if (leftResult != nullptr) {
        return leftResult;
    }
    
    return findRecursive(node->right, id);
}

Client* ClientBST::find(const std::string& id) {
    return findRecursive(root, id);
}

void ClientBST::displayInOrderRecursive(ClientNode* node) const {
    if (node == nullptr) {
        return;
    }
    
    displayInOrderRecursive(node->left);
    
    // Display client information
    std::cout << "Client ID: " << node->data->getId() << std::endl;
    std::cout << "Name: " << node->data->getName() << std::endl;
    std::cout << "Total Balance: $" << node->data->getTotalBalance() << std::endl;
    std::cout << "Max Transaction Limit: $" << node->data->getMaxTransactionLimit() << std::endl;
    
    // Display client type based on commission rate
    double commission = node->data->calculateCommission(100.0);
    if (commission == 1.0) {
        std::cout << "Type: Gold" << std::endl;
        std::cout << "Benefits: " << dynamic_cast<GoldClient*>(node->data)->getBenefits() << std::endl;
    } else if (commission == 2.0) {
        std::cout << "Type: Platinum" << std::endl;
        std::cout << "Benefits: " << dynamic_cast<PlatinumClient*>(node->data)->getBenefits() << std::endl;
    } else {
        std::cout << "Type: Standard" << std::endl;
        std::cout << "Benefits: " << dynamic_cast<StandardClient*>(node->data)->getBenefits() << std::endl;
    }
    
    std::cout << "------------------------" << std::endl;
    
    displayInOrderRecursive(node->right);
}

void ClientBST::displayInOrder() const {
    if (root == nullptr) {
        std::cout << "No clients to display." << std::endl;
        return;
    }
    
    std::cout << "Client List (ordered by balance):" << std::endl;
    std::cout << "------------------------" << std::endl;
    displayInOrderRecursive(root);
}

void ClientBST::saveToFileRecursive(FILE* file, ClientNode* node) const {
    if (node == nullptr) {
        return;
    }
    
    saveToFileRecursive(file, node->left);
    
    // Determine client type and save appropriate info
    Client* client = node->data;
    int clientType = 0; // 0 for Standard, 1 for Platinum, 2 for Gold
    
    double commission = client->calculateCommission(100.0);
    if (commission == 1.0) {
        clientType = 2; // Gold
    } else if (commission == 2.0) {
        clientType = 1; // Platinum
    }
    
    fprintf(file, "%s,%s,%d\n", client->getId().c_str(), client->getName().c_str(), clientType);
    
    saveToFileRecursive(file, node->right);
}

bool ClientBST::saveToFile(const std::string& filename) const {
    FILE* file = fopen(filename.c_str(), "w");
    if (file == nullptr) {
        return false;
    }
    
    saveToFileRecursive(file, root);
    
    fclose(file);
    return true;
}

bool ClientBST::loadFromFile(const std::string& filename) {
    FILE* file = fopen(filename.c_str(), "r");
    if (file == nullptr) {
        return false;
    }
    
    // Clear existing tree
    destroyRecursive(root);
    root = nullptr;
    
    char id[256], name[256];
    int clientType;
    
    while (fscanf(file, "%255[^,],%255[^,],%d\n", id, name, &clientType) == 3) {
        Client* client = nullptr;
        
        switch (clientType) {
            case 0: // Standard
                client = new StandardClient(id, name);
                break;
            case 1: // Platinum
                client = new PlatinumClient(id, name);
                break;
            case 2: // Gold
                client = new GoldClient(id, name);
                break;
            default:
                continue; // Skip invalid records
        }
        
        insert(client);
    }
    
    fclose(file);
    return true;
}

ClientNode* ClientBST::getRoot() const {
    return root;
} 