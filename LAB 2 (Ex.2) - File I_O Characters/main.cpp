#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

// Place charCnt prototype (declaration) here
int charCnt(const string& fileName, const char& ch);


int main() {
   string filename;
   char ch;
   int chCnt = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;

   chCnt = charCnt(filename, ch);   
   cout << "# of " << ch << "'s: " << chCnt << endl;
   
   return 0;
}

// Place charCnt implementation here
int charCnt(const string& fileName, const char& ch) {
   ifstream inFS;
   // string data;
   char data;
   int cnt = 0;

   // open file with function call string
   inFS.open(fileName);

   // check if file opened correctly
   // if (!inFS.is_open()) {
   if (!inFS) {

      cout << "Error opening " << fileName << endl;

      exit(EXIT_FAILURE);

   }

   // // read in string from file
   // getline(inFS, data);

   // // continue to read data until end of file
   // while (!inFS.fail()) {

   //    // iterated through ea char in string to count occurances of ch match
   //    for (unsigned i = 0; i < data.size(); ++i) {

   //       if (data.at(i) == ch) {

   //          ++cnt;

   //       }

   //    }

   //    getline(inFS, data);

   // }

   while (inFS.get(data)) {

      if (data == ch) {{

         ++cnt;

      }}

   }


   // close file
   inFS.close();

   return cnt;
}
