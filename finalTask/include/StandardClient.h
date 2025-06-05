#ifndef STANDARD_CLIENT_H
#define STANDARD_CLIENT_H

#include "Client.h"
#include <string>

/**
 * @class StandardClient
 * @brief Represents standard clients with higher commissions
 */
class StandardClient : public Client {
public:
    /**
     * @brief Constructor
     * @param id Client ID
     * @param name Client name
     */
    StandardClient(const std::string& id, const std::string& name);
    
    /**
     * @brief Calculate commission for a transaction (5%)
     * @param amount Transaction amount
     * @return Commission amount
     */
    double calculateCommission(double amount) const override;
    
    /**
     * @brief Get the maximum transaction limit (1000)
     * @return Maximum transaction amount allowed
     */
    double getMaxTransactionLimit() const override;
    
    /**
     * @brief Get the benefits description for Standard clients
     * @return String describing benefits
     */
    std::string getBenefits() const;
};

#endif // STANDARD_CLIENT_H 