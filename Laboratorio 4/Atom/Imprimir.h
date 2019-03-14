///////////////////////////////////////////////////
///Problema 4                                   ///
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

    public:
      //.d=

      //.i
      //Funcion que regresa un booleano que verifica si los valores son validos o no
      bool errorResultados(float x, int dof){
        if (x < 0 || dof <= 0) {
          return true;
        }
        return false;
      }
      //.i
      //Funcion que immprime los resultados obtenidos
      void imprimeResultados(float x, int dof, float p) {
          cout << "x = " << x << endl;
          cout << "dof = " << dof << endl;
          cout << "p = " << p << endl;
      }
      //.i
      //Funcion que imprime el mensaje de error
      void imprimeError() {
        cout << "ERROR valores invalidos" << endl;
      }


};


#endif
