///////////////////////////////////////////////////
///Problema 4                                   ///
///Autor: Gerardo Aldair Ponce Gomez A00818934  ///
///////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <iomanip>
#include "Calcular.h"
#include "Imprimir.h"
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//.b=28
vector<float>NumerosX;
vector<float>NumerosY;
//.d=22


int main() {
  float x = 0.00000;
  float dof = 0.00000;
  float pay = 3.14159265358979323846;
  float aux = 0.00000, gamma = 0.00000, ope = 0.00000;
  float gamma1 = 0.00000, gamma2 = 0.00000;
  float error = 0.0001;
  float p = 0.00000, p1 = 0.00000;
  bool err = false;
  float num_seg = 10, num_seg2 = 2*num_seg;
  cout << "Ingrese el valor de x: ";
  cin >> x;
  cout << "Ingrese el valor dof: ";
  cin >> dof;
  cout << endl;
  cout << setprecision(5) << fixed;

  Calcular calcu;
  Imprimir imprime;
  err = imprime.errorResultados(x,dof);
  if (err == false) {
    ope = (dof+1)/2;
    gamma1 = calcu.calculaGamma(ope);
    ope = dof/2;
    gamma2 = calcu.calculaGamma(ope);
    aux = pow((dof * pay),0.5);
    gamma = gamma1 / (aux * gamma2);

    p = calcu.calculaValor(x,dof,num_seg,gamma);
    p1 = calcu.calculaValor(x,dof,num_seg2,gamma);
    aux = p - p1;

    while (aux > error) {
      p = calcu.calculaValor(x,dof,num_seg,gamma);
      p1 = calcu.calculaValor(x,dof,num_seg2,gamma);
      aux = p - p1;
      num_seg = num_seg*2;
      num_seg2 = num_seg*2;
    }


    imprime.imprimeResultados(x,dof,p);
  }
  else {
    imprime.imprimeError();
  }


  //system("pause");
  return 0;
}
