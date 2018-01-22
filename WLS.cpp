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