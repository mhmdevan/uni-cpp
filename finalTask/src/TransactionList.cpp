#include "../include/TransactionList.h"
#include <iostream>
#include <cstdio>

TransactionList::TransactionList() : head(nullptr), tail(nullptr), size(0) {
    // Constructor implementation
}

TransactionList::~TransactionList() {
    // Delete all nodes in the list
    TransactionNode* current = head;
    
    while (current != nullptr) {
        TransactionNode* next = current->next;
        delete current;
        current = next;
    }
    
    head = nullptr;
    tail = nullptr;
}

void TransactionList::addTransaction(Transaction* tx) {
    if (tx == nullptr) {
        return;
    }
    
    TransactionNode* newNode = new TransactionNode(tx);
    
    if (head == nullptr) {
        // List is empty
        head = newNode;
        tail = newNode;
    } else {
        // Add to the end of the list
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    
    size++;
}

bool TransactionList::removeTransaction(const std::string& id) {
    if (head == nullptr) {
        return false;
    }
    
    TransactionNode* current = head;
    
    while (current != nullptr) {
        if (current->data->getId() == id) {
            // Found the node to remove
            
            if (current == head && current == tail) {
                // Only node in the list
                head = nullptr;
                tail = nullptr;
            } else if (current == head) {
                // First node in the list
                head = current->next;
                head->prev = nullptr;
            } else if (current == tail) {
                // Last node in the list
                tail = current->prev;
                tail->next = nullptr;
            } else {
                // Middle node in the list
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            
            delete current;
            size--;
            return true;
        }
        
        current = current->next;
    }
    
    return false;
}

Transaction* TransactionList::getTransaction(const std::string& id) {
    TransactionNode* current = head;
    
    while (current != nullptr) {
        if (current->data->getId() == id) {
            return current->data;
        }
        
        current = current->next;
    }
    
    return nullptr;
}

void TransactionList::displayTransactions() const {
    if (head == nullptr) {
        std::cout << "No transactions to display." << std::endl;
        return;
    }
    
    TransactionNode* current = head;
    int count = 1;
    
    while (current != nullptr) {
        std::cout << "Transaction #" << count << ":" << std::endl;
        std::cout << current->data->getDetails() << std::endl;
        
        current = current->next;
        count++;
    }
}

int TransactionList::getSize() const {
    return size;
}

bool TransactionList::saveToFile(const std::string& filename) const {
    FILE* file = fopen(filename.c_str(), "w");
    if (file == nullptr) {
        return false;
    }
    
    TransactionNode* current = head;
    
    while (current != nullptr) {
        Transaction* tx = current->data;
        fprintf(file, "%s,%s,%s,%.2f,%d,%.2f\n", 
                tx->getId().c_str(),
                tx->getSenderWalletId().c_str(),
                tx->getRecipientWalletId().c_str(),
                tx->getAmount(),
                static_cast<int>(tx->getType()),
                tx->getCommission());
        
        current = current->next;
    }
    
    fclose(file);
    return true;
}

bool TransactionList::loadFromFile(const std::string& filename) {
    FILE* file = fopen(filename.c_str(), "r");
    if (file == nullptr) {
        return false;
    }
    
    // Clear existing transactions
    TransactionNode* current = head;
    while (current != nullptr) {
        TransactionNode* next = current->next;
        delete current;
        current = next;
    }
    
    head = nullptr;
    tail = nullptr;
    size = 0;
    
    char id[256], senderWalletId[256], recipientWalletId[256];
    double amount, commission;
    int typeInt;
    
    while (fscanf(file, "%255[^,],%255[^,],%255[^,],%lf,%d,%lf\n", 
                  id, senderWalletId, recipientWalletId, &amount, &typeInt, &commission) == 6) {
        TxType type = static_cast<TxType>(typeInt);
        
        Transaction* tx = new Transaction(id, senderWalletId, recipientWalletId, amount, type, commission);
        addTransaction(tx);
    }
    
    fclose(file);
    return true;
} 