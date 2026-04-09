
#pragma once
#include "Cell.h"

class Iterator {
private:
    Iterator(Cell *CellPtr); // Since we pass in a pointer to cell object, Iterator gets access to Cell's methods
    friend class LinkedList; 
    
public:
    Iterator();
    Iterator(const Iterator& iterator); // Pass by reference

    double getValue() {return m_CellPtr -> getValue(); }
    void setValue(double value) { m_CellPtr -> setValue(value); }

    bool hasNext() const { return m_CellPtr != nullptr; } // True if we're not at the end of the list
    bool hasPrevious() const { return m_CellPtr != nullptr; } // True if we're not at the beginning of the list

    void next() { m_CellPtr = m_CellPtr -> getNext();} // Increment the iterator
    void previous() {m_CellPtr = m_CellPtr -> getPrevious();}

private:
    Cell *m_CellPtr;
};