#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "MyString.h"
#include "Data.h"
#include <vector>

// Dictionary entry structure - a key-value pair
struct Entry {
    MyString key;  // Surname
    Data value;    // Employee data
    
    Entry(const MyString& key, const Data& value);
    Entry(const Entry& other);
    Entry& operator=(const Entry& other);
};

// Dictionary class to store and manage key-value pairs
class Dictionary {
private:
    std::vector<Entry> entries;
    
    // Helper method to find an entry by key
    int findEntryIndex(const MyString& key) const;

public:
    // Constructors and destructor
    Dictionary();
    Dictionary(const Dictionary& other);
    ~Dictionary();
    
    // Dictionary operations
    bool insert(const MyString& key, const Data& value);
    bool remove(const MyString& key);
    bool contains(const MyString& key) const;
    
    // Getters
    size_t size() const;
    bool empty() const;
    Data* getValue(const MyString& key);
    const Data* getValue(const MyString& key) const;
    
    // Access methods
    Data& operator[](const MyString& key);
    const Data& operator[](const MyString& key) const;
    
    // Output methods
    void print() const;
    void printKeys() const;
    
    // Clear the dictionary
    void clear();
};

#endif // DICTIONARY_H 