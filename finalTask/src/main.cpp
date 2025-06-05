#include "../include/Blockchain.h"
#include "../include/GoldClient.h"
#include "../include/PlatinumClient.h"
#include "../include/StandardClient.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits> // For std::numeric_limits

// Function prototypes
void displayMenu();
void createClient(Blockchain& blockchain);
void createWallet(Blockchain& blockchain);
void processTransaction(Blockchain& blockchain);
void displayClients(Blockchain& blockchain);
void displayTransactions(Blockchain& blockchain);
void saveData(Blockchain& blockchain);
void loadData(Blockchain& blockchain);
void displayBlockchain(const Blockchain& blockchain);

int main() {
    // Seed random number generator
    srand(static_cast<unsigned int>(time(nullptr)));
    
    // Create blockchain system
    Blockchain blockchain;
    
    // Try to load existing data
    blockchain.loadData();
    
    // Main menu loop
    int choice = 0;
    bool exit = false;
    
    while (!exit) {
        displayMenu();
        std::cout << "Enter your choice: ";
        
        // Make sure we read a valid integer
        if (!(std::cin >> choice)) {
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a number." << std::endl;
            continue;
        }
        
        // Clear input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choice) {
            case 1:
                createClient(blockchain);
                break;
            case 2:
                createWallet(blockchain);
                break;
            case 3:
                processTransaction(blockchain);
                break;
            case 4:
                displayClients(blockchain);
                break;
            case 5:
                displayTransactions(blockchain);
                break;
            case 6:
                saveData(blockchain);
                break;
            case 7:
                loadData(blockchain);
                break;
            case 8:
                displayBlockchain(blockchain);
                break;
            case 9:
                exit = true;
                std::cout << "Exiting program. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 9." << std::endl;
        }
        
        std::cout << std::endl;
    }
    
    // Save data before exiting
    saveData(blockchain);
    
    return 0;
}

void displayMenu() {
    std::cout << "=== Blockchain Financial System ===" << std::endl;
    std::cout << "1. Create Client" << std::endl;
    std::cout << "2. Create Wallet" << std::endl;
    std::cout << "3. Process Transaction" << std::endl;
    std::cout << "4. Display Clients" << std::endl;
    std::cout << "5. Display Transactions" << std::endl;
    std::cout << "6. Save Data" << std::endl;
    std::cout << "7. Load Data" << std::endl;
    std::cout << "8. Display Blockchain" << std::endl;
    std::cout << "9. Exit" << std::endl;
    std::cout << "=================================" << std::endl;
}

void createClient(Blockchain& blockchain) {
    std::string id, name;
    int clientType;
    
    std::cout << "=== Create Client ===" << std::endl;
    
    std::cout << "Enter client ID: ";
    std::getline(std::cin, id);
    
    std::cout << "Enter client name: ";
    std::getline(std::cin, name);
    
    std::cout << "Select client type:" << std::endl;
    std::cout << "1. Standard (5% commission, $1000 limit)" << std::endl;
    std::cout << "2. Platinum (2% commission, $5000 limit)" << std::endl;
    std::cout << "3. Gold (1% commission, $10000 limit)" << std::endl;
    std::cout << "Enter choice: ";
    std::cin >> clientType;
    
    Client* client = nullptr;
    
    switch (clientType) {
        case 1:
            client = new StandardClient(id, name);
            break;
        case 2:
            client = new PlatinumClient(id, name);
            break;
        case 3:
            client = new GoldClient(id, name);
            break;
        default:
            std::cout << "Invalid client type. Creating Standard client by default." << std::endl;
            client = new StandardClient(id, name);
    }
    
    blockchain.addClient(client);
    std::cout << "Client created successfully." << std::endl;
}

void createWallet(Blockchain& blockchain) {
    std::string clientId, walletId;
    double initialBalance;
    
    std::cout << "=== Create Wallet ===" << std::endl;
    
    std::cout << "Enter client ID: ";
    std::getline(std::cin, clientId);
    
    std::cout << "Enter wallet ID: ";
    std::getline(std::cin, walletId);
    
    std::cout << "Enter initial balance: $";
    std::cin >> initialBalance;
    
    if (blockchain.createWallet(clientId, walletId, initialBalance)) {
        std::cout << "Wallet created successfully." << std::endl;
    }
}

void processTransaction(Blockchain& blockchain) {
    std::string senderWalletId, recipientWalletId;
    double amount;
    
    std::cout << "=== Process Transaction ===" << std::endl;
    
    std::cout << "Enter sender wallet ID: ";
    std::getline(std::cin, senderWalletId);
    
    std::cout << "Enter recipient wallet ID: ";
    std::getline(std::cin, recipientWalletId);
    
    std::cout << "Enter transaction amount: $";
    std::cin >> amount;
    
    if (blockchain.processTransaction(senderWalletId, recipientWalletId, amount)) {
        std::cout << "Transaction processed successfully." << std::endl;
    }
}

void displayClients(Blockchain& blockchain) {
    std::cout << "=== Client List ===" << std::endl;
    blockchain.displayClients();
}

void displayTransactions(Blockchain& blockchain) {
    std::cout << "=== Transaction List ===" << std::endl;
    blockchain.displayTransactions();
}

void saveData(Blockchain& blockchain) {
    if (blockchain.saveData()) {
        std::cout << "Data saved successfully." << std::endl;
    } else {
        std::cout << "Error saving data." << std::endl;
    }
}

void loadData(Blockchain& blockchain) {
    if (blockchain.loadData()) {
        std::cout << "Data loaded successfully." << std::endl;
    } else {
        std::cout << "Error loading data." << std::endl;
    }
}

void displayBlockchain(const Blockchain& blockchain) {
    std::cout << "=== Blockchain Information ===" << std::endl;
    
    auto blocks = blockchain.getBlocks();
    std::cout << "Total blocks: " << blocks.size() << std::endl;
    
    bool isValid = blockchain.validateChain();
    std::cout << "Chain validity: " << (isValid ? "Valid" : "Invalid") << std::endl;
    
    std::cout << "\nBlock details:" << std::endl;
    for (size_t i = 0; i < blocks.size(); i++) {
        std::cout << "Block #" << i << ":" << std::endl;
        std::cout << "  Hash: " << blocks[i]->getHash() << std::endl;
        if (i > 0) {
            std::cout << "  Previous Hash: " << blocks[i]->getPreviousHash() << std::endl;
        } else {
            std::cout << "  Genesis Block" << std::endl;
        }
        
        auto txs = blocks[i]->getTransactions();
        std::cout << "  Transactions: " << txs.size() << std::endl;
        
        // Display transaction details if any
        if (!txs.empty()) {
            std::cout << "  Transaction IDs:" << std::endl;
            for (const auto& tx : txs) {
                std::cout << "    - " << tx->getId() << std::endl;
            }
        }
        
        std::cout << std::endl;
    }
} 