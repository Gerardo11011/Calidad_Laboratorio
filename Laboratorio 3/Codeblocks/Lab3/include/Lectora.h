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
      Lectora (string nombre){
        archivo.open(nombre.c_str());
        xK = 0; //.m
        renglon = 0; //.m
        totales = 0; //.m
      }
      //.i
      ~Lectora(){
        archivo.close();
      }
      //.i
      int getxK(){
        return xK; //.m
      }
      //.i
      int getTotales(){
        return totales; //.m
      }
      //.i
      bool existeArchivo(){
        if (archivo.is_open()) {
          return true;
        }
        else {
          return false;
        }
      }

      //.i
      void Contar(vector<float>&NumX,vector<float>&NumY){
        string linea;
        string X;
        string Y;
        bool vacio = false;
        int primeralinea = 0;
        while(! archivo.eof()){
            getline(archivo,linea);
            if (linea[0] == '\0' && vacio == false && primeralinea == 0) {
              vacio = true;
              primeralinea++;
              vacioArch = true;
            }
            primeralinea++;
            if(renglon == 0){
                xK = atoi(linea.c_str());
                renglon++;
            }
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
