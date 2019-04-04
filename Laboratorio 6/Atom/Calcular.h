///////////////////////////////////////////////////
///Problema 3                                   ///
///Autor: Gerardo Aldair Ponce Gomez A00818934  ///
///////////////////////////////////////////////////
#ifndef CALCULAR_H
#define CALCULAR_H
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <algorithm>
//.b=45
using namespace std;

class Calcular{
private:
    float X = 0;
    float Y = 0;
    float XY = 0;
    float XX = 0;
    float YY = 0;
    float Correlation = 0;
    float B0 = 0;
    float B1 = 0;

public:
  //.i
  //Funcion que obtiene el valor de X
  float getX(){
    return X;
  }
  //.i
  //Funcion que obtiene el valor de Y
  float getY(){
    return Y;
  }
  //.i
  //Funcion que obtiene el valor de la Correlacion
  float getcorrelation(){
    return Correlation;
  }
  //.i
  //Funcion que obtiene el valor de B0
  float getB0(){
    return B0;
  }
  //.i
  //Funcion que obtiene el valor de B1
  float getB1(){
    return B1;
  }
  //.i
  //Funcion que realiza las Sumatorias para obtener las variables necesarias para el calculo de la correlacion
  void Sumatorias(vector<float> NumX,vector<float> NumY, int iN){
      //accumulate(NumX.begin(),NumX.end(),X);
      //accumulate(NumY.begin(),NumY.end(),Y);
        for (int a = 0; a < iN; a++) {
          X += NumX[a];
          Y += NumY[a];
          XY += NumX[a]*NumY[a];
          XX += NumX[a] * NumX[a];
          YY += NumY[a] * NumY[a];
        }
    }
    //.i
    //Funcion que realza el calcula el calculo de la correlacion
    void Correlacion(vector<float>&NumX,vector<float>&NumY, int iN){
        Sumatorias(NumX, NumY,iN);
        Correlation =((iN * XY - X * Y) / (sqrt(iN * XX - X * X) * sqrt(iN * YY -Y * Y)));
    }
    //.i
    //Funcion que calcula el valor de la regresion
    void Regresion(vector<float>&NumX,vector<float>&NumY, int iN){
        B1 = ((( X * Y ) - (iN * XY)) / (( X * X ) - ( iN * XX )));
        B0 = ((Y - (B1 * X)) / iN);
    }
};




#endif
