///////////////////////////////////////////////////
///Problema 7                                   ///
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
      bool numerror;

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
        numerror = false;
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

      //Funcion que comprueba si el archivo esta vacio
      bool getVacioArchivo(){
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

      //Funcion que retorna el conteo de total de datos
      float getTotales(){
        return totales;
      }

      //Funcion que retorna el booleano de numerror
      bool getNumerror(){
        return numerror;
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
        float num = 0;
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
              num = atof(aux.c_str());
              //IF que comprueba que si el numero es menor a 0 y cambia el estado de numerror
              if (num < 0) {
                numerror = true;
              }
              NumW.push_back(num);

              linea.erase(0,linea.find(',')+1);
              aux = linea.substr(0,linea.find(','));
              num = atof(aux.c_str());
              //IF que comprueba que si el numero es menor a 0 y cambia el estado de numerror
              if (num < 0) {
                numerror = true;
              }
              NumX.push_back(num);

              linea.erase(0,linea.find(',')+1);
              aux = linea.substr(0,linea.find(','));
              num = atof(aux.c_str());
              //IF que comprueba que si el numero es menor a 0 y cambia el estado de numerror
              if (num < 0) {
                numerror = true;
              }
              NumY.push_back(num);

              linea.erase(0,linea.find(',')+1);
              aux = linea.substr(linea.find(',')+1);
              num = atof(aux.c_str());
              //IF que comprueba que si el numero es menor a 0 y cambia el estado de numerror
              if (num < 0) {
                numerror = true;
              }
              NumZ.push_back(num);

              //Se cuentan el total de datos ingresados
              totales++;
            }
        }
      }
  };

#endif
