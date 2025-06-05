#ifndef PLATINUM_CLIENT_H
#define PLATINUM_CLIENT_H

#include "Client.h"
#include <string>

/**
 * @class PlatinumClient
 * @brief Represents mid-tier clients with moderate commissions
 */
class PlatinumClient : public Client {
public:
    /**
     * @brief Constructor
     * @param id Client ID
     * @param name Client name
     */
    PlatinumClient(const std::string& id, const std::string& name);
    
    /**
     * @brief Calculate commission for a transaction (2%)
     * @param amount Transaction amount
     * @return Commission amount
     */
    double calculateCommission(double amount) const override;
    
    /**
     * @brief Get the maximum transaction limit (5000)
     * @return Maximum transaction amount allowed
     */
    double getMaxTransactionLimit() const override;
    
    /**
     * @brief Get the benefits description for Platinum clients
     * @return String describing benefits
     */
    std::string getBenefits() const;
};

#endif // PLATINUM_CLIENT_H 