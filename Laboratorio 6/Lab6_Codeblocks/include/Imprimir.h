///////////////////////////////////////////////////
///Problema 6                                   ///
///Autor: Gerardo Aldair Ponce Gomez A00818934  ///
///////////////////////////////////////////////////
#ifndef IMPRIMIR_H
#define IMPRIMIR_H

#include <iostream>
#include <iomanip>
using namespace std;

//.b=30

class Imprimir {
    //.d=10

    public:

      //.i
      //Funcion que imprime los resultados
      void imprimeResultados(int N, float K, float R, float RR, float  B0, float B1, float YK, float signi, float rango, float LS, float LI) { //.m
        cout << setprecision(5) << fixed << endl;
        cout << "N = " << N << endl;
        cout << "xk = " << K << endl;
        cout << "r = " << R << endl;
        cout << "r2 = " << RR << endl;
        cout << "b0 = " << B0 << endl;
        cout << "b1 = " << B1 <<endl;
        cout << "yk = " << YK << endl;
        cout << setprecision(10) << fixed;
        cout << "sig = " << signi << endl;
        cout << setprecision(5) << fixed;
        cout << "ran = " << rango << endl;
        cout << "LS = " << LS << endl;
        cout << "LI = " << LI << endl << endl;
      }

      //.i
      //Funcion que imprime el mensaje de archivo inexistente
      void imprimeNoexiste() {
        cout << "\nEl archivo no existe" << endl << endl;
      }

      //.i
      //Funcion que imprime mensaje de datos invalidos
      void imprimeErrorpDof() {
        cout << "\nERROR valores invalidos" << endl << endl;
      }

      //.i
      //Funcion que imprime mensaje de error en caso de que los datos no sean mayores o iguales a 0
      void imprimeMayor0(){
        cout << "\nLos datos no son mayores o iguales a 0" << endl << endl;
      }

};

#endif
