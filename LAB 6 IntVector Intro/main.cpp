#include <iostream>
#include <stdexcept>
using namespace std;

#include "IntVector.h"

int main() {
   IntVector *v1 = new IntVector;
   IntVector *v2 = new IntVector(10);
   IntVector *v3 = new IntVector(1, 1);

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

   // delete[] v1;
   // v1 = nullptr;
   // delete[] v2;
   // v2 = nullptr;
   // delete[] v3;
   // v3 = nullptr;

   return 0;
}