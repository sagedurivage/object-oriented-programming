#include <iostream>
#include <string>

using namespace std;

class Date {
 private:
   unsigned _day;
   unsigned _month;
   string _mName;
   unsigned _year;

 public:
   Date();
   Date(unsigned m, unsigned d, unsigned y);
   Date(const string &mn, unsigned d, unsigned y);
   void printNumeric() const;
   void printAlpha() const;

 private:

   bool isLeap(unsigned y) const;
   unsigned daysPerMonth(unsigned m, unsigned y) const;
   string name(unsigned m) const;
   unsigned number(const string &mn) const;
};



// Implement the Date member functions here



// creates the date January 1st, 2000.
Date::Date() : _day(1), _month(1), _mName("January"), _year(2000) {}


/* parameterized constructor: month number, day, year 
      - e.g. (3, 1, 2010) will construct the date March 1st, 2010

      If any of the arguments are invalid (e.g. 15 for month or 32 for day)
      then the constructor will construct instead a valid Date as close
      as possible to the arguments provided - e.g. in above example,
      Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
      In case of such invalid input, the constructor will issue a console error message: 

      Invalid date values: Date corrected to 12/31/2010.
      (with a newline at the end).
*/
Date::Date(unsigned m, unsigned d, unsigned y) {
   bool corrected = false;
   _year = y;

   // check validity of month parameter
   if (m < 1) {
      m = 1;
      corrected = true;
   }
   else if (m > 12) {
      m = 12;
      corrected = true;
   }
   // assign valid value to private variable
   _month = m;
   _mName = name(m);

   // check validity of day parameter
   if (d < 1) {
      d = 1;
      corrected = true;
   }
   else if (d > daysPerMonth(m, y)) {
      d = daysPerMonth(m, y);
      corrected = true;
   }
   // assign valid value to private variable
   _day = d;

   if (corrected) {
         cout << "Invalid date values: Date corrected to ";
         printNumeric();
         cout << "." << endl;
   }

}


/* parameterized constructor: month name, day, year
   - e.g. (December, 15, 2012) will construct the date December 15th, 2012

      If the constructor is unable to recognize the string argument as a valid month name,
      then it will issue a console error message: 

      Invalid month name: the Date was set to 1/1/2000.
      (with a newline at the end).

      If the day argument is invalid for the given month (but the month name was valid),
      then the constructor will handle this error in the same manner as the other
      parameterized constructor. 

      This constructor will recognize both "december" and "December"
      as month name.
*/
Date::Date(const string &mn, unsigned d, unsigned y) {
   bool corrected = false;
   unsigned m = number(mn);
   _year = y;

   // user input did not match month names available
   if (m == 0) {
      _day = 1;
      _month = 1;
      _mName = "January";
      _year = 2000;

      cout << "Invalid month name: the Date was set to ";
      printNumeric();
      cout << "." << endl;
   }
   else {
      // assign valid value to private variable
      _month = m;
      _mName = name(m);

      // check validity of day parameter
      if (d < 1) {
         d = 1;
         corrected = true;
      }
      else if (d > daysPerMonth(m, y)) {
         d = daysPerMonth(m, y);
         corrected = true;
      }
      // assign valid value to private variable
      _day = d;
      
      if (corrected) {
         cout << "Invalid date values: Date corrected to ";
         printNumeric();
         cout << "." << endl;
      }
   }

}


/* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
   Does not output a newline at the end.
*/
void Date::printNumeric() const {
   cout << _month << "/" << _day << "/" << _year;
}


/* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
   The first letter of the month name is upper case, and the month name is
   printed in full - January, not Jan, jan, or january. 
   Does not output a newline at the end.
*/
void Date::printAlpha() const {
   cout << _mName << " " << _day << ", " << _year;
}


/*-----------------private-----------------*/


/* Returns true if the year passed in is a leap year, otherwise returns false.
*/
bool Date::isLeap(unsigned y) const {
   if (y % 4 == 0) {
      if (y % 100 == 0) {
         if (y % 400 == 0) {
            return true;
         }

         return false;
      }

      return true;
   }

   return false;
}


/* Returns number of days allowed in a given month
   -  e.g. daysPerMonth(9, 2000) returns 30.
   Calculates February's days for leap and non-leap years,
   thus, the reason year is also a parameter.
*/
unsigned Date::daysPerMonth(unsigned m, unsigned y) const {
   unsigned dNum = 0;

   // months with 31 days
   if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
      dNum = 31;
   }
   // months with 30 days
   else if (m == 4 || m == 6 || m == 9 || m == 11 ) {
      dNum = 30;
   }
   // february special case; need to check for leap year
   else if (m == 2) {
      if (isLeap(y)) {
         dNum = 29;
      } else {
         dNum = 28;
      }
   }

   return dNum;
}


/* Returns the name of a given month
   - e.g. name(12) returns the string "December"
*/
string Date::name(unsigned m) const {
   string mName = "";

   if (m == 1) {
      mName = "January";
   } else if (m == 2) {
      mName = "February";
   } else if (m == 3) {
      mName = "March";
   } else if (m == 4) {
      mName = "April";
   } else if (m == 5) {
      mName = "May";
   } else if (m == 6) {
      mName = "June";
   } else if (m == 7) {
      mName = "July";
   } else if (m == 8) {
      mName = "August";
   } else if (m == 9) {
      mName = "September";
   } else if (m == 10) {
      mName = "October";
   } else if (m == 11) {
      mName = "November";
   } else if (m == 12) {
      mName = "December";
   }

   return mName;
}


/* Returns the number of a given named month
   - e.g. number("March") returns 3
*/
unsigned Date::number(const string &mn) const {
   unsigned m = 0;

   if (mn == "January" || mn == "january") {
      m = 1;
   } else if (mn == "February" || mn == "february") {
      m = 2;
   } else if (mn == "March" || mn == "march") {
      m = 3;
   } else if (mn == "April" || mn == "april") {
      m = 4;
   } else if (mn == "May" || mn == "may") {
      m = 5;
   } else if (mn == "June" || mn == "june") {
      m = 6;
   } else if (mn == "July" || mn == "july") {
      m = 7;
   } else if (mn == "August" || mn == "august") {
      m = 8;
   } else if (mn == "September" || mn == "september") {
      m = 9;
   } else if (mn == "October" || mn == "october") {
      m = 10;
   } else if (mn == "November" || mn == "november") {
      m = 11;
   } else if (mn == "December" || mn == "december") {
      m = 12;
   }
   // if mn = else, then m remains = 0 to trip consol error in constructor

   return m;
}



// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned mber, day, year;
   string mName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> mber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(mber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> mName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(mName, day, year);
   } else {
      return Date();
   }
}
