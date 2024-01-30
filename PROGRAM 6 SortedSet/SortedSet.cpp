#include <iostream>

#include "SortedSet.h"

using namespace std;

// Constructors & Destructor
SortedSet::SortedSet() : IntList() {}

SortedSet::SortedSet(const SortedSet &setToCopy) : IntList(setToCopy) {}

SortedSet::SortedSet(const IntList &setToCopy) : IntList(setToCopy) {
    remove_duplicates();
    selection_sort();
}

SortedSet::~SortedSet() {}

// Accessors
bool SortedSet::in(int value) const {
    // list is empty
    if (empty()) {
        return false;
    }
    // value out of bounds of set
    else if (head->value > value || tail->value < value) {
        return false;
    }
    // value found at extrmeties
    else if (head->value == value || tail->value == value){
        return true;
    }
    // check list body
    IntNode *curr = head->next;
    // iterate until tail (already checked)
    while (curr != tail) {
        if (curr->value == value) {
            return true;
        }
        curr = curr->next;
    }
    // value not found in list body
    return false;
}

SortedSet SortedSet::operator|(const SortedSet &rhs) const {
    SortedSet unified = rhs;
    // iterate through implicit set
    IntNode *curr = head;
    while (curr) {
        // add each value to unified list
        unified.add(curr->value);
        // update condition
        curr = curr->next;
    }
    return unified;
}

SortedSet SortedSet::operator&(const SortedSet &rhs) const {
    SortedSet intersect;
    // iterate through implicit set
    IntNode *curr = head;
    while (curr) {
        // add each shared value to unified list
        if (rhs.in(curr->value)) {
            intersect.add(curr->value);
        }
        // update condition
        curr = curr->next;
    }
    return intersect;
}

// Mutators
void SortedSet::add(int value) {
    // check value is not already included
    if (!in(value)) {
        if (head == nullptr) {
            head = tail = new IntNode(value);
        }
        else {
            if (value <= head->value) {
                // push_front
                IntNode *curr = new IntNode(value);
                curr->next = head;
                head = curr;
            }
            else if (tail->value <= value) {
                // push_back
                tail->next = new IntNode(value);
                tail = tail->next;
            }
            // value lies within the bounds of a list > 1 nodes long
            else {
                // conditional to exit while loop
                bool inserted = false;
                IntNode *curr = head;
                // iterate through list until new node is 'inserted'
                while (!inserted) {
                    if (curr->next->value >= value) {
                        IntNode *insert = new IntNode(value);
                        insert->next = curr->next;
                        curr->next = insert;
                        // update conditional
                        inserted = true;
                    } else {
                    // update curr to point to next node in list
                    curr = curr->next;
                    }
                }
            }
        }
    }
}

void SortedSet::push_front(int value) {add(value);}

void SortedSet::push_back(int value) {add(value);}

void SortedSet::insert_ordered(int value) {add(value);}

SortedSet SortedSet::operator|=(SortedSet &rhs) {
    *this = *this | rhs;
    return *this;
}

SortedSet SortedSet::operator&=(SortedSet &rhs) {
    *this = *this & rhs;
    return *this;
}
