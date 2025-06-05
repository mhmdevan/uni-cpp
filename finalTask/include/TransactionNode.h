#ifndef TRANSACTION_NODE_H
#define TRANSACTION_NODE_H

#include "Transaction.h"

/**
 * @class TransactionNode
 * @brief Node for the doubly-linked list of transactions
 */
class TransactionNode {
public:
    Transaction* data;
    TransactionNode* prev;
    TransactionNode* next;
    
    /**
     * @brief Constructor
     * @param data Pointer to the transaction
     */
    explicit TransactionNode(Transaction* data);
    
    /**
     * @brief Destructor - does not delete transaction data
     */
    ~TransactionNode();
};

#endif // TRANSACTION_NODE_H 