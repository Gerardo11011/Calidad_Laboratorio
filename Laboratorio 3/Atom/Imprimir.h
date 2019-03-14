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

      void vacioArchivo(bool vacio, int N, int K, float R, float RR, float  B0, float B1, float YK) {
        if (vacio == true) {
          cout << "El archivo esta vacio" << endl;
        }
        else {
          imprimeResultados(N, K, R, RR, B0, B1, YK);
        }
      }
      //.i
      void imprimeResultados(int N, int K, float R, float RR, float  B0, float B1, float YK) {
        cout << setprecision(5) << fixed;
        cout << "N = " << N << endl;
        cout << "xk = " << K << endl;
        cout << "r = " << R << endl;
        cout << "r2 = " << RR << endl;
        cout << "b0 = " << B0 << endl;
        cout << "b1 = " << B1 <<endl;
        cout << "yk = " << YK << endl;
      }

};

#endif
