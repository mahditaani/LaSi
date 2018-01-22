//
// Created by mahdi on 05/12/17.
//
#include "generate.h"



bool pmtQE(double l){//Simulates the QE of the pmt rejecting hits accordingly.
//    std::cout << "Lambda: "<< l<<std::endl;
    std::default_random_engine generator(rand());
    std::uniform_real_distribution<double> distribution(0.0, 100);
    double rand = distribution(generator);

    if (l >= 2.75e-7 && l<=3.5e-7){
        double m = 400000000; //gradient for first part of QE
        double qe = m*(l-2.75e-7);
        if (rand<= qe) {
//            std::cout << "QE: "<<qe<<" ranval: "<< rand<<std::endl;
            return true;} else {return false;}

    }
    else if (l > 3.5e-7 && l<=6.25e-7){
        double m = -109090909.091; //gradient for second part of QE
        double qe = m*(l-3.5e-7)+30;
        if (rand <= qe) {
//            std::cout << "QE: "<<qe<<" ranval: "<< rand<<std::endl;
            return true;} else {return false;}

    }
    else {return false;}


}//End of pmtQE function.

bool wlsQE(double l){//Simulates the QE of the pmt rejecting hits accordingly.
//    std::cout << "Lambda: "<< l<<std::endl;
    std::default_random_engine generator(rand());
    std::uniform_real_distribution<double> distribution(0.0, 100);
    double rand = distribution(generator);

    if (l >= 2.75e-7 && l<=3.5e-7){
        double m = 400000000; //gradient for first part of QE
        double qe = m*(l-2.75e-7);
        if (rand<= qe) {
//            std::cout << "QE: "<<qe<<" ranval: "<< rand<<std::endl;
            return true;} else {return false;}

    }
    else if (l > 3.5e-7 && l<=6.25e-7){
        double m = -109090909.091; //gradient for second part of QE
        double qe = m*(l-3.5e-7)+30;
        if (rand <= qe) {
//            std::cout << "QE: "<<qe<<" ranval: "<< rand<<std::endl;
            return true;} else {return false;}

    }
    else {return false;}


}//End of wlsQE function.

std::vector<Muon> GenMuons(int n, double eLow, double eHigh){

//n = number of muons to generate


    std::vector<Muon> muons;

    for (int i= 0; i < n; i++)
    {
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
//    std::cout << "Total Photons: " << nPhot <<std::endl;

    double angleDiff = 2*PI/nPhot;

    double height = _muon.GetVtx(2) - pmtVtx[2]; //Difference between the pmt and muon in the z direction (upwards).

    double cAng = EnergyToCherenkovAngle(_muon.GetE(), quartzRefractiveIndex,_muon.GetM() );
//    std::cout << "Cherenkov Angle: " << cAng <<std::endl;

//    double hyp = sin(cAng ); //projection on the z = 0 plane.
    double hyp = height*tan(cAng ); //projection on the z = 0 plane.
//    std::cout << "Hypot : " << hyp <<std::endl;

    for(int i = 0; i < nPhot; i++)
    {
        double xVal = hyp*cos(i*angleDiff)+ _muon.GetVtx(0);
        //std::cout <<"xvalPhot: " << xVal <<std::endl;
        double yVal = hyp*sin(i*angleDiff)+_muon.GetVtx(1);
        //std::cout <<"yvalPhot: " << yVal <<std::endl;
//        std::cout <<xVal<<" " << yVal <<std::endl;
        double point[2] = {xVal, yVal};

        if (withWLSP && InSquare(point, pmtLength, pmtVtx[0], pmtVtx[1])&& pmtQE(_muon.GetPhoton(i).lambda())) {pDetected++;} // Add detected virtual hit if WLS and in the Square (WLS plate).
        if (!withWLSP && InCircle(point, pmtLength, pmtVtx[0], pmtVtx[1])&& pmtQE(_muon.GetPhoton(i).lambda())) {pDetected++;} // Add detected virtual hit if no WLS and in the circle (pmt area).

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
        double xVal = hyp*cos(ToRad(i*3.6))+_muon.GetVtx(0);
//        std::cout <<"xvalPhot: " << xVal <<std::endl;
        double yVal = hyp*sin(ToRad(i*3.6))+_muon.GetVtx(1);
//        std::cout <<"yvalPhot: " << yVal <<std::endl;
        double point[2] = {xVal, yVal};

        if (withWLSP && InSquare(point, pmtLength, pmtVtx[0], pmtVtx[1])) {pDetected++;} // Add detected virtual hit if WLS and in the Sqare (WLS plate).
        if (!withWLSP && InCircle(point, pmtLength, pmtVtx[0], pmtVtx[1])) {pDetected++;} // Add detected virtual hit if no WLS and in the circle (pmt area).

    } // End of for loop counting virtual hits.



    return (double)pDetected/100;
}// End of PercentDetected function.

std::vector<detected> photonJourney(Muon _muon){

    //This function will determine the number of photons hitting the PMT and WLS
    std::vector<detected> detectPhots;

    int nPhot = _muon.GetNumPhot();
    //std::cout << "Total Photons: " << nPhot <<std::endl;

    double angleDiff = 2*PI/nPhot;

    double height = _muon.GetVtx(2) - pmtPos[2]; //Difference between the pmt and muon in the z direction (upwards).

    double cAng = EnergyToCherenkovAngle(_muon.GetE(), quartzRefractiveIndex,_muon.GetM() );
//    std::cout << "Cherenkov Angle: " << cAng <<std::endl;

//    double hyp = sin(cAng ); //projection on the z = 0 plane.
    double hyp = height*tan(cAng ); //projection on the z = 0 plane.
//    std::cout << "Hypot : " << hyp <<std::endl;

    for(int i = 0; i < nPhot; i++)
    {
        double xVal = hyp*cos(i*angleDiff)+ _muon.GetVtx(0);
        //std::cout <<"xvalPhot: " << xVal <<std::endl;
        double yVal = hyp*sin(i*angleDiff)+_muon.GetVtx(1);
        //std::cout <<"yvalPhot: " << yVal <<std::endl;
        //std::cout <<xVal<<" " << yVal <<std::endl;
        double point[2] = {xVal, yVal};

        if (withWLS){
            if ( InCircle(point, pmtRadius, pmtPos[0], pmtPos[1])&& pmtQE(_muon.GetPhoton(i).lambda())) {detected d; d.wavelength = _muon.GetPhoton(i).lambda(); d.material = "PMT"; detectPhots.push_back(d);} // Add detected virtual hit if WLS and in the Square (WLS plate).
            else if ( !InCircle(point, pmtRadius, pmtPos[0], pmtPos[1]) && InSquare(point, WLSLength, pmtPos[0], pmtPos[1])&& wlsQE(_muon.GetPhoton(i).lambda())) {detected d; d.wavelength = _muon.GetPhoton(i).lambda(); d.material = "WLS"; detectPhots.push_back(d);} // Add detected virtual hit if WLS and in the Square (WLS plate).

        }
        if (!withWLS && InCircle(point, pmtRadius, pmtPos[0], pmtPos[1])&& pmtQE(_muon.GetPhoton(i).lambda())) {detected d; d.wavelength = _muon.GetPhoton(i).lambda(); d.material = "PMT"; detectPhots.push_back(d);} // Add detected virtual hit if no WLS and in the circle (pmt area).



    } // End of for loop counting virtual hits.


    return detectPhots;
}
