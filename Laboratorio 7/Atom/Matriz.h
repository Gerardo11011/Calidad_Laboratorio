///////////////////////////////////////////////////
///Problema 7                                   ///
///Autor: Gerardo Aldair Ponce Gomez A00818934  ///
///////////////////////////////////////////////////
#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <algorithm>

using namespace std;

class Matriz {

    public:
      //.i
    void calcuRenglones(vector<float>& NumW, vector<float>& NumX, vector<float>& NumY, vector<float>& NumZ, float totales, float matriz[][5]) {
      ////////RENGLON 1////////
      //B0
      matriz[0][0] = totales;
      float aux = 0;
      //B1
      for (int i = 0; i < totales; i++) {
        aux = aux + NumW[i];
      }

      matriz[0][1] = aux;
      aux = 0;

      //B2
      for (int i = 0; i < totales; i++) {
        aux = aux + NumX[i];
      }
      matriz[0][2] = aux;
      aux = 0;

      //B3
      for (int i = 0; i < totales; i++) {
        aux = aux + NumY[i];
      }
      matriz[0][3] = aux;
      aux = 0;

      //B4
      for (int i = 0; i < totales; i++) {
        aux = aux + NumZ[i];
      }
      matriz[0][4] = aux;


      ////////RENGLON 2////////
      //B0
      aux = 0;
      for (int i = 0; i < totales; i++) {
        aux = aux + NumW[i];
      }
      matriz[1][0] = aux;
      aux = 0;

      //B1
      for (int i = 0; i < totales; i++) {
        aux = aux + pow(NumW[i],2);
      }
      matriz[1][1] = aux;
      aux = 0;

      //B2
      for (int i = 0; i < totales; i++) {
        aux = aux + NumX[i] * NumW[i];
      }

      matriz[1][2] = aux;
      aux = 0;

      //B3
      for (int i = 0; i < totales; i++) {
        aux = aux + NumY[i] * NumW[i];
      }

      matriz[1][3] = aux;
      aux = 0;

      //B4
      for (int i = 0; i < totales; i++) {
        aux = aux + NumZ[i] * NumW[i];
      }
      matriz[1][4] = aux;

      ////////RENGLON 3////////
      //B0
      aux = 0;
      for (int i = 0; i < totales; i++) {
        aux = aux + NumX[i];
      }
      matriz[2][0] = aux;
      aux = 0;

      //B1
      for (int i = 0; i < totales; i++) {
        aux = aux + NumW[i] * NumX[i];
      }
      matriz[2][1] = aux;
      aux = 0;

      //B2
      for (int i = 0; i < totales; i++) {
        aux = aux + pow(NumX[i], 2);
      }

      matriz[2][2] = aux;
      aux = 0;

      //B3
      for (int i = 0; i < totales; i++) {
        aux = aux + NumY[i] * NumX[i];
      }

      matriz[2][3] = aux;
      aux = 0;

      //B4
      for (int i = 0; i < totales; i++) {
        aux = aux + NumZ[i] * NumX[i];
      }
      matriz[2][4] = aux;


      ////////RENGLON 4////////
      //B0
      aux = 0;
      for (int i = 0; i < totales; i++) {
        aux = aux + NumY[i];
      }
      matriz[3][0] = aux;
      aux = 0;

      //B1
      for (int i = 0; i < totales; i++) {
        aux = aux + NumW[i] * NumY[i];
      }
      matriz[3][1] = aux;
      aux = 0;

      //B2
      for (int i = 0; i < totales; i++) {
        aux = aux + NumX[i] * NumY[i];
      }

      matriz[3][2] = aux;
      aux = 0;

      //B3
      for (int i = 0; i < totales; i++) {
        aux = aux + pow(NumY[i], 2);
      }

      matriz[3][3] = aux;
      aux = 0;

      //B4
      for (int i = 0; i < totales; i++) {
        aux = aux + NumZ[i] * NumY[i];
      }
      matriz[3][4] = aux;
    }
};

#endif
