#ifndef TRANSACTION_LIST_H
#define TRANSACTION_LIST_H

#include "TransactionNode.h"
#include <string>

/**
 * @class TransactionList
 * @brief Doubly-linked list for managing transactions
 */
class TransactionList {
private:
    TransactionNode* head;
    TransactionNode* tail;
    int size;

public:
    /**
     * @brief Default constructor
     */
    TransactionList();
    
    /**
     * @brief Destructor - deletes all nodes but not the transaction data
     */
    ~TransactionList();
    
    /**
     * @brief Add a transaction to the list
     * @param tx Pointer to the transaction to add
     */
    void addTransaction(Transaction* tx);
    
    /**
     * @brief Remove a transaction by ID
     * @param id ID of the transaction to remove
     * @return true if transaction was found and removed, false otherwise
     */
    bool removeTransaction(const std::string& id);
    
    /**
     * @brief Find a transaction by ID
     * @param id ID of the transaction to find
     * @return Pointer to the found transaction, or nullptr if not found
     */
    Transaction* getTransaction(const std::string& id);
    
    /**
     * @brief Display all transactions in the list
     */
    void displayTransactions() const;
    
    /**
     * @brief Get the number of transactions in the list
     * @return The size of the list
     */
    int getSize() const;
    
    /**
     * @brief Save transactions to a file
     * @param filename Name of the file to save to
     * @return true if successful, false otherwise
     */
    bool saveToFile(const std::string& filename) const;
    
    /**
     * @brief Load transactions from a file
     * @param filename Name of the file to load from
     * @return true if successful, false otherwise
     */
    bool loadFromFile(const std::string& filename);
};

#endif // TRANSACTION_LIST_H 