#ifndef SORTEDSET_H
#define SORTEDSET_H

#include "IntList.h"

#include <ostream>

using namespace std;

class SortedSet : public IntList {
 public:
    // Constructors & Destructor
    SortedSet();
    SortedSet(const SortedSet &);
    SortedSet(const IntList &);
    ~SortedSet();
    // Accessors
    bool in(int value) const;
    SortedSet operator|(const SortedSet &rhs) const;
    SortedSet operator&(const SortedSet &rhs) const;
    // Mutators
    void add(int value);
    void push_front(int value);
    void push_back(int value);
    void insert_ordered(int value);
    SortedSet operator|=(SortedSet &rhs);
    SortedSet operator&=(SortedSet &rhs);
};

#endif
