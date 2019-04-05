///////////////////////////////////////////////////
///Problema 6                                   ///
///Autor: Gerardo Aldair Ponce Gomez A00818934  ///
///////////////////////////////////////////////////
#ifndef LECTORA_H
#define LECTORA_H
#include <fstream>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include "Imprimir.h"
using namespace std;
//.b=65

int vacioArch = 0;
class Lectora {
  private:
    fstream archivo;
    float xK;
    int renglon;
    int totales;
    int error;

  public:
    //.i
    //Constructor
    Lectora (string nombre){
      archivo.open(nombre.c_str());
      xK = 0;
      renglon = 0;
      totales = 0;
    }
    //.i
    //Destructor
    ~Lectora(){
      archivo.close();
    }
    //.i
    //Funcion que obtiene el valor de xK
    int getxK(){
      return xK;
    }
    //.i
    //Funcion que obtiene el valor de la cantidad de datos ingresados
    int getTotales(){
      return totales;
    }
    //.i
    //Funcion que comprueba si existe el archivo
    bool existeArchivo(){
      if (archivo.is_open()) {
        return true;
      }
      else {
        return false;
      }
    }

    //.i
    //Funcion que imprime si el archivo esta vacio o manda a imprimir los resultados
    void vacioArchivo() { //.m
      cout << endl;
      cout << "El archivo esta vacio" << endl << endl;
      system("pause");
    }

    //.i
    //Funcion que retorna el valor del error
    int error0(){
      return error;
    }

    //.i
    //Funcion que cuenta y lee los datos del archivo y los almacena
    void Contar(vector<float>&NumX,vector<float>&NumY){
      string linea;
      string X;
      string Y;
      bool vacio = false;
      int primeralinea = 0;
      while(! archivo.eof()){
        getline(archivo,linea);
        //IF que verifica que el archivo no este vacio
        if (linea[0] == '\0' && vacio == 0 && primeralinea == 0) {
          vacio = 1;
          primeralinea++;
          vacioArch = true;
          vacioArchivo();
        }
        primeralinea++;
        //almacena el dato del primer renglon unicamente
        if(renglon == 0){
          xK = atoi(linea.c_str());
          renglon++;
          if (xK < 0) {
            error = 1;
          }
        }
        //Lee el resto de las lineas y almacena los valores que estan en el archivo
        else if(renglon > 0 && linea.size() > 1){
          X = linea.substr(0,linea.find(','));
          stringstream ss;
          ss << X;
          float aux;
          ss >> aux;
          ss.clear();
          if (aux < 0) {
            error = 1;
          }
          NumX.push_back(aux);
          Y = linea.substr(linea.find(',')+1);
          ss << Y;
          ss >> aux;
          ss.clear();
          if (aux < 0) {
            error = 1;
          }
          NumY.push_back(aux);
          totales++;
        }
      }
    }
};

#endif
