///////////////////////////////////////////////////
///Problema 7                                   ///
///Autor: Gerardo Aldair Ponce Gomez A00818934  ///
///////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include "Lectora.h"
#include "Matriz.h"
#include "Imprimir.h"
#include "Gauss.h"

using namespace std;

//.i
int main(int argc, char const *argv[]) {
  vector<float> x;
  vector<float> y;
  vector<float> z;
  vector<float> w;
  string nombreArchivo;
  float b0 = 0, b1 = 0, b2 = 0, b3 = 0 , zk = 0;
  float wk, yk, xk;
  cout << "Introduzca el nombre del archivo a leer: ";
  cin >> nombreArchivo;
  Lectora lector (nombreArchivo);
  Imprimir imprime;
  //IF que comprueba si el archivo ingresado existe
  if (lector.existeArchivo()){
    lector.Contar(x,y,z,w);
    //IF que comprueva que si el archivo esta vacio
    if (!lector.getVacioArchivo()) {
      wk = lector.getwk();
      yk = lector.getyk();
      xk = lector.getxk();
      //IF que comprueba que todos los valores sean mayor o igual a 0
      if (!lector.getNumerror()) {
        Matriz matrix;
        Gauss gauss;
        float totales = lector.getTotales();
        float matriz[4][5] = {0};
        //Se calcula la matriz
        matrix.calcuRenglones(w,x,y,z, totales, matriz);
        //Se aplica el metodo de gauss para resolver la matriz
        gauss.Calcular(b0,b1,b2,b3, zk, matriz, totales, wk, xk, yk);
        //Se imprime los resultados
        imprime.imprimeResultados(totales, wk, xk, yk, b0, b1, b2, b3, zk);
      }
      //Se imprime mensaje de error en caso de que los numeros no sean mayores o iguales a 0
      else {
        imprime.imprimeMayor0();
      }
    }
    //Se imprime el mensaje de que el archivo esta vacio
    else {
      imprime.vacioArchivo();
    }
  }
  //Se imprime mensaje de que el archvio no existe
  else {
    imprime.imprimeNoexiste();
  }

  system("pause");
  return 0;
}
