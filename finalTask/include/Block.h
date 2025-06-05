#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <vector>
#include <memory>
#include "Transaction.h"
#include <ctime>
#include <sstream>
#include <iomanip>

/**
 * @class Block
 * @brief Represents a block in the blockchain containing transactions
 */
class Block {
private:
    std::string previousHash;
    std::string hash;
    time_t timestamp;
    std::vector<std::shared_ptr<Transaction>> transactions;
    int nonce;
    
    /**
     * @brief Calculates the hash of the block
     * @return The calculated hash
     */
    std::string calculateHash() const;

public:
    /**
     * @brief Constructor
     * @param previousHash Hash of the previous block
     * @param transactions Vector of transactions in this block
     */
    Block(const std::string& previousHash, const std::vector<std::shared_ptr<Transaction>>& transactions);
    
    /**
     * @brief Get the previous block's hash
     * @return The previous hash
     */
    std::string getPreviousHash() const;
    
    /**
     * @brief Get this block's hash
     * @return The hash
     */
    std::string getHash() const;
    
    /**
     * @brief Get the block's timestamp
     * @return The timestamp
     */
    time_t getTimestamp() const;
    
    /**
     * @brief Get the transactions in this block
     * @return Vector of transaction pointers
     */
    std::vector<std::shared_ptr<Transaction>> getTransactions() const;
    
    /**
     * @brief Validate this block's hash
     * @return true if hash is valid, false otherwise
     */
    bool validateHash() const;
};

#endif // BLOCK_H 