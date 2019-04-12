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
    void calcuRenglones(vector<float>& NumW, vector<float>& NumX, vector<float>& NumY, vector<float>& NumZ, float totales, float Matriz[][5]) {
      ////////RENGLON 1////////
      //B0
      Matriz[0][0] = totales;
      float Aux = 0;
      //B1
      for (int i = 0; i < totales; i++) {
        Aux = Aux + NumW[i];
      }

      Matriz[0][1] = Aux;
      Aux = 0;

      //B2
      for (int i = 0; i < totales; i++) {
        Aux = Aux + NumX[i];
      }
      Matriz[0][2] = Aux;
      Aux = 0;

      //B3
      for (int i = 0; i < totales; i++) {
        Aux = Aux + NumY[i];
      }
      Matriz[0][3] = Aux;
      Aux = 0;

      //B4
      for (int i = 0; i < totales; i++) {
        Aux = Aux + NumZ[i];
      }
      Matriz[0][4] = Aux;


      ////////RENGLON 2////////
      //B0
      Aux = 0;
      for (int i = 0; i < totales; i++) {
        Aux = Aux + NumW[i];
      }
      Matriz[1][0] = Aux;
      Aux = 0;

      //B1
      for (int i = 0; i < totales; i++) {
        Aux = Aux + pow(NumW[i],2);
      }
      Matriz[1][1] = Aux;
      Aux = 0;

      //B2
      for (int i = 0; i < totales; i++) {
        Aux = Aux + NumX[i] * NumW[i];
      }

      Matriz[1][2] = Aux;
      Aux = 0;

      //B3
      for (int i = 0; i < totales; i++) {
        Aux = Aux + NumY[i] * NumW[i];
      }

      Matriz[1][3] = Aux;
      Aux = 0;

      //B4
      for (int i = 0; i < totales; i++) {
        Aux = Aux + NumZ[i] * NumW[i];
      }
      Matriz[1][4] = Aux;

      ////////RENGLON 3////////
      //B0
      Aux = 0;
      for (int i = 0; i < totales; i++) {
        Aux = Aux + NumX[i];
      }
      Matriz[2][0] = Aux;
      Aux = 0;

      //B1
      for (int i = 0; i < totales; i++) {
        Aux = Aux + NumW[i] * NumX[i];
      }
      Matriz[2][1] = Aux;
      Aux = 0;

      //B2
      for (int i = 0; i < totales; i++) {
        Aux = Aux + pow(NumX[i], 2);
      }

      Matriz[2][2] = Aux;
      Aux = 0;

      //B3
      for (int i = 0; i < totales; i++) {
        Aux = Aux + NumY[i] * NumX[i];
      }

      Matriz[2][3] = Aux;
      Aux = 0;

      //B4
      for (int i = 0; i < totales; i++) {
        Aux = Aux + NumZ[i] * NumX[i];
      }
      Matriz[2][4] = Aux;


      ////////RENGLON 4////////
      //B0
      Aux = 0;
      for (int i = 0; i < totales; i++) {
        Aux = Aux + NumY[i];
      }
      Matriz[3][0] = Aux;
      Aux = 0;

      //B1
      for (int i = 0; i < totales; i++) {
        Aux = Aux + NumW[i] * NumY[i];
      }
      Matriz[3][1] = Aux;
      Aux = 0;

      //B2
      for (int i = 0; i < totales; i++) {
        Aux = Aux + NumX[i] * NumY[i];
      }

      Matriz[3][2] = Aux;
      Aux = 0;

      //B3
      for (int i = 0; i < totales; i++) {
        Aux = Aux + pow(NumY[i], 2);
      }

      Matriz[3][3] = Aux;
      Aux = 0;

      //B4
      for (int i = 0; i < totales; i++) {
        Aux = Aux + NumZ[i] * NumY[i];
      }
      Matriz[3][4] = Aux;
    }
};

#endif
