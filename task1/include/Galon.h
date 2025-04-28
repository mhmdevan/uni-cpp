#ifndef GALON_H
#define GALON_H

#include <iostream>

class Galon {
private:
    double totalVolume;     // Total volume of the gallon
    double alcoholVolume;   // Volume of alcohol in the gallon
    
public:
    // Constructors and destructor
    Galon();
    Galon(double totalVolume, double alcoholConcentration);
    Galon(const Galon& other);
    ~Galon();
    
    // Getters
    double getTotalVolume() const;
    double getAlcoholVolume() const;
    double getConcentration() const;  // Returns alcohol concentration as percentage
    
    // Setters
    void setTotalVolume(double volume);
    void setAlcoholVolume(double volume);
    void setConcentration(double concentration);
    
    // Operations
    void addLiquid(double volume, double concentration);
    void removeLiquid(double volume);
    
    // Print method
    void print() const;
};

// Calculate number of mixing operations to reach target concentration
int calculateMixingOperations(Galon& galon1, Galon& galon2, double targetConcentration, double transferVolume);

#endif // GALON_H 