#include <iostream>
#include <string>

using namespace std;


void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

//Implement the flipString function here
void flipString(string &s) {
   char curr;

   // base case: stop when string is 1 char long
   if (s.size() > 1) {
      curr = s.front();
      s.erase(s.begin());
      flipString(s);
      s.push_back(curr);
   }
}

