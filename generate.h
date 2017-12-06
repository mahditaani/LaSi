//
// Created by mahdi on 05/12/17.
//

#ifndef LASI_GENERATE_H
#define LASI_GENERATE_H
//C++ INCLUDES
#include <iostream>
#include <vector>

//LaSi INCLUDES
#include "physics.h"
#include "photon.h"
#include "mathematics.h"
#include "muon.h"

//Variables used from global.
extern double quartzThickness;
extern double quartzDiameter;
extern double quartzAngle;

std::vector<Muon> GenMuons(int n, double eLow, double eHigh);//Function to generate n muons between energies eLow and eHigh.


int PhotonsDetected(Muon _muon, double pmtVtx[3], bool withWLSP, double pmtLength);//Function to calculate how many photons are detected in the pmt.

double PercentDetected(Muon _muon, double pmtVtx[3], bool withWLSP, double pmtLength); //Function to calculate the percentage of photons detected, no longer used.

#endif //LASI_GENERATE_H
