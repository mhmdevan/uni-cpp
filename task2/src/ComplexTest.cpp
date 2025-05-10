#include "../include/Complex.h"
#include <iostream>
#include <iomanip>

int main() {
    // Test Complex class operations
    std::cout << "=== Complex Number Operations ===\n";
    
    // Create complex numbers
    Complex z1(3.0, 4.0);
    Complex z2(1.0, 2.0);
    
    std::cout << "z1 = ";
    z1.print();
    std::cout << std::endl;
    
    std::cout << "z2 = ";
    z2.print();
    std::cout << std::endl;
    
    // Test module
    std::cout << "Module of z1: " << z1.module() << std::endl;
    
    // Test inverse
    std::cout << "Inverse of z1: ";
    z1.inverse().print();
    std::cout << std::endl;
    
    // Test addition
    std::cout << "z1 + z2 = ";
    z1.add(z2).print();
    std::cout << std::endl;
    
    // Test subtraction
    std::cout << "z1 - z2 = ";
    z1.subtract(z2).print();
    std::cout << std::endl;
    
    // Test multiplication
    std::cout << "z1 * z2 = ";
    z1.multiply(z2).print();
    std::cout << std::endl;
    
    // Test division
    std::cout << "z1 / z2 = ";
    z1.divide(z2).print();
    std::cout << std::endl;
    
    // Test ComplexVector
    std::cout << "\n=== Complex Vector Operations ===\n";
    
    // Create and initialize the weight vector
    ComplexVector weights(3);
    weights.at(0) = Complex(1.0, 1.0);
    weights.at(1) = Complex(2.0, -1.0);
    weights.at(2) = Complex(0.5, 0.5);
    
    std::cout << "Weight vector:\n";
    weights.print();
    
    // Create and initialize the input vector
    ComplexVector inputs(3);
    inputs.at(0) = Complex(2.0, 0.0);
    inputs.at(1) = Complex(1.0, 1.0);
    inputs.at(2) = Complex(3.0, -2.0);
    
    std::cout << "\nInput vector:\n";
    inputs.print();
    
    // Perform element-wise operations
    std::cout << "\nElement-wise addition:\n";
    ComplexVector addResult = weights.addVector(inputs);
    addResult.print();
    
    std::cout << "\nElement-wise subtraction:\n";
    ComplexVector subResult = weights.subtractVector(inputs);
    subResult.print();
    
    std::cout << "\nElement-wise multiplication:\n";
    ComplexVector mulResult = weights.multiplyVector(inputs);
    mulResult.print();
    
    std::cout << "\nElement-wise division:\n";
    ComplexVector divResult = weights.divideVector(inputs);
    divResult.print();
    
    // Test user input
    std::cout << "\n=== User Input Test ===\n";
    std::cout << "Enter size for vector: ";
    int size;
    std::cin >> size;
    
    ComplexVector userVector(size);
    std::cout << "Enter elements for vector:\n";
    userVector.input();
    
    std::cout << "\nYour vector:\n";
    userVector.print();
    
    return 0;
} 