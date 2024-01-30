#include <iostream>
#include <stdexcept>
using namespace std;

#include "IntVector.h"

int main() {
   IntVector *v1 = new IntVector;
   IntVector *v2 = new IntVector(10);
   IntVector *v3 = new IntVector(1, 1);

   /*
   v1 = {}
   v2 = {0,0,0,0,0,0,0,0,0,0}
   v3 = {1}
   */

   // test size()
   if (v1->size() != 0) {
      cout << "size of v1 is " << v1->size() << " when it should be 0." << endl;
   }
   if (v2->size() != 10) {
      cout << "size of v2 is " << v2->size() << " when it should be 10." << endl;
   }
   if (v3->size() != 1) {
      cout << "size of v3 is " << v3->size() << " when it should be 1." << endl;
   }

   // test capacity()
   if (v1->capacity() != 0) {
      cout << "capacity of v1 is " << v1->capacity() << " when it should be 0." << endl;
   }
   if (v2->capacity() != 10) {
      cout << "capacity of v2 is " << v2->capacity() << " when it should be 10." << endl;
   }
   if (v3->capacity() != 1) {
      cout << "capacity of v3 is " << v3->capacity() << " when it should be 1." << endl;
   }

   // test empty()
   if (!v1->empty()) {
      cout << "v1 is not empty when it should be." << endl;
   }
   if (v2->empty()) {
      cout << "v2 is empty when it should not be." << endl;
   }
   if (v3->empty()) {
      cout << "v3 is empty when it should not be." << endl;
   }

   // test at()
   if (v2->at(0) != 0) {
      cout << "v2 at index 0 is " << v2->at(0) << " when it should be 0." << endl;
   }
   if (v2->at(9) != 0) {
      cout << "v2 at index 9 is " << v2->at(0) << " when it should be 0." << endl;
   }
   if (v3->at(0) != 1) {
      cout << "v3 at index 0 is " << v2->at(0) << " when it should be 1." << endl;
   }

   // test front()
   if (v2->front() != 0) {
      cout << "first element of v2 is " << v2->front() << " when it should be 0." << endl;
   }
   if (v3->front() != 1) {
      cout << "first element of v3 is " << v3->front() << " when it should be 1." << endl;
   }

   // test back()
   if (v2->back() != 0) {
      cout << "last element of v2 is " << v2->front() << " when it should be 0." << endl;
   }
   if (v3->back() != 1) {
      cout << "last element of v3 is " << v3->front() << " when it should be 1." << endl;
   }

   // test insert()
   // v1->insert(0, 0);  // out of range
   v2->insert(0, 1);
   v2->insert(5, 1);
   v2->insert(12, 1);
   if (v2->at(0) != 1) {
      cout << "v2 at index 0 is " << v2->at(0) << " when it should be 1." << endl;
   }
   if (v2->at(5) != 1) {
      cout << "v2 at index 0 is " << v2->at(0) << " when it should be 1." << endl;
   }
   if (v2->at(12) != 1) {
      cout << "v2 at index 0 is " << v2->at(0) << " when it should be 1." << endl;
   }
   if (v2->size() != 13) {
      cout << "size of v2 is " << v2->size() << " when it should be 13." << endl;
   }

   /*
   v1 = {}
   v2 = {1,0,0,0,0,1,0,0,0,0,0,0,12}
   v3 = {1}
   */

   // test erase()
   // v1->erase(0);  // out of range
   v2->erase(11);
   v2->erase(5);
   v2->erase(0);
   if (v2->size() != 10) {
      cout << "size of v2 is " << v2->size() << " when it should be 10." << endl;
   }

   /*
   v1 = {}
   v2 = {0,0,0,0,0,0,0,0,0,0}
   v3 = {1}
   */

   // test assign()
   v1->assign(3, 0);
   if (v1->at(0) != 0) {
      cout << "v1 at index 0 is " << v1->at(0) << " when it should be 0." << endl;
   }
   if (v1->at(2) != 0) {
      cout << "v1 at index 2 is " << v1->at(2) << " when it should be 0." << endl;
   }
   if (v1->size() != 3) {
      cout << "size of v1 is " << v1->size() << " when it should be 3." << endl;
   }
   v1->assign(1, 1);
   if (v1->at(0) != 1) {
      cout << "v1 at index 0 is " << v1->at(0) << " when it should be 1." << endl;
   }
   if (v1->size() != 1) {
      cout << "size of v1 is " << v1->size() << " when it should be 1." << endl;
   }
   v1->erase(0);

   /*
   v1 = {}
   v2 = {0,0,0,0,0,0,0,0,0,0}
   v3 = {1}
   */

   // test push_back()
   v1->push_back(0);
   v1->push_back(1);
   if (v1->at(0) != 0) {
      cout << "v1 at index 0 is " << v1->at(0) << " when it should be 0." << endl;
   }
   if (v1->at(1) != 1) {
      cout << "v1 at index 1 is " << v1->at(1) << " when it should be 1." << endl;
   }
   if (v1->size() != 2) {
      cout << "size of v1 is " << v1->size() << " when it should be 2." << endl;
   }

   /*
   v1 = {0,1}
   v2 = {0,0,0,0,0,0,0,0,0,0}
   v3 = {1}
   */

   // test pop_back()
   v1->pop_back();
   if (v1->at(0) != 0) {
      cout << "v1 at index 0 is " << v1->at(0) << " when it should be 0." << endl;
   }
   if (v1->size() != 1) {
      cout << "size of v1 is " << v1->size() << " when it should be 1." << endl;
   }
   v1->pop_back();
   if (v1->size() != 0) {
      cout << "size of v1 is " << v1->size() << " when it should be 0." << endl;
   }

   /*
   v1 = {}
   v2 = {0,0,0,0,0,0,0,0,0,0}
   v3 = {1}
   */

   // test clear()
   v2->clear();
   if (v2->size() != 0) {
      cout << "size of v2 is " << v2->size() << " when it should be 0." << endl;
   }

   /*
   v1 = {}
   v2 = {}
   v3 = {1}
   */

   //test resize()
   v1->resize(1, 0);
   if (v1->at(0) != 0) {
      cout << "v1 at index 0 is " << v1->at(0) << " when it should be 0." << endl;
   }
   if (v1->size() != 1) {
      cout << "size of v1 is " << v1->size() << " when it should be 1." << endl;
   }
   v1->resize(10, 1);
   if (v1->at(1) != 1) {
      cout << "v1 at index 1 is " << v1->at(1) << " when it should be 1." << endl;
   }
   if (v1->size() != 10) {
      cout << "size of v1 is " << v1->size() << " when it should be 10." << endl;
   }
   v1->resize(5, 0);
   if (v1->size() != 5) {
      cout << "size of v1 is " << v1->size() << " when it should be 5." << endl;
   }

   /*
   v1 = {0,1,1,1,1,1,1,1,1,1}
   v2 = {}
   v3 = {1}
   */

   // test reserve()
   v3->reserve(5);
   if (v3->capacity() != 5) {
      cout << "capacity of v3 is " << v3->capacity() << " when it should be 5." << endl;
   }


   delete v1;
   delete v2;
   delete v3;

   return 0;
}