#include <iostream>
#include <cstdlib>

// Forward declarations for test functions
int myStringTest();
int complexTest();
int clientTest();

int main() {
    int choice = 0;
    bool exit = false;
    
    while (!exit) {
        // Display menu
        std::cout << "\n==== C++ Object-Oriented Programming Tasks ====\n";
        std::cout << "1. MyString Vector Test\n";
        std::cout << "2. Complex Numbers Vector Test\n";
        std::cout << "3. Client Management System Test\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        // Clear input buffer
        std::cin.ignore(10000, '\n');
        
        switch (choice) {
            case 1:
                system("clear"); // Clear console (for Unix/Mac)
                std::cout << "\n---- MyString Vector Test ----\n\n";
                system("./build/MyStringTest");
                break;
                
            case 2:
                system("clear");
                std::cout << "\n---- Complex Numbers Vector Test ----\n\n";
                system("./build/ComplexTest");
                break;
                
            case 3:
                system("clear");
                std::cout << "\n---- Client Management System Test ----\n\n";
                system("./build/ClientTest");
                break;
                
            case 0:
                exit = true;
                std::cout << "Exiting program. Goodbye!\n";
                break;
                
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
    
    return 0;
} 