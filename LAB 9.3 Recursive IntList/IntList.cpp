#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}

void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

ostream & operator<<(ostream &o, const IntList &list) {
   // base case: list empty
   if (list.head == nullptr) {
      return o;   // output empty
   }
   // recursive case
   o << list.head;
   return o;
}
// helper
ostream & operator<<(ostream &o, IntNode *index) {
   // base case: index is tail
   if (index->next == nullptr) {
      o << index->value;
      return o;
   }
   // recursive case
   o << index->value << " ";
   o << index->next;
   return o;
}

bool IntList::exists(int val) const {
   // base case: empty list
   if (head == nullptr) {
      return false;
   }
   // recursive case
   return exists(head, val);
}
// helper
bool IntList::exists(IntNode *index, int val) const {
   // base case: val found at index
   if (index->value == val) {
      return true;
   }
   // recursive case
   if (index->next) {   // there exists another item in list to check
      return exists(index->next, val);
   } else {             // val not found in list
      return false;
   }
}
