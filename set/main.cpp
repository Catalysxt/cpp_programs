#include "Cell.h"
#include "Iterator.h"
#include "LinkedList.h"
#include "set.h"

#include <iostream>

//******************************************************************************
// The Set Class
//
// Description: 

//  Ahmad Sarraj
//  Mar 2025
//******************************************************************************

int main() {
 
    using namespace std;

    Set s1, t1;

    for (int i = 0; i <= 7; i++) {s1.insert(i);}
    for (int i = 0; i <= 3; i++) {t1.insert(i);}

    cout << endl << "s1 = ";
    s1.write(cout);
    cout << endl;

    cout << endl << "t1 = ";
    t1.write(cout);
    cout << endl;

    cout << "union: ";
    unionSet(s1, t1).write(cout);
    cout << endl;

    cout << "intersection: ";
    intersection(s1, t1).write(cout);
    cout << endl;

    cout << "difference: ";
    difference(s1, t1).write(cout);
    cout << endl;
}

//******************************************************************************
// Output

// s1 = { 0, 1, 2, 3, 4, 5, 6, 7}

// t1 = { 0, 1, 2, 3}
// union: { 0, 1, 2, 3, 4, 5, 6, 7}
// intersection: { 0, 1, 2, 3}
// difference: { 4, 5, 6, 7}

//******************************************************************************
