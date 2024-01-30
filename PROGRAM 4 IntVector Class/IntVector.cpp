#include <iostream>
#include <stdexcept>
using namespace std;

#include "IntVector.h"

IntVector::IntVector(unsigned capacity, int value) {
   _size = capacity;
   _capacity = capacity;

   // make sure 'vector' is not empty
   if (_capacity > 0) {
      // initialize _data to point to new location in heap storing an array of data
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
   // check bounds
   if (index < 0 || index >= _size) {
      throw out_of_range("IntVector::at_range_check");
   }
   else {
      return _data[index];
   }
}

// mutator callable
int & IntVector::at(unsigned index) {
   if (index < 0 || index >= _size) {
      throw out_of_range("IntVector::at_range_check");
   }
   else {
      return _data[index];
   }
}

void IntVector::insert(unsigned index, int value) {
   // check bounds
   if (index < 0 || index > _size) {
      throw out_of_range("IntVector::insert_range_check");
   } else {
      if (_size == _capacity) {
         expand();
      }
      // increment _size by 1 for new value to be added
      ++_size;

      // move each element to the right, from last element to index parameter
      for (unsigned i = _size - 1; i > index; --i) {
         _data[i] = _data[i - 1];
      }
      // include value parameter at parameter index in _data array
      at(index) = value;
   }
}

void IntVector::erase(unsigned index) {
   // check bounds
   if (index < 0 || index >= _size) {
      throw out_of_range("IntVector::erase_range_check");
   } else if (index >= 0 || index < _size) {
      // iterate through array shifting each element to the left
      for (unsigned i = index; i < _size - 1; ++i) {
         at(i) = at(i + 1);
      }
   }
   --_size;
}

const int & IntVector::front() const {
   return at(0);
}

// mutator callable
int & IntVector::front() {
   return at(0);
}

const int & IntVector::back() const {
   return at(_size - 1);
}

// mutator callable
int & IntVector::back() {
   return at(_size - 1);
}

void IntVector::assign(unsigned n, int value) {
   // check if new size n is larger than _capacity
   if (n > _capacity) {
      if (n > (2 * _capacity)) {
         expand(n - _capacity);
      } else {
         expand();
      }
   }
   // update _size
   _size = n;
   // initialize each element of the array(<-_data) to value parameter
   for (unsigned i = 0; i < n; ++i) {
      at(i) = value;
   }
}

void IntVector::push_back(int value) {
   // check 'vector' has space to add an element
   if (_size == _capacity) {
      expand();
   }
   ++_size;
   _data[_size - 1] = value;
}

void IntVector::pop_back() {
   --_size;
}

void IntVector::clear() {
   _size = 0;
}

void IntVector::resize(unsigned n, int value) {
   // check if additional elements need to be appended to _data
   if (n > _size) {
      // check if _capacity needs to be expanded
      if (n > (2 * _capacity)) {
         expand(n - _capacity);
      } else if (n > _capacity) {
         expand();
      }
      // assign value parameter to additonal indeces appended to 'vector'
      do {
         ++_size;
         at(_size - 1) = value;
      } while (_size < n);
   } else {
      // update _size
      _size = n;
   }
}

void IntVector::reserve(unsigned n) {
   if (n > _capacity) {
      expand(n - _capacity);
   }
}

// ---------------------------------------- private helpers ----------------------------------------

void IntVector::expand() {
   // check if _capacity is 0 (default)
   if (_capacity < 1) {
      _capacity = 1;
   } else {
      _capacity *= 2;
   }

   // initialize newData to point to new location in heap storing an array with (updated _capacity) elements
   int *newData = new int[_capacity];

   // copy each element of the array(<-_data) to the front of the array(<-newData)
   for (unsigned int i = 0; i < _size; ++i) {
      newData[i] = _data[i];
   }

   // deallocate array of data that _data is pointing to in heap 
   delete[] _data;
   // point _data to the array that newData is pointing to in heap
   _data = newData;
}

void IntVector::expand(unsigned amount) {
   // update _capacity with amount parameter
   _capacity += amount;

   int *newData = new int[_capacity];

   for (unsigned int i = 0; i < _size; ++i) {
      newData[i] = _data[i];
   }

   delete[] _data;
   _data = newData;
}