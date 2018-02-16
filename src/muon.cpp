//
// Created by mahdi on 05/12/17.
//
#include "../inc/muon.h"


double Muon::nPhotons(double x, double minL, double maxL, double energy, double mass){

    // Generate photons x = path length, minL, maxL = range of wavelengths (in m)
    // energy = energy of particle, mass = mass of particle
    // sc = sin of Cherenkov angle

    double beta = E2P(energy, mass)/energy;
    double sc = sin( acos(1/(quartzRefractiveIndex*beta) ) );
    const double f = ((1./minL) - (1/maxL));
    double mu = 2*PI*sc*sc*f*x*alpha;

    return genRan->Poisson(mu);
}

std::vector<Photon> Muon::genPhotons(double x, double minL, double maxL, double energy, double mass){

    // Generate a vector of photons
    // Generate photons x = path length, minL, maxL = range of wavelengths (in m)
    // sc = sin of Cherenkov angle
    // output list of photons Photons

    // get number of photons
    std::vector<Photon> pVec;
    double nToGen = nPhotons(x,minL,maxL,energy, mass);
    pVec.reserve(nToGen);

    for (auto i = 0; i < nToGen; ++i ){
        double lambVal = genRan->Uniform(minL,maxL);//*(maxL - minL);
        pVec.push_back(lambVal);
    }
    return pVec;
}


    Muon::Muon(double _vtx[3], double energy){
        vtx[0] = _vtx[0];
        vtx[1] = _vtx[1];
        vtx[2] = _vtx[2];
        M = 0.1;
        E = energy;
        P = E2P(E,M);
        Phots = genPhotons(pathLength, wavelengthLow, wavelengthHigh, energy, M);
        numPhot = Phots.size();
    }



    Muon::Muon(double _x, double _y, double _z, double energy){
        vtx[0] = _x;
        vtx[1]=_y;
        vtx[2]=_z;
        M = 0.1;
        E = energy;
        P = E2P(E,M);
        Phots = genPhotons(pathLength, wavelengthLow, wavelengthHigh,energy, M);
        numPhot = Phots.size();
    }

    void Muon::GetVtx(double val[3]){val=vtx;}
    double Muon::GetVtx(int i){return vtx[i];}
    Photon Muon::GetPhoton(int i){if(i>=0 && i< Phots.size()){return Phots[i];}else{std::cout<< "The photon number does not exist. First photon returned."<<std::endl; return Phots[0];}}
    std::vector<Photon> Muon::GetPhotons(){return Phots;}
    double Muon::GetNumPhot(){return numPhot;}
    double Muon::GetE(){return E;}
    double Muon::GetP(){return P;}
    double Muon::GetM(){return M;}
//double GetTheta(){return theta;}
//double GetPhi(){return phi;}


