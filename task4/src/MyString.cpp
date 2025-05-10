#include "../include/MyString.h"
#include <cstring>
#include <iostream>

// Private helper method
void MyString::allocate_and_copy(const char* str) {
    if (str) {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    } else {
        length = 0;
        data = new char[1];
        data[0] = '\0';
    }
}

// Default constructor
MyString::MyString() : data(nullptr), length(0) {
    data = new char[1];
    data[0] = '\0';
}

// Constructor from C-string
MyString::MyString(const char* str) : data(nullptr), length(0) {
    allocate_and_copy(str);
}

// Copy constructor
MyString::MyString(const MyString& other) : data(nullptr), length(0) {
    allocate_and_copy(other.data);
}

// Destructor
MyString::~MyString() {
    delete[] data;
}

// Assignment operator from MyString
MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] data;
        allocate_and_copy(other.data);
    }
    return *this;
}

// Assignment operator from C-string
MyString& MyString::operator=(const char* str) {
    if (data != str) {
        delete[] data;
        allocate_and_copy(str);
    }
    return *this;
}

// Getters
const char* MyString::c_str() const {
    return data;
}

size_t MyString::size() const {
    return length;
}

bool MyString::empty() const {
    return length == 0;
}

// Comparison operators
bool MyString::operator==(const MyString& other) const {
    return strcmp(data, other.data) == 0;
}

bool MyString::operator!=(const MyString& other) const {
    return !(*this == other);
}

bool MyString::operator<(const MyString& other) const {
    return strcmp(data, other.data) < 0;
}

bool MyString::operator>(const MyString& other) const {
    return strcmp(data, other.data) > 0;
}

bool MyString::operator<=(const MyString& other) const {
    return (*this < other) || (*this == other);
}

bool MyString::operator>=(const MyString& other) const {
    return (*this > other) || (*this == other);
}

// Stream operators
std::ostream& operator<<(std::ostream& os, const MyString& str) {
    os << str.data;
    return os;
}

std::istream& operator>>(std::istream& is, MyString& str) {
    char buffer[1024];
    is >> buffer;
    str = buffer;
    return is;
} 