#include "../include/Dictionary.h"
#include <iostream>
#include <stdexcept>

// Entry struct implementations
Entry::Entry(const MyString& key, const Data& value) : key(key), value(value) {}

Entry::Entry(const Entry& other) : key(other.key), value(other.value) {}

Entry& Entry::operator=(const Entry& other) {
    if (this != &other) {
        key = other.key;
        value = other.value;
    }
    return *this;
}

// Dictionary class implementations

// Constructor and destructor
Dictionary::Dictionary() {}

Dictionary::Dictionary(const Dictionary& other) : entries(other.entries) {}

Dictionary::~Dictionary() {}

// Helper method to find an entry index
int Dictionary::findEntryIndex(const MyString& key) const {
    for (size_t i = 0; i < entries.size(); ++i) {
        if (entries[i].key == key) {
            return static_cast<int>(i);
        }
    }
    return -1; // Not found
}

// Dictionary operations
bool Dictionary::insert(const MyString& key, const Data& value) {
    int index = findEntryIndex(key);
    if (index >= 0) {
        // Key already exists, update value
        entries[index].value = value;
        return false; // Not a new insertion
    } else {
        // New key, add entry
        entries.push_back(Entry(key, value));
        return true;
    }
}

bool Dictionary::remove(const MyString& key) {
    int index = findEntryIndex(key);
    if (index >= 0) {
        // Found the key, remove entry
        entries.erase(entries.begin() + index);
        return true;
    }
    return false; // Key not found
}

bool Dictionary::contains(const MyString& key) const {
    return findEntryIndex(key) >= 0;
}

// Getters
size_t Dictionary::size() const {
    return entries.size();
}

bool Dictionary::empty() const {
    return entries.empty();
}

Data* Dictionary::getValue(const MyString& key) {
    int index = findEntryIndex(key);
    if (index >= 0) {
        return &entries[index].value;
    }
    return nullptr;
}

const Data* Dictionary::getValue(const MyString& key) const {
    int index = findEntryIndex(key);
    if (index >= 0) {
        return &entries[index].value;
    }
    return nullptr;
}

// Access methods
Data& Dictionary::operator[](const MyString& key) {
    int index = findEntryIndex(key);
    if (index >= 0) {
        return entries[index].value;
    } else {
        // Key not found, insert new entry with default Data
        insert(key, Data());
        return entries[entries.size() - 1].value;
    }
}

const Data& Dictionary::operator[](const MyString& key) const {
    int index = findEntryIndex(key);
    if (index >= 0) {
        return entries[index].value;
    }
    throw std::out_of_range("Key not found in dictionary");
}

// Output methods
void Dictionary::print() const {
    std::cout << "Dictionary Contents (" << entries.size() << " entries):" << std::endl;
    for (size_t i = 0; i < entries.size(); ++i) {
        std::cout << "Key: " << entries[i].key << std::endl;
        std::cout << "Value: " << entries[i].value << std::endl;
        std::cout << "------------------------" << std::endl;
    }
}

void Dictionary::printKeys() const {
    std::cout << "Dictionary Keys (" << entries.size() << " entries):" << std::endl;
    for (size_t i = 0; i < entries.size(); ++i) {
        std::cout << i+1 << ". " << entries[i].key << std::endl;
    }
}

// Clear the dictionary
void Dictionary::clear() {
    entries.clear();
} 