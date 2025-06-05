#include "../include/Transaction.h"
#include <sstream>
#include <iomanip>

Transaction::Transaction(const std::string& id, 
                       const std::string& senderWalletId, 
                       const std::string& recipientWalletId,
                       double amount, 
                       TxType type, 
                       double commission)
    : Entity(id), 
      senderWalletId(senderWalletId), 
      recipientWalletId(recipientWalletId),
      amount(amount), 
      type(type), 
      commission(commission) {
    // Constructor implementation
}

std::string Transaction::getId() const {
    return id;
}

std::string Transaction::getSenderWalletId() const {
    return senderWalletId;
}

std::string Transaction::getRecipientWalletId() const {
    return recipientWalletId;
}

double Transaction::getAmount() const {
    return amount;
}

TxType Transaction::getType() const {
    return type;
}

double Transaction::getCommission() const {
    return commission;
}

std::string Transaction::getDetails() const {
    std::stringstream ss;
    
    ss << "Transaction ID: " << id << std::endl;
    ss << "Type: ";
    
    switch (type) {
        case TxType::TRANSFER:
            ss << "Transfer";
            break;
        default:
            ss << "Unknown";
    }
    
    ss << std::endl;
    ss << "From Wallet: " << senderWalletId << std::endl;
    ss << "To Wallet: " << recipientWalletId << std::endl;
    ss << "Amount: $" << std::fixed << std::setprecision(2) << amount << std::endl;
    ss << "Commission: $" << std::fixed << std::setprecision(2) << commission << std::endl;
    ss << "Net Amount: $" << std::fixed << std::setprecision(2) << (amount + commission) << std::endl;
    
    return ss.str();
} 