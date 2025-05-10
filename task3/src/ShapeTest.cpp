#include "../include/Shape.h"
#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>

int main() {
    std::cout << "===== Geometric Shapes Hierarchy Test =====\n\n";
    
    // Create shapes
    std::cout << "----- Creating Shapes -----\n";
    Rectangle rect1(1.0, 2.0, 5.0, 8.0, RED);
    Rectangle rect2(10.0, 10.0, 20.0, 25.0, GREEN);
    Circle circle1(0.0, 0.0, 5.0, BLUE);
    Circle circle2(rect1); // Special constructor from Rectangle
    
    // Describe all shapes
    std::cout << "\n----- Describing Shapes -----\n";
    std::cout << "Rectangle 1:\n";
    rect1.describe();
    std::cout << "Perimeter: " << rect1.calculate_perimeter() << std::endl;
    std::cout << "Area: " << rect1.calculate_area() << std::endl;
    std::cout << std::endl;
    
    std::cout << "Rectangle 2:\n";
    rect2.describe();
    std::cout << "Perimeter: " << rect2.calculate_perimeter() << std::endl;
    std::cout << "Area: " << rect2.calculate_area() << std::endl;
    std::cout << std::endl;
    
    std::cout << "Circle 1:\n";
    circle1.describe();
    std::cout << "Perimeter: " << circle1.calculate_perimeter() << std::endl;
    std::cout << "Area: " << circle1.calculate_area() << std::endl;
    std::cout << std::endl;
    
    std::cout << "Circle 2 (from Rectangle 1):\n";
    circle2.describe();
    std::cout << "Perimeter: " << circle2.calculate_perimeter() << std::endl;
    std::cout << "Area: " << circle2.calculate_area() << std::endl;
    std::cout << std::endl;
    
    // Demonstrate polymorphism using a vector of base class pointers
    std::cout << "----- Polymorphism Demonstration -----\n";
    
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Rectangle>(0.0, 0.0, 4.0, 3.0, RED));
    shapes.push_back(std::make_unique<Circle>(5.0, 5.0, 2.0, GREEN));
    
    // Access shapes through base class pointers
    for (size_t i = 0; i < shapes.size(); ++i) {
        std::cout << "Shape " << i+1 << ":\n";
        shapes[i]->describe();
        std::cout << "Perimeter: " << shapes[i]->calculate_perimeter() << std::endl;
        std::cout << "Area: " << shapes[i]->calculate_area() << std::endl;
        std::cout << std::endl;
    }
    
    // Test inflate operation
    std::cout << "----- Testing Inflate Operation -----\n";
    std::cout << "Rectangle 1 before inflation:\n";
    rect1.describe();
    
    rect1.inflate(2.0);
    std::cout << "\nRectangle 1 after inflate(2.0):\n";
    rect1.describe();
    
    std::cout << "\nCircle 1 before inflation:\n";
    circle1.describe();
    
    circle1.inflate(3.0);
    std::cout << "\nCircle 1 after inflate(3.0):\n";
    circle1.describe();
    
    // Demonstrate virtual method behavior with pointers
    std::cout << "\n----- Testing Virtual Methods with Base Class Pointers -----\n";
    
    Shape* pShape1 = &rect2;
    Shape* pShape2 = &circle1;
    
    std::cout << "Rectangle through base pointer:\n";
    pShape1->describe();
    std::cout << "Perimeter: " << pShape1->calculate_perimeter() << std::endl;
    std::cout << "Area: " << pShape1->calculate_area() << std::endl;
    std::cout << std::endl;
    
    std::cout << "Circle through base pointer:\n";
    pShape2->describe();
    std::cout << "Perimeter: " << pShape2->calculate_perimeter() << std::endl;
    std::cout << "Area: " << pShape2->calculate_area() << std::endl;
    
    // Note: we cannot create instances of the abstract base class directly
    // Shape baseShape; // This would cause a compilation error
    
    return 0;
} 