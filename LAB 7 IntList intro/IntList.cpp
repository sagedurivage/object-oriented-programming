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
      head = tail = new IntNode(val);
   }
   // list is >= 1 nodes long
   else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

void IntList::pop_front() {
   // check list is 1 node long
   if (head == tail) {
      delete head;
      head = tail = nullptr;
   }
   // check list is > 1 nodes long
   else if (head->next != nullptr) {
      IntNode *next = head->next;
      delete head;
      head = next;
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

ostream & operator<<(ostream &out, const IntList &list) {
   if (!list.empty()) {
      IntNode *next = list.head;
      while (next != list.tail) {
         out << next->value << ' ';
         next = next->next;
      }
      out << next->value;
   }

   return out;
}
