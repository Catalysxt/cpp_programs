#include <iostream>
#include "Cell.h"
#include "Iterator.h"
#include "Linkedlist.h"

//******************************************************************************
// Linked List
//
// Description: This is an implementation of a doubly linked list with manual
// heap allocation, node linking, and a lightweight iterator type for forward
// and backward traversal. It contains various methods to interact with the
// data structure

//  Ahmad Sarraj
//  Mar 2025
//******************************************************************************

int main() {

    LinkedList list;
    for (int i = 0; i <= 10; i++) { list.add(i); }

    list.write(std::cout); // std::cout is an ostream object
    std::cout << '\n';

    { // Iterate forwards
        Iterator iterator = list.first();
        while (iterator.hasNext()) {
            std::cout << iterator.getValue() << " ";
            iterator.next();
        }
        std::cout << '\n';
    }

    { // Iterate backwards
        Iterator iterator = list.last();
        while (iterator.hasPrevious()) {
            std::cout << iterator.getValue() << " ";
            iterator.previous();
        }
        std::cout << '\n';
    }


    // --- size() and empty() ---
    std::cout << "Size: " << list.size() << "\n";
    std::cout << "Empty? " << (list.empty() ? "yes" : "no") << "\n\n";

    // --- find() ---
    Iterator found;
    if (list.find(5.0, found)) {
        std::cout << "Found value: " << found.getValue() << "\n";
    } else {
        std::cout << "Value 5 not found\n";
    }

    // --- Copy constructor ---
    // Creates a completely independent copy of the list
    LinkedList copyList(list);
    std::cout << "Copy of list: ";
    copyList.write(std::cout);
    std::cout << "\n";

    // --- equal() and notEqual() ---
    // Compare two lists: same size AND same values means equal
    std::cout << "list == copyList? " << (list.equal(copyList) ? "yes" : "no") << "\n";
    copyList.add(42.0); // Make the copy different`
    std::cout << "list != copyList? " << (list.notEqual(copyList) ? "yes" : "no") << "\n\n";

    // --- add(list) ---
    // Append the contents of one list onto another
    LinkedList extras;
    extras.add(100.0);
    extras.add(200.0);
    std::cout << "Extras: ";
    extras.write(std::cout);
    std::cout << "\n";

    list.add(extras); // Appends extras to the end of list
    std::cout << "After adding extras: ";
    list.write(std::cout);
    std::cout << "\n\n";

    // --- insert(iterator, value) ---
    // Insert a single value before the position pointed to by the iterator
    Iterator insertPos = list.first();
    insertPos.next(); // Move to second element
    list.insert(insertPos, 999.0); // Insert 999 before the second element
    std::cout << "After inserting 999 at position 1: ";
    list.write(std::cout);
    std::cout << "\n";

    // --- insert(iterator, list) ---
    // Insert an entire list before the position pointed to by the iterator
    LinkedList toInsert;
    toInsert.add(77.0);
    toInsert.add(88.0);
    Iterator insertPos2 = list.first();
    list.insert(insertPos2, toInsert); // Insert before the first element
    std::cout << "After inserting [77, 88] at the front: ";
    list.write(std::cout);
    std::cout << "\n\n";

    // --- erase(iterator) ---
    // Remove a single element at the given position
    Iterator erasePos = list.first();
    std::cout << "Erasing first element (" << erasePos.getValue() << "): ";
    list.erase(erasePos);
    list.write(std::cout);
    std::cout << "\n\n";

}

// [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
// 0 1 2 3 4 5 6 7 8 9 10 
// 10 9 8 7 6 5 4 3 2 1 0 

// Size: 11
// Empty? no

// Found value: 5
// Copy of list: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
// list == copyList? no
// list != copyList? yes

// Extras: [100, 200]
// After adding extras: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 100, 200]

// After inserting 999 at position 1: [0, 999, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 100, 200]
// After inserting [77, 88] at the front: [77, 88, 0, 999, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 100, 200]

// Erasing first element (77): [88, 0, 999, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 100, 200]
