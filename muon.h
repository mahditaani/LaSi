//
// Created by mahdi on 05/12/17.
//

#ifndef LASI_MUON_H
#define LASI_MUON_H
//C++ INCLUDES
#include <iostream>


//ROOT INCLUDES
#include "TRandom.h"

//LaSi INCLUDES
#include "photon.h"
#include "physics.h"


//Variables used from global
extern double quartzRefractiveIndex;
extern double alpha;
extern TRandom* genRan;
extern double pathLength;
extern double wavelengthLow;
extern double wavelengthHigh;




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


#endif //LASI_MUON_H
