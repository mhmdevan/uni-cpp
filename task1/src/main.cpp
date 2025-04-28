#include <iostream>
#include <string>

// Forward declarations of test functions
int vectorTest();
int myStringTest();
int rectangleTest();
int galonTest();

int main() {
    int choice = 0;
    bool exit = false;
    
    while (!exit) {
        // Display menu
        std::cout << "\n==== C++ Class Implementation Tests ====\n";
        std::cout << "1. Vector Class Test\n";
        std::cout << "2. MyString Class Test\n";
        std::cout << "3. Rectangle Class Test\n";
        std::cout << "4. Galon Concentration Test\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        // Clear input buffer
        std::cin.ignore(10000, '\n');
        
        switch (choice) {
            case 1:
                system("clear"); // Clear console (for Unix/Mac)
                std::cout << "\n---- Vector Class Test ----\n\n";
                system("./build/VectorTest");
                break;
                
            case 2:
                system("clear");
                std::cout << "\n---- MyString Class Test ----\n\n";
                system("./build/MyStringTest");
                break;
                
            case 3:
                system("clear");
                std::cout << "\n---- Rectangle Class Test ----\n\n";
                system("./build/RectangleTest");
                break;
                
            case 4:
                system("clear");
                std::cout << "\n---- Galon Concentration Test ----\n\n";
                system("./build/GalonTest");
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