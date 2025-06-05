#ifndef GOLD_CLIENT_H
#define GOLD_CLIENT_H

#include "Client.h"
#include <string>

/**
 * @class GoldClient
 * @brief Represents premium clients with low commissions
 */
class GoldClient : public Client {
public:
    /**
     * @brief Constructor
     * @param id Client ID
     * @param name Client name
     */
    GoldClient(const std::string& id, const std::string& name);
    
    /**
     * @brief Calculate commission for a transaction (1%)
     * @param amount Transaction amount
     * @return Commission amount
     */
    double calculateCommission(double amount) const override;
    
    /**
     * @brief Get the maximum transaction limit (10000)
     * @return Maximum transaction amount allowed
     */
    double getMaxTransactionLimit() const override;
    
    /**
     * @brief Get the benefits description for Gold clients
     * @return String describing benefits
     */
    std::string getBenefits() const;
};

#endif // GOLD_CLIENT_H 