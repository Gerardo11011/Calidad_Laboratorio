///////////////////////////////////////////////////
///Problema 5                                   ///
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
//.b=50
//.d=2


//.i
int main() {
  float x = 1.00000; //.m
  //dof es igual a los grados de libertad segun el metodo simpson
  float dof = 0.00000;
  //gamma1, gamma2, ope y aux son auxiliares para almacenar valores|| Gamma es el valor calculado total de gamma
  float aux = 0.00000, gamma = 0.00000, ope = 0.00000;
  float gamma1 = 0.00000, gamma2 = 0.00000;
  float error = 0.000000000001, difp = 1.00000; //.m
  float p1 = 0.00000, pt = 0.00000, d = x / 2, p2 = 0.00000;
  bool dire1 = false, dire2 = false; //.m
  //num_seg son el total de iteraciones que se realizaran para el calculo de los valores f(x)
  float num_seg = 100.00000; //.m
  cout << "Ingrese el valor de p: "; //.m
  cin >> pt; //.m
  cout << "Ingrese el valor dof: ";
  cin >> dof;

  //If que valida los datos ingresados
  if (pt >=  0 && pt <= 0.5 && dof > 0) {

    dof = floor(dof);
    cout << endl;
    //Se asigna la preciosion a 5 digitos despues del punto
    cout << setprecision(5) << fixed;

    //.d=13
    Calcular calcu;
    Imprimir imprime;

    //Operaciones para el calculo de toda gamma
    ope = (dof+1)/2;
    gamma1 = calcu.calculaGamma(ope);
    ope = dof/2;
    gamma2 = calcu.calculaGamma(ope);
    aux = pow((dof * pi),0.5);
    //Se almacena el valor total de gamma
    gamma = gamma1 / (aux * gamma2);

    //Se calcula el valor de p con el metodo simpson con el total de iteraciones establecidas
    p1 = calcu.calculaValor(x,dof,num_seg,gamma);


    //ciclo que vuelve a calcular los valores de p y los comprueba hasta que se obtenga el grado de error deseado
    while (abs(difp) > error) {
      //Si p es menor que la p introducida se corrige los valores de x
      if (p1 < pt) {
        x = x + d;
        p2 = calcu.calculaValor(x,dof,num_seg,gamma);
        dire2 = true;
    }
    else{
      x = x - d;
      p2 = calcu.calculaValor(x,dof,num_seg,gamma);
      dire2 = false;
    }
    //Se calcula el error de p
    difp = p2-p1;
    //Se guarda el nuevo valor de p
    p1 = p2;
    //If que comprueba si hubo cambio de direccion
    if (dire1 != dire2) {
      d = d / 2;
    }
    //Se le asigna la misma direccion por si cambia de direccion
    dire1 = dire2;
    }
    //Se imprime el valor de p
    imprime.imprimeResultados(x,dof,pt);

  }
  //Else en el que se imprime el mensaje de error
  else {
    cout << endl;
    cout << "ERROR valores invalidos" << endl;
  }

  //system("pause");
  return 0;
}
