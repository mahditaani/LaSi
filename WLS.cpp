//
// Created by mahdi on 17/01/18.
//

#include "WLS.h"
#include <iostream>

WLS::WLS(float x) {

    lengthX = x;
    lengthY = x;


}

WLS::WLS(float *l) {

    lengthX = l[0];
    lengthY = l[1];

}

WLS::WLS(float x, float y) {

    lengthX = x;
    lengthY = y;

}

float WLS::GetLength(int i) {

    if (i == 0) {return lengthX;}
    else if (i ==1) {return lengthY;}
    else {
        std::cout << "Selected length does not exist, using length x. " << std::endl;

    }

}


float WLS::GetQE(){
    return qe;
}

float WLS::GetRefractiveIndex() {

    return refractiveIndex;
}
float WLS::GetThickness() {

    return thickness;

}



int WLS::GetAbsorbArraySize(){

    return absorbArraySize;
}

int WLS::GetEmitArraySize(){

    return emitArraySize;
}

std::vector<float*> WLS::GetAbsorbSpectrum(){
    std::vector<float*> v;
    float a[1] = {absorbArraySize};
    v.push_back(a);
    v.push_back(absorbWavelength);
    v.push_back(absorb);
    return v;
}
std::vector<float*> WLS::GetEmitSpectrum(){
    std::vector<float*> v;
    float a[1] = {emitArraySize};
    v.push_back(a);
    v.push_back(emitWavelength);
    v.push_back(emit);
    return v;

}



bool WLS::QE(){

    std::default_random_engine generator(rand());
    std::uniform_real_distribution<double> distribution(0.0, 100);
    double rand = distribution(generator);
    if (rand <= qe) {
//        std::cout << "QE result: True." << std::endl;
        return true;
    } else {
//        std::cout << "QE result: False." << std::endl;
        return false;
    }
}

bool WLS::Absorb(double l){

//    std::cout << "This photon has wavelength: " << l << "m." << std::endl;
    int arrayIndex = -1; //This will be used to refer to the absorption amplitude in the array.
    float probAbsorb = 0; //This will be the probability of absorption.

    l*=1e9; // This converts the wavelength from m to nm.


    std::default_random_engine generator(rand());
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    double rand = distribution(generator);

    //Loop to find out which value from the absorption spectra to use i.e. finds out the correct amplitude for the wavelength.
    for(int i = 0; i < absorbArraySize - 1; i++ ){

        if (l >= absorbWavelength[i] && l <absorbWavelength[i+1]){
            arrayIndex = i; break;
        }

    }//End of for loop.

    // This part of the code will work out where the detected wavelength is relative to the two reference wavelengths.
    // If the wavelength is halfway between two wavelengths in absorb[] then the probability of absorption will be halfway
    // between absorb[x] and absorb[x+1].

    if (arrayIndex != -1) {
        float diff = l / (absorbWavelength[arrayIndex] - absorbWavelength[arrayIndex + 1]);
        float diffAbsorb = diff * (absorb[arrayIndex] - absorb[arrayIndex]);
        probAbsorb = absorb[arrayIndex] + diffAbsorb;
    }

    //Now this part of the code generates a random number and returns true iff it is lower than the probability of absorption.
    if(rand < probAbsorb){
//        std::cout << "Absorption result: True." << std::endl;
        return true;

    } else {
//        std::cout << "Absorption result: False." << std::endl;
        return false;
    }


}

std::vector<Photon> WLS::Emit() {

    std::vector<Photon> e; // Vector to hold the emitted photons.
    Photon a(genRan->Gaus(500.,16.)); //Placeholder emission, don't fully understand the emission of WLS yet.
    e.push_back(a);

    return e;

}


