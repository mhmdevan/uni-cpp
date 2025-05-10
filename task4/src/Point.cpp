#include "../include/Point.h"
#include <iostream>
#include <iomanip>

// Default constructor
Point::Point() : x(0.0), y(0.0) {}

// Parameterized constructor
Point::Point(double x, double y) : x(x), y(y) {}

// Copy constructor
Point::Point(const Point& other) : x(other.x), y(other.y) {}

// Assignment operator
Point& Point::operator=(const Point& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

// Getter methods
double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

// Setter methods
void Point::setX(double x) {
    this->x = x;
}

void Point::setY(double y) {
    this->y = y;
}

void Point::setPoint(double x, double y) {
    this->x = x;
    this->y = y;
}

// Member operator overloads for +=
Point& Point::operator+=(const Point& other) {
    x += other.x;
    y += other.y;
    return *this;
}

Point& Point::operator+=(double value) {
    x += value;
    y += value;
    return *this;
}

// Member operator overload for binary +
Point Point::operator+(const Point& other) const {
    return Point(x + other.x, y + other.y);
}

Point Point::operator+(double value) const {
    return Point(x + value, y + value);
}

// Friend operator overloads for -=
Point& operator-=(Point& left, const Point& right) {
    left.x -= right.x;
    left.y -= right.y;
    return left;
}

Point& operator-=(Point& left, double value) {
    left.x -= value;
    left.y -= value;
    return left;
}

// Friend operator overloads for binary -
Point operator-(const Point& left, const Point& right) {
    return Point(left.x - right.x, left.y - right.y);
}

Point operator-(const Point& left, double value) {
    return Point(left.x - value, left.y - value);
}

Point operator-(double value, const Point& right) {
    return Point(value - right.x, value - right.y);
}

// Print method
void Point::print() const {
    std::cout << "Point(" << x << ", " << y << ")";
}

// Friend function for stream output
std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "Point(" << std::fixed << std::setprecision(2) 
       << point.x << ", " << point.y << ")";
    return os;
} 