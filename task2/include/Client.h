#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

// Class representing a client with personal and financial information
class Client {
private:
    int code;               // Integer code
    char name[51];          // Name (max 50 chars + null terminator)
    int age;                // Age (18-65)
    char gender;            // Gender ('M' or 'F')
    double salary;          // Salary (100,000 - 500,000)

public:
    // Constructors and destructor
    Client();
    Client(int code, const char* name, int age, char gender, double salary);
    Client(const Client& other);
    ~Client();

    // Getters
    int getCode() const;
    const char* getName() const;
    int getAge() const;
    char getGender() const;
    double getSalary() const;

    // Setters
    void setCode(int code);
    void setName(const char* name);
    void setAge(int age);
    void setGender(char gender);
    void setSalary(double salary);

    // Input and output methods
    void input();
    void print() const;
};

// Class to manage a vector of clients
class VectClient {
private:
    std::vector<Client> clients;
    int count;

public:
    // Constructors and destructor
    VectClient();
    VectClient(int count);
    VectClient(const VectClient& other);
    ~VectClient();

    // Vector operations
    int getCount() const;
    void setCount(int count);
    
    // CRUD operations
    void createClient();           // C: Insert a new client
    void readAllClients() const;   // R: Read all clients
    Client* findClientByName(const char* name); // Find client by name
    void updateClient(int code);   // U: Update a specific client
    bool deleteClient(int code);   // D: Delete a specific client
    
    // Table printing
    void printTable() const;
};

#endif // CLIENT_H 