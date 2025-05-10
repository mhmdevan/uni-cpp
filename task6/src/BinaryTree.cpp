#include "../include/BinaryTree.h"
#include <iostream>

namespace BinaryTreeNS {

// Node implementations
Node::Node() : value(0), left(nullptr), right(nullptr) {}

Node::Node(int val) : value(val), left(nullptr), right(nullptr) {}

Node::Node(const Node& other) : value(other.value), left(nullptr), right(nullptr) {}

Node::~Node() {}

int Node::getValue() const {
    return value;
}

Node* Node::getLeft() const {
    return left;
}

Node* Node::getRight() const {
    return right;
}

void Node::setValue(int val) {
    value = val;
}

void Node::setLeft(Node* node) {
    left = node;
}

void Node::setRight(Node* node) {
    right = node;
}

// BinaryTree implementations
BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::BinaryTree(int rootValue) {
    root = new Node(rootValue);
}

BinaryTree::BinaryTree(const BinaryTree& other) {
    root = copyTree(other.root);
}

BinaryTree::~BinaryTree() {
    destroyTree(root);
}

Node* BinaryTree::copyTree(const Node* node) {
    if (node == nullptr) {
        return nullptr;
    }
    
    Node* newNode = new Node(node->value);
    newNode->left = copyTree(node->left);
    newNode->right = copyTree(node->right);
    
    return newNode;
}

void BinaryTree::destroyTree(Node* node) {
    if (node == nullptr) {
        return;
    }
    
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}

void BinaryTree::insert(int value) {
    if (root == nullptr) {
        root = new Node(value);
        return;
    }
    
    Node* current = root;
    Node* parent = nullptr;
    
    while (current != nullptr) {
        parent = current;
        
        if (value <= current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    
    if (value <= parent->value) {
        parent->left = new Node(value);
    } else {
        parent->right = new Node(value);
    }
}

bool BinaryTree::search(int value) const {
    Node* current = root;
    
    while (current != nullptr) {
        if (value == current->value) {
            return true;
        } else if (value < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    
    return false;
}

void BinaryTree::printInOrder(Node* node) const {
    if (node == nullptr) {
        return;
    }
    
    printInOrder(node->left);
    std::cout << node->value << " ";
    printInOrder(node->right);
}

void BinaryTree::print() const {
    if (root == nullptr) {
        std::cout << "Tree is empty" << std::endl;
        return;
    }
    
    printInOrder(root);
    std::cout << std::endl;
}

int BinaryTree::countNodes(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    
    return 1 + countNodes(node->left) + countNodes(node->right);
}

int BinaryTree::count() const {
    return countNodes(root);
}

int BinaryTree::sumValues(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    
    return node->value + sumValues(node->left) + sumValues(node->right);
}

int BinaryTree::sum() const {
    return sumValues(root);
}

BinaryTree& BinaryTree::operator=(const BinaryTree& other) {
    if (this != &other) {
        destroyTree(root);
        root = copyTree(other.root);
    }
    return *this;
}

} // namespace BinaryTreeNS 