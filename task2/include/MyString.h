#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <cstring>
#include <vector>
#include <stdarg.h>

class MyString {
private:
    char* str;
    int length;

public:
    // Constructors and destructor
    MyString();
    MyString(const char* s);
    MyString(const MyString& other);
    ~MyString();

    // Getters and setters
    char* get_string() const;
    void set_string(const char* s);

    // Other methods
    int get_length() const;
    void print() const;
};

// Global function for concatenating any number of string pointers
MyString concatenateStrings(int count, ...);

#endif // MYSTRING_H 