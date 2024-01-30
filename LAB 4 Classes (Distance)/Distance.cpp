#include <iostream>

using namespace std;

#include "Distance.h"

/* Constructs a default Distance of 0 (0 feet and 0.0 inches)
*/
Distance::Distance() : _feet(0), _inches(0.0) {}

/* Constructs a distance of ft feet and in inches,
   unless in >= 12, in which case the values of feet and inches
   are adjusted accordingly. A Distance will always be positive.
   Just convert negative inches to positive. Don't subtract from feet.
*/
Distance::Distance(unsigned ft, double in) : _feet(ft), _inches(in) {init();}

/* Constructs a distance of 0 ft and in inches, 
   unless in >= 12, in which case the values of feet and inches
   are adjusted accordingly. A Distance will always be positive.
   Just convert negative inches to positive. Don't subtract from feet.
*/
Distance::Distance(double in) : _feet(0), _inches(in) {init();}

/* Returns just the feet portion of the Distance
*/
unsigned Distance::getFeet() const {return _feet;}

/* Returns just the inches portion of the Distance
*/
double Distance::getInches() const {return _inches;}

/* Returns the entire distance as the equivalent amount of inches.
   (e.g., 4 feet 3.5 inches would be returned as 51.5 inches)
*/
double Distance::distanceInInches() const {return _inches + (_feet * 12.0);}

/* Returns the entire distance as the equivalent amount of feet.
   (e.g., 3 feet 6 inches would be returned as 3.5 feet)
*/
double Distance::distanceInFeet() const {return distanceInInches() / 12.0;}

/* Returns the entire distance as the equivalent amount of meters.
   1 inch equals 0.0254 meters.
   (e.g., 2 feet 8.12 inches would be returned as 0.815848 meters)
*/
double Distance::distanceInMeters() const {return distanceInInches() * 0.0254;}

/* Returns the sum of 2 Distances.
*/
Distance Distance::operator+(const Distance &rhs) const {
   Distance sum;

   sum._inches = distanceInInches() + rhs.distanceInInches();
   sum.init();

   return sum;
}

/* Returns the difference between 2 Distances.
*/
Distance Distance::operator-(const Distance &rhs) const {
   Distance diff;
   
   diff._inches = distanceInInches() - rhs.distanceInInches();
   diff.init();

   return diff;
}

/* Outputs to the stream out the Distance in the format: 
   feet' inches'' (i.e. 3' 3.41'')
*/
ostream & operator<<(ostream &out, const Distance &rhs) {
   
   out << rhs._feet << "' " << rhs._inches << "\"";

   return out;
}

/*---------------private---------------*/


/* Used by the 2 parameterized constructors to convert any negative values to positive and
   inches >= 12 to the appropriate number of feet and inches.
*/
void Distance::init() {
   
   // negative inches
   if (_inches < 0) {
      _inches *= -1;
   }

   // too many inches
   while (_inches >= 12.0) {
      ++_feet;
      _inches -= 12.0;
   }

}
