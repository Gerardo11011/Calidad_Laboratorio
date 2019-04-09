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
  lector.Contar(x,y,z,w);
  Matriz matrix;
  Imprimir imprime;
  float totales = lector.getTotales();
  wk = lector.getwk();
  yk = lector.getyk();
  xk = lector.getxk();
  float matriz[4][5] = {0};

  matrix.calcuRe1(w,x,y,z, totales, matriz);
  matrix.calcuRe2(w,x,y,z, totales, matriz);
  matrix.calcuRe3(w,x,y,z, totales, matriz);
  matrix.calcuRe4(w,x,y,z, totales, matriz);

  Gauss gauss;
  gauss.Calcular(b0,b1,b2,b3, zk, matriz, totales, wk, xk, yk);

  imprime.imprimeResultados(totales, wk, xk, yk, b0, b1, b2, b3, zk);
/*
  for (int i = 0; i < lector.getTotales(); i++) {
    cout << "w: " << w[i] << " x: " << x[i] << " y: " << y[i] << " z: " << z[i] << endl;
  }
*/
/*
  cout << setprecision(1) << fixed;
  cout << "B0 = " << renglon1[0] << " B1 = " << renglon1[1] << " B2 = " << renglon1[2] << " B3 = " << renglon1[3] << " = " << renglon1[4] << endl;
  cout << "B0 = " << renglon2[0] << " B1 = " << renglon2[1] << " B2 = " << renglon2[2] << " B3 = " << renglon2[3] << " = " << renglon2[4] << endl;
  cout << "B0 = " << renglon3[0] << " B1 = " << renglon3[1] << " B2 = " << renglon3[2] << " B3 = " << renglon3[3] << " = " << renglon3[4] << endl;
  cout << "B0 = " << renglon4[0] << " B1 = " << renglon4[1] << " B2 = " << renglon4[2] << " B3 = " << renglon4[3] << " = " << renglon4[4] << endl;
*/
  return 0;
}
