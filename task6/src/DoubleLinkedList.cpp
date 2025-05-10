#include "../include/DoubleLinkedList.h"
#include <iostream>
#include <cmath>

namespace DoubleLinkedListNS {

// Point implementations
Point::Point() : x(0.0), y(0.0) {}

Point::Point(double x, double y) : x(x), y(y) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

void Point::setX(double x) {
    this->x = x;
}

void Point::setY(double y) {
    this->y = y;
}

Point& Point::operator=(const Point& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

// Circle implementations
Circle::Circle() : center(), radius(0.0) {}

Circle::Circle(const Point& center, double radius) : center(center), radius(radius) {}

Circle::Circle(double x, double y, double radius) : center(x, y), radius(radius) {}

Circle::Circle(const Circle& other) : center(other.center), radius(other.radius) {}

Point Circle::getCenter() const {
    return center;
}

double Circle::getRadius() const {
    return radius;
}

void Circle::setCenter(const Point& center) {
    this->center = center;
}

void Circle::setRadius(double radius) {
    this->radius = radius;
}

Circle& Circle::operator=(const Circle& other) {
    if (this != &other) {
        center = other.center;
        radius = other.radius;
    }
    return *this;
}

// Helper function to compare circles (used in search and other operations)
bool circlesEqual(const Circle& c1, const Circle& c2) {
    return (c1.getCenter().getX() == c2.getCenter().getX() &&
            c1.getCenter().getY() == c2.getCenter().getY() &&
            c1.getRadius() == c2.getRadius());
}

// Node implementations
Node::Node() : value(), prev(nullptr), next(nullptr) {}

Node::Node(const Circle& circle) : value(circle), prev(nullptr), next(nullptr) {}

Node::Node(const Node& other) : value(other.value), prev(nullptr), next(nullptr) {}

Node::~Node() {}

Circle Node::getValue() const {
    return value;
}

Node* Node::getPrev() const {
    return prev;
}

Node* Node::getNext() const {
    return next;
}

void Node::setValue(const Circle& circle) {
    value = circle;
}

void Node::setPrev(Node* node) {
    prev = node;
}

void Node::setNext(Node* node) {
    next = node;
}

// DoubleLinkedList implementations
DoubleLinkedList::DoubleLinkedList() : head(nullptr), tail(nullptr) {}

DoubleLinkedList::DoubleLinkedList(const Circle& circle) {
    head = new Node(circle);
    tail = head;
}

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& other) : head(nullptr), tail(nullptr) {
    if (other.head == nullptr) {
        return;
    }
    
    // Copy first node
    head = new Node(other.head->value);
    tail = head;
    
    // Copy remaining nodes
    Node* otherCurrent = other.head->next;
    
    while (otherCurrent != nullptr) {
        Node* newNode = new Node(otherCurrent->value);
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        otherCurrent = otherCurrent->next;
    }
}

DoubleLinkedList::~DoubleLinkedList() {
    Node* current = head;
    Node* next;
    
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
    
    head = nullptr;
    tail = nullptr;
}

void DoubleLinkedList::pushFront(const Circle& circle) {
    Node* newNode = new Node(circle);
    
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }
    
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void DoubleLinkedList::pushBack(const Circle& circle) {
    Node* newNode = new Node(circle);
    
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }
    
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}

void DoubleLinkedList::print() const {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    
    Node* current = head;
    int index = 0;
    
    while (current != nullptr) {
        std::cout << "Circle " << index << ": Center(" 
                  << current->value.getCenter().getX() << ", " 
                  << current->value.getCenter().getY() << "), Radius: " 
                  << current->value.getRadius() << std::endl;
        
        current = current->next;
        index++;
    }
}

bool DoubleLinkedList::search(const Circle& circle) const {
    Node* current = head;
    
    while (current != nullptr) {
        if (circlesEqual(current->value, circle)) {
            return true;
        }
        current = current->next;
    }
    
    return false;
}

bool DoubleLinkedList::update(const Circle& oldCircle, const Circle& newCircle) {
    Node* current = head;
    
    while (current != nullptr) {
        if (circlesEqual(current->value, oldCircle)) {
            current->value = newCircle;
            return true;
        }
        current = current->next;
    }
    
    return false;
}

bool DoubleLinkedList::remove(const Circle& circle) {
    if (head == nullptr) {
        return false;
    }
    
    // If head is the node to remove
    if (circlesEqual(head->value, circle)) {
        Node* temp = head;
        
        if (head == tail) {
            // Only one node in list
            head = nullptr;
            tail = nullptr;
        } else {
            // More than one node in list
            head = head->next;
            head->prev = nullptr;
        }
        
        delete temp;
        return true;
    }
    
    // If tail is the node to remove
    if (circlesEqual(tail->value, circle)) {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        return true;
    }
    
    // Check interior nodes
    Node* current = head->next;
    
    while (current != tail) {
        if (circlesEqual(current->value, circle)) {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            return true;
        }
        current = current->next;
    }
    
    return false;
}

int DoubleLinkedList::count() const {
    int count = 0;
    Node* current = head;
    
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    
    return count;
}

double DoubleLinkedList::sumRadii() const {
    double sum = 0.0;
    Node* current = head;
    
    while (current != nullptr) {
        sum += current->value.getRadius();
        current = current->next;
    }
    
    return sum;
}

DoubleLinkedList& DoubleLinkedList::operator=(const DoubleLinkedList& other) {
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
        tail = nullptr;
        
        // Copy the other list
        if (other.head != nullptr) {
            // Copy first node
            head = new Node(other.head->value);
            tail = head;
            
            // Copy remaining nodes
            current = other.head->next;
            
            while (current != nullptr) {
                Node* newNode = new Node(current->value);
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
                current = current->next;
            }
        }
    }
    
    return *this;
}

} // namespace DoubleLinkedListNS 