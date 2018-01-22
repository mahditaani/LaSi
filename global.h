//
// Created by mahdi on 05/12/17.
//

#ifndef LASI_GLOBAL_H
#define LASI_GLOBAL_H

//ROOT INCLUDES
#include "TRandom.h"

//C++ INCLUDES
#include <vector>
#include <cstdlib>

//LaSi INCLUDES
#include "mathematics.h"


double quartzThickness = 0.01; //in m.
double quartzPos[3] = {-0.01,0,0.18}; //in m.
double quartzDiameter = 0.15; //in m. These are dummy values.
double quartzAngle = 48.36 ; //Angle of quartz plate in degrees.
double quartzRefractiveIndex = 1.5;
double pathLength = quartzThickness/sin(ToRad(quartzAngle)); //Gives the path length inside the quartz plate.

double pmtPos[3] = {0,0,0};//H1  //in m. //THIS DEFINES THE CENTER OF THE GEOMETRY
//double pmtPos[3] = {-0.04,0,0};//H2  //in m.
//double pmtPos[3] = {-0.08,0,0};//H3  //in m.
//double pmtPos[3] = {-0.12,0,0};//H4  //in m.
//double pmtPos[3] = {-0.16,0,0};//H5  //in m.
//double pmtPos[3] = {-0.20,0,0};//H6  //in m.
//double pmtPos[3] = {-0.24,0,0};//H7  //in m.
//double pmtPos[3] = {-0.28,0,0};//H8  //in m.
double pmtDiameter = 0.078; //in m.
double pmtRadius = pmtDiameter/2; //in m.

bool withWLS = true;
double WLSLength = 0.28; //in m.
double WLSThickness = 0.013; //in m.

double wavelengthLow = 2.75e-7;
double wavelengthHigh = 6.25e-7;


double alpha = 1/137.035999139;
double nc = 1.46;

TRandom* genRan;

inline void initRan(){
    genRan = new TRandom(12345);
}

inline void initRan(int i){
    genRan = new TRandom(i);
}





#endif //LASI_GLOBAL_H
