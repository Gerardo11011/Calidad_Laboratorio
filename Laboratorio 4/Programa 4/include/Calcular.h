///////////////////////////////////////////////////
///Problema 4                                   ///
///Autor: Gerardo Aldair Ponce Gomez A00818934  ///
///////////////////////////////////////////////////
#ifndef CALCULAR_H
#define CALCULAR_H
#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
#include <cmath>
//.b=45
using namespace std;
//.d=4
const float pi = 3.14159265358979323846;


class Calcular{
private:
  int dof;
  float x;
public:
  //.d=15
  //.i
  Calcular(int grados, float equis){
    int dof = grados;
    float x = equis;
  }
  //.d=13
  //.i
  float calculaGamma(float x){
    if (x == 1) {
      return 1;
    }
    else if (x == 0.5) {
      return sqrt(pi);
    }
    else {
      return (x-1) * calculaGamma(x-1);
    }
  }
  //.i
  float calculaValor(float x, int dof, float num_seg, float gamma){
    float xi = 0.00000;
    float W = x/num_seg;
    float step1 = 0.00000, step2 = 0.00000, aux = 0.00000;
    float fx = 0.00000;
    vector <float> myVector;
    for (float i = 0.00000; i <= num_seg; i++) {
      xi = W * i;
      step1 = 1.00000 + (xi * xi / dof);
      aux = -((dof + 1.00000) / 2.00000 );
      step2 = pow(step1,aux);
      fx = gamma * step2;
      myVector.push_back(fx);
    }

    float acum4 = 0.00000;

    for (float i = 1.00000; i <= num_seg - 1.00000; i+=2.00000) {
      aux = 4 * myVector[i];
      acum4 = acum4 + aux;
    }

    float acum2 = 0.00000;
    for (float i = 2.00000; i <= num_seg - 2.00000; i+=2.00000) {
      aux = 2 * myVector[i];
      acum2 = acum2 + aux;
    }

    float p = 0.00000;
    aux = W/3;
    p = aux * (myVector[0] + acum4 + acum2 + myVector[num_seg]);
    return p;
  }
};
#endif
