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

//.b=80

class Lectora {
    private:
      fstream Archivo;
      float Wk; //.m
      float Xk; //.m
      float Yk; //.m
      float Totales;
      bool Vacioarch;
      bool Numerror;

    public:
      //.i
      //Constructor
      Lectora (string Nombre){
        Archivo.open(Nombre.c_str());
        Wk = 0; //.m
        Xk = 0; //.m
        Yk = 0; //.m
        Vacioarch = false;
        Totales = 0;
        Numerror = false;
      }
      //.i
      //Destructor
      ~Lectora(){
        Archivo.close();
      }
      //.i
        //Funcion que obtiene el valor de wk
      float getwk(){  //.m
        return Wk; //.m
      }
      //.i
      //Funcion que obtiene el valor de la cantidad de xk
      float getxk(){ //.m
        return Xk; //.m
      }

      //.i
      //Funcion que obtiene el valor de yk
      float getyk(){
        return Yk;
      }

      //Funcion que comprueba si el Archivo esta vacio
      bool getVacioArchivo(){
        return Vacioarch;
      }


      //.i
      //Funcion que comprueba si existe el Archivo
      bool existeArchivo(){
        if (Archivo.is_open()) {
          return true;
        }
        else {
          return false;
        }
      }

      //.i
      //Funcion que retorna el conteo de total de datos
      float getTotales(){
        return Totales;
      }

      //.i
      //Funcion que retorna el booleano de Numerror
      bool getNumerror(){
        return Numerror;
      }

      //.i
      //.d=4
      //.d=11
      //Funcion que cuenta y lee los datos del Archivo y los almacenas
      void Contar(vector<float>&NumX,vector<float>&NumY, vector<float>&NumZ, vector<float>&NumW){
        string Linea;
        string X;
        string Y, Z, W;
        string Auxwk, Auxxk, Auxyk, Aux;
        float Num = 0;
        int Renglon = 0;
        while(! Archivo.eof()){
            getline(Archivo,Linea);
            //IF que verifica que el Archivo no este vacio
            if (Linea[0] == '\0' && Vacioarch == false && Renglon == 0) {
              Renglon++;
              Vacioarch = true;
            }
            //almacena el dato del primer Renglon unciamente
            if(Renglon == 0){
              Auxwk = Linea.substr(0, Linea.find(','));
              Wk = atof(Auxwk.c_str());
              Auxxk = Linea.substr(Linea.find(',')+1, Linea.find_last_of(','));
              Xk = atof(Auxxk.c_str());
              Auxyk = Linea.substr(Linea.find_last_of(',')+1, Linea.size());
              Yk = atof(Auxyk.c_str());
              if (Wk < 0 || Xk < 0 || Yk < 0) {
                Numerror = true;
              }
              Renglon++;
            }
            //Lee el resto de las lineas y almacena los valores que estan en el Archivo
            else if(Renglon > 0 && Linea.size() > 1){
              Aux = Linea.substr(0,Linea.find(','));
              Num = atof(Aux.c_str());

              NumW.push_back(Num);

              Linea.erase(0,Linea.find(',')+1);
              Aux = Linea.substr(0,Linea.find(','));
              Num = atof(Aux.c_str());

              NumX.push_back(Num);

              Linea.erase(0,Linea.find(',')+1);
              Aux = Linea.substr(0,Linea.find(','));
              Num = atof(Aux.c_str());

              NumY.push_back(Num);

              Linea.erase(0,Linea.find(',')+1);
              Aux = Linea.substr(Linea.find(',')+1);
              Num = atof(Aux.c_str());
              NumZ.push_back(Num);

              //IF que comprueba que si el numero es menor a 0 y cambia el estado de Numerror
              if (NumW[Totales] < 0 || NumX[Totales] < 0 || NumY[Totales] < 0 || NumZ[Totales] < 0) {
                Numerror = true;
              }
              //Se cuentan el total de datos ingresados
              Totales++;
            }
        }
      }
  };

#endif
