#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

class Rectangle {
private:
    double left;
    double bottom;
    double right;
    double top;

    // Normalize boundaries (make sure left < right and bottom < top)
    void normalize();

public:
    // Constructors and destructor
    Rectangle();
    Rectangle(double left, double bottom, double right, double top);
    Rectangle(const Rectangle& other);
    ~Rectangle();

    // Print method
    void print() const;
    
    // Calculation methods
    double perimeter() const;
    double area() const;
    
    // Inflate method
    void inflate(double dx, double dy);
    
    // Getter and setter methods
    void set(double left, double bottom, double right, double top);
    void get(double& left, double& bottom, double& right, double& top) const;
};

// Global function to create a rectangle from two others
Rectangle getBoundingRectangle(const Rectangle& r1, const Rectangle& r2);

#endif // RECTANGLE_H 