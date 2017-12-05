//
// Created by mahdi on 05/12/17.
//

#include "physics.h"

double E2P(double Energy, double Mass) {

    double momentum;

    momentum = sqrt(pow(Energy, 2) - pow(Mass,2));

    return momentum;

}

double P2E(double momentum, double Mass) {

    double energy;

    energy = sqrt(pow(momentum, 2) + pow(Mass,2));

    return energy;

}

double EnergyToCherenkovAngle(double energy, double n, double mass){

    double theta;

    theta = acos ( 1 / ( n*E2P(energy, mass)/energy)  )  ;

    return theta;

}

double MomentumToCherenkovAngle(double momentum, double n, double mass){

    double theta;

    theta = acos ( 1 / ( n*momentum/P2E(momentum, mass)  )  );

    return theta;

}
double ChernkovAngleToMomentum(double angle,double n, double mass){

    double momentum;

    momentum = mass / sqrt( pow(n*cos(ToRad(angle)),2) - 1 );

    return momentum;

}

