#include <iostream>

#include "IntList.h"

using namespace std;

IntList::IntList() {
    head = tail = nullptr;
}

IntList::~IntList() {
    clear();
}

void IntList::clear() {
    // check head is not nullptr
    while (head) {
        pop_front();
    }
}

void IntList::push_front(int val) {
    // check if list is empty
    if (head == nullptr) {
        head = tail = new IntNode(val);
    }
    // list is >= 1 nodes long
    else {
        IntNode *curr = new IntNode(val);
        curr->next = head;
        head = curr;
    }
}

void IntList::pop_front() {
    // check list is 1 node long
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    }
    // check list is > 1 nodes long
    else if (head->next) {
        IntNode *curr = head->next;
        delete head;
        head = curr;
    }
}

bool IntList::empty() const {
    return head == nullptr;
}

const int & IntList::front() const {
    return head->value;
}

const int & IntList::back() const {
    return tail->value;
}

IntList::IntList(const IntList &cpy) {
    if (cpy.head == nullptr) {
        head = tail = nullptr;
    } else {
        head = tail = new IntNode(cpy.head->value);
        IntNode *curr = cpy.head->next;
        // will not enter loop if list is only 1 node long
        while (curr) {
            push_back(curr->value);
            curr = curr->next;
        }
    }
}

IntList & IntList::operator=(const IntList &rhs) {
    // avoid self-assignment
    if (this != &rhs) {
        clear();
        if (rhs.head == nullptr) {
            head = tail = nullptr;
        } else {
            head = tail = new IntNode(rhs.head->value);
            IntNode *curr = rhs.head->next;
            while (curr) {
                push_back(curr->value);
                curr = curr->next;
            }
        }
    }
    return *this;
}

void IntList::push_back(int value) {
    if (head == nullptr) {
        head = tail = new IntNode(value);
    } else {
        tail->next = new IntNode(value);
        tail = tail->next;
    }
}

void IntList::selection_sort() {
    // keep track of relative minimum value
    IntNode *min = nullptr;
    int temp = 0;
    // iterate through list from head to second-to-last node
    IntNode *i = head;
    while (i != tail) {
        min = i;
        // iterate through list from i to last node
        IntNode *j = i->next;
        while (j) {
            if (j->value < min->value) {
                min = j;
            }
            j = j->next;
        }
        // perform 'swap' of value member value
        temp = min->value;
        min->value = i->value;
        i->value = temp;

        i = i->next;
    }
}

void IntList::insert_ordered(int value) {
    if (head == nullptr) {
        push_back(value);
    }
    else {
        if (value <= head->value) {
            push_front(value);
        }
        else if (tail->value <= value) {
            push_back(value);
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

void IntList::remove_duplicates() {
    // iterate through list from head to second-to-last node
    IntNode *i = head;
    while (i != nullptr && i != tail) {
        // iterate through list from i to second-to-last node
        IntNode *j = i;
        while(j->next != tail) {
            if (j->next->value == i->value) {
                IntNode *extract = j->next;
                j->next = extract->next;
                delete extract;
            } else {
                // update conditional
                j = j->next;
            }
        }
        // check tail value independently
        if (tail->value == i->value) {
            delete tail;
            tail = j;
            j->next = nullptr;
        } else {
            // update conditional
            i = i->next;
        }
    }
}

ostream & operator<<(ostream &out, const IntList &rhs) {
    if (!rhs.empty()) {
        IntNode *curr = rhs.head;
        while (curr != rhs.tail) {
            out << curr->value << ' ';
            curr = curr->next;
        }
        out << curr->value;
    }

    return out;
}

IntNode * IntList::min(IntNode *) {return nullptr;}
void IntList::copy(const IntList &) {}
