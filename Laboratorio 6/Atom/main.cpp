///////////////////////////////////////////////////
///Problema 6                                   ///
///Autor: Gerardo Aldair Ponce Gomez A00818934  ///
///////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

#include "Lectora.h"
#include "Calcular.h"
#include "Imprimir.h"
#include "CalcularP.h"
#include "Rango.h"
#include "Significancia.h"
using namespace std;


extern bool vacioArch;

//.b=33
//.d=2

//.i
int main() {
  string nombreArchivo;
  cout << "Introduzca el nombre del archivo a leer: ";
  cin >> nombreArchivo;
  Lectora lector (nombreArchivo);
  Calcular calcu;
  vector<float>NumerosX;
  vector<float>NumerosY;
  float corre, correa2, b0, b1, yk, xK;
  int N;
  Significancia signi;
  Imprimir imp;
  Rango intervalo;
  if(lector.existeArchivo()){
    //Se cuentan cuantos X y Y hay (Numeros)
    lector.Contar(NumerosX,NumerosY);
    //Calcula la correlacion
    calcu.Correlacion(NumerosX, NumerosY, lector.getTotales());
    //Calcula la Regresion
    calcu.Regresion(NumerosX, NumerosY, lector.getTotales());
    N = lector.getTotales();//.m
    xK = lector.getxK(); //.m
    corre = calcu.getcorrelation(); //.m
    //Correlacion al cuadrado
    correa2 = corre * corre;//.m
    b0 = calcu.getB0();//.m
    b1 = calcu.getB1();//.m
    yk = calcu.getB0()+(calcu.getB1()*lector.getxK());//.m
  }
  else {
    imp.imprimeNoexiste(); //.m
  }

  /////////////////////////////////////////////////////

  //.b=50
  //.d=27
  float x = signi.CalculaX(corre,correa2, N);
  float dof = N-2;
  dof = floor(dof);
  //gamma1, gamma2, ope y aux son auxiliares para almacenar valores|| Gamma es el valor calculado total de gamma
  float aux = 0.0000000000;
  float errorp = 0.0001, p = 0.0000000000, p1 = 0.00000;
  //num_seg son el total de iteraciones que se realizaran para el calculo de los valores f(x)
  float num_seg = 300.0000000000, num_seg2 = 2*num_seg; //.m
  CalcularP calcuP;
  //almacena el valor para comprobar el grado de error
  float significancia;
  //ciclo que vuelve a calcular los valores de p y los comprueba hasta que se obtenga el grado de error deseado
  do{
    p = calcuP.calculaValor(x,dof,num_seg);
    p1 = calcuP.calculaValor(x,dof,num_seg2);
    aux = p - p1;
    num_seg = num_seg*2;
    num_seg2 = num_seg*2;
  }while (abs(aux) > errorp);
  significancia = signi.calcuSigni(p);

  /////////////////////////////////////////////////////

  //.b=54
  //.d=22
  p1 = calcuP.calculaValor(x,dof,num_seg);
  float errorT = 0.000000000001, difp = 1.00000;
  float pt = 0.35, d = x / 2, p2 = 0.00000;
  bool dire1 = false, dire2 = false;
  x = 1.00000;

  if (pt >=  0 && pt <= 0.5 && dof > 0) {
    //ciclo que vuelve a calcular los valores de p y los comprueba hasta que se obtenga el grado de error deseado
    while (abs(difp) > errorT) {
      //Si p es menor que la p introducida se corrige los valores de x
      if (p1 < pt) {
        x = x + d;
        p2 = calcuP.calculaValor(x,dof,num_seg);
        dire2 = true;
      }
      else{
        x = x - d;
        p2 = calcuP.calculaValor(x,dof,num_seg);
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
  }
  else {
    imp.imprimeErrorpDof();//.m
  }

  /////////////////////////////////////////////////////
  float distT = x;
  float ene = N;

  //Variable que guarda el valor de la desviacion estandar
  float desviacion = intervalo.desviacionStandar(ene, b0, b1, NumerosX, NumerosY);
  //Variable que guarda el valor del promedio del vector x
  float averageX = intervalo.promX(NumerosX);
  //Variable que guarda el valor del rango del intervalo
  float rango = intervalo.rango(distT, desviacion, ene, xK, averageX, NumerosX);
  //Variable que guarda el valor del limite superior
  float rangoUP = intervalo.rangoUP(yk, rango);
  //Variable que guarda el valor del limite inferior
  float rangoLP = intervalo.rangoLP(yk, rango);
  //Se manda a imprimir los valores calculados
  imp.vacioArchivo(vacioArch, N, xK, corre, correa2, b0, b1, yk, significancia, rango, rangoUP, rangoLP);


  system("pause");
    return 0;
}
