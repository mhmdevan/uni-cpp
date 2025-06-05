#include "../include/GoldClient.h"

GoldClient::GoldClient(const std::string& id, const std::string& name)
    : Client(id, name) {
    // Constructor implementation
}

double GoldClient::calculateCommission(double amount) const {
    // Gold clients pay 1% commission
    return amount * 0.01;
}

double GoldClient::getMaxTransactionLimit() const {
    // Gold clients have a high transaction limit
    return 10000.0;
}

std::string GoldClient::getBenefits() const {
    return "Priority processing, low fees";
} 