#include "../include/Complex.h"
#include <iostream>
#include <cmath>
#include <iomanip>

// Complex class implementation

// Constructors and destructor
Complex::Complex() : real(0.0), imaginary(0.0) {}

Complex::Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

Complex::Complex(const Complex& other) : real(other.real), imaginary(other.imaginary) {}

Complex::~Complex() {}

// Getters and setters
double Complex::getReal() const {
    return real;
}

double Complex::getImaginary() const {
    return imaginary;
}

void Complex::setReal(double real) {
    this->real = real;
}

void Complex::setImaginary(double imaginary) {
    this->imaginary = imaginary;
}

// Operations
void Complex::print() const {
    if (imaginary >= 0) {
        std::cout << real << " + " << imaginary << "i";
    } else {
        std::cout << real << " - " << std::abs(imaginary) << "i";
    }
}

double Complex::module() const {
    return std::sqrt(real * real + imaginary * imaginary);
}

Complex Complex::inverse() const {
    double denominator = real * real + imaginary * imaginary;
    if (denominator == 0) {
        std::cerr << "Error: Division by zero in inverse operation." << std::endl;
        return Complex();
    }
    
    return Complex(real / denominator, -imaginary / denominator);
}

// Complex number operations
Complex Complex::add(const Complex& other) const {
    return Complex(real + other.real, imaginary + other.imaginary);
}

Complex Complex::subtract(const Complex& other) const {
    return Complex(real - other.real, imaginary - other.imaginary);
}

Complex Complex::multiply(const Complex& other) const {
    // (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
    double resultReal = real * other.real - imaginary * other.imaginary;
    double resultImaginary = real * other.imaginary + imaginary * other.real;
    return Complex(resultReal, resultImaginary);
}

Complex Complex::divide(const Complex& other) const {
    // (a + bi) / (c + di) = (ac + bd)/(c^2 + d^2) + (bc - ad)/(c^2 + d^2)i
    double denominator = other.real * other.real + other.imaginary * other.imaginary;
    if (denominator == 0) {
        std::cerr << "Error: Division by zero." << std::endl;
        return Complex();
    }
    
    double resultReal = (real * other.real + imaginary * other.imaginary) / denominator;
    double resultImaginary = (imaginary * other.real - real * other.imaginary) / denominator;
    return Complex(resultReal, resultImaginary);
}

// ComplexVector class implementation

// Constructors and destructor
ComplexVector::ComplexVector() : size(0) {}

ComplexVector::ComplexVector(int size) : size(size) {
    elements.resize(size);
}

ComplexVector::ComplexVector(const ComplexVector& other) : elements(other.elements), size(other.size) {}

ComplexVector::~ComplexVector() {}

// Vector operations
void ComplexVector::setSize(int size) {
    this->size = size;
    elements.resize(size);
}

int ComplexVector::getSize() const {
    return size;
}

void ComplexVector::input() {
    for (int i = 0; i < size; i++) {
        double real, imaginary;
        std::cout << "Enter real part for element " << i << ": ";
        std::cin >> real;
        std::cout << "Enter imaginary part for element " << i << ": ";
        std::cin >> imaginary;
        elements[i] = Complex(real, imaginary);
    }
}

void ComplexVector::print() const {
    for (int i = 0; i < size; i++) {
        std::cout << "Element " << i << ": ";
        elements[i].print();
        std::cout << std::endl;
    }
}

Complex& ComplexVector::at(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return elements[index];
}

const Complex& ComplexVector::at(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return elements[index];
}

// Element-wise operations between two vectors
ComplexVector ComplexVector::addVector(const ComplexVector& other) const {
    int resultSize = std::min(size, other.size);
    ComplexVector result(resultSize);
    
    for (int i = 0; i < resultSize; i++) {
        result.elements[i] = elements[i].add(other.elements[i]);
    }
    
    return result;
}

ComplexVector ComplexVector::subtractVector(const ComplexVector& other) const {
    int resultSize = std::min(size, other.size);
    ComplexVector result(resultSize);
    
    for (int i = 0; i < resultSize; i++) {
        result.elements[i] = elements[i].subtract(other.elements[i]);
    }
    
    return result;
}

ComplexVector ComplexVector::multiplyVector(const ComplexVector& other) const {
    int resultSize = std::min(size, other.size);
    ComplexVector result(resultSize);
    
    for (int i = 0; i < resultSize; i++) {
        result.elements[i] = elements[i].multiply(other.elements[i]);
    }
    
    return result;
}

ComplexVector ComplexVector::divideVector(const ComplexVector& other) const {
    int resultSize = std::min(size, other.size);
    ComplexVector result(resultSize);
    
    for (int i = 0; i < resultSize; i++) {
        result.elements[i] = elements[i].divide(other.elements[i]);
    }
    
    return result;
} 