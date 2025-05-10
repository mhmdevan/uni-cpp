#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <cstring>

class MyString {
private:
    char* data;
    size_t length;

    void allocate_and_copy(const char* str);

public:
    // Constructors and destructor
    MyString();                       // Default constructor
    MyString(const char* str);        // Constructor from C-string
    MyString(const MyString& other);  // Copy constructor
    ~MyString();                      // Destructor

    // Assignment operators
    MyString& operator=(const MyString& other);
    MyString& operator=(const char* str);

    // Getters
    const char* c_str() const;
    size_t size() const;
    bool empty() const;

    // Comparison operators
    bool operator==(const MyString& other) const;
    bool operator!=(const MyString& other) const;
    bool operator<(const MyString& other) const;
    bool operator>(const MyString& other) const;
    bool operator<=(const MyString& other) const;
    bool operator>=(const MyString& other) const;

    // Stream operators
    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
    friend std::istream& operator>>(std::istream& is, MyString& str);
};

#endif // MYSTRING_H 