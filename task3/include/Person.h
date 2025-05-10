#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

// Base class for all persons
class Person {
protected:
    std::string name;
    std::string address;
    std::string phone;

public:
    // Constructors and destructor
    Person();
    Person(const std::string& name, const std::string& address, const std::string& phone);
    Person(const Person& other);
    virtual ~Person();

    // Getters
    std::string getName() const;
    std::string getAddress() const;
    std::string getPhone() const;

    // Setters
    void setName(const std::string& name);
    void setAddress(const std::string& address);
    void setPhone(const std::string& phone);

    // Virtual methods
    virtual void print() const;
};

// Natural Person (derived from Person)
class NaturalPerson : public Person {
protected:
    std::string passport;
    int age;

public:
    // Constructors and destructor
    NaturalPerson();
    NaturalPerson(const std::string& name, const std::string& address, const std::string& phone,
                 const std::string& passport, int age);
    NaturalPerson(const NaturalPerson& other);
    virtual ~NaturalPerson();

    // Getters
    std::string getPassport() const;
    int getAge() const;

    // Setters
    void setPassport(const std::string& passport);
    void setAge(int age);

    // Virtual methods
    virtual void print() const override;
};

// Employer (derived from NaturalPerson)
class Employer : public NaturalPerson {
private:
    std::string company;
    double salary;

public:
    // Constructors and destructor
    Employer();
    Employer(const std::string& name, const std::string& address, const std::string& phone,
            const std::string& passport, int age, const std::string& company, double salary);
    Employer(const Employer& other);
    ~Employer();

    // Getters
    std::string getCompany() const;
    double getSalary() const;

    // Setters
    void setCompany(const std::string& company);
    void setSalary(double salary);

    // Virtual methods
    virtual void print() const override;
};

// Supervisor (derived from NaturalPerson)
class Supervisor : public NaturalPerson {
private:
    std::string department;
    std::string position;
    int teamSize;

public:
    // Constructors and destructor
    Supervisor();
    Supervisor(const std::string& name, const std::string& address, const std::string& phone,
              const std::string& passport, int age, const std::string& department,
              const std::string& position, int teamSize);
    Supervisor(const Supervisor& other);
    ~Supervisor();

    // Getters
    std::string getDepartment() const;
    std::string getPosition() const;
    int getTeamSize() const;

    // Setters
    void setDepartment(const std::string& department);
    void setPosition(const std::string& position);
    void setTeamSize(int teamSize);

    // Virtual methods
    virtual void print() const override;
};

// Legal Person (derived from Person)
class LegalPerson : public Person {
protected:
    std::string legalCode;
    double tax;
    int foundationYear;

public:
    // Constructors and destructor
    LegalPerson();
    LegalPerson(const std::string& name, const std::string& address, const std::string& phone,
               const std::string& legalCode, double tax, int foundationYear);
    LegalPerson(const LegalPerson& other);
    virtual ~LegalPerson();

    // Getters
    std::string getLegalCode() const;
    double getTax() const;
    int getFoundationYear() const;

    // Setters
    void setLegalCode(const std::string& legalCode);
    void setTax(double tax);
    void setFoundationYear(int foundationYear);

    // Virtual methods
    virtual void print() const override;
    virtual double calculateProfit() const;
};

// Limited Company (derived from LegalPerson)
class Ltda : public LegalPerson {
private:
    std::vector<std::string> partners;
    double capitalization;

public:
    // Constructors and destructor
    Ltda();
    Ltda(const std::string& name, const std::string& address, const std::string& phone,
        const std::string& legalCode, double tax, int foundationYear,
        const std::vector<std::string>& partners, double capitalization);
    Ltda(const Ltda& other);
    ~Ltda();

    // Getters
    const std::vector<std::string>& getPartners() const;
    double getCapitalization() const;

    // Setters
    void setPartners(const std::vector<std::string>& partners);
    void addPartner(const std::string& partner);
    void setCapitalization(double capitalization);

    // Virtual methods
    virtual void print() const override;
    virtual double calculateProfit() const override;
};

// Public Limited Company (derived from LegalPerson)
class SA : public LegalPerson {
protected:
    std::vector<std::string> stakeholders;
    int shareholderCount;
    double stockPrice;

public:
    // Constructors and destructor
    SA();
    SA(const std::string& name, const std::string& address, const std::string& phone,
       const std::string& legalCode, double tax, int foundationYear,
       const std::vector<std::string>& stakeholders, int shareholderCount, double stockPrice);
    SA(const SA& other);
    virtual ~SA();

    // Getters
    const std::vector<std::string>& getStakeholders() const;
    int getShareholderCount() const;
    double getStockPrice() const;

    // Setters
    void setStakeholders(const std::vector<std::string>& stakeholders);
    void addStakeholder(const std::string& stakeholder);
    void setShareholderCount(int shareholderCount);
    void setStockPrice(double stockPrice);

    // Virtual methods
    virtual void print() const override;
    virtual double calculateProfit() const override;
};

// Government Entity (derived from Person)
class GovernmentEntity : public Person {
protected:
    std::string code;
    std::string description;
    double annualBudget;

public:
    // Constructors and destructor
    GovernmentEntity();
    GovernmentEntity(const std::string& name, const std::string& address, const std::string& phone,
                    const std::string& code, const std::string& description, double annualBudget);
    GovernmentEntity(const GovernmentEntity& other);
    virtual ~GovernmentEntity();

    // Getters
    std::string getCode() const;
    std::string getDescription() const;
    double getAnnualBudget() const;

    // Setters
    void setCode(const std::string& code);
    void setDescription(const std::string& description);
    void setAnnualBudget(double annualBudget);

    // Virtual methods
    virtual void print() const override;
    virtual double calculateProfit() const;
};

// Public Company (derived from SA and GovernmentEntity - multiple inheritance)
class PublicCompany : public SA, public GovernmentEntity {
private:
    std::string serviceName;

public:
    // Constructors and destructor
    PublicCompany();
    PublicCompany(const std::string& name, const std::string& address, const std::string& phone,
                 const std::string& legalCode, double tax, int foundationYear,
                 const std::vector<std::string>& stakeholders, int shareholderCount, double stockPrice,
                 const std::string& code, const std::string& description, double annualBudget,
                 const std::string& serviceName);
    PublicCompany(const PublicCompany& other);
    ~PublicCompany();

    // Getters
    std::string getServiceName() const;

    // Setters
    void setServiceName(const std::string& serviceName);

    // Virtual methods
    virtual void print() const override;
    virtual double calculateProfit() const override;
};

#endif // PERSON_H 