//
// Created by mahdi on 05/12/17.
//

#ifndef LASI_PHYSICS_H
#define LASI_PHYSICS_H

//LaSi INCLUDES
#include "mathematics.h"


double E2P(double Energy, double Mass);//Function to work out momentum from a given energy.

double P2E(double momentum, double Mass);//Function to work out energy from a given momentum.

double EnergyToCherenkovAngle(double energy, double n, double mass);//Function to work out the Cherenkov angle from a given energy.

double MomentumToCherenkovAngle(double momentum, double n, double mass);//Function to work out the Cherenkov angle from a given momentum.

double ChernkovAngleToMomentum(double angle,double n, double mass);//Function to work out the momentum from a given Cherenkov angle.



#endif //LASI_PHYSICS_H
