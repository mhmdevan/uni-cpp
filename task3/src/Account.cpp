#include "../include/Account.h"
#include <cstring>
#include <iostream>
#include <iomanip>

// Account class implementation

// Constructors and destructor
Account::Account() : taxRate(0.0), balance(0.0) {
    strcpy(id, "");
    strcpy(name, "");
}

Account::Account(const char* id, const char* name, double taxRate, double balance) 
    : taxRate(taxRate), balance(balance) {
    // Set ID (max 5 characters)
    strncpy(this->id, id, 5);
    this->id[5] = '\0';
    
    // Set name (max 50 characters)
    strncpy(this->name, name, 50);
    this->name[50] = '\0';
}

Account::Account(const Account& other) : taxRate(other.taxRate), balance(other.balance) {
    strcpy(id, other.id);
    strcpy(name, other.name);
}

Account::~Account() {
    // Nothing to clean up (no dynamic memory)
}

// Getters
const char* Account::getId() const {
    return id;
}

const char* Account::getName() const {
    return name;
}

double Account::getTaxRate() const {
    return taxRate;
}

double Account::getBalance() const {
    return balance;
}

// Setters
void Account::setId(const char* id) {
    strncpy(this->id, id, 5);
    this->id[5] = '\0';
}

void Account::setName(const char* name) {
    strncpy(this->name, name, 50);
    this->name[50] = '\0';
}

void Account::setTaxRate(double taxRate) {
    this->taxRate = taxRate;
}

void Account::setBalance(double balance) {
    this->balance = balance;
}

// Virtual methods
void Account::print() const {
    std::cout << "Account Information:" << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Tax Rate: " << std::fixed << std::setprecision(2) << taxRate << "%" << std::endl;
    std::cout << "Balance: $" << std::fixed << std::setprecision(2) << balance << std::endl;
}

double Account::netAmount() const {
    // Calculate net amount after tax deduction
    double taxAmount = balance * (taxRate / 100.0);
    return balance - taxAmount;
}

// SavingsAccount class implementation

// Constructors and destructor
SavingsAccount::SavingsAccount() : Account(), serviceFee(0.0) {}

SavingsAccount::SavingsAccount(const char* id, const char* name, double taxRate, double balance, double serviceFee)
    : Account(id, name, taxRate, balance), serviceFee(serviceFee) {}

SavingsAccount::SavingsAccount(const SavingsAccount& other)
    : Account(other), serviceFee(other.serviceFee) {}

SavingsAccount::~SavingsAccount() {
    // Nothing to clean up (no dynamic memory)
}

// Getters and setters
double SavingsAccount::getServiceFee() const {
    return serviceFee;
}

void SavingsAccount::setServiceFee(double serviceFee) {
    this->serviceFee = serviceFee;
}

// Overridden virtual methods
void SavingsAccount::print() const {
    std::cout << "Savings Account Information:" << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Tax Rate: " << std::fixed << std::setprecision(2) << taxRate << "%" << std::endl;
    std::cout << "Balance: $" << std::fixed << std::setprecision(2) << balance << std::endl;
    std::cout << "Service Fee: $" << std::fixed << std::setprecision(2) << serviceFee << std::endl;
    std::cout << "Net Amount: $" << std::fixed << std::setprecision(2) << netAmount() << std::endl;
}

double SavingsAccount::netAmount() const {
    // Calculate net amount after tax deduction and service fee
    double baseNetAmount = Account::netAmount();
    return baseNetAmount - serviceFee;
}

// BusinessAccount class implementation

// Constructors and destructor
BusinessAccount::BusinessAccount() : Account(), dividendRate(0.0) {}

BusinessAccount::BusinessAccount(const char* id, const char* name, double taxRate, double balance, double dividendRate)
    : Account(id, name, taxRate, balance), dividendRate(dividendRate) {}

BusinessAccount::BusinessAccount(const BusinessAccount& other)
    : Account(other), dividendRate(other.dividendRate) {}

BusinessAccount::~BusinessAccount() {
    // Nothing to clean up (no dynamic memory)
}

// Getters and setters
double BusinessAccount::getDividendRate() const {
    return dividendRate;
}

void BusinessAccount::setDividendRate(double dividendRate) {
    this->dividendRate = dividendRate;
}

// Overridden virtual methods
void BusinessAccount::print() const {
    std::cout << "Business Account Information:" << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Tax Rate: " << std::fixed << std::setprecision(2) << taxRate << "%" << std::endl;
    std::cout << "Balance: $" << std::fixed << std::setprecision(2) << balance << std::endl;
    std::cout << "Dividend Rate: " << std::fixed << std::setprecision(2) << dividendRate << "%" << std::endl;
    std::cout << "Net Amount: $" << std::fixed << std::setprecision(2) << netAmount() << std::endl;
}

double BusinessAccount::netAmount() const {
    // Calculate net amount after tax deduction and add dividends
    double baseNetAmount = Account::netAmount();
    double dividendAmount = baseNetAmount * (dividendRate / 100.0);
    return baseNetAmount + dividendAmount;
} 