//
// Created by mahdi on 05/12/17.
//

#ifndef LASI_MUON_H
#define LASI_MUON_H

#include <iostream>
//#include "generate.h"
#include "TRandom.h"
#include "photon.h"
#include "physics.h"
extern double quartzRefractiveIndex;
extern double alpha;
extern TRandom* genRan;
extern double pathLength;
extern double wavelengthLow;
extern double wavelengthHigh;
/*
double nPhotons(double x, double minL, double maxL, double energy, double mass);

std::vector<Photon> genPhotons(double x, double minL, double maxL, double energy, double mass);
*/
class Muon{
//Point of Muon's creation.
    double vtx[3];
    double numPhot;
    double E;
    double P;
    double M;
    std::vector<Photon> Phots;
//Angles of muon's direction. Downwards for now.
//double theta;
//double phi;

public:

//Muon(double _vtx[3], double _theta, double _phi):vtx(_vtx),theta(_theta),phi(_phi){}
//Muon(double _x, double _y, double _z, double _theta, double _phi):vtx[0](_x),vtx[1](_y),vtx[2](_z),theta(_theta),phi(_phi){}

    Muon(double _vtx[3], double energy);

    Muon(double _x, double _y, double _z, double energy);
    ~Muon(){}

    void GetVtx(double val[3]);
    double GetVtx(int i);
    Photon GetPhoton(int i);
    std::vector<Photon> GetPhotons();
    double GetNumPhot();
    double GetE();
    double GetP();
    double GetM();
//double GetTheta(){return theta;}
//double GetPhi(){return phi;}
    double nPhotons(double x, double minL, double maxL, double energy, double mass);

    std::vector<Photon> genPhotons(double x, double minL, double maxL, double energy, double mass);


};

/*
double nPhotons(double x, double minL, double maxL, double energy, double mass){

    // Generate photons x = path length, minL, maxL = range of wavelengths (in m)
    // energy = energy of particle, mass = mass of particle
    // sc = sin of Cherenkov angle

    double beta = E2P(energy, mass)/energy;
    double sc = sin( acos(1/(quartzRefractiveIndex*beta) ) );
    const double f = ((1./minL) - (1/maxL));
    double mu = 2*PI*sc*sc*f*x*alpha;

    return genRan->Poisson(mu);
}

std::vector<Photon> genPhotons(double x, double minL, double maxL, double energy, double mass){

    // Generate a vector of photons
    // Generate photons x = path length, minL, maxL = range of wavelengths (in m)
    // sc = sin of Cherenkov angle
    // output list of photons Photons

    // get number of photons
    std::vector<Photon> pVec;
    double nToGen = nPhotons(x,minL,maxL,energy, mass);
    pVec.reserve(nToGen);

    for (auto i = 0; i < nToGen; ++i ){
        double lambVal = genRan->Uniform(minL,maxL)*(maxL - minL);
        pVec.push_back(lambVal);
    }
    return pVec;
}

class Muon{
//Point of Muon's creation.
    double vtx[3];
    double numPhot;
    double E;
    double P;
    double M;
    std::vector<Photon> Phots;
//Angles of muon's direction. Downwards for now.
//double theta;
//double phi;

public:

//Muon(double _vtx[3], double _theta, double _phi):vtx(_vtx),theta(_theta),phi(_phi){}
//Muon(double _x, double _y, double _z, double _theta, double _phi):vtx[0](_x),vtx[1](_y),vtx[2](_z),theta(_theta),phi(_phi){}

    Muon(double _vtx[3], double energy){
        vtx[0] = _vtx[0];
        vtx[1] = _vtx[1];
        vtx[2] = _vtx[2];
        M = 0.1;
        E = energy;
        P = E2P(E,M);
        Phots = genPhotons(pathLength, wavelengthLow, wavelengthHigh, energy, M);
        numPhot = Phots.size();
    }



    Muon(double _x, double _y, double _z, double energy){
        vtx[0] = _x;
        vtx[1]=_y;
        vtx[2]=_z;
        M = 0.1;
        E = energy;
        P = E2P(E,M);
        Phots = genPhotons(pathLength, wavelengthLow, wavelengthHigh,energy, 0.1);
        numPhot = Phots.size();
    }
    ~Muon(){}

    void GetVtx(double val[3]){val=vtx;}
    double GetVtx(int i){return vtx[i];}
    Photon GetPhoton(int i){if(i>=0 && i< Phots.size()){return Phots[i];}else{std::cout<< "The photon number does not exist. First photon returned."<<std::endl; return Phots[0];}}
    std::vector<Photon> GetPhotons(){return Phots;}
    double GetNumPhot(){return numPhot;}
    double GetE(){return E;}
    double GetP(){return P;}
    double GetM(){return M;}
//double GetTheta(){return theta;}
//double GetPhi(){return phi;}


};
*/

#endif //LASI_MUON_H
