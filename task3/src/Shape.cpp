#include "../include/Shape.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

// Helper function to convert Color enum to string
std::string colorToString(Color color) {
    switch (color) {
        case RED: return "Red";
        case GREEN: return "Green";
        case BLUE: return "Blue";
        default: return "Unknown";
    }
}

// Shape class implementation

// Constructors and destructor
Shape::Shape() : color(RED) {}

Shape::Shape(Color color) : color(color) {}

Shape::Shape(const Shape& other) : color(other.color) {}

Shape::~Shape() {}

// Getters and setters
Color Shape::getColor() const {
    return color;
}

void Shape::setColor(Color color) {
    this->color = color;
}

// Virtual methods
void Shape::describe() const {
    std::cout << "Shape: Base class" << std::endl;
    std::cout << "Color: " << colorToString(color) << std::endl;
}

// Rectangle class implementation

// Helper method to normalize coordinates
void Rectangle::normalize() {
    if (left > right) {
        std::swap(left, right);
    }
    if (bottom > top) {
        std::swap(bottom, top);
    }
}

// Constructors and destructor
Rectangle::Rectangle() : Shape(), left(0.0), bottom(0.0), right(1.0), top(1.0) {}

Rectangle::Rectangle(double left, double bottom, double right, double top, Color color)
    : Shape(color), left(left), bottom(bottom), right(right), top(top) {
    normalize();
}

Rectangle::Rectangle(const Rectangle& other)
    : Shape(other), left(other.left), bottom(other.bottom), right(other.right), top(other.top) {}

Rectangle::~Rectangle() {}

// Getters
double Rectangle::getLeft() const {
    return left;
}

double Rectangle::getBottom() const {
    return bottom;
}

double Rectangle::getRight() const {
    return right;
}

double Rectangle::getTop() const {
    return top;
}

double Rectangle::getWidth() const {
    return right - left;
}

double Rectangle::getHeight() const {
    return top - bottom;
}

double Rectangle::getCenterX() const {
    return (left + right) / 2.0;
}

double Rectangle::getCenterY() const {
    return (bottom + top) / 2.0;
}

double Rectangle::getDiagonal() const {
    double width = getWidth();
    double height = getHeight();
    return std::sqrt(width * width + height * height);
}

// Setters
void Rectangle::setLeft(double left) {
    this->left = left;
    normalize();
}

void Rectangle::setBottom(double bottom) {
    this->bottom = bottom;
    normalize();
}

void Rectangle::setRight(double right) {
    this->right = right;
    normalize();
}

void Rectangle::setTop(double top) {
    this->top = top;
    normalize();
}

void Rectangle::setDimensions(double left, double bottom, double right, double top) {
    this->left = left;
    this->bottom = bottom;
    this->right = right;
    this->top = top;
    normalize();
}

// Overridden virtual methods
double Rectangle::calculate_perimeter() const {
    return 2.0 * (getWidth() + getHeight());
}

double Rectangle::calculate_area() const {
    return getWidth() * getHeight();
}

void Rectangle::describe() const {
    std::cout << "Shape: Rectangle" << std::endl;
    std::cout << "Color: " << colorToString(color) << std::endl;
    std::cout << "Coordinates: [Left: " << left << ", Bottom: " << bottom
              << ", Right: " << right << ", Top: " << top << "]" << std::endl;
    std::cout << "Width: " << getWidth() << ", Height: " << getHeight() << std::endl;
}

void Rectangle::inflate(double amount) {
    left -= amount;
    bottom -= amount;
    right += amount;
    top += amount;
}

// Circle class implementation

// Constructors and destructor
Circle::Circle() : Shape(), centerX(0.0), centerY(0.0), radius(1.0) {}

Circle::Circle(double centerX, double centerY, double radius, Color color)
    : Shape(color), centerX(centerX), centerY(centerY), radius(radius) {
    // Ensure radius is positive
    if (radius < 0) {
        this->radius = -radius;
    }
}

// Special constructor from Rectangle
Circle::Circle(const Rectangle& rect) : Shape(rect.getColor()) {
    // Use the center of the rectangle as the center of the circle
    centerX = rect.getCenterX();
    centerY = rect.getCenterY();
    
    // Use half the diagonal of the rectangle as the radius
    radius = rect.getDiagonal() / 2.0;
}

Circle::Circle(const Circle& other)
    : Shape(other), centerX(other.centerX), centerY(other.centerY), radius(other.radius) {}

Circle::~Circle() {}

// Getters
double Circle::getCenterX() const {
    return centerX;
}

double Circle::getCenterY() const {
    return centerY;
}

double Circle::getRadius() const {
    return radius;
}

// Setters
void Circle::setCenterX(double x) {
    centerX = x;
}

void Circle::setCenterY(double y) {
    centerY = y;
}

void Circle::setRadius(double radius) {
    // Ensure radius is positive
    this->radius = (radius < 0) ? -radius : radius;
}

void Circle::setDimensions(double centerX, double centerY, double radius) {
    this->centerX = centerX;
    this->centerY = centerY;
    setRadius(radius);
}

// Overridden virtual methods
double Circle::calculate_perimeter() const {
    return 2.0 * M_PI * radius;
}

double Circle::calculate_area() const {
    return M_PI * radius * radius;
}

void Circle::describe() const {
    std::cout << "Shape: Circle" << std::endl;
    std::cout << "Color: " << colorToString(color) << std::endl;
    std::cout << "Center: (" << centerX << ", " << centerY << ")" << std::endl;
    std::cout << "Radius: " << radius << std::endl;
}

void Circle::inflate(double amount) {
    radius += amount;
    if (radius < 0) {
        radius = 0;
    }
} 