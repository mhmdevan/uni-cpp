#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "ClientBST.h"
#include "TransactionList.h"
#include "Client.h"
#include "Transaction.h"
#include "Block.h"
#include <string>
#include <vector>
#include <memory>

/**
 * @class Blockchain
 * @brief Manages clients and transactions in the system
 */
class Blockchain {
private:
    ClientBST clients;
    TransactionList transactions;
    std::vector<std::shared_ptr<Block>> blocks;
    
    /**
     * @brief Find a client by wallet ID
     * @param walletId ID of the wallet to find
     * @return Pointer to the client owning the wallet, or nullptr if not found
     */
    Client* findClientByWalletId(const std::string& walletId);
    
    /**
     * @brief Recursive helper for findClientByWalletId
     * @param walletId ID of the wallet to find
     * @param node Current node in the recursion
     * @return Pointer to the client owning the wallet, or nullptr if not found
     */
    Client* findClientByWalletIdRecursive(const std::string& walletId, ClientNode* node);
    
public:
    /**
     * @brief Default constructor
     */
    Blockchain();
    
    /**
     * @brief Add a client to the blockchain
     * @param client Pointer to the client to add
     */
    void addClient(Client* client);
    
    /**
     * @brief Process a transaction between wallets
     * @param senderWalletId ID of the sender's wallet
     * @param recipientWalletId ID of the recipient's wallet
     * @param amount Transaction amount
     * @return true if transaction was processed successfully, false otherwise
     */
    bool processTransaction(const std::string& senderWalletId, const std::string& recipientWalletId, double amount);
    
    /**
     * @brief Display all clients
     */
    void displayClients() const;
    
    /**
     * @brief Display all transactions
     */
    void displayTransactions() const;
    
    /**
     * @brief Get a client by ID
     * @param id ID of the client to find
     * @return Pointer to the client if found, nullptr otherwise
     */
    Client* getClient(const std::string& id);
    
    /**
     * @brief Create a wallet for a client
     * @param clientId ID of the client
     * @param walletId ID for the new wallet
     * @param initialBalance Initial balance for the wallet
     * @return true if wallet was created successfully, false otherwise
     */
    bool createWallet(const std::string& clientId, const std::string& walletId, double initialBalance);
    
    /**
     * @brief Save clients and transactions to files
     * @return true if successful, false otherwise
     */
    bool saveData() const;
    
    /**
     * @brief Load clients and transactions from files
     * @return true if successful, false otherwise
     */
    bool loadData();
    
    /**
     * @brief Add a new block to the blockchain
     * @param transactions Transactions to include in the block
     */
    void addBlock(const std::vector<std::shared_ptr<Transaction>>& transactions);
    
    /**
     * @brief Validate the entire blockchain
     * @return true if valid, false otherwise
     */
    bool validateChain() const;
    
    /**
     * @brief Get all blocks in the blockchain
     * @return Vector of blocks
     */
    std::vector<std::shared_ptr<Block>> getBlocks() const;
    
    /**
     * @brief Get the latest block in the chain
     * @return Pointer to the latest block, or nullptr if chain is empty
     */
    std::shared_ptr<Block> getLatestBlock() const;
};

#endif // BLOCKCHAIN_H 