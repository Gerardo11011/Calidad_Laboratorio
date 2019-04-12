///////////////////////////////////////////////////
///Problema 7                                   ///
///Autor: Gerardo Aldair Ponce Gomez A00818934  ///
///////////////////////////////////////////////////
#ifndef IMPRIMIR_H
#define IMPRIMIR_H

#include <iostream>
#include <iomanip>
using namespace std;

//.b=29

class Imprimir {

    public:

      //.i
      //Funcion que imprime los resultados
      void imprimeResultados(int N, float Wk, float Xk, float Yk, float B0, float B1, float B2, float B3, float Zk) { //.m
        cout << "N = " << N << endl;
        cout << setprecision(5) << fixed;
        cout << "wk = " << Wk << endl;
        cout << "xk = " << Xk << endl;
        cout << "yk = " << Yk << endl;
        cout << "-----------------------" << endl;
        cout << "b0 = " << B0 << endl;
        cout << "b1 = " << B1 << endl;
        cout << "b2 = " << B2 << endl;
        cout << "b3 = " << B3 << endl;
        cout << "-----------------------" << endl;
        cout << "zk = " << Zk << endl;
      }

      //.i
      //Funcion que imprime mensaje de no existe archivo
      void imprimeNoexiste() {
        cout << "\nEl archivo no existe" << endl << endl;
      }

      //.i
      //Funcion que imprime que los numeros son mayor a 0
      void imprimeMayor0(){
        cout << "\nLos datos no son mayores o iguales a 0" << endl << endl;
      }

      //.i
      //Funcion que imprime mensaje de archivo vacio
      void vacioArchivo() {
        cout << "\nEl archivo esta vacio" << endl << endl;
      }

      //.d=9
      //.d=6

};

#endif
