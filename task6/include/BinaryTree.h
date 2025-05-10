#ifndef BINARY_TREE_H
#define BINARY_TREE_H

namespace BinaryTreeNS {

class Node {
private:
    int value;
    Node* left;
    Node* right;

public:
    // Constructors
    Node();
    Node(int val);
    Node(const Node& other);
    
    // Destructor
    ~Node();
    
    // Getters
    int getValue() const;
    Node* getLeft() const;
    Node* getRight() const;
    
    // Setters
    void setValue(int val);
    void setLeft(Node* node);
    void setRight(Node* node);
    
    // Friend class declaration
    friend class BinaryTree;
};

class BinaryTree {
private:
    Node* root;
    
    // Helper functions
    void destroyTree(Node* node);
    Node* copyTree(const Node* node);
    void printInOrder(Node* node) const;
    int countNodes(Node* node) const;
    int sumValues(Node* node) const;
    
public:
    // Constructors
    BinaryTree();
    BinaryTree(int rootValue);
    BinaryTree(const BinaryTree& other);
    
    // Destructor
    ~BinaryTree();
    
    // Operations
    void insert(int value);
    bool search(int value) const;
    void print() const;
    int count() const;
    int sum() const;
    
    // Assignment operator
    BinaryTree& operator=(const BinaryTree& other);
};

} // namespace BinaryTreeNS

#endif // BINARY_TREE_H 