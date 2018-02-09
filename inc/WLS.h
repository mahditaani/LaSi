//
// Created by mahdi on 17/01/18.
//

#ifndef LASI_WLS_H
#define LASI_WLS_H

#include <random>
#include <TRandom.h>
#include "photon.h"
#include <cmath>


extern TRandom* genRan;

class WLS {

    float lengthX;
    float lengthY;
    float refractiveIndex = 1.58;
    float thickness = 0.013;


/*
    // Values taken from EJ-280 datasheet.
    float qe = 86;
    static const int absorbArraySize = 14;
    static const int emitArraySize = 14;
    float absorbWavelength[absorbArraySize] = {350,360,370,380,390,400,410,420,430,440,450,460,470,480};
    float absorb[absorbArraySize] ={0.05,0.075,0.118,0.219,0.322,0.524,0.644,0.848,0.944,0.745,0.875,0.516,0.065,0.0};
    float emitWavelength[emitArraySize] = {470,480,490,500,510,520,530,540,550,560,570,580,590,600};
    float emit[emitArraySize] = {0.157,0.604,1.0,0.904,0.58,0.567,0.458,0.273,0.152,0.098,0.056,0.030,0.015,0.0};
*/
    // Values taken from EJ-286 datasheet.
    float qe = 92;
    static const int absorbArraySize = 15;
    static const int emitArraySize = 15;
    float absorbScale = 2.6; // The scale variables are used when the absorption/emission is given per unit thickness
    float emitScale = 1; // then scale according to your wls thickness.
    float absorbWavelength[absorbArraySize] = {280,290,300,310,320,330,340,350,360,370,380,390,400,410,420};
    float absorb[absorbArraySize] ={pow(0.54,absorbScale), pow(0.68,absorbScale), pow(0.89,absorbScale),
                                    pow(0.97,absorbScale), pow(1,absorbScale), pow(1,absorbScale), pow(1,absorbScale),
                                    pow(1,absorbScale), pow(1,absorbScale), pow(1,absorbScale), pow(1,absorbScale),
                                    pow(0.94,absorbScale), pow(0.65,absorbScale), pow(0.039,absorbScale),
                                    pow(0.0,absorbScale)};
    float emitWavelength[emitArraySize] = {390,400,410,420,430,440,450,460,470,480,490,500,510,520,530};
    float emit[emitArraySize] = {pow(0.0,emitScale), pow(0.1,emitScale), pow(0.71,emitScale), pow(0.98,emitScale),
                                 pow(0.91,emitScale), pow(0.63,emitScale), pow(0.49,emitScale), pow(0.35,emitScale),
                                 pow(0.20,emitScale), pow(0.13,emitScale), pow(0.081,emitScale), pow(0.052,emitScale),
                                 pow(0.03,emitScale), pow(0.021,emitScale), pow(0,emitScale)};


public:


    WLS(float x);
    WLS(float x, float y);
    WLS(float l[2]);
    ~WLS(){}

    int GetAbsorbArraySize();
    int GetEmitArraySize();
    std::vector<float*> GetAbsorbSpectrum();
    std::vector<float*> GetEmitSpectrum();

    float GetQE();
    bool QE();
    float GetLength(int i);
    bool Absorb(double l);
    std::vector<Photon> Emit();
    float GetRefractiveIndex();
    float GetThickness();

};







#endif //LASI_WLS_H
