#include "../include/Account.h"
#include <iostream>
#include <vector>
#include <memory>

int main() {
    std::cout << "===== Bank Account Hierarchy Test =====\n\n";
    
    // Create accounts using different constructors
    Account baseAccount("A1234", "John Doe", 15.0, 5000.0);
    SavingsAccount savingsAccount("S5678", "Jane Smith", 10.0, 3000.0, 25.0);
    BusinessAccount businessAccount("B9012", "Acme Corp", 20.0, 10000.0, 8.0);
    
    // Print account information
    std::cout << "----- Base Account -----\n";
    baseAccount.print();
    std::cout << "Net Amount: $" << std::fixed << std::setprecision(2) << baseAccount.netAmount() << "\n\n";
    
    std::cout << "----- Savings Account -----\n";
    savingsAccount.print();
    std::cout << "\n";
    
    std::cout << "----- Business Account -----\n";
    businessAccount.print();
    std::cout << "\n";
    
    // Demonstrate polymorphism using a vector of pointers to base class
    std::cout << "----- Polymorphism Demonstration -----\n";
    
    std::vector<std::unique_ptr<Account>> accounts;
    accounts.push_back(std::make_unique<Account>("A2468", "Alex Johnson", 18.0, 4000.0));
    accounts.push_back(std::make_unique<SavingsAccount>("S1357", "Emily Brown", 12.0, 2500.0, 15.0));
    accounts.push_back(std::make_unique<BusinessAccount>("B3579", "Tech Solutions", 22.0, 15000.0, 10.0));
    
    for (size_t i = 0; i < accounts.size(); ++i) {
        std::cout << "Account " << i+1 << ":\n";
        accounts[i]->print();
        std::cout << "\n";
    }
    
    // Calculations and comparisons
    std::cout << "----- Net Amount Calculations -----\n";
    
    double savingsNet = savingsAccount.netAmount();
    double businessNet = businessAccount.netAmount();
    
    std::cout << "Savings Account Net: $" << std::fixed << std::setprecision(2) << savingsNet << "\n";
    std::cout << "Business Account Net: $" << std::fixed << std::setprecision(2) << businessNet << "\n";
    
    if (savingsNet > businessNet) {
        std::cout << "The Savings Account has a higher net amount.\n";
    } else if (businessNet > savingsNet) {
        std::cout << "The Business Account has a higher net amount.\n";
    } else {
        std::cout << "Both accounts have the same net amount.\n";
    }
    
    return 0;
} 