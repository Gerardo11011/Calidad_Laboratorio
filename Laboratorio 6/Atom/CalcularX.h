#ifndef CALCULARX_H
#define CALCULARX_H
#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
using namespace std;

class CalcularX {
    public:
      float CalculaX(float corre, float correa2, float n){
        float auxNum = sqrt(n-2);
        float auxDen = sqrt(1-correa2);
        float x = abs(corre) * auxNum / auxDen;
        return x;
      }

      ///Funcion que calcula la desviacion estandar
      float desviacionStandar(int N, float b0, float b1, vector <float> &NumX,vector <float> &NumY){
        float acum = 0.00000, aux = 0.00000;
        for (int i = 0; i < N; i++) {
          aux = NumY[i] - b0 - b1 * NumX[i];
          acum = acum + pow(aux, 2);
        }
        aux = (1 / (N - 2));
        float ope = 0.00000, aux2 = 0.00000;
        aux2 = aux * acum;
        ope = sqrt(aux2);
        return ope;
      }
};

#endif
