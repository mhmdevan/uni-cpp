#include "../include/Person.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

// Person class implementation

// Constructors and destructor
Person::Person() : name(""), address(""), phone("") {}

Person::Person(const std::string& name, const std::string& address, const std::string& phone)
    : name(name), address(address), phone(phone) {}

Person::Person(const Person& other)
    : name(other.name), address(other.address), phone(other.phone) {}

Person::~Person() {}

// Getters
std::string Person::getName() const {
    return name;
}

std::string Person::getAddress() const {
    return address;
}

std::string Person::getPhone() const {
    return phone;
}

// Setters
void Person::setName(const std::string& name) {
    this->name = name;
}

void Person::setAddress(const std::string& address) {
    this->address = address;
}

void Person::setPhone(const std::string& phone) {
    this->phone = phone;
}

// Virtual methods
void Person::print() const {
    std::cout << "Person Information:\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Address: " << address << "\n";
    std::cout << "Phone: " << phone << "\n";
}

// NaturalPerson class implementation

// Constructors and destructor
NaturalPerson::NaturalPerson() : Person(), passport(""), age(0) {}

NaturalPerson::NaturalPerson(const std::string& name, const std::string& address, const std::string& phone,
                           const std::string& passport, int age)
    : Person(name, address, phone), passport(passport), age(age) {}

NaturalPerson::NaturalPerson(const NaturalPerson& other)
    : Person(other), passport(other.passport), age(other.age) {}

NaturalPerson::~NaturalPerson() {}

// Getters
std::string NaturalPerson::getPassport() const {
    return passport;
}

int NaturalPerson::getAge() const {
    return age;
}

// Setters
void NaturalPerson::setPassport(const std::string& passport) {
    this->passport = passport;
}

void NaturalPerson::setAge(int age) {
    this->age = age;
}

// Virtual methods
void NaturalPerson::print() const {
    Person::print();
    std::cout << "Passport: " << passport << "\n";
    std::cout << "Age: " << age << "\n";
}

// Employer class implementation

// Constructors and destructor
Employer::Employer() : NaturalPerson(), company(""), salary(0.0) {}

Employer::Employer(const std::string& name, const std::string& address, const std::string& phone,
                 const std::string& passport, int age, const std::string& company, double salary)
    : NaturalPerson(name, address, phone, passport, age), company(company), salary(salary) {}

Employer::Employer(const Employer& other)
    : NaturalPerson(other), company(other.company), salary(other.salary) {}

Employer::~Employer() {}

// Getters
std::string Employer::getCompany() const {
    return company;
}

double Employer::getSalary() const {
    return salary;
}

// Setters
void Employer::setCompany(const std::string& company) {
    this->company = company;
}

void Employer::setSalary(double salary) {
    this->salary = salary;
}

// Virtual methods
void Employer::print() const {
    NaturalPerson::print();
    std::cout << "Company: " << company << "\n";
    std::cout << "Salary: $" << std::fixed << std::setprecision(2) << salary << "\n";
}

// Supervisor class implementation

// Constructors and destructor
Supervisor::Supervisor() : NaturalPerson(), department(""), position(""), teamSize(0) {}

Supervisor::Supervisor(const std::string& name, const std::string& address, const std::string& phone,
                     const std::string& passport, int age, const std::string& department,
                     const std::string& position, int teamSize)
    : NaturalPerson(name, address, phone, passport, age),
      department(department), position(position), teamSize(teamSize) {}

Supervisor::Supervisor(const Supervisor& other)
    : NaturalPerson(other), department(other.department),
      position(other.position), teamSize(other.teamSize) {}

Supervisor::~Supervisor() {}

// Getters
std::string Supervisor::getDepartment() const {
    return department;
}

std::string Supervisor::getPosition() const {
    return position;
}

int Supervisor::getTeamSize() const {
    return teamSize;
}

// Setters
void Supervisor::setDepartment(const std::string& department) {
    this->department = department;
}

void Supervisor::setPosition(const std::string& position) {
    this->position = position;
}

void Supervisor::setTeamSize(int teamSize) {
    this->teamSize = teamSize;
}

// Virtual methods
void Supervisor::print() const {
    NaturalPerson::print();
    std::cout << "Department: " << department << "\n";
    std::cout << "Position: " << position << "\n";
    std::cout << "Team Size: " << teamSize << "\n";
}

// LegalPerson class implementation

// Constructors and destructor
LegalPerson::LegalPerson() : Person(), legalCode(""), tax(0.0), foundationYear(0) {}

LegalPerson::LegalPerson(const std::string& name, const std::string& address, const std::string& phone,
                       const std::string& legalCode, double tax, int foundationYear)
    : Person(name, address, phone), legalCode(legalCode), tax(tax), foundationYear(foundationYear) {}

LegalPerson::LegalPerson(const LegalPerson& other)
    : Person(other), legalCode(other.legalCode), tax(other.tax), foundationYear(other.foundationYear) {}

LegalPerson::~LegalPerson() {}

// Getters
std::string LegalPerson::getLegalCode() const {
    return legalCode;
}

double LegalPerson::getTax() const {
    return tax;
}

int LegalPerson::getFoundationYear() const {
    return foundationYear;
}

// Setters
void LegalPerson::setLegalCode(const std::string& legalCode) {
    this->legalCode = legalCode;
}

void LegalPerson::setTax(double tax) {
    this->tax = tax;
}

void LegalPerson::setFoundationYear(int foundationYear) {
    this->foundationYear = foundationYear;
}

// Virtual methods
void LegalPerson::print() const {
    Person::print();
    std::cout << "Legal Code: " << legalCode << "\n";
    std::cout << "Tax: " << std::fixed << std::setprecision(2) << tax << "%\n";
    std::cout << "Foundation Year: " << foundationYear << "\n";
}

double LegalPerson::calculateProfit() const {
    // Base implementation - will be overridden by derived classes
    return 0.0;
}

// Ltda class implementation

// Constructors and destructor
Ltda::Ltda() : LegalPerson(), capitalization(0.0) {}

Ltda::Ltda(const std::string& name, const std::string& address, const std::string& phone,
         const std::string& legalCode, double tax, int foundationYear,
         const std::vector<std::string>& partners, double capitalization)
    : LegalPerson(name, address, phone, legalCode, tax, foundationYear),
      partners(partners), capitalization(capitalization) {}

Ltda::Ltda(const Ltda& other)
    : LegalPerson(other), partners(other.partners), capitalization(other.capitalization) {}

Ltda::~Ltda() {}

// Getters
const std::vector<std::string>& Ltda::getPartners() const {
    return partners;
}

double Ltda::getCapitalization() const {
    return capitalization;
}

// Setters
void Ltda::setPartners(const std::vector<std::string>& partners) {
    this->partners = partners;
}

void Ltda::addPartner(const std::string& partner) {
    partners.push_back(partner);
}

void Ltda::setCapitalization(double capitalization) {
    this->capitalization = capitalization;
}

// Virtual methods
void Ltda::print() const {
    LegalPerson::print();
    std::cout << "Capitalization: $" << std::fixed << std::setprecision(2) << capitalization << "\n";
    std::cout << "Partners (" << partners.size() << "):\n";
    for (size_t i = 0; i < partners.size(); ++i) {
        std::cout << "  " << (i+1) << ". " << partners[i] << "\n";
    }
}

double Ltda::calculateProfit() const {
    // Profit calculation for Ltda based on capitalization
    double grossProfit = capitalization * 0.2;  // Assume 20% return on capital
    double taxAmount = grossProfit * (tax / 100.0);
    return grossProfit - taxAmount;
}

// SA class implementation

// Constructors and destructor
SA::SA() : LegalPerson(), shareholderCount(0), stockPrice(0.0) {}

SA::SA(const std::string& name, const std::string& address, const std::string& phone,
     const std::string& legalCode, double tax, int foundationYear,
     const std::vector<std::string>& stakeholders, int shareholderCount, double stockPrice)
    : LegalPerson(name, address, phone, legalCode, tax, foundationYear),
      stakeholders(stakeholders), shareholderCount(shareholderCount), stockPrice(stockPrice) {}

SA::SA(const SA& other)
    : LegalPerson(other), stakeholders(other.stakeholders),
      shareholderCount(other.shareholderCount), stockPrice(other.stockPrice) {}

SA::~SA() {}

// Getters
const std::vector<std::string>& SA::getStakeholders() const {
    return stakeholders;
}

int SA::getShareholderCount() const {
    return shareholderCount;
}

double SA::getStockPrice() const {
    return stockPrice;
}

// Setters
void SA::setStakeholders(const std::vector<std::string>& stakeholders) {
    this->stakeholders = stakeholders;
}

void SA::addStakeholder(const std::string& stakeholder) {
    stakeholders.push_back(stakeholder);
}

void SA::setShareholderCount(int shareholderCount) {
    this->shareholderCount = shareholderCount;
}

void SA::setStockPrice(double stockPrice) {
    this->stockPrice = stockPrice;
}

// Virtual methods
void SA::print() const {
    LegalPerson::print();
    std::cout << "Stock Price: $" << std::fixed << std::setprecision(2) << stockPrice << "\n";
    std::cout << "Shareholder Count: " << shareholderCount << "\n";
    std::cout << "Stakeholders (" << stakeholders.size() << "):\n";
    for (size_t i = 0; i < stakeholders.size(); ++i) {
        std::cout << "  " << (i+1) << ". " << stakeholders[i] << "\n";
    }
}

double SA::calculateProfit() const {
    // Profit calculation for SA based on stock price and shareholder count
    double marketCap = stockPrice * shareholderCount * 1000; // Assume 1000 shares per shareholder
    double grossProfit = marketCap * 0.05;  // Assume 5% profit margin
    double taxAmount = grossProfit * (tax / 100.0);
    return grossProfit - taxAmount;
}

// GovernmentEntity class implementation

// Constructors and destructor
GovernmentEntity::GovernmentEntity() : Person(), code(""), description(""), annualBudget(0.0) {}

GovernmentEntity::GovernmentEntity(const std::string& name, const std::string& address, const std::string& phone,
                                 const std::string& code, const std::string& description, double annualBudget)
    : Person(name, address, phone), code(code), description(description), annualBudget(annualBudget) {}

GovernmentEntity::GovernmentEntity(const GovernmentEntity& other)
    : Person(other), code(other.code), description(other.description), annualBudget(other.annualBudget) {}

GovernmentEntity::~GovernmentEntity() {}

// Getters
std::string GovernmentEntity::getCode() const {
    return code;
}

std::string GovernmentEntity::getDescription() const {
    return description;
}

double GovernmentEntity::getAnnualBudget() const {
    return annualBudget;
}

// Setters
void GovernmentEntity::setCode(const std::string& code) {
    this->code = code;
}

void GovernmentEntity::setDescription(const std::string& description) {
    this->description = description;
}

void GovernmentEntity::setAnnualBudget(double annualBudget) {
    this->annualBudget = annualBudget;
}

// Virtual methods
void GovernmentEntity::print() const {
    Person::print();
    std::cout << "Code: " << code << "\n";
    std::cout << "Description: " << description << "\n";
    std::cout << "Annual Budget: $" << std::fixed << std::setprecision(2) << annualBudget << "\n";
}

double GovernmentEntity::calculateProfit() const {
    // Government entities typically don't generate profit, but we can define a surplus
    return annualBudget * 0.01;  // Assume 1% surplus
}

// PublicCompany class implementation (multiple inheritance)

// Constructors and destructor
PublicCompany::PublicCompany() 
    : SA(), GovernmentEntity(), serviceName("") {}

PublicCompany::PublicCompany(const std::string& name, const std::string& address, const std::string& phone,
                           const std::string& legalCode, double tax, int foundationYear,
                           const std::vector<std::string>& stakeholders, int shareholderCount, double stockPrice,
                           const std::string& code, const std::string& description, double annualBudget,
                           const std::string& serviceName)
    : SA(name, address, phone, legalCode, tax, foundationYear, stakeholders, shareholderCount, stockPrice),
      GovernmentEntity(name, address, phone, code, description, annualBudget),
      serviceName(serviceName) {}

PublicCompany::PublicCompany(const PublicCompany& other)
    : SA(other), GovernmentEntity(other), serviceName(other.serviceName) {}

PublicCompany::~PublicCompany() {}

// Getters
std::string PublicCompany::getServiceName() const {
    return serviceName;
}

// Setters
void PublicCompany::setServiceName(const std::string& serviceName) {
    this->serviceName = serviceName;
}

// Virtual methods
void PublicCompany::print() const {
    // Need to handle the diamond problem by explicitly calling the base classes
    std::cout << "Public Company Information:\n";
    std::cout << "Name: " << SA::name << "\n";
    std::cout << "Address: " << SA::address << "\n";
    std::cout << "Phone: " << SA::phone << "\n";
    std::cout << "Legal Code: " << legalCode << "\n";
    std::cout << "Tax: " << std::fixed << std::setprecision(2) << tax << "%\n";
    std::cout << "Foundation Year: " << foundationYear << "\n";
    std::cout << "Stock Price: $" << std::fixed << std::setprecision(2) << stockPrice << "\n";
    std::cout << "Shareholder Count: " << shareholderCount << "\n";
    
    std::cout << "Government Code: " << code << "\n";
    std::cout << "Description: " << description << "\n";
    std::cout << "Annual Budget: $" << std::fixed << std::setprecision(2) << annualBudget << "\n";
    
    std::cout << "Service Name: " << serviceName << "\n";
    
    std::cout << "Stakeholders (" << stakeholders.size() << "):\n";
    for (size_t i = 0; i < stakeholders.size(); ++i) {
        std::cout << "  " << (i+1) << ". " << stakeholders[i] << "\n";
    }
}

double PublicCompany::calculateProfit() const {
    // Combine profit calculation from both base classes
    double saProfit = SA::calculateProfit();
    double govSurplus = GovernmentEntity::calculateProfit();
    
    // Public companies often have a hybrid profit model
    return saProfit * 0.7 + govSurplus * 0.3;  // 70% private, 30% public
} 