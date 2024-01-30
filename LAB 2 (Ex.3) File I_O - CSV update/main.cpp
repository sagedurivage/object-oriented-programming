#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   
   string inputFile;
   string outputFile;
   
   // check number of arguments
   if (argc != 3) {
      cout << endl << "Usage: myprog.exe inputFileName outputFileName" << endl;
      return 1;   // error
   }

   // Assign to inputFile value of 2nd command line argument
   inputFile = argv[1];

   // Assign to outputFile value of 3rd command line argument
   outputFile = argv[2];
   
   // Create input stream and open input csv file.
   ifstream inFS;

   inFS.open(inputFile);

   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
   // if (!inFS.is_open()) {
   if (!inFS) {

      cout << "Error opening " << inputFile << endl;
      return 1;   // error
      
   }
   
   // Read in integers from input file to vector.
   vector<int> dataVec;
   int data;
   char comma;

   // // begin to get ints from file
   // inFS >> data;

   // continue to read data until no more ints to get
   // while (!inFS.fail()) {
   while (inFS >> data) {

      // // ignore commas
      // inFS >> comma;
      // append data to vector
      dataVec.push_back(data);
      // // try to get another int from file
      // inFS >> data;

      // ignore commas
      inFS >> comma;


   }

   // Close input stream.
   inFS.close();
   
   // Get integer average of all values read in.
   int avg = 0;

   for (unsigned i = 0; i < dataVec.size(); ++i) {

      // sum vector ints
      avg += dataVec.at(i);

   }

   // compute average
   avg /= dataVec.size();

   // test
   // cout << avg << endl;
   
   // Convert each value within vector to be the difference between the original value and the average.
   for (unsigned i = 0; i < dataVec.size(); ++i) {

      dataVec.at(i) -= avg;

   }
   
   // Create output stream and open/create output csv file.
   ofstream outFS;

   outFS.open(outputFile);

   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.
   // if (!outFS.is_open()) {
   if (!outFS) {

      cout << "Error opening " << outputFile << endl;
      return 1;   // error
      
   }

   // Write converted values into ouptut csv file, each integer separated by a comma.
   unsigned i = 0;
   // read each int from vector to file except last int
   for (i = 0; i < dataVec.size() - 1; ++i) {

      outFS << dataVec.at(i) << ',';

   }

   // include last vector element without trailing comma
   outFS << dataVec.at(i);

   // Close output stream.
   outFS.close();
   
   return 0;
}