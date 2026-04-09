
#pragma once

class Cell {
private:
    Cell(double value, Cell *previous, Cell *next);
    friend class LinkedList; 

public:
    // getters
    double getValue() const { return m_value; }
    Cell *getPrevious() const { return m_previous; }
    Cell *getNext() const { return m_next; }

    // setters
    void setValue(double value) { m_value = value; }
    void setPrevious(Cell *previous) { m_previous = previous; }
    void setNext(Cell *next) {m_next = next;}

private:
    double m_value;
    Cell *m_previous;
    Cell *m_next;
};
