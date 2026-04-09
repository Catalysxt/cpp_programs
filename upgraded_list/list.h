#include <iostream>

// class OutOfMemoryException : public Exception {}; // Needs Exception class defined

template <class T>

class LinkedList {
    private:
        class Cell {
            private:
                Cell(const T& value, Cell *previous, Cell *next);
            public:
                // Overloaded methods
                const T value() const { return m_value; }
                T& value() { return m_value; }

                const Cell *previous() const { return m_previous; }
                Cell*& previous() { return m_previous; } // ? Cell*&. Dereferencing the pointer. What does it return?

                const Cell *next() const { return m_next; }
                Cell*& next() { return m_next; }

                friend class LinkedList; 

            private:
                T m_value; 
                Cell *m_previous; 
                Cell *m_next;  
        };
    public:
        class Iterator {
            public:
                Iterator();

            private:
                Iterator(Cell* CellPtr);
            
            public:
                Iterator(const Iterator& iterator);
                Iterator& operator=(const Iterator& iterator);

                bool operator==(const Iterator& iterator);
                bool operator!=(const Iterator& iterator);

                // Overload these operators to. NOTE: the int param is ignored by compiler. It's used to distinguish the two
                bool operator++(); // prefix: ++i;
                bool operator++(int); // postfix: i++;

                bool operator--(); // prefix: --i;
                bool operator--(int); // postfix: i--;         
                
                T operator*() const;
                T& operator*();

                friend class LinkedList;
            
            private:
                Cell *m_CellPtr;
        };

        class ReverseIterator {
            public:
                ReverseIterator();
            
            private:
                ReverseIterator(Cell* cellPtr);
            
            public:
                ReverseIterator(const ReverseIterator& iterator);

                ReverseIterator& operator=(const ReverseIterator& iterator);
                bool operator==(const ReverseIterator& iterator);
                bool operator!=(const ReverseIterator& iterator);

                bool operator++(); // prefix: ++i
                bool operator++(int); // postfix: i++
                bool operator--();
                bool operator--(int);

                // 2 versions. A const and non-const version 
                T operator*() const;
                T& operator*();

                friend class LinkedList;

            private:
                Cell *m_CellPtr;
        };
    public:
        LinkedList();
        LinkedList(const LinkedList& list);
        LinkedList& operator=(const LinkedList& list);
        ~LinkedList();

        void clear();
        int size() const { return m_size; }
        bool empty() const { return m_size == 0; }

        bool operator==(const LinkedList& list) const;
        bool operator!=(const LinkedList& list) const;

        void add(const T& value); // Rather than double value
        void add(const LinkedList& list);

        void insert(const Iterator& insertPosition, const T& value);
        void insert(const Iterator& insertPosition, const LinkedList& list);
    
        void erase(const Iterator& erasePos);
        void remove(const Iterator& firstPos, const Iterator& lastPos = Iterator(nullptr));

        // Forward iteration
        Iterator begin() const { return Iterator(m_firstCellPtr); }
        Iterator end() const { return Iterator(nullptr); }

        // Reverse iteration
        ReverseIterator rbegin() const { return ReverseIterator(m_lastCellPtr); }
        ReverseIterator rend() const { return ReverseIterator(nullptr); }

        // Read/write methods
        template <class U> // ?
        friend std::istream& operator>>(std::istream& outStream, LinkedList<U>& list);

        template <class U>
        friend std::ostream& operator<<(std::ostream& outStream, const LinkedList<U>& list);

    private:
        int m_size;
        Cell* m_firstCellPtr;
        Cell* m_lastCellPtr; 
};

template <class T>
LinkedList<T>::Cell::Cell(const T& value, Cell* previous, Cell* next) :
    m_value(value), m_previous(previous), m_next(next) {}

// Iterator

template <class T>
LinkedList<T>::Iterator::Iterator() : m_CellPtr(nullptr) {}

template <class T>
LinkedList<T>::Iterator::Iterator(Cell* CellPtr) : m_CellPtr(CellPtr) {}

template <class T>
LinkedList<T>::Iterator::Iterator(const Iterator& position) : m_CellPtr(position.m_CellPtr) {}

template <class T>
typename LinkedList<T>::Iterator&
LinkedList<T>::Iterator::operator=(const Iterator& iterator) {
    m_CellPtr = iterator.m_CellPtr;
    return *this;
}

template <class T>
bool LinkedList<T>::Iterator::operator==(const Iterator& position) {
    return (m_CellPtr == position.m_CellPtr);
}

template <class T>
bool LinkedList<T>::Iterator::operator!=(const Iterator& position) {
    return !(*this == position);
}

template <class T>
bool LinkedList<T>::Iterator::operator++() {
    if (m_CellPtr != nullptr) {
        m_CellPtr = m_CellPtr->next();
        return true;
    }
    return false;
}

template <class T>
bool LinkedList<T>::Iterator::operator++(int) { // int param is not used. 
    if (m_CellPtr != nullptr) {
        m_CellPtr = m_CellPtr->next();
        return true;
    }
    return false;
}

template <class T>
bool LinkedList<T>::Iterator::operator--() {
    if (m_CellPtr != nullptr) {
        m_CellPtr = m_CellPtr->previous();
        return true;
    }
    return false;
}

template <class T>
bool LinkedList<T>::Iterator::operator--(int) {
    if (m_CellPtr != nullptr) {
        m_CellPtr = m_CellPtr->previous();
        return true;
    }
    return false;
}

template <class T>
T LinkedList<T>::Iterator::operator*() const {
    return m_CellPtr->value();
}

template <class T>
T& LinkedList<T>::Iterator::operator*() {
    return m_CellPtr->value();
}

// ReverseIterator

template <class T>
LinkedList<T>::ReverseIterator::ReverseIterator() : m_CellPtr(nullptr) {}

template <class T>
LinkedList<T>::ReverseIterator::ReverseIterator(Cell* currCellPtr) : m_CellPtr(currCellPtr) {}

// Copy constructor
template <class T>
LinkedList<T>::ReverseIterator::ReverseIterator(const ReverseIterator& position) : m_CellPtr(position.m_CellPtr) {}

template <class T>
typename LinkedList<T>::ReverseIterator&
LinkedList<T>::ReverseIterator::operator=(const ReverseIterator& iterator) {
    m_CellPtr = iterator.m_CellPtr;
    return *this;
}


template <class T>
bool LinkedList<T>::ReverseIterator::operator==(const ReverseIterator& position) {
    return (m_CellPtr == position.m_CellPtr);
    // Do the pointers point to the same cell?
}

template <class T>
bool LinkedList<T>::ReverseIterator::operator!=(const ReverseIterator& position) {
    return !(*this == position);
}

template <class T>
bool LinkedList<T>::ReverseIterator::operator++() {
    if (m_CellPtr != nullptr) {
        m_CellPtr = m_CellPtr->previous();
        return true;
    }
    return false;
}

template <class T>
bool LinkedList<T>::ReverseIterator::operator++(int) { // int param is not used. 
    if (m_CellPtr != nullptr) {
        m_CellPtr = m_CellPtr->previous();
        return true;
    }
    return false;
}

template <class T>
bool LinkedList<T>::ReverseIterator::operator--() {
    if (m_CellPtr != nullptr) {
        m_CellPtr = m_CellPtr->next();
        return true;
    }
    return false;
}

template <class T>
bool LinkedList<T>::ReverseIterator::operator--(int) {
    if (m_CellPtr != nullptr) {
        m_CellPtr = m_CellPtr->next();
        return true;
    }
    return false;
}

template <class T>
T LinkedList<T>::ReverseIterator::operator*() const {
    return m_CellPtr->value();
}

template <class T>
T& LinkedList<T>::ReverseIterator::operator*() {
    return m_CellPtr->value();
}

// LinkedList implementation

template <class T>
LinkedList<T>::LinkedList() : m_size(), m_firstCellPtr(nullptr), m_lastCellPtr(nullptr) {}

template <class T>
LinkedList<T>::LinkedList(const LinkedList& list) {
    *this = list;
}

template <class T>
typename LinkedList<T>::LinkedList& LinkedList<T>::operator=(const LinkedList<T> &list) {
    m_size = 0;
    m_firstCellPtr = 0;
    m_lastCellPtr = 0;

    if (list.m_size > 0) {
        for (Cell* listCellPtr = list.m_firstCellPtr, *nextCellPtr = list.m_lastCellPtr->next();
            listCellPtr != nextCellPtr;
            listCellPtr = listCellPtr->next()) {
                Cell *newCellPtr = new Cell(listCellPtr->value(), m_lastCellPtr, nullptr);

                if (m_firstCellPtr == nullptr) {
                    m_firstCellPtr = newCellPtr;
                }
                else {
                    m_lastCellPtr->next() = newCellPtr;
                }
                m_lastCellPtr = newCellPtr;
                m_size++;
            }
    }
    return *this;
}

template <class T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <class T>
void LinkedList<T>::clear() {
    Cell *currCellPtr = m_firstCellPtr;
    
    while (currCellPtr != nullptr) {
        Cell *deleteCellPtr = currCellPtr;
        currCellPtr = currCellPtr->next();
        delete deleteCellPtr;   
    }
    // Reset the list
    m_size = 0;
    m_firstCellPtr = 0;
    m_lastCellPtr = 0;
}

// Returns true if 2 lists have same size and values
template <class T>
bool LinkedList<T>::operator==(const LinkedList<T>& list) const {
    if (m_size != list.m_size) { return false; }

    for (Iterator thisIterator = begin(), listIterator = list.begin();
        thisIterator != end(); ++thisIterator, ++listIterator) {
            if (*thisIterator != *listIterator) { // Values are unequal
                return false;
            }
        }
    return true;
}

template <class T>
bool LinkedList<T>::operator!=(const LinkedList<T>& list) const {
    return !(*this == list);
}

// add adds a new value to the end of the list
template <class T>
void LinkedList<T>::add(const T& value) {
    Cell *newCellPtr = new Cell(value, m_lastCellPtr, nullptr);

    if (m_lastCellPtr == nullptr) {
        m_firstCellPtr = newCellPtr;
        m_lastCellPtr = newCellPtr;
    }
    else {
        m_lastCellPtr->next() = newCellPtr;
        m_lastCellPtr = newCellPtr;
     }
    m_size++;
}

template <class T>
void LinkedList<T>::add(const LinkedList<T>& list) {
    for (Cell* listCellPtr = list.m_firstCellPtr;
    listCellPtr != nullptr; listCellPtr = listCellPtr->next()) {
        const T& value = listCellPtr->value();
        Cell *newCellPtr = new Cell(value, m_lastCellPtr, nullptr);

        if (m_lastCellPtr == nullptr) {
            m_firstCellPtr = newCellPtr;
        }
        else {
            m_lastCellPtr->next() = newCellPtr;
        }
        m_lastCellPtr = newCellPtr;
    }
    m_size += list.m_size;
}

// insert methods add a value at a given position (iterator)

template <class T>
void LinkedList<T>::insert(const Iterator& insertPosition, const T& value) {
    if (insertPosition.m_CellPtr == nullptr) {
        add(value);
    } 
    else {
        Cell *insertCellPtr = insertPosition.m_CellPtr;
        Cell *newCellPtr = new Cell(value, insertCellPtr->previous(), insertCellPtr);

        insertCellPtr->previous() = newCellPtr;

        if (insertCellPtr == m_firstCellPtr) {
            m_firstCellPtr = newCellPtr;
        }
        else {
            newCellPtr->previous()->next() = newCellPtr;
        }
        ++m_size;
    }
}

template <class T>
void LinkedList<T>::insert(const Iterator& insertPosition, const LinkedList<T>& list) {
    if (insertPosition.m_CellPtr == nullptr) {
        add(list);
    }
    else {
        Cell *insertCellPtr = insertPosition.m_CellPtr;

        Cell *firstInsertCellPtr = nullptr, *lastInsertCellPtr = nullptr;

        for (Cell *listCellPtr = list.m_firstCellPtr; listCellPtr != nullptr; listCellPtr = listCellPtr->next()) {
            const T& value = listCellPtr->value();
            Cell *newCellPtr = new Cell(value, lastInsertCellPtr, nullptr);

            if (firstInsertCellPtr == nullptr) {
                firstInsertCellPtr = newCellPtr;
            }
            else {
                lastInsertCellPtr->next() = newCellPtr;
            }
            lastInsertCellPtr = newCellPtr;
        }

        if (firstInsertCellPtr != nullptr) {
            if (insertCellPtr->previous() != nullptr) {
                insertCellPtr->previous()->next() = firstInsertCellPtr;
                firstInsertCellPtr->previous() = insertCellPtr->previous();
            }
            else {
                m_firstCellPtr = firstInsertCellPtr;
            }
        }

        if (lastInsertCellPtr != nullptr) {
            lastInsertCellPtr->next() = insertCellPtr;
            insertCellPtr->previous() = lastInsertCellPtr;
        }

        m_size += list.m_size;
    }
}

template <class T>
void LinkedList<T>::erase(const Iterator& removePosition) {
    remove(removePosition, removePosition);
}

template <class T>
void LinkedList<T>::remove(const Iterator& firstPos, const Iterator& lastPos) {
    Cell *firstCellPtr = firstPos.m_CellPtr, *lastCellPtr = lastPos.m_CellPtr;
    lastCellPtr = (lastCellPtr == nullptr) ? m_lastCellPtr : lastCellPtr;

    Cell *previousCellPtr = firstCellPtr->previous(), *nextCellPtr = lastCellPtr->next();

    Cell *currCellPtr = firstCellPtr;
    while (currCellPtr != nextCellPtr) {
        Cell *deleteCellPtr = currCellPtr;
        currCellPtr = currCellPtr->next();
        delete deleteCellPtr;
        --m_size;
    }
    // We need to update previous and next cell pointers after removing cells

    if (previousCellPtr != nullptr) {
        previousCellPtr->next() = nextCellPtr;
    }
    else {
        m_firstCellPtr = nextCellPtr;
    }

    if (nextCellPtr != nullptr) {
        nextCellPtr->previous() = previousCellPtr;
    }
    else {
        m_lastCellPtr = previousCellPtr;
    }
}

template <class T>
std::istream& operator>>(std::istream& inStream, LinkedList<T>& list) {
    int size;
    inStream >> size;

    for (int count = 0; count < size; count++) {
        T value;
        inStream >> value;
        list.add(value);
    }
    return inStream;
}

template <class T>
std::ostream& operator<<(std::ostream& outStream, const LinkedList<T>& list) {
    outStream << "[";

    bool first = true;
    for (const T& value : list) {
        outStream << (first ? "" : ",") << value;
        first = false;
    }

    outStream << "]";
    return outStream;
}