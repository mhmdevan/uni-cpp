#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

namespace DoubleLinkedListNS {

class Point {
private:
    double x;
    double y;
    
public:
    Point();
    Point(double x, double y);
    Point(const Point& other);
    
    double getX() const;
    double getY() const;
    
    void setX(double x);
    void setY(double y);
    
    // Copy assignment operator
    Point& operator=(const Point& other);
};

class Circle {
private:
    Point center;
    double radius;
    
public:
    Circle();
    Circle(const Point& center, double radius);
    Circle(double x, double y, double radius);
    Circle(const Circle& other);
    
    Point getCenter() const;
    double getRadius() const;
    
    void setCenter(const Point& center);
    void setRadius(double radius);
    
    // Copy assignment operator
    Circle& operator=(const Circle& other);
};

class Node {
private:
    Circle value;
    Node* prev;
    Node* next;
    
public:
    // Constructors
    Node();
    Node(const Circle& circle);
    Node(const Node& other);
    
    // Destructor
    ~Node();
    
    // Getters
    Circle getValue() const;
    Node* getPrev() const;
    Node* getNext() const;
    
    // Setters
    void setValue(const Circle& circle);
    void setPrev(Node* node);
    void setNext(Node* node);
    
    // Friend class declaration
    friend class DoubleLinkedList;
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;
    
public:
    // Constructors
    DoubleLinkedList();
    DoubleLinkedList(const Circle& circle);
    DoubleLinkedList(const DoubleLinkedList& other);
    
    // Destructor
    ~DoubleLinkedList();
    
    // Operations
    void pushFront(const Circle& circle);
    void pushBack(const Circle& circle);
    void print() const;
    bool search(const Circle& circle) const;
    bool update(const Circle& oldCircle, const Circle& newCircle);
    bool remove(const Circle& circle);
    int count() const;
    double sumRadii() const;
    
    // Assignment operator
    DoubleLinkedList& operator=(const DoubleLinkedList& other);
};

} // namespace DoubleLinkedListNS

#endif // DOUBLE_LINKED_LIST_H 