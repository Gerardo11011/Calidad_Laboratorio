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
    //.i
    void Calcular(float &B0,float &B1, float &B2, float &B3, float &Zk, float Matriz[][5], float Totales, float Wk, float Xk, float Yk) {

      ///Ciclo que recorre la Matriz por el total de incognitas
      for (int i=0; i<4; i++){
        /// Se encuentra el valor Maximo y la posicion del mismo
        float Maximo = abs(Matriz[i][i]);
        int Maxpos = i;
        for (int k=i+1; k<4; k++){
          if (abs(Matriz[k][i]) > Maximo){
            Maximo = abs(Matriz[k][i]);
            Maxpos = k;
          }
        }

        /// Se ordena la columna
        for (int k=i; k<4+1; k++){
          float Temporal = Matriz[Maxpos][k];
          Matriz[Maxpos][k] = Matriz[i][k];
          Matriz[i][k] = Temporal;
        }

        /// Ciclo que va a igualando a 0
        for (int k=i+1; k<4; k++){
          float Cero = -Matriz[k][i]/Matriz[i][i];
          for (int j=i; j<4+1; j++){
            if (i==j){
              Matriz[k][j] = 0;
            }
            else{
              Matriz[k][j] += Cero * Matriz[i][j];
            }
          }
        }
      }

      ///Se despeja la incognita
      B3=Matriz[3][4]/Matriz[3][3];
      B2=((Matriz[2][4]+(-Matriz[2][3]*B3))/Matriz[2][2]);
      B1=((Matriz[1][4]+(-Matriz[1][3]*B3)+(-Matriz[1][2]*B2))/Matriz[1][1]);
      B0=((Matriz[0][4]+(-Matriz[0][3]*B3)+(-Matriz[0][2]*B2)+(-Matriz[0][1]*B1))/Matriz[0][0]);

      Zk = B0+B1*Wk+B2*Xk+B3*Yk;
    }
};

#endif
