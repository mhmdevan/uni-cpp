#include "../include/Person.h"
#include <iostream>
#include <vector>
#include <memory>

// Function to display different person types through a base class pointer
void displayPerson(const Person* person) {
    person->print();
    std::cout << "------------------------\n";
}

// Function to demonstrate polymorphism with profit calculation
void displayProfit(const LegalPerson* entity) {
    entity->print();
    std::cout << "Annual Profit: $" << entity->calculateProfit() << std::endl;
    std::cout << "------------------------\n";
}

int main() {
    std::cout << "\n===== TASK 3: MULTILEVEL AND MULTIPLE INHERITANCE =====\n\n";
    
    // Creating objects of different classes
    
    std::cout << "Creating objects...\n\n";
    
    // Natural persons
    NaturalPerson johnDoe("John Doe", "123 Main St", "555-1234", "A12345678", 35);
    
    Employer janeSmith("Jane Smith", "456 Oak Ave", "555-5678", "B87654321", 42, 
                      "Tech Solutions Inc", 75000.0);
    
    Supervisor bobJohnson("Bob Johnson", "789 Pine Rd", "555-9012", "C13579246", 50, 
                        "Engineering", "Senior Manager", 12);
    
    // Legal persons
    std::vector<std::string> techPartners = {"Alice Brown", "David Wilson", "Emma Davis"};
    Ltda techCompany("TechSoft Ltd", "101 Silicon St", "555-2468", "TL12345", 15.5, 2010,
                    techPartners, 500000.0);
    
    std::vector<std::string> energyStakeholders = {"Global Investments", "Green Capital", "Future Holdings"};
    SA energyCorp("EnergyTech SA", "202 Power Ave", "555-1357", "ES67890", 22.0, 2005,
                 energyStakeholders, 5000, 125.75);
    
    // Government entity
    GovernmentEntity transportDept("Transportation Department", "303 Government Blvd", "555-3691",
                                 "GOV-TD-123", "Public Transportation Services", 10000000.0);
    
    // Multiple inheritance
    std::vector<std::string> utilityStakeholders = {"City Investment Fund", "National Power Holdings", "Infrastructure Inc"};
    PublicCompany utilityCompany("National Utility Corp", "404 Power St", "555-9876",
                               "NUC-2023", 18.5, 1980, utilityStakeholders, 10000, 45.80,
                               "GOV-UT-456", "National Utility Services", 25000000.0,
                               "Electricity and Water Supply");
    
    // Demonstrating polymorphism using base class pointers
    std::cout << "===== DEMONSTRATING POLYMORPHISM WITH BASE CLASS POINTERS =====\n\n";
    
    std::vector<Person*> people = {
        &johnDoe,
        &janeSmith,
        &bobJohnson,
        &techCompany,
        &energyCorp,
        &transportDept,
        static_cast<SA*>(&utilityCompany)  // Explicit cast to resolve ambiguity
    };
    
    for (const auto& person : people) {
        displayPerson(person);
    }
    
    // Demonstrating profit calculation polymorphism
    std::cout << "===== DEMONSTRATING PROFIT CALCULATION POLYMORPHISM =====\n\n";
    
    std::vector<LegalPerson*> legalEntities = {
        &techCompany,
        &energyCorp,
        static_cast<LegalPerson*>(static_cast<SA*>(&utilityCompany))
    };
    
    for (const auto& entity : legalEntities) {
        displayProfit(entity);
    }
    
    // Demonstrating multiple inheritance
    std::cout << "===== DEMONSTRATING MULTIPLE INHERITANCE =====\n\n";
    
    std::cout << "Public Company Information (Multiple Inheritance Example):\n";
    utilityCompany.print();
    std::cout << "\nProfit Calculation: $" << utilityCompany.calculateProfit() << "\n";
    std::cout << "------------------------\n";
    
    // Analysis of inheritance advantages and disadvantages
    std::cout << "\n===== ANALYSIS OF INHERITANCE PATTERNS =====\n\n";
    
    std::cout << "Multilevel Inheritance (e.g., Person -> NaturalPerson -> Employer):\n";
    std::cout << "Advantages:\n";
    std::cout << " - Clear hierarchy that models real-world relationships\n";
    std::cout << " - Each level adds specific functionality to the previous one\n";
    std::cout << " - Code reuse through inheriting functionalities\n";
    std::cout << "Disadvantages:\n";
    std::cout << " - Deep inheritance trees can become complex to understand\n";
    std::cout << " - Changes to base classes can have cascading effects on derived classes\n";
    std::cout << " - May lead to inherited methods that don't make sense for all derived classes\n\n";
    
    std::cout << "Multiple Inheritance (e.g., PublicCompany inheriting from SA and GovernmentEntity):\n";
    std::cout << "Advantages:\n";
    std::cout << " - Can model complex relationships where an entity has characteristics of multiple types\n";
    std::cout << " - Combines functionality from different class hierarchies\n";
    std::cout << " - Allows for more flexible designs\n";
    std::cout << "Disadvantages:\n";
    std::cout << " - Diamond problem (ambiguity when same method exists in multiple base classes)\n";
    std::cout << " - Increased complexity in understanding class behavior\n";
    std::cout << " - Can lead to subtle bugs if not carefully designed\n";
    std::cout << " - Not supported in all object-oriented languages\n\n";
    
    std::cout << "Both inheritance patterns are powerful tools in C++ but require careful design\n";
    std::cout << "to avoid complexity and maintenance issues in large codebases.\n";
    
    return 0;
} 