#include "../include/Vector.h"
#include <cmath>
#include <iostream>

// Constructors and destructor
Vector::Vector() : x(0.0), y(0.0), z(0.0) {}

Vector::Vector(double x, double y, double z) : x(x), y(y), z(z) {}

Vector::Vector(const Vector& other) : x(other.x), y(other.y), z(other.z) {}

Vector::~Vector() {}

// Input method
void Vector::input() {
    std::cout << "Enter x component: ";
    std::cin >> x;
    std::cout << "Enter y component: ";
    std::cin >> y;
    std::cout << "Enter z component: ";
    std::cin >> z;
}

// Public methods
void Vector::print() const {
    std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
}

double Vector::magnitude() const {
    return std::sqrt(x*x + y*y + z*z);
}

Vector Vector::unitVector() const {
    double mag = magnitude();
    if (mag > 0) {
        return Vector(x/mag, y/mag, z/mag);
    }
    return Vector();
}

// Vector operations
double Vector::dotProduct(const Vector& other) const {
    return x*other.x + y*other.y + z*other.z;
}

Vector Vector::crossProduct(const Vector& other) const {
    return Vector(
        y*other.z - z*other.y,
        z*other.x - x*other.z,
        x*other.y - y*other.x
    );
}

double Vector::angleBetween(const Vector& other) const {
    double magProduct = magnitude() * other.magnitude();
    if (magProduct > 0) {
        double cosTheta = dotProduct(other) / magProduct;
        // Clamp cosTheta to [-1, 1] to avoid numerical issues
        cosTheta = std::max(-1.0, std::min(1.0, cosTheta));
        return std::acos(cosTheta);
    }
    return 0.0;
}

double Vector::euclideanDistance(const Vector& other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    double dz = z - other.z;
    return std::sqrt(dx*dx + dy*dy + dz*dz);
}

double Vector::manhattanDistance(const Vector& other) const {
    return std::abs(x - other.x) + std::abs(y - other.y) + std::abs(z - other.z);
} 