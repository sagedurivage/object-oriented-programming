#include <iostream>
using namespace std;

#include "IntList.h"

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
   else if (head->next != nullptr) {
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

// new members

IntList::IntList(const IntList &cpy) {
   // check if list being copied is empty
   if (cpy.head == nullptr) {
      head = tail = nullptr;
   } else {
      // point implicit's head & tail to new node allocated in heap initialized with cpy's head node value member
      head = tail = new IntNode(cpy.head->value);
      // define an IntNode pointer (stack) that points to cpy's second node
      IntNode *curr = cpy.head->next;
      // iterate until end of list
      // will not enter loop if list is 1 node long
      while (curr != nullptr) {
         push_back(curr->value);
         curr = curr->next;
      }
   }
}

IntList & IntList::operator=(const IntList &rhs) {
   // avoid self-assignment
   if (this != &rhs) {
      // deallocate implicit parameter's data
      clear();
      // check if list being copied is empty
      if (rhs.head == nullptr) {
         head = tail = nullptr;
      } else {
         // point implicit's head & tail to new node allocated in heap initialized with cpy's head node value member
         head = tail = new IntNode(rhs.head->value);
         // define an IntNode pointer (stack) that points to cpy's second node
         IntNode *curr = rhs.head->next;
         // iterate until end of list
         // will not enter loop if list is 1 node long
         while (curr != nullptr) {
            push_back(curr->value);
            curr = curr->next;
         }
      }
   }
   return *this;
}

void IntList::push_back(int value) {
   // check if list is empty
   if (head == nullptr) {
      head = tail = new IntNode(value);
   }
   // list is >= 1 nodes long
   else {
      // allocate new node in heap that is pointed to by end node's next
      tail->next = new IntNode(value);
      // update tail to point to new end node
      tail = tail->next;
   }
}

void IntList::selection_sort() {
   // use an IntNode pointer to keep track of node with relative minimum value
   IntNode *min = nullptr;
   int temp = 0;
   // iterate through list from head to second-to-last node
   IntNode *i = head;
   while (i != tail) {
      min = i;
      // iterate through list from the node following the node pointed to by i to last node
      IntNode *j = i->next;
      while (j != nullptr) {
         if (j->value < min->value) {
            // point min to node with the new relative minimum
            min = j;
         }
         // update conditional
         j = j->next;
      }
      // perform 'swap' of value member value
      temp = min->value;
      min->value = i->value;
      i->value = temp;
      // update conditional
      i = i->next;
   }
}

void IntList::insert_ordered(int value) {
   // check if list is empty
   if (head == nullptr) {
      push_back(value);
   }
   // list is >= 1 nodes long
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
         // point IntNode pointer to first node in list (to evaluate value of following node)
         IntNode *curr = head;
         // iterate through list until new node is 'inserted'
         while (!inserted) {
            // check if value of node after that pointed to by curr is greater than or equal to value
            if (curr->next->value >= value) {
               // define IntNode pointer (stack) to 'hold' newly allocate node (heap) while it gets inserted
               IntNode *insert = new IntNode(value);
               // point node to be indserted's next member to node after node pointed to by curr
               insert->next = curr->next;
               // point node pointed to by curr's next member to newly allocated node (pointed to by insert)
               curr->next = insert;
               // update condition
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
   // if list empty, then i == head == nullptr; while condition not satisfied
   // if list 1 node long, then i == head == tail == node; while condition not satisfied
   IntNode *i = head;
   while (i != nullptr && i != tail) {
      // iterate through list from i to second-to-last node (check tail value independently)
      // only enter loop if there are more than 2 nodes in list
      IntNode *j = i;
      while(j->next != tail) {
         // check if value members of each node match
         if (j->next->value == i->value) {
            // define IntNode pointer (stack) to 'hold' node in list to be deallocated
            IntNode *extract = j->next;
            // point node pointed to by j's next member to node following node to be deallocated
            j->next = extract->next;
            // deallocate node 'held' by extract
            delete extract;
         } else {
            // update conditional
            j = j->next;
         }
      }
      // check node pointed to by tail's value member (j points to node preceeding node pointed to by tail)
      if (tail->value == i->value) {
         // deallocate node pointed to by tail
         delete tail;
         // catch dangling pointers
         tail = j;
         j->next = nullptr;
      } else {
         // update conditional
         i = i->next;
      }
   }
}

// global friend
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
