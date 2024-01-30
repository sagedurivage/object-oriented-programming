#include <iostream>
#include <stdexcept>
using namespace std;

#include "IntVector.h"

IntVector::IntVector(unsigned capacity, int value) {
   _size = capacity;
   _capacity = capacity;

   // make sure 'vector' is not empty
   if (_capacity > 0) {
      // initialize _data to point to new location in heap storing out array of data
      _data = new int[_size];
      // fill array with value specified
      for (unsigned i = 0; i < _size; ++i) {
         _data[i] = value;
      }
   }
   // in the case that 'vector' is empty
   else {
      // initialize _data to point to nullptr
      _data = nullptr;
   }
}

IntVector::~IntVector() {
   // deallocate data that _data is pointing to in heap
   delete[] _data;
   // catch dangling pointer
   _data = nullptr;

   cout << "Destructor called." << endl;
}

unsigned IntVector::size() const {
   return _size;
}

unsigned IntVector::capacity() const {
   return _capacity;
}

bool IntVector::empty() const {
   return _size == 0;
}

const int & IntVector::at(unsigned index) const {
   // check if 'vector is empty
   if (_size == 0) {
      throw out_of_range("IntVector::at_range_check");
   }
   // bounds checking
   if (index < 0 || index > _size - 1) {
      throw out_of_range("IntVector::at_range_check");
   }
   else {
      return _data[index];
   }
}

const int & IntVector::front() const {
   return _data[0];
}

const int & IntVector::back() const {
   return _data[_size - 1];
}
