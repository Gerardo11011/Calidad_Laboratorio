///////////////////////////////////////////////////
///Problema 7                                   ///
///Autor: Gerardo Aldair Ponce Gomez A00818934  ///
///////////////////////////////////////////////////

//Programa que calcula los diferentes parametros de regresion multiple Y una prediccion mejorada zk

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
  vector<float> X;
  vector<float> Y;
  vector<float> Z;
  vector<float> W;
  string NombreArchivo;
  float B0 = 0, B1 = 0, B2 = 0, B3 = 0 , Zk = 0;
  float Wk, Yk, Xk;
  cout << "Introduzca el nombre del archivo a leer: ";
  cin >> NombreArchivo;
  Lectora Lector (NombreArchivo);
  Imprimir Imprime;
  //IF que comprueba si el archivo ingresado existe
  if (Lector.existeArchivo()){
    Lector.Contar(X,Y,Z,W);
    //IF que comprueva que si el archivo esta vacio
    if (!Lector.getVacioArchivo()) {
      Wk = Lector.getwk();
      Yk = Lector.getyk();
      Xk = Lector.getxk();
      //IF que comprueba que todos los valores sean mayor o igual a 0
      if (!Lector.getNumerror()) {
        Matriz matrix;
        Gauss gauss;
        float totales = Lector.getTotales();
        float matriz[4][5] = {0};
        //Se calcula la matriz
        matrix.calcuRenglones(W,X,Y,Z, totales, matriz);
        //Se aplica el metodo de gauss para resolver la matriz
        gauss.Calcular(B0,B1,B2,B3, Zk, matriz, totales, Wk, Xk, Yk);
        //Se imprime los resultados
        Imprime.imprimeResultados(totales, Wk, Xk, Yk, B0, B1, B2, B3, Zk);
      }
      //Se imprime mensaje de error en caso de que los numeros no sean mayores o iguales a 0
      else {
        Imprime.imprimeMayor0();
      }
    }
    //Se imprime el mensaje de que el archivo esta vacio
    else {
      Imprime.vacioArchivo();
    }
  }
  //Se imprime mensaje de que el archvio no existe
  else {
    Imprime.imprimeNoexiste();
  }

  system("pause");
  return 0;
}
