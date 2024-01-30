#include <iostream>
using namespace std;

#include "IntList.h"

IntList::IntList() {
   head = nullptr;
   tail = nullptr;
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
      // point head & tail to newly allocated node (heap) with value of parameter
      head = tail = new IntNode(val);
   }
   // list is >= 1 nodes long
   else {
      // define an IntNode pointer (stack) that points to a newly allocated node (heap) with value of parameter
      IntNode *temp = new IntNode(val);
      // point newly allocated node's next member to what head points to; first node in list
      temp->next = head;
      // point head to newly allocated node, making the node the first in the list
      head = temp;
   }
}

void IntList::pop_front() {
   // check list is 1 node long
   if (head == tail) {
      // deallocate the single node in list
      delete head;
      // catch dangling pointers
      head = tail = nullptr;
   }
   // check list is > 1 nodes long
   else if (head->next != nullptr) {
      // define an IntNode pointer (stack) that points to the second node (until it is null) in list (heap)
      IntNode *next = head->next;
      // deallocate the first node in list that head points to
      delete head;
      // point head to what next points to; newly first node in list
      head = next;
   }
   // do nothing if list is empty
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

ostream & operator<<(ostream &out, const IntList &list) {
   if (!list.empty()) {
      // define an IntNode pointer (stack) that points to the first node in list (heap)
      IntNode *next = list.head;
      // check list is > 1 node long
      while (next != list.tail) {
         // send value of node pointed to by next to ostream
         out << next->value << ' ';
         // point next to next node in list
         next = next->next;
      }
      // send value of node pointed to by tail to ostream
      out << next->value;
   }

   return out;
}
