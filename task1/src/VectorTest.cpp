#include "../include/Vector.h"
#include <iostream>
#include <iomanip>
    
int main() {
    // Create vectors
    Vector v1(1.0, 2.0, 3.0);
    Vector v2(4.0, 5.0, 6.0);
    
    // Print vectors
    std::cout << "Vector v1: ";
    v1.print();
    std::cout << "Vector v2: ";
    v2.print();
    
    // Calculate and print magnitude
    std::cout << "Magnitude of v1: " << v1.magnitude() << std::endl;
    
    // Calculate and print unit vector
    std::cout << "Unit vector of v1: ";
    v1.unitVector().print();
    
    // Calculate and print dot product
    std::cout << "Dot product of v1 and v2: " << v1.dotProduct(v2) << std::endl;
    
    // Calculate and print cross product
    std::cout << "Cross product of v1 and v2: ";
    v1.crossProduct(v2).print();
    
    // Calculate and print angle between vectors
    std::cout << "Angle between v1 and v2 (in radians): " << v1.angleBetween(v2) << std::endl;
    std::cout << "Angle between v1 and v2 (in degrees): " << v1.angleBetween(v2) * 180.0 / M_PI << std::endl;
    
    // Calculate and print Euclidean distance
    std::cout << "Euclidean distance between v1 and v2: " << v1.euclideanDistance(v2) << std::endl;
    
    // Calculate and print Manhattan distance
    std::cout << "Manhattan distance between v1 and v2: " << v1.manhattanDistance(v2) << std::endl;
    
    // Test input method
    std::cout << "\nInput new vector v3:" << std::endl;
    Vector v3;
    v3.input();
    
    std::cout << "Vector v3: ";
    v3.print();
    
    return 0;
} 