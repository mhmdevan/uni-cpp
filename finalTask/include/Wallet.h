#ifndef WALLET_H
#define WALLET_H

#include "Entity.h"
#include <string>

/**
 * @class Wallet
 * @brief Represents a wallet that stores funds for transactions
 */
class Wallet : public Entity {
private:
    double balance;
    std::string ownerId; // ID of the client who owns this wallet

public:
    /**
     * @brief Constructor
     * @param id Wallet ID
     * @param ownerId ID of the client who owns this wallet
     * @param balance Initial balance (default 0.0)
     */
    Wallet(const std::string& id, const std::string& ownerId, double balance = 0.0);
    
    /**
     * @brief Deposit funds into the wallet
     * @param amount Amount to deposit
     * @return true if deposit successful, false otherwise
     */
    bool deposit(double amount);
    
    /**
     * @brief Withdraw funds from the wallet
     * @param amount Amount to withdraw
     * @return true if successful, false if insufficient funds
     */
    bool withdraw(double amount);
    
    /**
     * @brief Get the current balance
     * @return The wallet balance
     */
    double getBalance() const;
    
    /**
     * @brief Get the ID of the owner
     * @return The owner's ID
     */
    std::string getOwnerId() const;
    
    /**
     * @brief Override of the getId method from Entity
     * @return The wallet's ID
     */
    std::string getId() const override;
};

#endif // WALLET_H 