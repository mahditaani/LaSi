//
// Created by mahdi on 05/12/17.
//
#include "mathematics.h"

double ToRad(double inDeg){ // Converts degrees to radians.
    return inDeg*PI/180;
}

double ToDeg(double i){return i*180/PI;}//Converts radians to degrees.


bool InSquare(double _vtx[2], double _length){// Function to check if a value is in a square of a given length centered at 0,0.

    bool inside = false;
    if (_vtx[0] > - _length/2 && _vtx[0] < _length/2){inside = true;}
    if (_vtx[1] > - _length/2 && _vtx[1] < _length/2 && inside){inside = true;} else {inside = false;}

    return inside;

}// End of InSquare function.

bool InSquare(double _vtx[2], double _length, double x, double y){// Function to check if a value is in a square of a given length centered at x,y.

    bool inside = false;
    if (_vtx[0] > (- _length/2 + x) && _vtx[0] < (_length/2 +x)){inside = true;}
    if (_vtx[1] > (- _length/2 +y) && _vtx[1] < (_length/2+y) && inside){inside = true;} else {inside = false;}

    return inside;

}// End of InSquare function, off center.

bool InCircle(double _vtx[2], double _radius){ // Function to check if a value is in a circle of a given radius centered at 0,0.

    bool inside = false;
    double x = _vtx[0];
    double y = _vtx[1];
    double val = sqrt( pow(x,2) + pow(y,2));

    if (val < _radius) {inside = true;}

    return inside;
} // End of InCircle function.

bool InCircle(double _vtx[2], double _radius, double xOff, double yOff){ // Function to check if a value is in a circle of a given radius centered at xOff,yOff.

    bool inside = false;
    double x = _vtx[0];
    double y = _vtx[1];
    double val = sqrt( pow((x-xOff),2) + pow((y-yOff),2));

    if (val < _radius) {inside = true;}

    return inside;
} // End of InCircle function, off center.

void RotatePlate(double val[3], double angle){//This function rotates the plate by angle degrees around the y axis.
    double z = val[2];
    double x = val[0];
    val[2] = z*cos(ToRad(angle)) - x*sin(ToRad(angle));
    val[0] = z*sin(ToRad(angle)) + x*cos(ToRad(angle));

}//End of RotatePlate function.

void RandomUniformInCircle(double point[3], double radius){//Generates points distributed randomly and uniformly in a circle with a given radius.
    double theta;
    double r;

    double x, y;
    std::default_random_engine generator(rand());
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    r = sqrt(distribution(generator))*radius;//here we use the square root of the random number to allow the center to not be so dense. A small change in r doesnt change x and y much.
    theta = distribution(generator)*2*PI;
    x = r*cos(theta);
    y = r*sin(theta);

    point[0] = x;
    point[1] = y;// Generates a random muon in the quartz plate and sets the x and y positions in the circle.
    point[2] = quartzPos[2]; // The z position is just the z value of the quartz plate (the height).



}//End of RandomUniformInCircle function.




