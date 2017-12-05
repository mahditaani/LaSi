//
// Created by mahdi on 05/12/17.
//
#include "generate.h"


std::vector<Muon> GenMuons(int n, double eLow, double eHigh){

//n = number of muons to generate


    std::vector<Muon> muons;

    for (int i= 0; i < n; i++)
    {
//vtx
//
        double vtx[3];

        RandomUniformInCircle(vtx, quartzDiameter/2); //Generates a random point in a circle (quartz plate).

        RotatePlate(vtx, quartzAngle) ; //Rotates plate to get the positions of the muons  in cartesian coordinates.

        double e = genRan->Uniform(eLow,eHigh);

        muons.push_back(Muon(vtx,e));

    }

    return muons;


}// End of GenMuons function.

int PhotonsDetected(Muon _muon, double pmtVtx[3], bool withWLSP, double pmtLength) {

// This will generate 100 lines 3.6 degrees (phi) and cherenkovAngle degrees (theta).
// The number of lines that go through the pmt area will be the percentage of photons that will reach the pmt(w and w/o WLSP).
// If PMT only then pmtLength is just the radius of the pmt, if WLSP is present then length is the full length of one side of the PMT.

    int pDetected = 0;
    int nPhot = _muon.GetNumPhot();
    //std::cout << "Total Photons: " << nPhot <<std::endl;

    double angleDiff = 2*PI/nPhot;

    double height = _muon.GetVtx(2) - pmtVtx[2]; //Difference between the pmt and muon in the z direction (upwards).

    double cAng = EnergyToCherenkovAngle(_muon.GetE(), quartzRefractiveIndex,_muon.GetM() );
//std::cout << "Cherenkov Angle: " << cAng <<std::endl;

    double hyp = sin(cAng ); //projection on the z = 0 plane.
    //std::cout << "Hypot : " << hyp <<std::endl;

    for(int i = 0; i < nPhot; i++)
    {
        double xVal = hyp*cos(i*angleDiff);
        double yVal = hyp*sin(i*angleDiff);
        double point[2] = {xVal, yVal};

/*
if (withWLSP && InSquare(point, pmtLength)) {percentDetected++;} // Add detected virtual hit if WLS and in the Sqare (WLS plate).
if (!withWLSP && InCircle(point, pmtLength)) {percentDetected++;} // Add detected virtual hit if no WLS and in the circle (pmt area).
*/
        if (withWLSP && InSquare(point, pmtLength, pmtVtx[0], pmtVtx[1])) {pDetected++;} // Add detected virtual hit if WLS and in the Sqare (WLS plate).
        if (!withWLSP && InCircle(point, pmtLength, pmtVtx[0], pmtVtx[1])) {pDetected++;} // Add detected virtual hit if no WLS and in the circle (pmt area).

    } // End of for loop counting virtual hits.



    return pDetected;
}// End of PhotonsDetected function.


double PercentDetected(Muon _muon, double pmtVtx[3], bool withWLSP, double pmtLength) {

// This will generate 100 lines 3.6 degrees (phi) and cherenkovAngle degrees (theta).
// The number of lines that go through the pmt area will be the percentage of photons that will reach the pmt(w and w/o WLSP).
// If PMT only then pmtLength is just the radius of the pmt, if WLSP is present then length is the full length of one side of the PMT.

    int pDetected = 0;

    double height = _muon.GetVtx(2) - pmtVtx[2]; //Difference between the pmt and muon in the z direction (upwards).

    double cAng = EnergyToCherenkovAngle(_muon.GetE(), quartzRefractiveIndex,_muon.GetM() );
    //std::cout << "Cherenkov Angle: " << cAng <<std::endl;

    double hyp = sin(cAng ); //projection on the z = 0 plane.
    //std::cout << "Hypot : " << hyp <<std::endl;

    for(int i = 0; i < 100; i++)
    {
        double xVal = hyp*cos(ToRad(i*3.6));
        double yVal = hyp*sin(ToRad(i*3.6));
        double point[2] = {xVal, yVal};

/*
if (withWLSP && InSquare(point, pmtLength)) {percentDetected++;} // Add detected virtual hit if WLS and in the Sqare (WLS plate).
if (!withWLSP && InCircle(point, pmtLength)) {percentDetected++;} // Add detected virtual hit if no WLS and in the circle (pmt area).
*/
        if (withWLSP && InSquare(point, pmtLength, pmtVtx[0], pmtVtx[1])) {pDetected++;} // Add detected virtual hit if WLS and in the Sqare (WLS plate).
        if (!withWLSP && InCircle(point, pmtLength, pmtVtx[0], pmtVtx[1])) {pDetected++;} // Add detected virtual hit if no WLS and in the circle (pmt area).

    } // End of for loop counting virtual hits.



    return (double)pDetected/100;
}// End of PercentDetected function.
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
*/


