#include <iostream>
#include <cmath>
#include "Distance.h"

using namespace std;

Distance::Distance() {
    /* Constructs a default Distance of 0 (0 feet and 0.0 inches)
    */
    feet = 0;
    inches = 0.0;
}


Distance::Distance(unsigned ft, double in) {
    /* Constructs a distance of ft feet and in inches,
    unless in >= 12, in which case the values of feet and inches
    are adjusted accordingly. A Distance will always be positive.
    */
    inches = in;
    feet = ft;
    
    init();
}


Distance::Distance(double in) {
    /* Constructs a distance of 0 ft and in inches, 
    unless in >= 12, in which case the values of feet and inches
    are adjusted accordingly. A Distance will always be positive.
    */
    feet = 0;
    inches = in;
    
    init();
}


unsigned Distance::getFeet() const {
    /* Returns just the feet portion of the Distance
    */
    return feet;
}


double Distance::getInches() const {
    /* Returns just the inches portion of the Distance
    */
    return inches;
}


double Distance::distanceInInches() const {
    /* Returns the entire distance as the equivalent amount of inches.
    (e.g., 4 feet 3.5 inches would be returned as 51.5 inches)
    */
    double distInches = (feet * 12) + inches;
    
    return distInches;
}


double Distance::distanceInFeet() const {
    /* Returns the entire distance as the equivalent amount of feet.
    (e.g., 3 feet 6 inches would be returned as 3.5 feet)
    */
    double distFeet;
    distFeet = feet + (inches / 12.0);
    
    return distFeet;
}


double Distance::distanceInMeters() const {
    /* Returns the entire distance as the equivalent amount of meters.
    1 inch equals 0.0254 meters.
    (e.g., 2 feet 8.12 inches would be returned as 0.815848 meters)
    */
    double meters;
    meters = ((feet * 12) + inches) / 39.3701;
    
    return meters;
}


const Distance Distance::operator+(const Distance &rhs) const {
    /* Returns the sum of 2 Distances.
    */
    Distance distanceTotal;
    
    return Distance(distanceInInches() + rhs.distanceInInches());
}


const Distance Distance::operator-(const Distance &rhs) const {
    /* Returns the difference between 2 Distances.
    */
    Distance distanceTotal;
    
    return Distance(distanceInInches() - rhs.distanceInInches());
}


ostream & operator<<(ostream &out, const Distance &rhs) {
    /* Outputs to the stream out the Distance in the format: 
    feet' inches'' (i.e. 3' 3.41'')
    */
    out << rhs.feet << "' " << rhs.inches << "\"";
	return out;
}


void Distance::init() {
    /* Used by the 2 parameterized constructors to convert any negative values to positive and
    inches >= 12 to the appropriate number of feet and inches.
    */
    inches = abs(inches);
    
    if (inches >= 12) {
        while (inches >= 12) {
            feet += 1;
            inches -= 12;
        }
    }
}