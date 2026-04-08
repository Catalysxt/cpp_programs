#include "Stack.h"
#include "Cell.h"

#include <cassert>
// For assert macro

Stack::Stack() : m_firstCellPtr(nullptr), m_size(0) {} // Empty stack

void Stack::push(int value) {
    m_firstCellPtr = new Cell(value, m_firstCellPtr); // Create a new cell
        // new dynamically allocates memory
    m_size++; // Extend the stack
}

int Stack::top() {
    assert(!empty()); // Check if stack is occupied
    return m_firstCellPtr->getValue();
}

void Stack::pop() {
    assert(!empty());
    Cell *deleteCellPtr = m_firstCellPtr; // Store the value
    m_firstCellPtr = m_firstCellPtr->getNext(); // Reshuffle the stack
    delete deleteCellPtr; // Delete it
    m_size--; // Decrement the size
}

int Stack::size() const { return m_size; }

bool Stack::empty() const { return (m_firstCellPtr == nullptr); }