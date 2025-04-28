#include "../include/Galon.h"
#include <iostream>
#include <iomanip>

int main() {
    double initialVolume, initialConcentration;
    double targetConcentration;
    double transferVolume;
    
    // Get input from user
    std::cout << "Enter initial volume of each gallon (in liters): ";
    std::cin >> initialVolume;
    
    std::cout << "Enter initial alcohol concentration in first gallon (%): ";
    std::cin >> initialConcentration;
    
    std::cout << "Enter target concentration to achieve (%): ";
    std::cin >> targetConcentration;
    
    std::cout << "Enter transfer volume (in liters): ";
    std::cin >> transferVolume;
    
    // Create galons
    Galon galon1(initialVolume, initialConcentration);
    Galon galon2(initialVolume, 0.0);  // Second galon contains only water
    
    // Print initial state
    std::cout << "\nInitial state:" << std::endl;
    std::cout << "Galon 1: ";
    galon1.print();
    std::cout << "Galon 2: ";
    galon2.print();
    
    // Calculate number of operations
    int operations = calculateMixingOperations(galon1, galon2, targetConcentration, transferVolume);
    
    // Print final state
    std::cout << "\nAfter " << operations << " mixing operations:" << std::endl;
    std::cout << "Galon 1: ";
    galon1.print();
    std::cout << "Galon 2: ";
    galon2.print();
    
    std::cout << "\nNumber of mixing operations needed: " << operations << std::endl;
    
    return 0;
} 