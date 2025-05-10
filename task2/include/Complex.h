#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>
#include <vector>

class Complex {
private:
    double real;      // Real part 'a'
    double imaginary; // Imaginary part 'b'

public:
    // Constructors and destructor
    Complex();
    Complex(double real, double imaginary);
    Complex(const Complex& other);
    ~Complex();

    // Getters and setters
    double getReal() const;
    double getImaginary() const;
    void setReal(double real);
    void setImaginary(double imaginary);

    // Operations
    void print() const;         // Print in format a + bi
    double module() const;      // Calculate |z| = sqrt(a^2 + b^2)
    Complex inverse() const;    // Calculate z^(-1) = (a - bi) / (a^2 + b^2)

    // Complex number operations
    Complex add(const Complex& other) const;      // z1 + z2 = (a + c) + (b + d)i
    Complex subtract(const Complex& other) const; // z1 - z2 = (a - c) + (b - d)i
    Complex multiply(const Complex& other) const; // z1 * z2 = (ac - bd) + (ad + bc)i
    Complex divide(const Complex& other) const;   // z1 / z2 = (ac + bd)/(c^2 + d^2) + (bc - ad)/(c^2 + d^2)i
};

// Class to store a vector of complex numbers
class ComplexVector {
private:
    std::vector<Complex> elements;
    int size;

public:
    // Constructors and destructor
    ComplexVector();
    ComplexVector(int size);
    ComplexVector(const ComplexVector& other);
    ~ComplexVector();

    // Vector operations
    void setSize(int size);
    int getSize() const;
    void input();                         // Input all elements
    void print() const;                   // Print all elements
    Complex& at(int index);               // Get element at index
    const Complex& at(int index) const;   // Get element at index (const version)
    
    // Element-wise operations between two vectors
    ComplexVector addVector(const ComplexVector& other) const;
    ComplexVector subtractVector(const ComplexVector& other) const;
    ComplexVector multiplyVector(const ComplexVector& other) const;
    ComplexVector divideVector(const ComplexVector& other) const;
};

#endif // COMPLEX_H 