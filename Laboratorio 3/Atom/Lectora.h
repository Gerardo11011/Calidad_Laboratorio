#ifndef LECTORA_H
#define LECTORA_H
///////////////////////////////////////////////////
///Problema 3                                   ///
///Autor: Gerardo Aldair Ponce Gomez A00818934  ///
///////////////////////////////////////////////////
#include <fstream>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//.b=74
//.d=36

bool vacioArch = false; //.m

class Lectora {
    private:
      fstream archivo;
      int xK;
      int renglon;
      int totales;

    public:
      //.i
      //Constructor
      Lectora (string nombre){
        archivo.open(nombre.c_str());
        xK = 0; //.m
        renglon = 0; //.m
        totales = 0; //.m
      }
      //.i
      //Destructor
      ~Lectora(){
        archivo.close();
      }
      //.i
      //Funcion que obtiene el valor de xK
      int getxK(){
        return xK; //.m
      }
      //.i
      //Funcion que obtiene el valor de la cantidad de datos ingresados
      int getTotales(){
        return totales; //.m
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
      //Funcion que cuenta y lee los datos del archivo y los almacenas
      void Contar(vector<float>&NumX,vector<float>&NumY){
        string linea;
        string X;
        string Y;
        bool vacio = false;
        int primeralinea = 0;
        while(! archivo.eof()){
            getline(archivo,linea);
            //IF que verifica que el archivo no este vacio
            if (linea[0] == '\0' && vacio == false && primeralinea == 0) {
              vacio = true;
              primeralinea++;
              vacioArch = true;
            }
            primeralinea++;
            //almacena el dato del primer renglon unciamente
            if(renglon == 0){
                xK = atoi(linea.c_str());
                renglon++;
            }
            //Lee el resto de las lineas y almacena los valores que estan en el archivo
            else if(renglon > 0 && linea.size() > 1){
                X = linea.substr(0,linea.find(','));
                stringstream ss;
                ss << X;
                float aux;
                ss >> aux;
                ss.clear();
                NumX.push_back(aux);
                Y = linea.substr(linea.find(',')+1);
                ss << Y;
                ss >> aux;
                ss.clear();
                NumY.push_back(aux);
                totales++;
            }
        }
      }
  };

#endif
