#include "../include/MyString.h"
#include <iostream>
#include <vector>

int main() {
    // [1] Create a vector of MyString objects initialized with constructor
    std::cout << "=== Vector of MyString objects ===\n";
    std::vector<MyString> stringVector;
    
    // Initialize with different constructors
    stringVector.push_back(MyString()); // Default constructor
    stringVector.push_back(MyString("Hello")); // Parameterized constructor
    stringVector.push_back(MyString("World")); // Parameterized constructor
    stringVector.push_back(MyString("C++")); // Parameterized constructor
    stringVector.push_back(MyString("Programming")); // Parameterized constructor
    
    // Print each element of the vector
    for (size_t i = 0; i < stringVector.size(); i++) {
        std::cout << "Vector element " << i << ": ";
        stringVector[i].print();
        std::cout << std::endl;
    }
    
    // [2] Create an array of 5 pointers to MyString objects
    std::cout << "\n=== Array of MyString pointers ===\n";
    MyString* stringPtrArray[5];
    
    // Initialize the pointers
    stringPtrArray[0] = new MyString();
    stringPtrArray[1] = new MyString("First");
    stringPtrArray[2] = new MyString("Second");
    stringPtrArray[3] = new MyString("Third");
    stringPtrArray[4] = new MyString("Fourth");
    
    // Print each element from the pointer array
    for (int i = 0; i < 5; i++) {
        std::cout << "Pointer array element " << i << ": ";
        stringPtrArray[i]->print();
        std::cout << std::endl;
    }
    
    // [3] Test the concatenation function
    std::cout << "\n=== String Concatenation ===\n";
    
    // Get the raw C strings from our MyString objects
    const char* str1 = "Hello, ";
    const char* str2 = "World! ";
    const char* str3 = "This ";
    const char* str4 = "is ";
    const char* str5 = "concatenation.";
    
    // Concatenate multiple strings
    MyString concatenated = concatenateStrings(5, str1, str2, str3, str4, str5);
    
    std::cout << "Concatenated string: ";
    concatenated.print();
    std::cout << std::endl;
    
    // Clean up dynamically allocated memory
    for (int i = 0; i < 5; i++) {
        delete stringPtrArray[i];
    }
    
    return 0;
} 