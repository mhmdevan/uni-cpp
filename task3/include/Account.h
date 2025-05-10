#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <iomanip>

class Account {
protected:
    char id[6];           // id: 5 characters max + null terminator
    char name[51];        // name: 50 characters max + null terminator
    double taxRate;       // tax rate as percentage
    double balance;       // monthly income in dollars

public:
    // Constructors and destructor
    Account();
    Account(const char* id, const char* name, double taxRate, double balance);
    Account(const Account& other);
    virtual ~Account();

    // Getters
    const char* getId() const;
    const char* getName() const;
    double getTaxRate() const;
    double getBalance() const;

    // Setters
    void setId(const char* id);
    void setName(const char* name);
    void setTaxRate(double taxRate);
    void setBalance(double balance);

    // Virtual methods
    virtual void print() const;
    virtual double netAmount() const;
};

class SavingsAccount : public Account {
private:
    double serviceFee;    // fixed dollar cost for card maintenance

public:
    // Constructors and destructor
    SavingsAccount();
    SavingsAccount(const char* id, const char* name, double taxRate, double balance, double serviceFee);
    SavingsAccount(const SavingsAccount& other);
    ~SavingsAccount();

    // Getters and setters
    double getServiceFee() const;
    void setServiceFee(double serviceFee);

    // Overridden virtual methods
    virtual void print() const override;
    virtual double netAmount() const override;
};

class BusinessAccount : public Account {
private:
    double dividendRate;  // percentage of card yield (from net value after taxes)

public:
    // Constructors and destructor
    BusinessAccount();
    BusinessAccount(const char* id, const char* name, double taxRate, double balance, double dividendRate);
    BusinessAccount(const BusinessAccount& other);
    ~BusinessAccount();

    // Getters and setters
    double getDividendRate() const;
    void setDividendRate(double dividendRate);

    // Overridden virtual methods
    virtual void print() const override;
    virtual double netAmount() const override;
};

#endif // ACCOUNT_H 