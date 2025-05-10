#include "../include/BinaryTree.h"
#include "../include/LinkedList.h"
#include "../include/DoubleLinkedList.h"
#include <iostream>

void testBinaryTree() {
    std::cout << "\n=== Testing Binary Search Tree ===\n" << std::endl;
    
    BinaryTreeNS::BinaryTree bst;
    
    // Test insert
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    
    // Test print (should print in-order: 20 30 40 50 60 70 80)
    std::cout << "Tree contents (in-order): ";
    bst.print();
    
    // Test search
    std::cout << "Search for 40: " << (bst.search(40) ? "Found" : "Not found") << std::endl;
    std::cout << "Search for 55: " << (bst.search(55) ? "Found" : "Not found") << std::endl;
    
    // Test count
    std::cout << "Node count: " << bst.count() << std::endl;
    
    // Test sum
    std::cout << "Sum of values: " << bst.sum() << std::endl;
    
    // Test copy constructor
    BinaryTreeNS::BinaryTree bst2(bst);
    std::cout << "Copied tree contents: ";
    bst2.print();
    
    // Test assignment operator
    BinaryTreeNS::BinaryTree bst3;
    bst3 = bst;
    std::cout << "Assigned tree contents: ";
    bst3.print();
}

void testLinkedList() {
    std::cout << "\n=== Testing Linked List ===\n" << std::endl;
    
    LinkedListNS::LinkedList list;
    
    // Test insert
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);
    
    // Test print
    std::cout << "List contents: ";
    list.print();
    
    // Test search
    std::cout << "Search for 30: " << (list.search(30) ? "Found" : "Not found") << std::endl;
    std::cout << "Search for 35: " << (list.search(35) ? "Found" : "Not found") << std::endl;
    
    // Test edit
    std::cout << "Edit 30 to 35: " << (list.edit(30, 35) ? "Success" : "Failed") << std::endl;
    std::cout << "List after edit: ";
    list.print();
    
    // Test remove
    std::cout << "Remove 20: " << (list.remove(20) ? "Success" : "Failed") << std::endl;
    std::cout << "List after removal: ";
    list.print();
    
    // Test count
    std::cout << "Node count: " << list.count() << std::endl;
    
    // Test sum
    std::cout << "Sum of values: " << list.sum() << std::endl;
    
    // Test copy constructor
    LinkedListNS::LinkedList list2(list);
    std::cout << "Copied list contents: ";
    list2.print();
    
    // Test assignment operator
    LinkedListNS::LinkedList list3;
    list3 = list;
    std::cout << "Assigned list contents: ";
    list3.print();
}

void testDoubleLinkedList() {
    std::cout << "\n=== Testing Double Linked List ===\n" << std::endl;
    
    DoubleLinkedListNS::DoubleLinkedList list;
    
    // Test pushBack
    list.pushBack(DoubleLinkedListNS::Circle(1.0, 2.0, 3.0));  // Circle at (1,2) with radius 3
    list.pushBack(DoubleLinkedListNS::Circle(4.0, 5.0, 6.0));  // Circle at (4,5) with radius 6
    
    // Test pushFront
    list.pushFront(DoubleLinkedListNS::Circle(7.0, 8.0, 9.0)); // Circle at (7,8) with radius 9
    list.pushFront(DoubleLinkedListNS::Circle(10.0, 11.0, 12.0)); // Circle at (10,11) with radius 12
    
    // Test print
    std::cout << "List contents:" << std::endl;
    list.print();
    
    // Test search
    DoubleLinkedListNS::Circle searchCircle(4.0, 5.0, 6.0);
    std::cout << "Search for Circle(4,5,6): " << (list.search(searchCircle) ? "Found" : "Not found") << std::endl;
    
    DoubleLinkedListNS::Circle missingCircle(99.0, 99.0, 99.0);
    std::cout << "Search for Circle(99,99,99): " << (list.search(missingCircle) ? "Found" : "Not found") << std::endl;
    
    // Test update
    DoubleLinkedListNS::Circle newCircle(4.0, 5.0, 7.0); // Same center, different radius
    std::cout << "Update Circle(4,5,6) to Circle(4,5,7): " << (list.update(searchCircle, newCircle) ? "Success" : "Failed") << std::endl;
    std::cout << "List after update:" << std::endl;
    list.print();
    
    // Test remove
    std::cout << "Remove Circle(10,11,12): " << (list.remove(DoubleLinkedListNS::Circle(10.0, 11.0, 12.0)) ? "Success" : "Failed") << std::endl;
    std::cout << "List after removal:" << std::endl;
    list.print();
    
    // Test count
    std::cout << "Node count: " << list.count() << std::endl;
    
    // Test sum
    std::cout << "Sum of radii: " << list.sumRadii() << std::endl;
    
    // Test copy constructor
    DoubleLinkedListNS::DoubleLinkedList list2(list);
    std::cout << "Copied list contents:" << std::endl;
    list2.print();
    
    // Test assignment operator
    DoubleLinkedListNS::DoubleLinkedList list3;
    list3 = list;
    std::cout << "Assigned list contents:" << std::endl;
    list3.print();
}

int main() {
    std::cout << "===== Data Structures Implementation Testing =====" << std::endl;
    
    testBinaryTree();
    testLinkedList();
    testDoubleLinkedList();
    
    return 0;
} 