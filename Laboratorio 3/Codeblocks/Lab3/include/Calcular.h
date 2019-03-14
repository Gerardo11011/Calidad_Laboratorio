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
  float getX(){
    return X;
  }
  //.i
  float getY(){
    return Y;
  }
  //.i
  float getcorrelation(){
    return Correlation;
  }
  //.i
  float getB0(){
    return B0;
  }
  //.i
  float getB1(){
    return B1;
  }
  //.i
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
    void Correlacion(vector<float>&NumX,vector<float>&NumY, int iN){
        Sumatorias(NumX, NumY,iN);
        Correlation =((iN * XY - X * Y) / (sqrt(iN * XX - X * X) * sqrt(iN * YY -Y * Y)));
    }
    //.i
    void Regresion(vector<float>&NumX,vector<float>&NumY, int iN){
        B1 = ((( X * Y ) - (iN * XY)) / (( X * X ) - ( iN * XX )));
        B0 = ((Y - (B1 * X)) / iN);
    }
};




#endif
