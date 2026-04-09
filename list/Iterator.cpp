#include "Iterator.h"
#include "Cell.h"

Iterator::Iterator(Cell *cellPtr) : m_CellPtr(cellPtr) {}

Iterator::Iterator() : m_CellPtr(nullptr) {} // Empty construction

Iterator::Iterator(const Iterator& iterator) : m_CellPtr(iterator.m_CellPtr) {}