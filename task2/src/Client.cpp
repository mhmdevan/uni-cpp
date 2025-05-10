#include "../include/Client.h"
#include <iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>

// Client class implementation

// Constructors and destructor
Client::Client() : code(0), age(18), gender('M'), salary(100000.0) {
    strcpy(name, "");
}

Client::Client(int code, const char* name, int age, char gender, double salary) : code(code), age(age), gender(gender), salary(salary) {
    // Validate and set parameters
    setName(name);
    setAge(age);
    setGender(gender);
    setSalary(salary);
}

Client::Client(const Client& other) : code(other.code), age(other.age), gender(other.gender), salary(other.salary) {
    strcpy(name, other.name);
}

Client::~Client() {
    // Nothing to clean up (name is fixed size)
}

// Getters
int Client::getCode() const {
    return code;
}

const char* Client::getName() const {
    return name;
}

int Client::getAge() const {
    return age;
}

char Client::getGender() const {
    return gender;
}

double Client::getSalary() const {
    return salary;
}

// Setters
void Client::setCode(int code) {
    this->code = code;
}

void Client::setName(const char* name) {
    // Ensure name is not too long (max 50 chars)
    strncpy(this->name, name, 50);
    this->name[50] = '\0'; // Ensure null termination
}

void Client::setAge(int age) {
    // Validate age (18-65)
    if (age >= 18 && age <= 65) {
        this->age = age;
    } else {
        std::cerr << "Warning: Age must be between 18 and 65. Setting to default." << std::endl;
        this->age = 18;
    }
}

void Client::setGender(char gender) {
    // Validate gender (M or F)
    if (gender == 'M' || gender == 'F') {
        this->gender = gender;
    } else {
        std::cerr << "Warning: Gender must be 'M' or 'F'. Setting to 'M'." << std::endl;
        this->gender = 'M';
    }
}

void Client::setSalary(double salary) {
    // Validate salary (100,000-500,000)
    if (salary >= 100000.0 && salary <= 500000.0) {
        this->salary = salary;
    } else {
        std::cerr << "Warning: Salary must be between 100,000 and 500,000. Setting to default." << std::endl;
        this->salary = 100000.0;
    }
}

// Input and output methods
void Client::input() {
    std::cout << "Enter client code: ";
    std::cin >> code;
    
    std::cin.ignore(); // Clear the newline character
    
    std::cout << "Enter client name (max 50 chars): ";
    std::cin.getline(name, 51);
    
    int inputAge;
    do {
        std::cout << "Enter client age (18-65): ";
        std::cin >> inputAge;
        if (inputAge < 18 || inputAge > 65) {
            std::cout << "Age must be between 18 and 65. Try again." << std::endl;
        }
    } while (inputAge < 18 || inputAge > 65);
    setAge(inputAge);
    
    char inputGender;
    do {
        std::cout << "Enter client gender (M/F): ";
        std::cin >> inputGender;
        inputGender = toupper(inputGender);
        if (inputGender != 'M' && inputGender != 'F') {
            std::cout << "Gender must be 'M' or 'F'. Try again." << std::endl;
        }
    } while (inputGender != 'M' && inputGender != 'F');
    setGender(inputGender);
    
    double inputSalary;
    do {
        std::cout << "Enter client salary (100,000-500,000): ";
        std::cin >> inputSalary;
        if (inputSalary < 100000.0 || inputSalary > 500000.0) {
            std::cout << "Salary must be between 100,000 and 500,000. Try again." << std::endl;
        }
    } while (inputSalary < 100000.0 || inputSalary > 500000.0);
    setSalary(inputSalary);
}

void Client::print() const {
    std::cout << "Code: " << code << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Gender: " << gender << std::endl;
    std::cout << "Salary: " << std::fixed << std::setprecision(2) << salary << std::endl;
}

// VectClient class implementation

// Constructors and destructor
VectClient::VectClient() : count(0) {}

VectClient::VectClient(int count) : count(count) {
    clients.resize(count);
}

VectClient::VectClient(const VectClient& other) : clients(other.clients), count(other.count) {}

VectClient::~VectClient() {}

// Vector operations
int VectClient::getCount() const {
    return count;
}

void VectClient::setCount(int count) {
    this->count = count;
    clients.resize(count);
}

// CRUD operations
void VectClient::createClient() {
    Client newClient;
    std::cout << "\n=== Creating a new client ===\n";
    newClient.input();
    
    clients.push_back(newClient);
    count++;
    
    std::cout << "Client added successfully!" << std::endl;
}

void VectClient::readAllClients() const {
    if (count == 0) {
        std::cout << "No clients to display." << std::endl;
        return;
    }
    
    for (int i = 0; i < count; i++) {
        std::cout << "\n=== Client " << i+1 << " ===\n";
        clients[i].print();
    }
}

Client* VectClient::findClientByName(const char* name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(clients[i].getName(), name) == 0) {
            return &clients[i];
        }
    }
    return nullptr; // Client not found
}

void VectClient::updateClient(int code) {
    for (int i = 0; i < count; i++) {
        if (clients[i].getCode() == code) {
            std::cout << "\n=== Updating client with code " << code << " ===\n";
            std::cout << "Current client information:" << std::endl;
            clients[i].print();
            
            std::cout << "\nEnter new information:" << std::endl;
            clients[i].input();
            
            std::cout << "Client updated successfully!" << std::endl;
            return;
        }
    }
    
    std::cout << "Client with code " << code << " not found." << std::endl;
}

bool VectClient::deleteClient(int code) {
    for (int i = 0; i < count; i++) {
        if (clients[i].getCode() == code) {
            // Remove client at index i
            clients.erase(clients.begin() + i);
            count--;
            std::cout << "Client with code " << code << " deleted successfully!" << std::endl;
            return true;
        }
    }
    
    std::cout << "Client with code " << code << " not found." << std::endl;
    return false;
}

// Table printing
void VectClient::printTable() const {
    if (count == 0) {
        std::cout << "No clients to display." << std::endl;
        return;
    }
    
    // Print table header
    std::cout << std::setfill('-') << std::setw(80) << "-" << std::setfill(' ') << std::endl;
    std::cout << "| " << std::setw(5) << "Code" << " | "
              << std::setw(20) << "Name" << " | "
              << std::setw(5) << "Age" << " | "
              << std::setw(6) << "Gender" << " | "
              << std::setw(15) << "Salary" << " |" << std::endl;
    std::cout << std::setfill('-') << std::setw(80) << "-" << std::setfill(' ') << std::endl;
    
    // Print table rows
    for (int i = 0; i < count; i++) {
        std::cout << "| " << std::setw(5) << clients[i].getCode() << " | "
                  << std::setw(20) << clients[i].getName() << " | "
                  << std::setw(5) << clients[i].getAge() << " | "
                  << std::setw(6) << clients[i].getGender() << " | "
                  << std::setw(15) << std::fixed << std::setprecision(2) << clients[i].getSalary() << " |" << std::endl;
    }
    
    std::cout << std::setfill('-') << std::setw(80) << "-" << std::setfill(' ') << std::endl;
    std::cout << "Total clients: " << count << std::endl;
} 