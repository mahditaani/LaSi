//
// Created by mahdi on 17/01/18.
//

#ifndef LASI_WLS_H
#define LASI_WLS_H

class WLS {

    float lengthX;
    float lengthY;


public:


    WLS(float x);
    WLS(float x, float y);
    WLS(float l[2]);
    ~WLS(){}


    float GetLength(int i);


};







#endif //LASI_WLS_H
