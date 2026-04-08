#pragma once
#include "Cell.h"

class Queue {
public:
    Queue();
    void enter(int value);
    int first();
    void remove();
    int size() const;
    bool empty() const;

private:
    int m_size;
    Cell *m_firstCellptr;
    Cell *m_lastCellptr;
};