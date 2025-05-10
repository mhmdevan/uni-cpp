#include "../include/MyString.h"
#include <cstring>
#include <iostream>
#include <stdarg.h>

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

// Global function for concatenating any number of string pointers
MyString concatenateStrings(int count, ...) {
    // Initialize the result string
    char* result = new char[1];
    result[0] = '\0';
    size_t totalLength = 0;
    
    // Start variable arguments
    va_list args;
    va_start(args, count);
    
    // First pass: calculate total length
    va_list args_copy;
    va_copy(args_copy, args);
    
    for (int i = 0; i < count; i++) {
        const char* str = va_arg(args_copy, const char*);
        if (str) {
            totalLength += strlen(str);
        }
    }
    
    va_end(args_copy);
    
    // Allocate memory for the concatenated string
    delete[] result;
    result = new char[totalLength + 1];
    result[0] = '\0';
    
    // Second pass: concatenate strings
    for (int i = 0; i < count; i++) {
        const char* str = va_arg(args, const char*);
        if (str) {
            strcat(result, str);
        }
    }
    
    va_end(args);
    
    // Create and return a MyString object
    MyString concatenated(result);
    delete[] result;
    
    return concatenated;
} 