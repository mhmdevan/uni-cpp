#include "../include/Rectangle.h"
#include <iostream>

int main() {
    // Test default constructor
    Rectangle r1;
    std::cout << "Default constructor: ";
    r1.print();
    
    // Test parameterized constructor
    Rectangle r2(10.0, 20.0, 30.0, 40.0);
    std::cout << "Parameterized constructor: ";
    r2.print();
    
    // Test copy constructor
    Rectangle r3(r2);
    std::cout << "Copy constructor: ";
    r3.print();
    
    // Test normalization (using non-normalized values)
    Rectangle r4(30.0, 40.0, 10.0, 20.0);  // left > right, bottom > top
    std::cout << "After normalization: ";
    r4.print();
    
    // Test perimeter and area
    std::cout << "Perimeter of r2: " << r2.perimeter() << std::endl;
    std::cout << "Area of r2: " << r2.area() << std::endl;
    
    // Test inflate method
    std::cout << "Before inflation: ";
    r2.print();
    r2.inflate(5.0, 10.0);
    std::cout << "After inflation: ";
    r2.print();
    
    // Test get and set methods
    double left, bottom, right, top;
    r2.get(left, bottom, right, top);
    std::cout << "Using get method: Left=" << left << ", Bottom=" << bottom
              << ", Right=" << right << ", Top=" << top << std::endl;
    
    r2.set(100.0, 200.0, 300.0, 400.0);
    std::cout << "After set method: ";
    r2.print();
    
    // Test getBoundingRectangle
    Rectangle r5(0.0, 0.0, 50.0, 50.0);
    Rectangle r6(25.0, 25.0, 75.0, 75.0);
    
    std::cout << "Rectangle 5: ";
    r5.print();
    std::cout << "Rectangle 6: ";
    r6.print();
    
    Rectangle r7 = getBoundingRectangle(r5, r6);
    std::cout << "Bounding rectangle: ";
    r7.print();
    
    return 0;
} 