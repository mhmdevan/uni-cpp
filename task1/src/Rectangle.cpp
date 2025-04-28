#include "../include/Rectangle.h"
#include <iostream>
#include <algorithm>

// Private method to normalize boundaries
void Rectangle::normalize() {
    if (left > right) {
        std::swap(left, right);
    }
    if (bottom > top) {
        std::swap(bottom, top);
    }
}

// Default constructor
Rectangle::Rectangle() : left(0.0), bottom(0.0), right(1.0), top(1.0) {}

// Parameterized constructor
Rectangle::Rectangle(double left, double bottom, double right, double top)
    : left(left), bottom(bottom), right(right), top(top) {
    normalize();
}

// Copy constructor
Rectangle::Rectangle(const Rectangle& other)
    : left(other.left), bottom(other.bottom), right(other.right), top(other.top) {}

// Destructor
Rectangle::~Rectangle() {}

// Print method
void Rectangle::print() const {
    std::cout << "Rectangle: [Left: " << left << ", Bottom: " << bottom
              << ", Right: " << right << ", Top: " << top << "]"
              << " Width: " << (right - left) << ", Height: " << (top - bottom)
              << std::endl;
}

// Calculate perimeter
double Rectangle::perimeter() const {
    return 2 * ((right - left) + (top - bottom));
}

// Calculate area
double Rectangle::area() const {
    return (right - left) * (top - bottom);
}

// Inflate rectangle
void Rectangle::inflate(double dx, double dy) {
    left -= dx;
    right += dx;
    bottom -= dy;
    top += dy;
    
    // Make sure the rectangle is still valid after inflation
    normalize();
}

// Set rectangle boundaries
void Rectangle::set(double left, double bottom, double right, double top) {
    this->left = left;
    this->bottom = bottom;
    this->right = right;
    this->top = top;
    normalize();
}

// Get rectangle boundaries
void Rectangle::get(double& left, double& bottom, double& right, double& top) const {
    left = this->left;
    bottom = this->bottom;
    right = this->right;
    top = this->top;
}

// Global function to create a bounding rectangle from two rectangles
Rectangle getBoundingRectangle(const Rectangle& r1, const Rectangle& r2) {
    double left1, bottom1, right1, top1;
    double left2, bottom2, right2, top2;
    
    r1.get(left1, bottom1, right1, top1);
    r2.get(left2, bottom2, right2, top2);
    
    double newLeft = std::min(left1, left2);
    double newBottom = std::min(bottom1, bottom2);
    double newRight = std::max(right1, right2);
    double newTop = std::max(top1, top2);
    
    return Rectangle(newLeft, newBottom, newRight, newTop);
} 