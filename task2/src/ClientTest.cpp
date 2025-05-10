#include "../include/Client.h"
#include <iostream>
#include <cstring>

int main() {
    std::cout << "=== Client Management System ===\n\n";
    
    // Create a vector of clients
    std::cout << "Enter the initial number of clients: ";
    int initialCount;
    std::cin >> initialCount;
    
    VectClient clientVector(initialCount);
    
    // Input clients if there are any initial ones
    if (initialCount > 0) {
        std::cout << "\nPlease input information for " << initialCount << " clients:\n";
        for (int i = 0; i < initialCount; i++) {
            std::cout << "\n=== Client " << i+1 << " ===\n";
            Client client;
            client.input();
            // We don't use .at() for VectClient since we didn't define that method
            // Instead, we'll create new clients via the createClient method
            clientVector.createClient();
        }
    }
    
    // Main menu loop
    bool exit = false;
    char choice;
    
    while (!exit) {
        std::cout << "\n=== Main Menu ===\n";
        std::cout << "C: Create a new client\n";
        std::cout << "R: Read all clients\n";
        std::cout << "F: Find a client by name\n";
        std::cout << "U: Update a client\n";
        std::cout << "D: Delete a client\n";
        std::cout << "T: Print client table\n";
        std::cout << "Q: Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        choice = toupper(choice);
        
        switch (choice) {
            case 'C': {
                clientVector.createClient();
                break;
            }
            case 'R': {
                clientVector.readAllClients();
                break;
            }
            case 'F': {
                std::cin.ignore(); // Clear the newline character
                char searchName[51];
                std::cout << "Enter client name to search: ";
                std::cin.getline(searchName, 51);
                
                Client* found = clientVector.findClientByName(searchName);
                if (found) {
                    std::cout << "\n=== Client Found ===\n";
                    found->print();
                } else {
                    std::cout << "Client with name '" << searchName << "' not found." << std::endl;
                }
                break;
            }
            case 'U': {
                int code;
                std::cout << "Enter client code to update: ";
                std::cin >> code;
                clientVector.updateClient(code);
                break;
            }
            case 'D': {
                int code;
                std::cout << "Enter client code to delete: ";
                std::cin >> code;
                clientVector.deleteClient(code);
                break;
            }
            case 'T': {
                clientVector.printTable();
                break;
            }
            case 'Q': {
                exit = true;
                std::cout << "Exiting program. Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        }
    }
    
    return 0;
} 