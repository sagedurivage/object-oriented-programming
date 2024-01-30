#include <iostream>

using namespace std;

// Rational Class declaration
class Rational {
   private:
      int _numerator;
      int _denominator; 
   public:
      Rational();
      explicit Rational(int); 
      Rational(int, int); 
      Rational add(const Rational &) const; 
      Rational subtract(const Rational &) const; 
      Rational multiply(const Rational &) const; 
      Rational divide(const Rational &) const;
      void simplify();
      void display() const;
   private:
      int gcd(int, int) const;
};

/*----public----*/

// Implement Rational class member functions here
Rational::Rational() : _numerator(0), _denominator(1) {}   //default constructor
Rational::Rational(int numerator) : _numerator(numerator), _denominator(1) {}   // Parameterized constructor
Rational::Rational(int numerator, int denominator) : _numerator(numerator), _denominator(denominator) {}   // Parameterized constructor
// (a/b) + (c/d) = (ad + bc) / (b*d)
Rational Rational::add(const Rational &rhs) const {
   Rational sum;

   if (_denominator == rhs._denominator) {
      sum._numerator = _numerator + rhs._numerator;
      sum._denominator = _denominator;
   } else {
      sum._numerator = (_numerator * rhs._denominator) + (rhs._numerator * _denominator);
      sum._denominator = _denominator * rhs._denominator;
   }

   return sum;
}
// (a/b) - (c/d) = (ad - bc) / (b*d)
Rational Rational::subtract(const Rational &rhs) const {
   Rational diff;

   if (_denominator == rhs._denominator) {
      diff._numerator = _numerator - rhs._numerator;
      diff._denominator = _denominator;
   } else {
      diff._numerator = (_numerator * rhs._denominator) - (rhs._numerator * _denominator);
      diff._denominator = _denominator * rhs._denominator;
   }

   return diff;
}
// (a/b) * (c/d) = (ac) / (bd)
Rational Rational::multiply(const Rational &rhs) const {
   Rational prod;

   prod._numerator = _numerator * rhs._numerator;
   prod._denominator = _denominator * rhs._denominator;

   return prod;
}
// // (a/b) / (c/d) = (ad) / (cb)
Rational Rational::divide(const Rational &rhs) const {
   Rational quot;

   quot._numerator = _numerator * rhs._denominator;
   quot._denominator = _denominator * rhs._numerator;

   return quot;
}
void Rational::simplify() {
   int gcd;

   // Check for zeros
   if (_numerator != 0 && _denominator != 0) {
      gcd = this->gcd(_numerator, _denominator);
      _numerator /= gcd;
      _denominator /= gcd;
   }
}
void Rational::display() const {
   cout << _numerator << " / " << _denominator;
}

/*----private----*/

int Rational::gcd(int numA, int numB) const {
   // Check for negatives
   if (numA < 0) {
      numA *= -1;
   }
   if (numB < 0) {
      numB *= -1;
   }

   // gcd private member function using Euclid's Algoirthm in C++
   while(numA != numB){
      if(numB > numA){
          numB -= numA;
      } else{
          numA -= numB;
      }
   }

   return numA;
}


// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

