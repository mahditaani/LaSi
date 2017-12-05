//
// Created by mahdi on 05/12/17.
//

#ifndef LASI_PHYSICS_H
#define LASI_PHYSICS_H

#include "mathematics.h"


double E2P(double Energy, double Mass);

double P2E(double momentum, double Mass);

double EnergyToCherenkovAngle(double energy, double n, double mass);

double MomentumToCherenkovAngle(double momentum, double n, double mass);

double ChernkovAngleToMomentum(double angle,double n, double mass);



#endif //LASI_PHYSICS_H
