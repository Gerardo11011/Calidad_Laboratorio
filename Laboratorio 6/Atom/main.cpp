///////////////////////////////////////////////////
///Problema 6                                   ///
///Autor: Gerardo Aldair Ponce Gomez A00818934  ///
///////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <iomanip>
#include "Lectora.h"
#include "Calcular.h"
#include "Imprimir.h"
#include "CalcularP.h"
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include "CalcularX.h"
using namespace std;
vector<float>NumerosX;
vector<float>NumerosY;
extern bool vacioArch;

int main() {
    string nombreArchivo;
    cout << "Introduzca el nombre del archivo a leer: ";
    cin >> nombreArchivo;
    Lectora lector (nombreArchivo);
    Calcular calcu;
    float corre, correa2, b0, b1, yk, xK;
    int N;
    CalcularX calcux;
    Imprimir imp;

    if(lector.existeArchivo()){
        lector.Contar(NumerosX,NumerosY);
        calcu.Correlacion(NumerosX, NumerosY, lector.getTotales());
        calcu.Regresion(NumerosX, NumerosY, lector.getTotales());
        N = lector.getTotales();//.m
        xK = lector.getxK(); //.m
        corre = calcu.getcorrelation(); //.m
        correa2 = corre * corre;//.m
        b0 = calcu.getB0();//.m
        b1 = calcu.getB1();//.m
        yk = calcu.getB0()+(calcu.getB1()*lector.getxK());//.m
        imp.vacioArchivo(vacioArch, N, xK, corre, correa2, b0, b1, yk);
    }
    else {
      imp.imprimeNoexiste(); //.m
    }

    float x = calcux.CalculaX(corre,correa2, N);


    ///////////////////

    float dof = N-2;
    //Pay es el valor de pi
    float pay = 3.14159265358979323846;
    //gamma1, gamma2, ope y aux son auxiliares para almacenar valores|| Gamma es el valor calculado total de gamma
    float aux = 100.0000000000, gamma = 0.0000000000, ope = 0.0000000000;
    float gamma1 = 0.0000000000, gamma2 = 0.0000000000;
    float errorp = 0.0001;
    float p = 0.0000000000, p1 = 0.00000;
    //num_seg son el total de iteraciones que se realizaran para el calculo de los valores f(x)
    float num_seg = 300.0000000000, num_seg2 = 2*num_seg;

    CalcularP calcuP;
      //Operaciones para el calculo de toda gamma
      ope = (dof+1)/2;
      gamma1 = calcuP.calculaGamma(ope);
      ope = dof/2;
      gamma2 = calcuP.calculaGamma(ope);
      aux = pow((dof * pay),0.5);
      //Se almacena el valor total de gamma
      gamma = gamma1 / (aux * gamma2);


      //almacena el valor para comprobar el grado de error
      float signi;
      //ciclo que vuelve a calcular los valores de p y los comprueba hasta que se obtenga el grado de error deseado
      do{
        p = calcuP.calculaValor(x,dof,num_seg,gamma);
        p1 = calcuP.calculaValor(x,dof,num_seg2,gamma);
        aux = p - p1;
        num_seg = num_seg*2;
        num_seg2 = num_seg*2;
      }while (abs(aux) > errorp);


      signi = 1 - 2 * p;


      //////////////////////////////////////////


      p1 = calcuP.calculaValor(x,dof,num_seg,gamma);

      float errorT = 0.000000000001, difp = 1.00000;

      float pt = 0.35, d = x / 2, p2 = 0.00000;
      bool dire1 = false, dire2 = false;
      x = 1.00000;


      //ciclo que vuelve a calcular los valores de p y los comprueba hasta que se obtenga el grado de error deseado
      while (abs(difp) > errorT) {
        //Si p es menor que la p introducida se corrige los valores de x
        if (p1 < pt) {
          x = x + d;
          p2 = calcuP.calculaValor(x,dof,num_seg,gamma);
          dire2 = true;
      }
      else{
        x = x - d;
        p2 = calcuP.calculaValor(x,dof,num_seg,gamma);
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

      float distT = x;

      float ene = N;

      float desviacion = calcux.desviacionStandar(ene, b0, b1, NumerosX, NumerosY);
      float averageX = calcux.promX(NumerosX);
      float rango = calcux.rango(distT, desviacion, ene, xK, averageX, NumerosX);
      float rangoUP = calcux.rangoUP(yk, rango);
      float rangoLP = calcux.rangoLP(yk, rango);

      imp.imprimeFaltantes(signi, rango, rangoUP, rangoLP);


    system("pause");
    return 0;
}
