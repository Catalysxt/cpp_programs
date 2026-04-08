#pragma once

class Cell {
    public:
        Cell(int value, Cell *next); // Constructor

        // Getters
        int getValue() const { return m_value; }
        Cell *getNext() const { return m_next; }
    private:
        int m_value;
        Cell *m_next; // NOTE: It's of type Cell not ptr
};
