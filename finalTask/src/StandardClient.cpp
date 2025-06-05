#include "../include/StandardClient.h"

StandardClient::StandardClient(const std::string& id, const std::string& name)
    : Client(id, name) {
    // Constructor implementation
}

double StandardClient::calculateCommission(double amount) const {
    // Standard clients pay 5% commission
    return amount * 0.05;
}

double StandardClient::getMaxTransactionLimit() const {
    // Standard clients have a lower transaction limit
    return 1000.0;
}

std::string StandardClient::getBenefits() const {
    return "Standard access";
} 