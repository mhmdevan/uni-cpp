#include "../include/Dictionary.h"
#include <iostream>
#include <iomanip>

int main() {
    std::cout << "\n===== DICTIONARY CLASS TEST =====\n" << std::endl;
    
    // Create a dictionary to store employee data
    Dictionary employeeDB;
    
    std::cout << "Creating an employee database..." << std::endl;
    
    // Test inserting entries
    std::cout << "\n----- Testing Insert Operation -----" << std::endl;
    
    // Create employee data
    Data johnData("Software Engineer", 28, MALE, 85000.0);
    Data maryData("Project Manager", 34, FEMALE, 95000.0);
    Data bobData("QA Engineer", 26, MALE, 75000.0);
    Data aliceData("UX Designer", 31, FEMALE, 82000.0);
    
    // Insert entries into dictionary
    employeeDB.insert("Smith", johnData);
    employeeDB.insert("Johnson", maryData);
    employeeDB.insert("Brown", bobData);
    employeeDB.insert("Davis", aliceData);
    
    std::cout << "Added 4 employees to the database." << std::endl;
    
    // Print dictionary contents
    std::cout << "\n----- Dictionary Contents -----" << std::endl;
    employeeDB.print();
    
    // Test access by key
    std::cout << "\n----- Testing Access by Key -----" << std::endl;
    
    std::cout << "Data for 'Smith': " << std::endl;
    if (const Data* smithData = employeeDB.getValue("Smith")) {
        std::cout << *smithData << std::endl;
    } else {
        std::cout << "Not found!" << std::endl;
    }
    
    std::cout << "Data for 'Johnson': " << std::endl;
    if (const Data* johnsonData = employeeDB.getValue("Johnson")) {
        std::cout << *johnsonData << std::endl;
    } else {
        std::cout << "Not found!" << std::endl;
    }
    
    std::cout << "Data for 'Wilson' (should not exist): " << std::endl;
    if (const Data* wilsonData = employeeDB.getValue("Wilson")) {
        std::cout << *wilsonData << std::endl;
    } else {
        std::cout << "Not found!" << std::endl;
    }
    
    // Test modifying data using operator[]
    std::cout << "\n----- Testing Modify Using operator[] -----" << std::endl;
    
    std::cout << "Before modification:" << std::endl;
    std::cout << "Brown: " << employeeDB["Brown"] << std::endl;
    
    employeeDB["Brown"].setSalary(80000.0);
    employeeDB["Brown"].setPosition("Senior QA Engineer");
    
    std::cout << "After modification:" << std::endl;
    std::cout << "Brown: " << employeeDB["Brown"] << std::endl;
    
    // Test removing entries
    std::cout << "\n----- Testing Remove Operation -----" << std::endl;
    
    std::cout << "Before removal - number of entries: " << employeeDB.size() << std::endl;
    employeeDB.printKeys();
    
    if (employeeDB.remove("Johnson")) {
        std::cout << "Removed 'Johnson' from the database." << std::endl;
    } else {
        std::cout << "Failed to remove 'Johnson' from the database." << std::endl;
    }
    
    if (employeeDB.remove("Wilson")) {
        std::cout << "Removed 'Wilson' from the database." << std::endl;
    } else {
        std::cout << "Failed to remove 'Wilson' from the database (as expected)." << std::endl;
    }
    
    std::cout << "After removal - number of entries: " << employeeDB.size() << std::endl;
    employeeDB.printKeys();
    
    // Test adding new entries with operator[]
    std::cout << "\n----- Testing Adding New Entries with operator[] -----" << std::endl;
    
    employeeDB["Wilson"].setPosition("CEO");
    employeeDB["Wilson"].setAge(45);
    employeeDB["Wilson"].setGender(MALE);
    employeeDB["Wilson"].setSalary(150000.0);
    
    std::cout << "After adding 'Wilson' - number of entries: " << employeeDB.size() << std::endl;
    employeeDB.printKeys();
    
    std::cout << "Wilson's data: " << employeeDB["Wilson"] << std::endl;
    
    // Final dictionary contents
    std::cout << "\n----- Final Dictionary Contents -----" << std::endl;
    employeeDB.print();
    
    return 0;
} 