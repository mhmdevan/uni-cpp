#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Entity.h"
#include <string>

// Transaction type enum
enum class TxType {
    TRANSFER
};

/**
 * @class Transaction
 * @brief Represents a financial transaction between wallets
 */
class Transaction : public Entity {
private:
    std::string senderWalletId;
    std::string recipientWalletId;
    double amount;
    TxType type;
    double commission;

public:
    /**
     * @brief Constructor
     * @param id Transaction ID
     * @param senderWalletId ID of the sender's wallet
     * @param recipientWalletId ID of the recipient's wallet
     * @param amount Transaction amount
     * @param type Transaction type
     * @param commission Commission amount
     */
    Transaction(const std::string& id, 
               const std::string& senderWalletId, 
               const std::string& recipientWalletId,
               double amount, 
               TxType type, 
               double commission);
    
    /**
     * @brief Override of the getId method from Entity
     * @return The transaction's ID
     */
    std::string getId() const override;
    
    /**
     * @brief Get sender wallet ID
     * @return The sender wallet's ID
     */
    std::string getSenderWalletId() const;
    
    /**
     * @brief Get recipient wallet ID
     * @return The recipient wallet's ID
     */
    std::string getRecipientWalletId() const;
    
    /**
     * @brief Get transaction amount
     * @return The transaction amount
     */
    double getAmount() const;
    
    /**
     * @brief Get transaction type
     * @return The transaction type
     */
    TxType getType() const;
    
    /**
     * @brief Get commission amount
     * @return The commission amount
     */
    double getCommission() const;
    
    /**
     * @brief Get transaction details as a formatted string
     * @return String with transaction details
     */
    std::string getDetails() const;
};

#endif // TRANSACTION_H 