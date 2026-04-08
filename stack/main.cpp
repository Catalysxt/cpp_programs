#include "Cell.h"
#include "Stack.h"
#include <iostream>

//******************************************************************************
// Implementation of a stack
//
// Description: This project is an implementation of a stack

//  Ahmad Sarraj
//  Mar 2025
//******************************************************************************

int main() {

    Stack s;

    for (int i = 0; i <= 18; i++) {
        s.push(i);
    }

    std::cout << "The size of the stack is: " << s.size() << std::endl;

    s.pop();
    s.pop();
    std::cout << "The new size of the stack is: " << s.size() << std::endl;

    std::cout << "The top value of the stack is: " << s.top() << std::endl;
    std::cout << "Is the stack empty: " << (s.empty() ? "Yes" : "No") << std::endl;
}

//******************************************************************************
// Output

// The size of the stack is: 19
// The new size of the stack is: 17
// The top value of the stack is: 16
// Is the stack empty: No

//******************************************************************************
