#include "../include/Data.h"
#include <iostream>
#include <iomanip>

// Default constructor
Data::Data() : position(""), age(0), gender(MALE), salary(0.0) {}

// Parameterized constructor
Data::Data(const MyString& position, int age, Gender gender, double salary)
    : position(position), age(age), gender(gender), salary(salary) {}

// Copy constructor
Data::Data(const Data& other)
    : position(other.position), age(other.age), gender(other.gender), salary(other.salary) {}

// Assignment operator
Data& Data::operator=(const Data& other) {
    if (this != &other) {
        position = other.position;
        age = other.age;
        gender = other.gender;
        salary = other.salary;
    }
    return *this;
}

// Getters
const MyString& Data::getPosition() const {
    return position;
}

int Data::getAge() const {
    return age;
}

Gender Data::getGender() const {
    return gender;
}

double Data::getSalary() const {
    return salary;
}

// Setters
void Data::setPosition(const MyString& position) {
    this->position = position;
}

void Data::setAge(int age) {
    this->age = age;
}

void Data::setGender(Gender gender) {
    this->gender = gender;
}

void Data::setSalary(double salary) {
    this->salary = salary;
}

// Utility method to convert Gender enum to string
const char* Data::genderToString(Gender gender) {
    switch (gender) {
        case MALE: return "Male";
        case FEMALE: return "Female";
        default: return "Unknown";
    }
}

// Print method
void Data::print() const {
    std::cout << "Position: " << position << ", "
              << "Age: " << age << ", "
              << "Gender: " << genderToString(gender) << ", "
              << "Salary: $" << std::fixed << std::setprecision(2) << salary;
}

// Friend function for stream output
std::ostream& operator<<(std::ostream& os, const Data& data) {
    os << "Position: " << data.position << ", "
       << "Age: " << data.age << ", "
       << "Gender: " << Data::genderToString(data.gender) << ", "
       << "Salary: $" << std::fixed << std::setprecision(2) << data.salary;
    return os;
} 