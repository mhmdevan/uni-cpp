#include "../include/Block.h"
#include <sstream>
#include <iomanip>
#include <ctime>
#include <functional>

Block::Block(const std::string& previousHash, const std::vector<std::shared_ptr<Transaction>>& transactions)
    : previousHash(previousHash), transactions(transactions), nonce(0) {
    timestamp = time(nullptr);
    hash = calculateHash();
}

std::string Block::calculateHash() const {
    std::stringstream ss;
    ss << previousHash << timestamp << nonce;
    
    // Add transaction information to hash calculation
    for (const auto& tx : transactions) {
        ss << tx->getId();
    }
    
    // Simple hash calculation (in a real blockchain, use SHA-256 or similar)
    std::hash<std::string> hasher;
    size_t hashValue = hasher(ss.str());
    
    // Convert to hexadecimal string
    std::stringstream hashStream;
    hashStream << std::hex << std::setfill('0') << std::setw(16) << hashValue;
    return hashStream.str();
}

std::string Block::getPreviousHash() const {
    return previousHash;
}

std::string Block::getHash() const {
    return hash;
}

time_t Block::getTimestamp() const {
    return timestamp;
}

std::vector<std::shared_ptr<Transaction>> Block::getTransactions() const {
    return transactions;
}

bool Block::validateHash() const {
    return hash == calculateHash();
} 