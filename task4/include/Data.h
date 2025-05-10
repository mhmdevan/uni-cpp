#ifndef DATA_H
#define DATA_H

#include "MyString.h"
#include <iostream>

// Gender enumeration
enum Gender { MALE, FEMALE };

// Data class to store employee information
class Data {
private:
    MyString position;
    int age;
    Gender gender;
    double salary;

public:
    // Constructors
    Data();
    Data(const MyString& position, int age, Gender gender, double salary);
    Data(const Data& other);

    // Assignment operator
    Data& operator=(const Data& other);

    // Getters
    const MyString& getPosition() const;
    int getAge() const;
    Gender getGender() const;
    double getSalary() const;

    // Setters
    void setPosition(const MyString& position);
    void setAge(int age);
    void setGender(Gender gender);
    void setSalary(double salary);

    // Utility method to convert Gender enum to string
    static const char* genderToString(Gender gender);
    
    // Print method
    void print() const;
    
    // Friend function for stream output
    friend std::ostream& operator<<(std::ostream& os, const Data& data);
};

#endif // DATA_H 