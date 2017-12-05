//
// Created by mahdi on 05/12/17.
//

#ifndef LASI_GENERATE_H
#define LASI_GENERATE_H

#include <iostream>
#include <vector>

//#include "global.h"
#include "physics.h"
#include "photon.h"
#include "mathematics.h"
#include "muon.h"


extern double quartzThickness;
extern double quartzDiameter;
extern double quartzAngle;

std::vector<Muon> GenMuons(int n, double eLow, double eHigh);


int PhotonsDetected(Muon _muon, double pmtVtx[3], bool withWLSP, double pmtLength);

double PercentDetected(Muon _muon, double pmtVtx[3], bool withWLSP, double pmtLength);

/*
double nPhotons(double x, double minL, double maxL, double energy, double mass);


std::vector<Photon> genPhotons(double x, double minL, double maxL, double energy, double mass);
*/
#endif //LASI_GENERATE_H
