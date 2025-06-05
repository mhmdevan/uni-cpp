# Blockchain Financial System

## Overview
This project implements a simplified blockchain financial transaction system where clients can create wallets and perform transactions. The system supports different types of clients with varying commission rates and transaction limits.

## Features
- Three types of clients: Standard, Platinum, and Gold
- Wallet management for clients
- Transaction processing between wallets
- Binary Search Tree for client management
- Doubly Linked List for transaction management
- File I/O for persisting data

## Class Hierarchy
- **Entity** (Abstract base class)
  - **Client** (Abstract base class)
    - **StandardClient**
    - **PlatinumClient**
    - **GoldClient**
  - **Wallet**
  - **Transaction**

## Data Structures
- **EntityVector**: Manages one-to-many relationships
- **ClientNode** and **ClientBST**: Implements a binary search tree for clients
- **TransactionNode** and **TransactionList**: Implements a doubly linked list for transactions

## Relationships
1. **Inheritance**:
   - Entity ← Client, Wallet, Transaction
   - Client ← GoldClient, PlatinumClient, StandardClient

2. **Composition**:
   - Blockchain → ClientBST
   - Blockchain → TransactionList
   - ClientBST → ClientNode
   - TransactionList → TransactionNode

3. **Aggregation**:
   - Client → Wallet (via EntityVector)

## Directory Structure
```
finalTask/
├── build/           # Compiled files
├── include/         # Header files
│   ├── Entity.h
│   ├── Client.h
│   ├── ...
├── src/             # Source files
│   ├── Entity.cpp
│   ├── Client.cpp
│   ├── ...
├── data/            # Data files
│   ├── Clients.txt
│   ├── Blockchain_transactions.txt
├── Makefile         # Build file
└── README.md        # This file
```

## Building and Running
1. Build the project:
   ```
   make
   ```

2. Run the application:
   ```
   make run
   ```

3. Clean build files:
   ```
   make clean
   ```

## Usage
The program provides a menu-based interface for:
1. Creating clients
2. Creating wallets
3. Processing transactions
4. Displaying client information
5. Displaying transaction history
6. Saving data to files
7. Loading data from files

## Client Types and Features
1. **Standard Client**:
   - 5% commission on transactions
   - $1,000 maximum transaction limit

2. **Platinum Client**:
   - 2% commission on transactions
   - $5,000 maximum transaction limit

3. **Gold Client**:
   - 1% commission on transactions
   - $10,000 maximum transaction limit 