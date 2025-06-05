#ifndef CLIENT_H
#define CLIENT_H

#include "Entity.h"
#include "EntityVector.h"
#include "Wallet.h"
#include <string>

/**
 * @class Client
 * @brief Abstract base class for different types of clients
 */
class Client : public Entity {
protected:
    std::string name;
    EntityVector wallets; // Collection of client's wallets

public:
    /**
     * @brief Constructor
     * @param id Client ID
     * @param name Client name
     */
    Client(const std::string& id, const std::string& name);
    
    /**
     * @brief Virtual destructor
     */
    virtual ~Client() = default;
    
    /**
     * @brief Add a wallet to the client
     * @param wallet Pointer to the wallet to add
     */
    void addWallet(Wallet* wallet);
    
    /**
     * @brief Get the total balance across all wallets
     * @return Sum of all wallet balances
     */
    double getTotalBalance() const;
    
    /**
     * @brief Get the client's name
     * @return The client's name
     */
    std::string getName() const;
    
    /**
     * @brief Override of the getId method from Entity
     * @return The client's ID
     */
    std::string getId() const override;
    
    /**
     * @brief Get a wallet by ID
     * @param walletId ID of the wallet to find
     * @return Pointer to the wallet, or nullptr if not found
     */
    Wallet* getWallet(const std::string& walletId);
    
    /**
     * @brief Get all wallets owned by the client
     * @return Reference to the vector of wallet pointers
     */
    std::vector<Entity*>& getWallets();
    
    /**
     * @brief Calculate commission for a transaction
     * @param amount Transaction amount
     * @return Commission amount
     */
    virtual double calculateCommission(double amount) const = 0;
    
    /**
     * @brief Get the maximum transaction limit
     * @return Maximum transaction amount allowed
     */
    virtual double getMaxTransactionLimit() const = 0;
};

#endif // CLIENT_H 