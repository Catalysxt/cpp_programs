#include "Linkedlist.h"
#include "Cell.h"
#include "Iterator.h"

#include <iostream>

LinkedList::LinkedList() : m_size(0), m_firstCellPtr(nullptr), m_lastCellPtr(nullptr) {}

LinkedList::~LinkedList() { clear(); }
// Clear the contents of the list

LinkedList::LinkedList(const LinkedList& list) { assign(list); }

// Copy the list
void LinkedList::assign(const LinkedList& list) {
    m_size = 0;
    m_firstCellPtr = nullptr;
    m_lastCellPtr = nullptr;
    Cell *listCellPtr = list.m_firstCellPtr;
    add(list);
}

void LinkedList::clear() {
    Cell *currentCellPtr = m_firstCellPtr;
    while (currentCellPtr != nullptr) {
        Cell *deleteCellPtr = currentCellPtr;
        currentCellPtr = currentCellPtr -> getNext();
        delete deleteCellPtr; 
        // We can only delete a cell once we call the next one.
        // If we delete the cell, we can't call getNext() since the object is deleted
    }
    // Restore list to default state
    m_size = 0;
    m_firstCellPtr = nullptr;
    m_lastCellPtr = nullptr;
}

// Iterates through list and returns true if there is a match

bool LinkedList::find(double value, Iterator& findIterator) {
    Iterator iterator = first();
    while (iterator.hasNext()) { // Whilst there is another value in the upcoming element
        if (value == iterator.getValue()) { // If there is a match
            findIterator = iterator;
            return true; // Early return 
        }
    iterator.next(); // Check the next cell
    }
    return false;
}

// Returns true if two lists have the same size AND same values, otherwise false
bool LinkedList::equal(const LinkedList& list) {
    if (m_size != list.m_size) { return false; }

    // Now we compare values
    Iterator thisIterator = first(), listIterator = list.first(); // ??
    while (thisIterator.hasNext()) {
        if (thisIterator.getValue() != listIterator.getValue()) { return false; }

        thisIterator.next();
        listIterator.next(); 
    }
    return true;
}

bool LinkedList::notEqual(const LinkedList& list) { return !equal(list); }

void LinkedList::add(double value) {
    Cell *newCellPtr = new Cell(value, m_lastCellPtr, nullptr);

    if (m_firstCellPtr == nullptr) { // List is empty
        m_firstCellPtr = newCellPtr;
        m_lastCellPtr = newCellPtr; }
        
    else { // List is not empty
         m_lastCellPtr -> setNext(newCellPtr);
         m_lastCellPtr = newCellPtr; } // Last cell is appended, thereby extending the list

    m_size++;
}

void LinkedList::add(const LinkedList& list) {
    Cell *listCellPtr = list.m_firstCellPtr;
    while (listCellPtr != nullptr) { // Whilst the list is not empty
        double value = listCellPtr -> getValue(); 
        Cell *newCellPtr = new Cell(value, m_lastCellPtr, nullptr);
    
    if (m_firstCellPtr == nullptr) { // If the list is empty
        m_firstCellPtr = newCellPtr; }
    else { // List is occupied
        m_lastCellPtr -> setNext(newCellPtr); } // Extend the list
   
        m_lastCellPtr = newCellPtr;
        listCellPtr = listCellPtr -> getNext();
    }
    m_size++;
}

void LinkedList::insert(const Iterator& iteratorPos, double value) {
    Cell *insertCellPtr = iteratorPos.m_CellPtr;
    Cell *newCellPtr = new Cell(value, insertCellPtr->getPrevious(), insertCellPtr);
    // New cell is inserted before the iteratorPos cell
    insertCellPtr -> setPrevious(newCellPtr); // ?

    if(insertCellPtr == m_firstCellPtr) { // If we're at the first cell
        m_firstCellPtr = insertCellPtr; }
    else {
        newCellPtr -> getPrevious() -> setNext(newCellPtr); } // ? Appears to be method chaining
    
    m_size++;
}

void LinkedList::insert(const Iterator& iteratorPos, const LinkedList& list) {
    Cell *insertCellPtr = iteratorPos.m_CellPtr; // Assign cell pointer to local variable for use within the method

    if (insertCellPtr == nullptr) { // If the position is beyound the size of the list
        add(list); } // Call add() instead
    
    else {
        Cell *firstInsertCellPtr = nullptr,
             *lastInsertCellPtr = nullptr,
             *listCellPtr = list.m_firstCellPtr;
        
        while (listCellPtr != nullptr) {
            Cell *newCellPtr = new Cell(listCellPtr->getValue(), lastInsertCellPtr, nullptr);
            
            if (firstInsertCellPtr == nullptr) { 
                firstInsertCellPtr = newCellPtr; // ??
            }
            else {
                lastInsertCellPtr -> setNext(newCellPtr);
            }

            lastInsertCellPtr = newCellPtr; // ?
            listCellPtr = listCellPtr->getNext(); // ?
        }

        if (firstInsertCellPtr != nullptr) { // Cell is not empty
            if (insertCellPtr->getPrevious() != nullptr) {
                insertCellPtr->getPrevious()->setNext(firstInsertCellPtr);
                firstInsertCellPtr->setPrevious(insertCellPtr->getPrevious());
            }
            else {
                m_firstCellPtr = firstInsertCellPtr;
            }
        }
        if (lastInsertCellPtr != nullptr) {
            lastInsertCellPtr->setNext(insertCellPtr);
            insertCellPtr->setPrevious(lastInsertCellPtr);
        }

        m_size += list.m_size; // Expand the list
    }

}

void LinkedList::erase(const Iterator& erasePos) {
    remove(erasePos, erasePos); // Simply call another method 
}

void LinkedList::remove(const Iterator& firstPos, const Iterator& lastPos) {
    Cell *firstCellPtr = firstPos.m_CellPtr,
         *lastCellPtr = lastPos.m_CellPtr;
    
    lastCellPtr = (lastCellPtr == nullptr ? m_lastCellPtr : lastCellPtr); // ? Idk the logic

    Cell *previousCellPtr = firstCellPtr->getPrevious(),
         *nextCellPtr = lastCellPtr->getNext();
    
    Cell *currentCellPtr = firstCellPtr;
    while (currentCellPtr != nextCellPtr) { // Delete all the cells within this range
        Cell *deleteCellPtr = currentCellPtr;
        currentCellPtr = currentCellPtr->getNext();
        delete deleteCellPtr;
        m_size--;
    }

    // Reassign first and last cell pointers
    if (previousCellPtr != nullptr) { // There are cells one cell before a destroyed cell
        previousCellPtr->setNext(nextCellPtr);
    }
    else {
        m_firstCellPtr = nextCellPtr;
    }

    if (nextCellPtr != nullptr) { // There is content after the cell we destroy
        nextCellPtr->setPrevious(previousCellPtr); }
    else {
        m_lastCellPtr = previousCellPtr; 
    }
}

void LinkedList::read(std::istream& inStream) {
    int size;
    inStream >> size; // ?

    int count = 0;
    while (count < size ) {
        double value;
        inStream >> value;
        add(value);
        count++;
    }
}

void LinkedList::write(std::ostream& outStream) {
    outStream << "[";
    bool firstVal = true;

    Iterator iterator = first();
    while (iterator.hasNext()) {
        outStream << (firstVal ? "" : ", ") << iterator.getValue();
        firstVal = false;
        iterator.next();
    }

    outStream << "]";
}