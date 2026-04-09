#pragma once
#include "Cell.h"
#include "Iterator.h"
#include <iostream>

class LinkedList {
public:
    LinkedList();

    // Duplicate the list
    LinkedList(const LinkedList& list);
    void assign(const LinkedList& list);

    ~LinkedList(); // Deallocates memory assigned to the cells

    int size() const { return m_size; }
    bool empty() const { return m_size == 0; }

    bool find(double value, Iterator& findIterator);
    // Return true if the value is found. Sets the iterator to the position of value

    // Comparision of two lists
    bool equal(const LinkedList& list);
    bool notEqual(const LinkedList& list);

    // add methods
    // Adds a value/list to the END of the list
    void add(double value);
    void add(const LinkedList& list);

    // insert methods 
    // Inserts value/list with the position set by the iterator
    void insert(const Iterator& iteratorPos, double value);
    void insert(const Iterator& iteratorPos, const LinkedList& list);

    // Erase a value at a specific position
    void erase(const Iterator& erasePos);

    // Clear all values in the list
    void clear();

    void remove(const Iterator& firstPos, const Iterator& lastPos = Iterator(nullptr));
    // Removes the first iterator to the last iterator from the list

    // Return iterators at first and last values
    Iterator first() const { return Iterator(m_firstCellPtr); }
    Iterator last() const { return Iterator(m_lastCellPtr); }

    void read(std::istream& inStream);
    void write(std::ostream& outStream);

private:
    int m_size;
    Cell *m_firstCellPtr;
    Cell *m_lastCellPtr;
};