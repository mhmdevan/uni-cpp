#include "../include/Client.h"

Client::Client(const std::string& id, const std::string& name)
    : Entity(id), name(name) {
    // Constructor implementation
}

void Client::addWallet(Wallet* wallet) {
    if (wallet != nullptr && wallet->getOwnerId() == id) {
        wallets.addEntity(wallet);
    }
}

double Client::getTotalBalance() const {
    double total = 0.0;
    
    // Get all wallets and sum their balances
    auto& allWallets = const_cast<EntityVector&>(wallets).getAllEntities();
    for (auto entity : allWallets) {
        Wallet* wallet = dynamic_cast<Wallet*>(entity);
        if (wallet != nullptr) {
            total += wallet->getBalance();
        }
    }
    
    return total;
}

std::string Client::getName() const {
    return name;
}

std::string Client::getId() const {
    return id;
}

Wallet* Client::getWallet(const std::string& walletId) {
    Entity* entity = wallets.getEntity(walletId);
    return dynamic_cast<Wallet*>(entity);
}

std::vector<Entity*>& Client::getWallets() {
    return wallets.getAllEntities();
} 