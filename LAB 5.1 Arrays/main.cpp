//include any standard libraries needed
#include <iostream>
#include <fstream>

using namespace std;


//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize);

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index);

// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize);


const int ARR_CAP = 100;

int main(int argc, char *argv[]) {
   
   // verify file name provided on command line
   string fileName;
   ifstream inFS;

   // check number of arguments
   if (argc != 2) {
      cout << "Usage: g++ exacutable.cpp unputFile.dat" << endl;
      return 1;   // error
   }
   // assign fileName with 2nd command line argument
   fileName = argv[1];

   // open file and verify it opened
   inFS.open(fileName);
   if (!inFS) {
      cout << "Error opening " << fileName << endl;
      return 1;   // error
   }

   // Declare an array of doubles of size ARR_CAP.
   double arr[ARR_CAP];
   // count to keep track of size
   int arrSize = 0;
    
   // Fill the array with up to ARR_CAP doubles from the file entered at the command line.
   while (arrSize < ARR_CAP && inFS >> arr[arrSize]) {
      ++arrSize;
   }
    
   // Call the mean function passing it this array and output the value returned.
   cout << "Mean: " << mean(arr, arrSize);
   cout << endl << endl;
    
   // Ask the user for the index (0 to size - 1) of the value they want to remove.
   int index = 0;
   cout << "Enter index of value to be removed (0 to " << arrSize - 1 << ") : ";
   cin >> index;
   cout << endl << endl;
	
   // Call the display function to output the array.
   cout << "Before removing value: ";
   display(arr, arrSize);
   cout << endl << endl;
   
   // Call the remove function to remove the value at the index provided by the user.
   remove(arr, arrSize, index);
    
   // Call the display function again to output the array with the value removed.
   cout << "After removing value: ";
   display(arr, arrSize);
   cout << endl << endl;
   
   // Call the mean function again to get the new mean
   cout << "Mean: " << mean(arr, arrSize);
   cout << endl << endl;
   
	return 0;
}

double mean(const double array[], int arraySize) {
   double sum = 0;

   // loop to sum all elements of array
   for (int i = 0; i < arraySize; ++i) {
      sum += array[i];
   }

   return sum / (arraySize * 1.0);
}

void remove(double array[], int &arraySize, int index) {

   if (0 <= index && index < arraySize) {
      // check if last element is being removed
      if (index != arraySize - 1) {
         // iterate through array beginning at index and shifting each element left once
         for (int i = index; i < arraySize - 1; ++i) {
            array[i] = array[i + 1];
         }
      }
      // make last value inaccessible
      --arraySize;
   }

}

void display(const double array[], int arraySize) {
   int i = 0;

   // iterate through array and output each before last element
   for (i = 0; i < arraySize - 1; ++i) {
      cout << array[i] << ", ";
   }
   // output last element (no trailing comma)
   cout << array[i];

}