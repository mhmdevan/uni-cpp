#include "../include/Blockchain.h"
#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stdexcept>
#include <cstdlib>

Blockchain::Blockchain()
{
    // Initialize with empty client BST and transaction list
    
    // Create a genesis block (first block in the chain)
    blocks.push_back(std::make_shared<Block>("0", std::vector<std::shared_ptr<Transaction>>()));
}

void Blockchain::addClient(Client *client)
{
    clients.insert(client);
}

bool Blockchain::processTransaction(const std::string &senderWalletId, const std::string &recipientWalletId, double amount)
{
    // Validate input
    if (senderWalletId == recipientWalletId)
    {
        std::cout << "Transaction failed: Sender and recipient wallets cannot be the same." << std::endl;
        return false;
    }
    
    if (amount <= 0)
    {
        std::cout << "Transaction failed: Amount must be greater than zero." << std::endl;
        return false;
    }
    
    // Find the clients that own the wallets
    Client *senderClient = findClientByWalletId(senderWalletId);
    Client *recipientClient = findClientByWalletId(recipientWalletId);
    
    if (senderClient == nullptr || recipientClient == nullptr)
    {
        std::cout << "Transaction failed: Client not found for one or both wallets." << std::endl;
        return false;
    }
    
    // Get the wallets
    Wallet *senderWallet = senderClient->getWallet(senderWalletId);
    Wallet *recipientWallet = recipientClient->getWallet(recipientWalletId);
    
    if (senderWallet == nullptr || recipientWallet == nullptr)
    {
        std::cout << "Transaction failed: One or both wallets not found." << std::endl;
        return false;
    }
    
    // Check transaction limit
    double maxLimit = senderClient->getMaxTransactionLimit();
    if (amount > maxLimit)
    {
        std::cout << "Transaction failed: Amount exceeds transaction limit of $" << maxLimit << std::endl;
        return false;
    }
    
    // Calculate commission
    double commission = senderClient->calculateCommission(amount);
    double totalAmount = amount + commission;
    
    // Check if sender has sufficient funds
    if (senderWallet->getBalance() < totalAmount)
    {
        std::cout << "Transaction failed: Insufficient funds." << std::endl;
        return false;
    }
    
    // Generate unique transaction ID
    std::stringstream txIdStream;
    txIdStream << "TX" << std::setfill('0') << std::setw(10) << time(nullptr) << std::setw(4) << rand() % 10000;
    std::string txId = txIdStream.str();
    
    // Create transaction object
    Transaction *tx = new Transaction(txId, senderWalletId, recipientWalletId, amount, TxType::TRANSFER, commission);
    
    // Process the transaction
    if (senderWallet->withdraw(totalAmount) && recipientWallet->deposit(amount))
    {
        transactions.addTransaction(tx);
        
        // Create a shared_ptr wrapper for the transaction to add to a block
        std::shared_ptr<Transaction> txPtr(tx, [](Transaction*) { /* Empty deleter to avoid double deletion */ });
        std::vector<std::shared_ptr<Transaction>> blockTransactions = {txPtr};
        
        // Add a new block to the blockchain
        try {
            addBlock(blockTransactions);
            std::cout << "Transaction added to blockchain in block #" << blocks.size() - 1 << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Warning: " << e.what() << std::endl;
        }
        
        std::cout << "Transaction successful. ID: " << txId << std::endl;
        return true;
    }
    else
    {
        std::cout << "Transaction failed: Error processing funds." << std::endl;
        delete tx;
        return false;
    }
}

void Blockchain::displayClients() const
{
    clients.displayInOrder();
}

void Blockchain::displayTransactions() const
{
    transactions.displayTransactions();
}

Client *Blockchain::getClient(const std::string &id)
{
    return clients.find(id);
}

bool Blockchain::createWallet(const std::string &clientId, const std::string &walletId, double initialBalance)
{
    Client *client = getClient(clientId);
    if (client == nullptr)
    {
        std::cout << "Wallet creation failed: Client not found." << std::endl;
        return false;
    }
    
    // Check if the wallet already exists
    if (findClientByWalletId(walletId) != nullptr)
    {
        std::cout << "Wallet creation failed: Wallet ID already exists." << std::endl;
        return false;
    }
    
    // Create the new wallet
    Wallet *wallet = new Wallet(walletId, clientId, initialBalance);
    client->addWallet(wallet);
    
    std::cout << "Wallet created successfully for client: " << client->getName() << std::endl;
    return true;
}

bool Blockchain::saveData() const
{
    // Make sure the data directory exists
    system("mkdir -p data");
    
    bool clientsSaved = clients.saveToFile("data/Clients.txt");
    bool transactionsSaved = transactions.saveToFile("data/Blockchain_transactions.txt");
    
    return clientsSaved && transactionsSaved;
}

bool Blockchain::loadData()
{
    bool clientsLoaded = clients.loadFromFile("data/Clients.txt");
    bool transactionsLoaded = transactions.loadFromFile("data/Blockchain_transactions.txt");
    
    return clientsLoaded && transactionsLoaded;
}

// Helper method to find a client by wallet ID
Client *Blockchain::findClientByWalletId(const std::string &walletId)
{
    // Find client by wallet ID by recursively searching the BST
    return findClientByWalletIdRecursive(walletId, clients.getRoot());
}

// Recursive helper for findClientByWalletId
Client *Blockchain::findClientByWalletIdRecursive(const std::string &walletId, ClientNode *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    
    // Check if this client has the wallet
    Client *client = node->data;
    Wallet *wallet = client->getWallet(walletId);
    if (wallet != nullptr)
    {
        return client;
    }
    
    // Recursively check left and right subtrees
    Client *leftResult = findClientByWalletIdRecursive(walletId, node->left);
    if (leftResult != nullptr)
    {
        return leftResult;
    }
    
    return findClientByWalletIdRecursive(walletId, node->right);
}

void Blockchain::addBlock(const std::vector<std::shared_ptr<Transaction>>& transactions) {
    if (blocks.empty()) {
        throw std::runtime_error("Blockchain not initialized with genesis block");
    }

    std::string previousHash = blocks.back()->getHash();
    blocks.push_back(std::make_shared<Block>(previousHash, transactions));
}

bool Blockchain::validateChain() const {
    if (blocks.size() <= 1) {
        return true; // Only genesis block or empty chain
    }

    for (size_t i = 1; i < blocks.size(); i++) {
        // Check if the previous hash matches
        if (blocks[i]->getPreviousHash() != blocks[i-1]->getHash()) {
            return false;
        }

        // Validate the block's hash
        if (!blocks[i]->validateHash()) {
            return false;
        }
    }

    return true;
}

std::vector<std::shared_ptr<Block>> Blockchain::getBlocks() const {
    return blocks;
}

std::shared_ptr<Block> Blockchain::getLatestBlock() const {
    if (blocks.empty()) {
        return nullptr;
    }
    return blocks.back();
}