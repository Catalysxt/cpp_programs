#include <iostream>
#include <exception> 

#include "list.h"

//******************************************************************************
// The UPGRADED List
//
// Description: This is an upgrade of the other list program in this repo. 

//  Ahmad Sarraj
//  Mar 2025
//******************************************************************************

int main() {

    LinkedList<double> list;
    list.add(1.0);
    list.add(2.0);
    list.add(3.0);

    std::cout << list << std::endl;

    // Print out the list
    for (double value : list ) {
        std::cout << value << " ";
    }
    std::cout << std::endl; 

    // We can also iterate through the list using iterator.begin() and iterator.end()
    for (LinkedList<double>::Iterator iterator = list.begin(); iterator != list.end(); ++iterator) {
        std::cout << *iterator << " ";
    }
    std::cout << std::endl;  

    // Reverse iteration is similar 
    std::cout << "Let's iterate through the list in reverse: \n";
    for (LinkedList<double>::ReverseIterator iterator = list.rbegin(); iterator != list.rend(); ++iterator) {
        std::cout << *iterator << " ";
    }
    std::cout << std::endl; 

}

//******************************************************************************
// Output

// [1,2,3]
// 1 2 3
// 1 2 3
// Let's iterate through the list in reverse:
// 3 2 1

//******************************************************************************
