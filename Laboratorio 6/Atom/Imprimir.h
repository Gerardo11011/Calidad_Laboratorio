///////////////////////////////////////////////////
///Problema 3                                   ///
///Autor: Gerardo Aldair Ponce Gomez A00818934  ///
///////////////////////////////////////////////////
#ifndef IMPRIMIR_H
#define IMPRIMIR_H

#include <iostream>
#include <iomanip>
using namespace std;

//.b=42
//.d=31

class Imprimir {
    private:
      int conta = 0;
      int xK = 0;
      float r = 0.0;
      float rr = 0.0;
      float b0 = 0.0;
      float b1 = 0.0;
      float yk = 0.0;

    public:
      //.i
      //Funcion que imprime si el archivo esta vacio o manda a imprimir los resultados
      void vacioArchivo(bool vacio, int N, int K, float R, float RR, float  B0, float B1, float YK, float signi, float rango, float LS, float LI) {
        if (vacio == true) {
          cout << "El archivo esta vacio" << endl;
        }
        else {
          imprimeResultados(N, K, R, RR, B0, B1, YK, signi, rango, LS, LI);
        }
      }
      //.i
      //Funcion que imprime los resultados
      void imprimeResultados(int N, float K, float R, float RR, float  B0, float B1, float YK, float signi, float rango, float LS, float LI) {
        cout << setprecision(5) << fixed;
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
        cout << "LI = " << LI << endl;
      }

      void imprimeNoexiste() {
        cout << "El archivo no existe" << endl;
      }

};

#endif
