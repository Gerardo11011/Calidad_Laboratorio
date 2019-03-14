//
//  Calcular.h
//  Calidad_4
//
//  Created by Francisco Javier Simón Muñoz on 3/9/19.
//  Copyright © 2019 Francisco Simón. All rights reserved.
//

#ifndef Calcular_h
#define Calcular_h
#include <iostream>
#include <cmath>
#include "Gamma.h"
#include <math.h>
# define M_PI           3.14159265358979323846  /* pi */
using namespace std;
//.i
class Calcular{
public:
    float calculaP(float iX, float idof);
    float calculaF(float idof, float valor);
};
//.i
float Calcular::calculaP(float iX, float idof){
    float segment = 10.00000;
    float iW = iX/segment;
    float iF0 = calculaF(idof, 0.00000);
    float iF1 = 0;
    float iF2 = 0;

    cout << "IF0: "<< iF0 << endl;
    for (float a = 1.00000; a <= segment-1.00000; a+=2.00000) {
        iF1 += (4.00000*(calculaF(idof,(a*iW))));
        cout << "IF: "<< a << " : " << iF1 << endl;
    }
    for (float a = 2.00000; a <= segment-2.00000; a+=2.00000) {
        iF2 += (2.00000*(calculaF(idof,(a*iW))));
        cout << "IF: "<< a << " : " << iF2<< endl;
    }
    float iF3 = calculaF(idof, iX);
    float res = ((iW/3.00000)*(iF0+iF1+iF2+iF3));
    return res;
}
//.i
float Calcular::calculaF(float idof, float valor){
    Gamma ganma;
    float cal1 = ganma.CalGamm((idof+1.00000)/2.00000);
    float cal2 = ganma.CalGamm(idof/2.00000);
    float cal3 = pow((idof*M_PI),(1.00000/2.00000));
    float cal4 = pow((1.00000+(pow(valor, 2.00000)/idof)),-((idof+1.00000)/2.00000));
    float res = (cal1/(cal3*cal2)*cal4);
    return res;
}


#endif /* Calcular_h */
