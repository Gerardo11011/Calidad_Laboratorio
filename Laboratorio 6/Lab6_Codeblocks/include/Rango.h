///////////////////////////////////////////////////
///Problema 6                                   ///
///Autor: Gerardo Aldair Ponce Gomez A00818934  ///
///////////////////////////////////////////////////
#ifndef RANGO_H
#define RANGO_H
#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
using namespace std;

class Rango {
    public:

      ///Funcion que calcula la desviacion estandar
      //.i
      float desviacionStandar(float N, float b0, float b1, vector <float> &NumX,vector <float> &NumY){
        float acum = 0.00000, aux = 0.00000;
        for (int i = 0; i < N; i++) {
          aux = NumY[i] - b0 - b1 * NumX[i];
          acum = acum + pow(aux, 2);
        }
        aux = 1 / (N - 2);
        float ope = 0.00000, aux2 = 0.00000;
        aux2 = aux * acum;
        ope = sqrt(aux2);
        return ope;
      }

      //Funcion que calcula el promedio del vector
      //.i
      float promX(vector <float> &NumX){
        float acum = 0.00000;
        float tamano = NumX.size();
        for (int i = 0; i < tamano; i++) {
          acum = acum + NumX[i];
        }
        float average = 0.00000;
        average = acum / tamano;
        return average;
      }

      //.i
      //Funcion que calcula el rango de un intervalo
      float rango(float distT, float desviacion, float N, float xk, float aveX, vector <float> &NumX){
        float tamano = NumX.size();
        float denominador = 0.00000, aux = 0.00000;
        for (int i = 0; i < tamano; i++) {
          aux = NumX[i] - aveX;
          denominador = denominador + pow(aux,2);
        }
        float numerador = 0.00000;
        aux = xk - aveX;
        numerador = pow(aux,2);
        aux = 1 / N;
        float raiz = 0.00000, ope = 0.00000, division = 0.00000;
        division = numerador / denominador;
        ope = 1 + aux + division;
        raiz = sqrt(ope);
        float result = 0.00000;
        result = distT * desviacion * raiz;
        return result;
      }

      //.i
      //Funcion que calcula el Limite superior
      float rangoUP(float yk, float rango){
        float result = 0.00000;
        result = yk + rango;
        return result;
      }

      //.i
      //Funcion que calcula el Limite Inferior
      float rangoLP(float yk, float rango){
        float result = 0.00000;
        result = yk - rango;
        if (result > 0) {
          return result;
        }
        else {
          result = 0;
          return result;
        }
      }
};

#endif
