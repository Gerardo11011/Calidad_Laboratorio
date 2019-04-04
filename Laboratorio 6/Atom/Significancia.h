#ifndef SIGNIFICANCIA_H
#define SIGNIFICANCIA_H
#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
using namespace std;

class Significancia {
    public:
      //Funcion que calcula el valor de x para comenzar a calcular la significancia
      float CalculaX(float corre, float correa2, float n){
        float auxNum = sqrt(n-2);
        float auxDen = sqrt(1-correa2);
        float x = abs(corre) * auxNum / auxDen;
        return x;
      }

      //Funcion que calcula la significancia
      float calcuSigni(float p){
        float signi = 0.00000;
        signi = 1 - 2 * p;
        return signi;
      }


};

#endif
