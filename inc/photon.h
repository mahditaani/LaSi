//
// Created by mahdi on 05/12/17.
//

#ifndef LASI_PHOTON_H
#define LASI_PHOTON_H

class Photon{

public:

    Photon():m_lambda(0){}

    Photon(double lambda):m_lambda(lambda){}

    Photon(const Photon& obj):m_lambda(obj.m_lambda){}

    ~Photon(){}

    double lambda() {return m_lambda;}

private:

    double m_lambda;

};


#endif //LASI_PHOTON_H
