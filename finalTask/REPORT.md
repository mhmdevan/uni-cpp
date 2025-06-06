# Blockchain Financial System
## Course Project Report
### Object-Oriented Programming in C++

**Group Members:**
- Эсламния Мохаммад 
- Бай Борис
- Потеряев Родион

**Submission Date:** May 2025

---

## 1. Problem Statement

This project implements a simplified financial transaction system based on blockchain concepts. The system allows different types of clients to create wallets and perform transactions between them, with varying commission rates based on client types. The system maintains a record of all transactions in a blockchain structure and provides data persistence through file operations.

## 2. Initial Data of the Problem

The initial requirements for the system include:

1. Implementation of a class hierarchy with Entity as the base class
2. Creation of different client types with varying commission rates and transaction limits
3. Implementation of wallet management for clients
4. Processing of transactions between wallets
5. Use of Binary Search Tree for client organization
6. Use of Doubly Linked List for transaction records
7. Implementation of file operations for data persistence
8. Implementation of a basic blockchain structure

## 3. Definition of Terms

The following terms are used throughout this report:

- **Entity**: The abstract base class that provides a common interface for all system entities with unique identifiers.
- **Client**: An abstract class that inherits from Entity and represents a user of the financial system.
- **Wallet**: A class that inherits from Entity and stores funds for transactions.
- **Transaction**: A class that inherits from Entity and represents a transfer of funds between wallets.
- **Block**: A container for transactions that forms part of the blockchain.
- **Blockchain**: A chain of blocks linked by cryptographic hashes, forming a secure transaction ledger.
- **Binary Search Tree (BST)**: A data structure for organizing clients by total balance.
- **Doubly Linked List**: A data structure for maintaining an ordered list of transactions.
- **Commission**: A fee charged on transactions, varying by client type.
- **Transaction Limit**: The maximum amount that can be transferred in a single transaction.

## 4. System Architecture

### 4.1 Class Hierarchy

The system is designed around a clear class hierarchy with well-defined relationships:

- **Entity** (Abstract Base Class): Provides a common interface for all system entities with unique identifiers.
  - **Client** (Abstract Base Class): Inherits from Entity and defines common functionality for all client types.
    - **StandardClient**: Implements standard client with 5% commission and $1,000 limit.
    - **PlatinumClient**: Implements premium client with 2% commission and $5,000 limit.
    - **GoldClient**: Implements high-tier client with 1% commission and $10,000 limit.
  - **Wallet**: Inherits from Entity and stores funds for transactions.
  - **Transaction**: Inherits from Entity and represents a transfer between wallets.
- **Block**: Represents a block in the blockchain containing transaction records.

### 4.2 Relationship Types

The system implements the following relationship types:

1. **Inheritance**: Entity serves as the base class for Client, Wallet, and Transaction.
2. **Composition**: 
   - Blockchain owns ClientBST, TransactionList, and a vector of Blocks.
   - ClientBST owns ClientNode objects.
   - TransactionList owns TransactionNode objects.
3. **Aggregation**: Client owns Wallets via EntityVector.
4. **Association**: Clients interact with Blockchain for transactions and queries.

### 4.3 Data Structures

The system implements three custom data structures:

1. **Binary Search Tree (ClientBST)**: Orders clients by their total balance.
   - **ClientNode**: Node in the BST, containing a Client pointer and left/right child pointers.

2. **Doubly Linked List (TransactionList)**: Stores transaction records chronologically.
   - **TransactionNode**: Node in the list, containing a Transaction pointer and prev/next pointers.

3. **EntityVector**: Utility class that manages one-to-many relationships (e.g., Client to Wallets).

4. **Blockchain**: A vector of Block objects connected by cryptographic hashes.

## 5. Implementation Details

### 5.1 Entity Class

#### Methods:
1. **Constructor**
   - **Parameters**: `const std::string& id`
   - **Return Value**: None
   - **Purpose**: Initializes the entity with a unique identifier
   - **Implementation**: Assigns the provided ID to the class member variable

2. **getId** (pure virtual)
   - **Parameters**: None
   - **Return Value**: `std::string`
   - **Purpose**: Retrieves the entity's unique identifier
   - **Implementation**: Must be implemented by derived classes

```cpp
// Entity.h
class Entity {
protected:
    std::string id; // Unique identifier

public:
    Entity(const std::string& id);
    virtual ~Entity() = default;
    virtual std::string getId() const = 0; // Pure virtual method
};

// Entity.cpp
Entity::Entity(const std::string& id) : id(id) {}
```

### 5.2 Client Class

#### Methods:
1. **Constructor**
   - **Parameters**: `const std::string& id, const std::string& name`
   - **Return Value**: None
   - **Purpose**: Initializes a client with an ID and name
   - **Implementation**: Calls the Entity constructor and initializes name

2. **addWallet**
   - **Parameters**: `Wallet* wallet`
   - **Return Value**: None
   - **Purpose**: Adds a wallet to the client's collection
   - **Implementation**: Adds the wallet to the EntityVector

3. **getTotalBalance**
   - **Parameters**: None
   - **Return Value**: `double`
   - **Purpose**: Calculates the total balance across all wallets
   - **Implementation**: Iterates through all wallets and sums their balances

4. **calculateCommission** (pure virtual)
   - **Parameters**: `double amount`
   - **Return Value**: `double`
   - **Purpose**: Calculates the commission for a transaction
   - **Implementation**: Implemented by derived classes based on client type

5. **getMaxTransactionLimit** (pure virtual)
   - **Parameters**: None
   - **Return Value**: `double`
   - **Purpose**: Retrieves the maximum transaction amount allowed
   - **Implementation**: Implemented by derived classes based on client type

```cpp
// Client.h (partial)
class Client : public Entity {
protected:
    std::string name;
    EntityVector wallets;

public:
    Client(const std::string& id, const std::string& name);
    virtual ~Client() = default;
    
    void addWallet(Wallet* wallet);
    double getTotalBalance() const;
    std::string getName() const;
    std::string getId() const override;
    Wallet* getWallet(const std::string& walletId);
    std::vector<Entity*>& getWallets();
    
    virtual double calculateCommission(double amount) const = 0;
    virtual double getMaxTransactionLimit() const = 0;
};

// Client.cpp (partial)
double Client::getTotalBalance() const {
    double total = 0.0;
    for (Entity* entity : wallets.getAllEntities()) {
        Wallet* wallet = static_cast<Wallet*>(entity);
        total += wallet->getBalance();
    }
    return total;
}
```

### 5.3 Wallet Class

#### Methods:
1. **Constructor**
   - **Parameters**: `const std::string& id, const std::string& ownerId, double balance`
   - **Return Value**: None
   - **Purpose**: Initializes a wallet with an ID, owner ID, and initial balance
   - **Implementation**: Calls the Entity constructor and initializes ownerId and balance

2. **deposit**
   - **Parameters**: `double amount`
   - **Return Value**: `bool`
   - **Purpose**: Adds funds to the wallet
   - **Implementation**: Increases the balance by the specified amount if positive

3. **withdraw**
   - **Parameters**: `double amount`
   - **Return Value**: `bool`
   - **Purpose**: Removes funds from the wallet
   - **Implementation**: Decreases the balance if sufficient funds are available

```cpp
// Wallet.h (partial)
class Wallet : public Entity {
private:
    double balance;
    std::string ownerId;

public:
    Wallet(const std::string& id, const std::string& ownerId, double balance = 0.0);
    
    bool deposit(double amount);
    bool withdraw(double amount);
    double getBalance() const;
    std::string getOwnerId() const;
    std::string getId() const override;
};

// Wallet.cpp (partial)
bool Wallet::deposit(double amount) {
    if (amount <= 0) {
        return false;
    }
    balance += amount;
    return true;
}

bool Wallet::withdraw(double amount) {
    if (amount <= 0 || amount > balance) {
        return false;
    }
    balance -= amount;
    return true;
}
```

### 5.4 Transaction Class

#### Methods:
1. **Constructor**
   - **Parameters**: `const std::string& id, const std::string& senderWalletId, const std::string& recipientWalletId, double amount, TxType type, double commission`
   - **Return Value**: None
   - **Purpose**: Initializes a transaction record
   - **Implementation**: Calls the Entity constructor and initializes transaction details

2. **getDetails**
   - **Parameters**: None
   - **Return Value**: `std::string`
   - **Purpose**: Provides a formatted string of transaction details
   - **Implementation**: Concatenates transaction information into a readable format

```cpp
// Transaction.h (partial)
enum class TxType {
    TRANSFER
};

class Transaction : public Entity {
private:
    std::string senderWalletId;
    std::string recipientWalletId;
    double amount;
    TxType type;
    double commission;
    time_t timestamp;

public:
    Transaction(const std::string& id, const std::string& senderWalletId, 
                const std::string& recipientWalletId, double amount, 
                TxType type, double commission);
    
    std::string getId() const override;
    std::string getDetails() const;
    
    // Getters
    std::string getSenderWalletId() const;
    std::string getRecipientWalletId() const;
    double getAmount() const;
    TxType getType() const;
    double getCommission() const;
    time_t getTimestamp() const;
};
```

### 5.5 Block Class

#### Methods:
1. **Constructor**
   - **Parameters**: `const std::string& previousHash, const std::vector<std::shared_ptr<Transaction>>& transactions`
   - **Return Value**: None
   - **Purpose**: Initializes a block in the blockchain
   - **Implementation**: Stores the previous hash and transactions, calculates a new hash

2. **calculateHash**
   - **Parameters**: None
   - **Return Value**: `std::string`
   - **Purpose**: Generates a hash for the block based on its contents
   - **Implementation**: Creates a hash using the previous hash, timestamp, and transaction data

3. **validateHash**
   - **Parameters**: None
   - **Return Value**: `bool`
   - **Purpose**: Verifies the integrity of the block
   - **Implementation**: Recalculates the hash and compares it with the stored hash

```cpp
// Block.h (partial)
class Block {
private:
    std::string previousHash;
    std::string hash;
    time_t timestamp;
    std::vector<std::shared_ptr<Transaction>> transactions;
    int nonce;
    
    std::string calculateHash() const;

public:
    Block(const std::string& previousHash, const std::vector<std::shared_ptr<Transaction>>& transactions);
    
    std::string getPreviousHash() const;
    std::string getHash() const;
    time_t getTimestamp() const;
    std::vector<std::shared_ptr<Transaction>> getTransactions() const;
    bool validateHash() const;
};

// Block.cpp (partial)
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
```

### 5.6 Blockchain Class

#### Methods:
1. **Constructor**
   - **Parameters**: None
   - **Return Value**: None
   - **Purpose**: Initializes the blockchain with a genesis block
   - **Implementation**: Creates an empty ClientBST, TransactionList, and a genesis block

2. **processTransaction**
   - **Parameters**: `const std::string& senderWalletId, const std::string& recipientWalletId, double amount`
   - **Return Value**: `bool`
   - **Purpose**: Processes a financial transaction between wallets
   - **Implementation**: 
     1. Validates the transaction details
     2. Finds the sender and recipient wallets
     3. Calculates commission based on sender's client type
     4. Withdraws funds from sender and deposits to recipient
     5. Creates a transaction record
     6. Adds the transaction to a new block in the blockchain

3. **addBlock**
   - **Parameters**: `const std::vector<std::shared_ptr<Transaction>>& transactions`
   - **Return Value**: None
   - **Purpose**: Adds a new block to the blockchain
   - **Implementation**: Creates a new block with the latest block's hash as the previous hash

4. **validateChain**
   - **Parameters**: None
   - **Return Value**: `bool`
   - **Purpose**: Verifies the integrity of the blockchain
   - **Implementation**: Checks each block's hash and its reference to the previous block

```cpp
// Blockchain.cpp (partial)
bool Blockchain::processTransaction(const std::string& senderWalletId, const std::string& recipientWalletId, double amount) {
    // Validate input
    if (senderWalletId == recipientWalletId) {
        std::cout << "Transaction failed: Sender and recipient wallets cannot be the same." << std::endl;
        return false;
    }
    
    if (amount <= 0) {
        std::cout << "Transaction failed: Amount must be greater than zero." << std::endl;
        return false;
    }
    
    // Find the clients that own the wallets
    Client* senderClient = findClientByWalletId(senderWalletId);
    Client* recipientClient = findClientByWalletId(recipientWalletId);
    
    if (senderClient == nullptr || recipientClient == nullptr) {
        std::cout << "Transaction failed: Client not found for one or both wallets." << std::endl;
        return false;
    }
    
    // Get the wallets
    Wallet* senderWallet = senderClient->getWallet(senderWalletId);
    Wallet* recipientWallet = recipientClient->getWallet(recipientWalletId);
    
    if (senderWallet == nullptr || recipientWallet == nullptr) {
        std::cout << "Transaction failed: One or both wallets not found." << std::endl;
        return false;
    }
    
    // Check transaction limit
    double maxLimit = senderClient->getMaxTransactionLimit();
    if (amount > maxLimit) {
        std::cout << "Transaction failed: Amount exceeds transaction limit of $" << maxLimit << std::endl;
        return false;
    }
    
    // Calculate commission
    double commission = senderClient->calculateCommission(amount);
    double totalAmount = amount + commission;
    
    // Check if sender has sufficient funds
    if (senderWallet->getBalance() < totalAmount) {
        std::cout << "Transaction failed: Insufficient funds." << std::endl;
        return false;
    }
    
    // Generate unique transaction ID
    std::stringstream txIdStream;
    txIdStream << "TX" << std::setfill('0') << std::setw(10) << time(nullptr) << std::setw(4) << rand() % 10000;
    std::string txId = txIdStream.str();
    
    // Create transaction object
    Transaction* tx = new Transaction(txId, senderWalletId, recipientWalletId, amount, TxType::TRANSFER, commission);
    
    // Process the transaction
    if (senderWallet->withdraw(totalAmount) && recipientWallet->deposit(amount)) {
        transactions.addTransaction(tx);
        
        // Create a shared_ptr wrapper for the transaction to add to a block
        std::shared_ptr<Transaction> txPtr(tx, [](Transaction* p) { /* Empty deleter to avoid double deletion */ });
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
    } else {
        std::cout << "Transaction failed: Error processing funds." << std::endl;
        delete tx;
        return false;
    }
}
```

## 6. Testing the Solution

The solution was tested using the following approach:

### 6.1 Unit Testing

Individual components were tested for correct functionality:

1. **Client Class Testing**:
   - Creating different types of clients (Standard, Platinum, Gold)
   - Verifying commission calculation for each client type
   - Testing transaction limits for each client type

2. **Wallet Testing**:
   - Creating wallets with initial balances
   - Testing deposit functionality
   - Testing withdraw functionality with sufficient and insufficient funds

3. **Transaction Testing**:
   - Creating transactions between wallets
   - Verifying transaction details

4. **Blockchain Testing**:
   - Creating a blockchain with a genesis block
   - Adding transactions and blocks
   - Validating the blockchain integrity

### 6.2 Integration Testing

The integrated system was tested with the following scenarios:

1. **Client Creation and Wallet Management**:
   - Creating clients and adding wallets
   - Retrieving wallet information

2. **Transaction Processing**:
   - Processing valid transactions between wallets
   - Testing transaction validation (amount limits, sufficient funds)
   - Verifying commission calculations

3. **Data Persistence**:
   - Saving client and transaction data to files
   - Loading data from files
   - Verifying data integrity after load

### 6.3 Test Results

The system performed as expected in all test cases:

1. Different client types correctly applied their respective commission rates and transaction limits.
2. Wallets properly managed deposits and withdrawals with appropriate validation.
3. Transactions were successfully processed and recorded in the blockchain.
4. The blockchain maintained its integrity through the validation process.
5. Data was successfully saved to and loaded from files.

## 7. Conclusion

### 7.1 What Was Studied

Through this project, we studied:
- Object-oriented programming principles in C++
- Class hierarchies and inheritance
- Polymorphism through virtual functions
- Data structure implementation (BST, Doubly Linked List)
- File I/O operations in C++
- Basic blockchain concepts and implementation

### 7.2 What Was Mastered

We mastered the following skills:
- Implementing abstract classes and interfaces
- Creating and managing class relationships (inheritance, composition, aggregation)
- Using polymorphism for flexible system design
- Implementing custom data structures for specific requirements
- Managing memory in complex C++ applications
- Designing a robust financial transaction system

### 7.3 What Was Implemented

We successfully implemented:
- A complete class hierarchy with Entity as the base class
- Three types of clients with different commission rates and transaction limits
- A wallet system for storing and transferring funds
- A transaction system with proper validation
- A binary search tree for organizing clients by balance
- A doubly linked list for managing transaction records
- File I/O operations for data persistence
- A basic blockchain structure for secure transaction recording

## 8. References

1. C++ Documentation: [https://en.cppreference.com/](https://en.cppreference.com/)
2. Object-Oriented Programming Concepts: [https://www.tutorialspoint.com/object_oriented_programming/](https://www.tutorialspoint.com/object_oriented_programming/)
3. Data Structures and Algorithms: [https://www.geeksforgeeks.org/data-structures/](https://www.geeksforgeeks.org/data-structures/)
4. Blockchain Fundamentals: [https://developer.ibm.com/technologies/blockchain/tutorials/](https://developer.ibm.com/technologies/blockchain/tutorials/) 