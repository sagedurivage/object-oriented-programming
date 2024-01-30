#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
int fileSum(const string& fileName);

int main() {

   string filename;
   int sum = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   
   sum = fileSum(filename);

   cout << "Sum: " << sum << endl;
   
   return 0;
}

// Place fileSum implementation here
int fileSum(const string& fileName) {
   ifstream inFS;
   int data;
   int sum = 0;

   // open file with function call string
   inFS.open(fileName);

   // check if file opened correctly
   // if (!inFS.is_open()) {
   if (!inFS) {

      cout << "Error opening " << fileName << endl;

      exit(EXIT_FAILURE);

   }

   // // begin reading data from file
   // inFS >> data;

   // continue reading data from file until end of file
   // while (!inFS.fail()) {
   while (inFS >> data) {

      sum += data;            // sum data
      // inFS >> data;           // continue reading data from file
      // cout << sum << endl; // testing

   }

   // close file
   inFS.close();

   /*
   // include last data read from file in sum when using .eof() condition
   sum += data;
   */

   return sum;
}
