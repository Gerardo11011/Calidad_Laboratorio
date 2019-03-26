///////////////////////////////////////////////////
///Problema 5                                   ///
///Autor: Gerardo Aldair Ponce Gomez A00818934  ///
///////////////////////////////////////////////////
#ifndef IMPRIMIR_H
#define IMPRIMIR_H


#include <iostream>
#include <iomanip>
using namespace std;

//.b=19
//.d=6

class Imprimir {
    private:

    public:
      //Funcion que immprime los resultados obtenidos
      //.i
      void imprimeResultados(float x, int dof, float p) {
          cout << "p = " << p << endl;
          cout << "dof = " << dof << endl;
          cout << "x = " << x << endl;
      }
};


#endif
