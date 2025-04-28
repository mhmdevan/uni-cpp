#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>

class Vector {
private:
    double x;
    double y;
    double z;

public:
    // Constructors and destructor
    Vector();
    Vector(double x, double y, double z);
    Vector(const Vector& other);
    ~Vector();

    // Input method
    void input();

    // Public methods
    void print() const;
    double magnitude() const;
    Vector unitVector() const;

    // Vector operations
    double dotProduct(const Vector& other) const;
    Vector crossProduct(const Vector& other) const;
    double angleBetween(const Vector& other) const;
    double euclideanDistance(const Vector& other) const;
    double manhattanDistance(const Vector& other) const;

    // Getters
    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }

    // Setters
    void setX(double value) { x = value; }
    void setY(double value) { y = value; }
    void setZ(double value) { z = value; }
};

#endif // VECTOR_H 