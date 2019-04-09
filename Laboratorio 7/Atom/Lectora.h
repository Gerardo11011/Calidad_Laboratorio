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
#include <stdlib.h>
#include <string>
using namespace std;



class Lectora {
    private:
      fstream archivo;
      float wk; //.m
      float xk; //.m
      float yk; //.m
      float totales;
      bool vacioArch;

    public:
      //.i
      //Constructor
      Lectora (string nombre){
        archivo.open(nombre.c_str());
        wk = 0; //.m
        xk = 0; //.m
        yk = 0; //.m
        vacioArch = false;
        totales = 0;
      }
      //.i
      //Destructor
      ~Lectora(){
        archivo.close();
      }
      //.i
      //Funcion que obtiene el aux de wk
      float getwk(){  //.m
        return wk; //.m
      }
      //.i
      //Funcion que obtiene el aux de la cantidad de datos ingresados
      float getxk(){ //.m
        return xk; //.m
      }

      //.i
      //Funcion que obtiene el aux de yk
      float getyk(){
        return yk;
      }

      bool vacioArchivo(){
        return vacioArch;
      }


      //.i
      //Funcion que comlinea si existe el archivo
      bool existeArchivo(){
        if (archivo.is_open()) {
          return true;
        }
        else {
          return false;
        }
      }

      float getTotales(){
        return totales;
      }

      //.i
      //.d=4
      //.d=11
      //Funcion que cuenta y lee los datos del archivo y los almacenas
      void Contar(vector<float>&NumX,vector<float>&NumY, vector<float>&NumZ, vector<float>&NumW){
        string linea;
        string X;
        string Y, Z, W;
        string auxwk, auxxk, auxyk, aux;
        int renglon = 0;
        while(! archivo.eof()){
            getline(archivo,linea);
            //IF que verifica que el archivo no este vacio
            if (linea[0] == '\0' && vacioArch == false && renglon == 0) {
              renglon++;
              vacioArch = true;
            }
            //almacena el dato del primer renglon unciamente
            if(renglon == 0){
              auxwk = linea.substr(0, linea.find(','));
              wk = atof(auxwk.c_str());
              auxxk = linea.substr(linea.find(',')+1, linea.find_last_of(','));
              xk = atof(auxxk.c_str());
              xk = xk;
              auxyk = linea.substr(linea.find_last_of(',')+1, linea.size());
              yk = atof(auxyk.c_str());
              renglon++;
            }
            //Lee el resto de las lineas y almacena los valores que estan en el archivo
            else if(renglon > 0 && linea.size() > 1){
              aux = linea.substr(0,linea.find(','));
              NumW.push_back(stof(aux.c_str()));
              linea.erase(0,linea.find(',')+1);
              aux = linea.substr(0,linea.find(','));
              NumX.push_back(stof(aux.c_str()));
              linea.erase(0,linea.find(',')+1);
              aux = linea.substr(0,linea.find(','));
              NumY.push_back(stof(aux.c_str()));
              linea.erase(0,linea.find(',')+1);
              aux = linea.substr(linea.find(',')+1);
              NumZ.push_back(stof(aux.c_str()));
                totales++;
            }
        }
      }
  };

#endif
