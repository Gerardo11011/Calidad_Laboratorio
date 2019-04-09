///////////////////////////////////////////////////
///Problema 7                                   ///
///Autor: Gerardo Aldair Ponce Gomez A00818934  ///
///////////////////////////////////////////////////
#ifndef GAUSS_H
#define GAUSS_H
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <algorithm>
using namespace std;

class Gauss {

  public:
    void Calcular(float &b0,float &b1, float &b2, float &b3, float &zk, float matriz[][5], float totales, float wk, float xk, float yk) {

      ///Ciclo que recorre la matriz por el total de incognitas
          for (int i=0; i<4; i++)
          {
              /// Se encuentra el valor maximo y la posicion del mismo
              float maximo = abs(matriz[i][i]);
              int maxpos = i;
              for (int k=i+1; k<4; k++)
              {
                  if (abs(matriz[k][i]) > maximo)
                  {
                      maximo = abs(matriz[k][i]);
                      maxpos = k;
                  }
              }

              /// Se ordena la columna
              for (int k=i; k<4+1; k++)
              {
                  float temporal = matriz[maxpos][k];
                  matriz[maxpos][k] = matriz[i][k];
                  matriz[i][k] = temporal;
              }

              /// Ciclo que va a igualando a 0
              for (int k=i+1; k<4; k++)
              {
                  float cero = -matriz[k][i]/matriz[i][i];
                  for (int j=i; j<4+1; j++)
                  {
                      if (i==j)
                      {
                          matriz[k][j] = 0;
                      }
                      else
                      {
                          matriz[k][j] += cero * matriz[i][j];
                      }
                  }
              }
          }

          ///Se despeja la incognita
          b3=matriz[3][4]/matriz[3][3];
          b2=((matriz[2][4]+(-matriz[2][3]*b3))/matriz[2][2]);
          b1=((matriz[1][4]+(-matriz[1][3]*b3)+(-matriz[1][2]*b2))/matriz[1][1]);
          b0=((matriz[0][4]+(-matriz[0][3]*b3)+(-matriz[0][2]*b2)+(-matriz[0][1]*b1))/matriz[0][0]);

          zk = b0+b1*wk+b2*xk+b3*yk;
    }
};

#endif
