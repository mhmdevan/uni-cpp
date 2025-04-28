#include "../include/Galon.h"
#include <iostream>
#include <iomanip>

// Default constructor
Galon::Galon() : totalVolume(0.0), alcoholVolume(0.0) {}

// Parameterized constructor
Galon::Galon(double totalVolume, double alcoholConcentration) 
    : totalVolume(totalVolume) {
    // Calculate alcohol volume based on concentration (as percentage)
    alcoholVolume = totalVolume * (alcoholConcentration / 100.0);
}

// Copy constructor
Galon::Galon(const Galon& other) 
    : totalVolume(other.totalVolume), alcoholVolume(other.alcoholVolume) {}

// Destructor
Galon::~Galon() {}

// Getters
double Galon::getTotalVolume() const {
    return totalVolume;
}

double Galon::getAlcoholVolume() const {
    return alcoholVolume;
}

double Galon::getConcentration() const {
    if (totalVolume > 0) {
        return (alcoholVolume / totalVolume) * 100.0;
    }
    return 0.0;
}

// Setters
void Galon::setTotalVolume(double volume) {
    if (volume >= 0) {
        totalVolume = volume;
        // Ensure alcohol volume is not greater than total volume
        if (alcoholVolume > totalVolume) {
            alcoholVolume = totalVolume;
        }
    }
}

void Galon::setAlcoholVolume(double volume) {
    if (volume >= 0 && volume <= totalVolume) {
        alcoholVolume = volume;
    }
}

void Galon::setConcentration(double concentration) {
    if (concentration >= 0 && concentration <= 100) {
        alcoholVolume = totalVolume * (concentration / 100.0);
    }
}

// Operations
void Galon::addLiquid(double volume, double concentration) {
    if (volume > 0) {
        // Calculate alcohol volume in the added liquid
        double addedAlcohol = volume * (concentration / 100.0);
        
        // Update total volumes
        totalVolume += volume;
        alcoholVolume += addedAlcohol;
    }
}

void Galon::removeLiquid(double volume) {
    if (volume > 0 && volume <= totalVolume) {
        // Calculate alcohol in the removed liquid (proportional to concentration)
        double currentConcentration = getConcentration() / 100.0;
        double removedAlcohol = volume * currentConcentration;
        
        // Update volumes
        totalVolume -= volume;
        alcoholVolume -= removedAlcohol;
    }
}

// Print method
void Galon::print() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Gallon: Total Volume = " << totalVolume << " L, "
              << "Alcohol Volume = " << alcoholVolume << " L, "
              << "Concentration = " << getConcentration() << "%" 
              << std::endl;
}

// Calculate number of mixing operations
int calculateMixingOperations(Galon& galon1, Galon& galon2, double targetConcentration, double transferVolume) {
    int operations = 0;
    
    // Continue mixing until galon1's concentration falls below target
    while (galon1.getConcentration() >= targetConcentration) {
        // Step 1: Remove from galon1 and add to galon2
        double removedVolume = std::min(transferVolume, galon1.getTotalVolume());
        double currentConcentration1 = galon1.getConcentration();
        double alcoholInTransfer = removedVolume * (currentConcentration1 / 100.0);
        
        galon1.removeLiquid(removedVolume);
        galon2.addLiquid(removedVolume, currentConcentration1);
        
        // Step 2: Remove from galon2 and add to galon1
        double removedVolume2 = std::min(transferVolume, galon2.getTotalVolume());
        double currentConcentration2 = galon2.getConcentration();
        double alcoholInTransfer2 = removedVolume2 * (currentConcentration2 / 100.0);
        
        galon2.removeLiquid(removedVolume2);
        galon1.addLiquid(removedVolume2, currentConcentration2);
        
        operations++;
        
        // Safety check to avoid infinite loop
        if (operations > 1000) {
            std::cout << "Warning: Maximum operations exceeded. The target concentration may not be achievable." << std::endl;
            break;
        }
    }
    
    return operations;
} 