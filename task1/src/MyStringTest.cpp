#include "../include/MyString.h"
#include <iostream>

int main() {
    // Test default constructor
    MyString str1;
    std::cout << "Default constructor: \"" << str1.get_string() << "\"" << std::endl;
    
    // Test parameterized constructor
    MyString str2("Hello, World!");
    std::cout << "Parameterized constructor: \"" << str2.get_string() << "\"" << std::endl;
    
    // Test copy constructor
    MyString str3(str2);
    std::cout << "Copy constructor: \"" << str3.get_string() << "\"" << std::endl;
    
    // Test get_string method
    std::cout << "Using get_string: \"" << str2.get_string() << "\"" << std::endl;
    
    // Test set_string method
    std::cout << "Before set_string: \"" << str1.get_string() << "\"" << std::endl;
    str1.set_string("New string content");
    std::cout << "After set_string: \"" << str1.get_string() << "\"" << std::endl;
    
    // Test get_length method
    std::cout << "Length of \"" << str1.get_string() << "\": " << str1.get_length() << std::endl;
    
    // Test print method
    std::cout << "Print method output: ";
    str1.print();
    std::cout << std::endl;
    
    return 0;
} 