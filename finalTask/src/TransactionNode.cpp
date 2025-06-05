#include "../include/TransactionNode.h"

TransactionNode::TransactionNode(Transaction* data)
    : data(data), prev(nullptr), next(nullptr) {
    // Constructor implementation
}

TransactionNode::~TransactionNode() {
    // Destructor - does not delete transaction data
    // Only the node is deleted, not the transaction it points to
} 