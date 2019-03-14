//
//  Gamma.h
//  Calidad_4
//
//  Created by Francisco Javier Simón Muñoz on 3/9/19.
//  Copyright © 2019 Francisco Simón. All rights reserved.
//

#ifndef Gamma_h
#define Gamma_h
#include <ctype.h>
#include <cmath>
#include <math.h>
# define M_PI           3.14159265358979323846  /* pi */
using namespace std;
//.i
class Gamma{
private:
    float iX = 0;
public:
    float CalGamm(float iX);
};
//.i
float Gamma::CalGamm(float iX){
    if(iX == 1){
        return 1;
    }
    else if (iX == 0.5){
        return sqrt(M_PI);
    }
    else {
        return ((iX-1)*(CalGamm(iX-1)));
    }
}


#endif /* Gamma_h */
