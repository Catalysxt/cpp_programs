#pragma once

#include "Cell.h"
#include "Iterator.h"
#include "LinkedList.h"

#include <iostream>

class Set : private LinkedList {
    public:
        Set();
        Set(double value);
        Set(const Set& set);
        void assign(const Set& set);
        ~Set();

        bool equal(const Set& set) const; // Returns true if set has values
        bool notEqual(const Set& set) const; 

        bool exists(double value) const; // Returns true if the value is present in the set
        bool exists(const Set& set) const; // Returns true if the set has values

        bool insert(double value);
        bool insert(const Set& set);
    
        bool remove(double value);
        bool remove(const Set& set);

        // These will call the inherited methods
        int size() const { return LinkedList::size(); }
        bool empty() const { return LinkedList::empty(); }
        Iterator first() const { return LinkedList::first(); }

        // These functions are friends of the set class. They can access set's private and protected members
        // NOTE: They are of type Set
        friend Set unionSet(const Set& leftSet, const Set& rightSet);
        friend Set intersection(const Set& leftSet, const Set& rightSet);
        friend Set difference(const Set& leftSet, const Set& rightSet);

        void read(std::istream& iStream);
        void write(std::ostream& oStream);

    private:

};