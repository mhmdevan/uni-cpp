#include "../include/MyString.h"
#include <cstring>
#include <iostream>

// Default constructor
MyString::MyString() : str(nullptr), length(0) {
    str = new char[1];
    str[0] = '\0';
}

// Parameterized constructor
MyString::MyString(const char* s) : str(nullptr), length(0) {
    if (s == nullptr) {
        str = new char[1];
        str[0] = '\0';
    } else {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }
}

// Copy constructor
MyString::MyString(const MyString& other) : str(nullptr), length(other.length) {
    str = new char[length + 1];
    strcpy(str, other.str);
}

// Destructor
MyString::~MyString() {
    delete[] str;
}

// Getter for string
char* MyString::get_string() const {
    return str;
}

// Setter for string
void MyString::set_string(const char* s) {
    if (str) {
        delete[] str;
    }
    
    if (s == nullptr) {
        length = 0;
        str = new char[1];
        str[0] = '\0';
    } else {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }
}

// Get length of string
int MyString::get_length() const {
    return length;
}

// Print the string
void MyString::print() const {
    std::cout << str;
} 