//
// Created by mahdi on 05/12/17.
//

#ifndef LASI_MATHEMATICS_H
#define LASI_MATHEMATICS_H


#include "math.h"
#include <random>

extern double quartzPos[];
#define PI 3.14159265



double ToRad(double inDeg);
double ToDeg(double i);

bool InSquare(double _vtx[2], double _length);
bool InSquare(double _vtx[2], double _length, double x, double y);

bool InCircle(double _vtx[2], double _radius);
bool InCircle(double _vtx[2], double _radius, double xOff, double yOff);

void RotatePlate(double val[3], double angle);

void RandomUniformInCircle(double point[2], double radius);



#endif //LASI_MATHEMATICS_H
