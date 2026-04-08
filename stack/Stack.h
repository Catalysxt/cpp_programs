#pragma once

#include "Cell.h"

class Stack {
public:
    Stack(); // Empty initialization 

    // Methods
    void push(int value); // Add a value to the stack
    int top(); // Return the top value
    void pop(); // Remove the top value
    int size() const; // Returns number of objects in the stack
    bool empty() const; // True if the stack is empty. It's a helper function. Used by other methods

private:
    Cell *m_firstCellPtr;
    int m_size;

};