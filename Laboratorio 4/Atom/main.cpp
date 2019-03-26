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
  //dof es igual a los grados de libertad segun el metodo simpson
  float dof = 0.00000;
  //Pay es el valor de pi
  float pay = 3.14159265358979323846;
  //gamma1, gamma2, ope y aux son auxiliares para almacenar valores|| Gamma es el valor calculado total de gamma
  float aux = 0.00000, gamma = 0.00000, ope = 0.00000;
  float gamma1 = 0.00000, gamma2 = 0.00000;
  float error = 0.0001;
  float p = 0.00000, p1 = 0.00000;
  bool err = false;
  //num_seg son el total de iteraciones que se realizaran para el calculo de los valores f(x)
  float num_seg = 10.00000, num_seg2 = 2*num_seg;
  cout << "Ingrese el valor de x: ";
  cin >> x;
  cout << "Ingrese el valor dof: ";
  cin >> dof;
  cout << endl;
  //Se asigna la preciosion a 5 digitos despues del punto
  cout << setprecision(5) << fixed;

  Calcular calcu;
  Imprimir imprime;
  //Se obtiene el booleano que verifica si los datos son validos
  err = imprime.errorResultados(x,dof);
  //IF que verifica si los datos son validos
  if (err == false) {

    //Operaciones para el calculo de toda gamma
    ope = (dof+1)/2;
    gamma1 = calcu.calculaGamma(ope);
    ope = dof/2;
    gamma2 = calcu.calculaGamma(ope);
    aux = pow((dof * pay),0.5);
    //Se almacena el valor total de gamma
    gamma = gamma1 / (aux * gamma2);

    //Se calcula el valor de p con el metodo simpson con el total de iteraciones establecidas
    p = calcu.calculaValor(x,dof,num_seg,gamma);
    //Se calcula el valor de p1 con el metodo simpson con el doble de iteraciones de P
    p1 = calcu.calculaValor(x,dof,num_seg2,gamma);
    //almacena el valor para comprobar el grado de error
    aux = p - p1;

    //ciclo que vuelve a calcular los valores de p y los comprueba hasta que se obtenga el grado de error deseado
    while (aux > error) {
      p = calcu.calculaValor(x,dof,num_seg,gamma);
      p1 = calcu.calculaValor(x,dof,num_seg2,gamma);
      aux = p - p1;
      num_seg = num_seg*2;
      num_seg2 = num_seg*2;
    }
    //Se imprime el valor de p
    imprime.imprimeResultados(x,dof,p);
  }
  //Else en el que se imprime el mensaje de error
  else {
    imprime.imprimeError();
  }

  //system("pause");
  return 0;
}
