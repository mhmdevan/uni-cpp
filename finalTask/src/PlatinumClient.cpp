#include "../include/PlatinumClient.h"

PlatinumClient::PlatinumClient(const std::string& id, const std::string& name)
    : Client(id, name) {
    // Constructor implementation
}

double PlatinumClient::calculateCommission(double amount) const {
    // Platinum clients pay 2% commission
    return amount * 0.02;
}

double PlatinumClient::getMaxTransactionLimit() const {
    // Platinum clients have a moderate transaction limit
    return 5000.0;
}

std::string PlatinumClient::getBenefits() const {
    return "Bonus rewards, moderate fees";
} 