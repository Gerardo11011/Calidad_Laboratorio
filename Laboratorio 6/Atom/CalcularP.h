///////////////////////////////////////////////////
///Problema 4                                   ///
///Autor: Gerardo Aldair Ponce Gomez A00818934  ///
///////////////////////////////////////////////////
#ifndef CALCULARP_H
#define CALCULARP_H
#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
#include <cmath>
//.b=45
using namespace std;
//.d=4
const float pi = 3.14159265358979323846;


class CalcularP{ //.m
private:
  int dof;
  float x;
public:
  //.i
  //Funcion que calcula el valor de gamma
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
  //Funcion que calcula el valor de la distribucion y obtiene el valor de la integral por el metodo de simpsons
  float calculaValor(float x, float dof, float num_seg){
    float xi = 0.0000000000;
    float W = x/num_seg;
    float step1 = 0.0000000000, step2 = 0.0000000000, aux = 100.0000000000;
    float fx = 0.0000000000;
    vector <float> myVector;
    float gamma = 0.0000000000, ope = 0.0000000000;
    float gamma1 = 0.0000000000, gamma2 = 0.0000000000;

    //Se calcula gamma
    ope = (dof+1)/2;
    gamma1 = calculaGamma(ope);
    ope = dof/2;
    gamma2 = calculaGamma(ope);
    aux = pow((dof * pi),0.5);
    //Se almacena el valor total de gamma
    gamma = gamma1 / (aux * gamma2);

    //Ciclo for que calcula el valor de todos los f(x)
    for (float i = 0.0000000000; i <= num_seg; i++) {
      xi = W * i;
      step1 = 1.0000000000 + (xi * xi / dof);
      aux = -((dof + 1.0000000000) / 2.0000000000 );
      step2 = pow(step1,aux);
      fx = gamma * step2;
      myVector.push_back(fx);
    }

    //Acumulador para cuando los variables se multiplican por 4
    float acum4 = 0.0000000000;
    //Ciclo for que multiplica los valores f(x) por 4 de acuerdo al metodo simpson
    for (float i = 1.0000000000; i <= num_seg - 1.0000000000; i+=2.0000000000) {
      aux = 4 * myVector[i];
      acum4 = acum4 + aux;
    }
    //Acumulador que almacena los valores de las variables multiplicadas por 2
    float acum2 = 0.0000000000;
    //Ciclo for que multiplica los valores f(x) por 4 de acuerdo al metodo simpson
    for (float i = 2.0000000000; i <= num_seg - 2.0000000000; i+=2.0000000000) {
      aux = 2 * myVector[i];
      acum2 = acum2 + aux;
    }

    float p = 0.0000000000;
    aux = W/3;
    //Se calcula el valor de p de acuerdo a la formula por el metodo simpson
    p = aux * (myVector[0] + acum4 + acum2 + myVector[num_seg]);
    return p;
  }
};
#endif
