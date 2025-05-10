#include "../include/LinkedList.h"
#include <iostream>

namespace LinkedListNS {

// Node implementations
Node::Node() : value(0), next(nullptr) {}

Node::Node(int val) : value(val), next(nullptr) {}

Node::Node(const Node& other) : value(other.value), next(nullptr) {}

Node::~Node() {}

int Node::getValue() const {
    return value;
}

Node* Node::getNext() const {
    return next;
}

void Node::setValue(int val) {
    value = val;
}

void Node::setNext(Node* node) {
    next = node;
}

// LinkedList implementations
LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(int value) {
    head = new Node(value);
}

LinkedList::LinkedList(const LinkedList& other) : head(nullptr) {
    if (other.head == nullptr) {
        return;
    }
    
    // Copy first node
    head = new Node(other.head->value);
    
    // Copy remaining nodes
    Node* current = head;
    Node* otherCurrent = other.head->next;
    
    while (otherCurrent != nullptr) {
        current->next = new Node(otherCurrent->value);
        current = current->next;
        otherCurrent = otherCurrent->next;
    }
}

LinkedList::~LinkedList() {
    Node* current = head;
    Node* next;
    
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
    
    head = nullptr;
}

void LinkedList::insert(int value) {
    Node* newNode = new Node(value);
    
    if (head == nullptr) {
        head = newNode;
        return;
    }
    
    // Add to end of list
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    
    current->next = newNode;
}

bool LinkedList::search(int value) const {
    Node* current = head;
    
    while (current != nullptr) {
        if (current->value == value) {
            return true;
        }
        current = current->next;
    }
    
    return false;
}

bool LinkedList::edit(int oldValue, int newValue) {
    Node* current = head;
    
    while (current != nullptr) {
        if (current->value == oldValue) {
            current->value = newValue;
            return true;
        }
        current = current->next;
    }
    
    return false;
}

bool LinkedList::remove(int value) {
    if (head == nullptr) {
        return false;
    }
    
    // If head is the node to remove
    if (head->value == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }
    
    // Search for the node to remove
    Node* current = head;
    while (current->next != nullptr && current->next->value != value) {
        current = current->next;
    }
    
    // If the node was found
    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        return true;
    }
    
    return false;
}

int LinkedList::count() const {
    int count = 0;
    Node* current = head;
    
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    
    return count;
}

int LinkedList::sum() const {
    int sum = 0;
    Node* current = head;
    
    while (current != nullptr) {
        sum += current->value;
        current = current->next;
    }
    
    return sum;
}

void LinkedList::print() const {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->value;
        if (current->next != nullptr) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

LinkedList& LinkedList::operator=(const LinkedList& other) {
    if (this != &other) {
        // Clean up existing list
        Node* current = head;
        Node* next;
        
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        
        head = nullptr;
        
        // Copy the other list
        if (other.head != nullptr) {
            // Copy first node
            head = new Node(other.head->value);
            
            // Copy remaining nodes
            current = head;
            Node* otherCurrent = other.head->next;
            
            while (otherCurrent != nullptr) {
                current->next = new Node(otherCurrent->value);
                current = current->next;
                otherCurrent = otherCurrent->next;
            }
        }
    }
    
    return *this;
}

} // namespace LinkedListNS 