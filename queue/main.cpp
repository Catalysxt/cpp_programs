#include <iostream>
#include <cmath>

#include "Cell.h"
#include "Queue.h"

//******************************************************************************
// Queue
//
// Description: This program is an implementation of a queue

//  Ahmad Sarraj
//  Mar 2025
//******************************************************************************

int main() {

    Queue q1;

    for (int i = 0; i <= 9; i++) { q1.enter(i); }

    std::cout << "The first element is: " << q1.first() << '\n';

    q1.remove();
    q1.remove();
    q1.remove();

    std::cout << "The first element is: " << q1.first() << '\n';

    std::cout << "The size of the queue is: " << q1.size() << '\n';
}

//******************************************************************************
// Output

// The first element is: 0
// The first element is: 3
// The size of the queue is: 7

//******************************************************************************
