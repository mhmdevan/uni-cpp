#include "../include/Wallet.h"

Wallet::Wallet(const std::string& id, const std::string& ownerId, double balance)
    : Entity(id), balance(balance), ownerId(ownerId) {
    // Ensure balance is never negative on initialization
    if (this->balance < 0.0) {
        this->balance = 0.0;
    }
}

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

double Wallet::getBalance() const {
    return balance;
}

std::string Wallet::getOwnerId() const {
    return ownerId;
}

std::string Wallet::getId() const {
    return id;
} 