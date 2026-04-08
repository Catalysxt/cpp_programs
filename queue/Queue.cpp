#include "Queue.h"
#include <cassert>

Queue::Queue() : m_size(0), m_firstCellptr(nullptr), m_lastCellptr(nullptr) { } // Constructor

void Queue::enter(int value) {
    Cell *newCellPtr = new Cell(value, nullptr); 

    if (empty()) {
        m_firstCellptr = m_lastCellptr = newCellPtr;
    }

    else {
        m_lastCellptr -> setNext(newCellPtr); // Extend the queue
        m_lastCellptr = newCellPtr; // A new cell has joined the queue
    }

    m_size++;
}

// Returns first value in the queue by examining the first cell
int Queue::first() {
    assert(!empty());
    return m_firstCellptr -> getValue();
}

void Queue::remove() {
    assert(!empty());
    Cell *deleteCellPtr = m_firstCellptr;
    m_firstCellptr = m_firstCellptr -> getNext(); // Update the first cell
    delete deleteCellPtr; // Delete the cell
    m_size--;
}

int Queue::size() const { return m_size; }

bool Queue::empty() const { return m_firstCellptr == nullptr; }