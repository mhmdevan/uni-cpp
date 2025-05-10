#ifndef LINKED_LIST_H
#define LINKED_LIST_H

namespace LinkedListNS {

class Node {
private:
    int value;
    Node* next;
    
public:
    // Constructors
    Node();
    Node(int val);
    Node(const Node& other);
    
    // Destructor
    ~Node();
    
    // Getters
    int getValue() const;
    Node* getNext() const;
    
    // Setters
    void setValue(int val);
    void setNext(Node* node);
    
    // Friend class declaration
    friend class LinkedList;
};

class LinkedList {
private:
    Node* head;
    
public:
    // Constructors
    LinkedList();
    LinkedList(int value);
    LinkedList(const LinkedList& other);
    
    // Destructor
    ~LinkedList();
    
    // Operations
    void insert(int value);
    bool search(int value) const;
    bool edit(int oldValue, int newValue);
    bool remove(int value);
    int count() const;
    int sum() const;
    void print() const;
    
    // Assignment operator
    LinkedList& operator=(const LinkedList& other);
};

} // namespace LinkedListNS

#endif // LINKED_LIST_H 