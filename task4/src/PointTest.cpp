#include "../include/Point.h"
#include <iostream>
#include <iomanip>

int main() {
    std::cout << "\n===== POINT CLASS TEST =====\n" << std::endl;
    
    // Test constructors
    std::cout << "Testing Constructors:" << std::endl;
    Point p1;                  // Default constructor
    Point p2(3.5, 7.2);        // Parameterized constructor
    Point p3 = p2;             // Copy constructor
    
    std::cout << "p1 (default): " << p1 << std::endl;
    std::cout << "p2 (parameterized): " << p2 << std::endl;
    std::cout << "p3 (copy of p2): " << p3 << std::endl;
    
    // Test getters and setters
    std::cout << "\nTesting Getters and Setters:" << std::endl;
    std::cout << "p1.getX(): " << p1.getX() << std::endl;
    std::cout << "p1.getY(): " << p1.getY() << std::endl;
    
    p1.setX(10.5);
    p1.setY(20.7);
    std::cout << "After setting x=10.5, y=20.7: " << p1 << std::endl;
    
    p1.setPoint(15.3, 25.8);
    std::cout << "After setting point to (15.3, 25.8): " << p1 << std::endl;
    
    // Test += operator (member function)
    std::cout << "\nTesting += Operator (Member Function):" << std::endl;
    
    // Case 1: p1 += p2
    Point p4(1.0, 2.0);
    Point p5(3.0, 4.0);
    std::cout << "p4: " << p4 << std::endl;
    std::cout << "p5: " << p5 << std::endl;
    p4 += p5;
    std::cout << "p4 += p5: " << p4 << std::endl;
    
    // Case 2: p1 += numeric value
    Point p6(5.0, 6.0);
    std::cout << "p6: " << p6 << std::endl;
    p6 += 2.5;
    std::cout << "p6 += 2.5: " << p6 << std::endl;
    
    // Case 3: p1 += p2 += numeric value (sequence)
    Point p7(1.0, 1.0);
    Point p8(2.0, 2.0);
    std::cout << "p7: " << p7 << std::endl;
    std::cout << "p8: " << p8 << std::endl;
    p7 += (p8 += 3.0);
    std::cout << "p8 += 3.0: " << p8 << std::endl;
    std::cout << "p7 += (p8 += 3.0): " << p7 << std::endl;
    
    // Test -= operator (friend function)
    std::cout << "\nTesting -= Operator (Friend Function):" << std::endl;
    
    // Case 1: p1 -= p2
    Point p9(10.0, 10.0);
    Point p10(3.0, 2.0);
    std::cout << "p9: " << p9 << std::endl;
    std::cout << "p10: " << p10 << std::endl;
    p9 -= p10;
    std::cout << "p9 -= p10: " << p9 << std::endl;
    
    // Case 2: p1 -= numeric value
    Point p11(8.0, 8.0);
    std::cout << "p11: " << p11 << std::endl;
    p11 -= 2.5;
    std::cout << "p11 -= 2.5: " << p11 << std::endl;
    
    // Case 3: p1 -= p2 -= numeric value (sequence)
    Point p12(10.0, 10.0);
    Point p13(5.0, 5.0);
    std::cout << "p12: " << p12 << std::endl;
    std::cout << "p13: " << p13 << std::endl;
    p12 -= (p13 -= 2.0);
    std::cout << "p13 -= 2.0: " << p13 << std::endl;
    std::cout << "p12 -= (p13 -= 2.0): " << p12 << std::endl;
    
    // Test binary + operator (member function)
    std::cout << "\nTesting Binary + Operator (Member Function):" << std::endl;
    Point p14(1.0, 2.0);
    Point p15(3.0, 4.0);
    Point p16 = p14 + p15;
    std::cout << "p14: " << p14 << std::endl;
    std::cout << "p15: " << p15 << std::endl;
    std::cout << "p14 + p15: " << p16 << std::endl;
    
    Point p17 = p14 + 5.0;
    std::cout << "p14 + 5.0: " << p17 << std::endl;
    
    // Test binary - operator (friend function)
    std::cout << "\nTesting Binary - Operator (Friend Function):" << std::endl;
    Point p18(10.0, 20.0);
    Point p19(3.0, 7.0);
    Point p20 = p18 - p19;
    std::cout << "p18: " << p18 << std::endl;
    std::cout << "p19: " << p19 << std::endl;
    std::cout << "p18 - p19: " << p20 << std::endl;
    
    Point p21 = p18 - 5.0;
    std::cout << "p18 - 5.0: " << p21 << std::endl;
    
    Point p22 = 15.0 - p19;
    std::cout << "15.0 - p19: " << p22 << std::endl;
    
    return 0;
} 