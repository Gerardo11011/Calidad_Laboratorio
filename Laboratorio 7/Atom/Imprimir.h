///////////////////////////////////////////////////
///Problema 7                                   ///
///Autor: Gerardo Aldair Ponce Gomez A00818934  ///
///////////////////////////////////////////////////
#ifndef IMPRIMIR_H
#define IMPRIMIR_H

#include <iostream>
#include <iomanip>
using namespace std;

//.b=30

class Imprimir {

    public:

      //.i
      //Funcion que imprime los resultados
      void imprimeResultados(int N, float wk, float xk, float yk, float b0, float b1, float b2, float b3, float zk) { //.m
        cout << "N = " << N << endl;
        cout << setprecision(5) << fixed;
        cout << "wk = " << wk << endl;
        cout << "xk = " << xk << endl;
        cout << "yk = " << yk << endl;
        cout << "-----------------------" << endl;
        cout << "b0 = " << b0 << endl;
        cout << "b1 = " << b1 << endl;
        cout << "b2 = " << b2 << endl;
        cout << "b3 = " << b3 << endl;
        cout << "-----------------------" << endl;
        cout << "zk = " << zk << endl;
      }

      void imprimeNoexiste() {
        cout << "\nEl archivo no existe" << endl << endl;
      }

      void imprimeMayor0(){
        cout << "\nLos datos no son mayores o iguales a 0" << endl << endl;
      }

      void vacioArchivo() {
        cout << "\nEl archivo esta vacio" << endl << endl;
      }

      //d.9
      //.d=6

};

#endif
