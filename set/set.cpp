#include <cassert>
#include <iostream>

#include "Cell.h"
#include "Iterator.h"
#include "LinkedList.h"
#include "set.h"


Set::Set() {}

Set::Set(double value) { add(value); }

Set::Set(const Set& set) : LinkedList(set) {} // Interesting

Set::~Set() {}

void Set::assign(const Set& set) {
    clear();
    add(set);
}

bool Set::equal(const Set& set) const {
    if (size() != set.size()) { return false; }

    Iterator iterator = first();
    while (iterator.hasNext()) {
        if (!set.exists(iterator.getValue())) { // If the value doesn't exist 
            return false; }
        iterator.next();
    }
    return true;
}

bool Set::notEqual(const Set& set) const { return !equal(set); }

bool Set::exists(double value) const {
    Iterator iterator = first();

    while (iterator.hasNext()) {
        if (value == iterator.getValue()) { return true; }
    
        iterator.next();
    }
    return false;
}

bool Set::exists(const Set& set) const {

    Iterator iterator = set.first();

    while(iterator.hasNext()) {
        if (!exists(iterator.getValue())) { return false; } // Return false if value isn't present
    
        iterator.next();
    }
    return true;
}

bool Set::insert(double value) {
    if(!exists(value)) {
        add(value);
        return true; // Value was successfully inserted
    }
    else { return false; }

}

bool Set::insert(const Set& set) {
    bool inserted = false;
    Iterator iterator = set.first();

    while(iterator.hasNext()) {
        double value = iterator.getValue();

        if(insert(value)) { inserted = true; }
        iterator.next();
    }

    return inserted;
}

// Returns true if value is present. Also, removes it
bool Set::remove(double value) {
    Iterator iterator;

    if (find(value, iterator)) {
        erase(iterator);
        return true;
    }
    return false;
}

// Returns true if one value is removed
bool Set::remove(const Set& set) {
    bool removed = false;
    Iterator iterator = set.first();
    while (iterator.hasNext()) {
        double value = iterator.getValue();
        if (remove(value)) { removed = true; }
        iterator.next();
    }
    return removed;
}

Set unionSet(const Set& leftSet, const Set& rightSet) {
    Set result = leftSet;
    result.insert(rightSet);
    return result;
}

// Removes the rightSet from the leftSet
Set difference(const Set& leftSet, const Set& rightSet) {
    Set result = leftSet;
    result.remove(rightSet);
    return result;
}

// Returns overlaping elements between 2 sets
Set intersection(const Set& leftSet, const Set& rightSet) {
  return difference(difference(unionSet(leftSet, rightSet),
                               difference(leftSet, rightSet)),
                    difference(rightSet, leftSet));
}

void Set::read(std::istream& iStream) {
    int size;
    iStream >> size;

    int count = 0;
    while (count < size) {
        double value;
        iStream >> value;
        insert(value);
        count++;
    }
}

void Set::write(std::ostream& oStream) {
    oStream << "{";
    bool firstVal = true;
    Iterator iterator = first();

    while (iterator.hasNext()) {
        oStream << (firstVal ? " " : ", ") << iterator.getValue();
        firstVal = false;
        iterator.next();
    }
    oStream << "}";

}