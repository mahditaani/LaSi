//
// Created by mahdi on 22/01/18.
//

#ifndef LASI_DATA_H
#define LASI_DATA_H

#include <cstdlib>



struct detected {

    double wavelength; // Stores the wavelength of the detected photon.
    std::string material; // Stores whether the photon was detected in the PMT or WLS.

};


#endif //LASI_DATA_H
