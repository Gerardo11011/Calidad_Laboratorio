  #ifndef CALCULARX_H
#define CALCULARX_H
#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>

class CalcularX {
    public:
      float CalculaX(float corre, float correa2, float n){
        float auxNum = sqrt(n-2);
        float auxDen = sqrt(1-correa2);
        float x = abs(corre) * auxNum / auxDen;
        return x;
      }
};

#endif
