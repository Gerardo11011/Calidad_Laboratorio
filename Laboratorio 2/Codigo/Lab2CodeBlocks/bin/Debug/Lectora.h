///////////////////////////////////////////////////
///Problema 2                                   ///
///Autor: Gerardo Aldair Ponce Gomez A00818934  ///
///Clase lectora: Lee el archivo y cuenta las   ///
///Las lineas del codigo del archivo solicitado ///
///////////////////////////////////////////////////
#ifndef LECTORA_H
#define LECTORA_H

#include <fstream>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int contador = 0;

//.b=74

class Lectora {
private:
    fstream archivo;
    int lineasModificadas;
    int lineasBases;
    int lineasAgregadas;
    int lineasBorradas;
    int lineasTotales;
    int items;
    string nombreClase;
    string tipo;
public:
    ///Lee el archivo y  inicializa las variables
    Lectora(string nombre){
      archivo.open(nombre.c_str());
      lineasModificadas = 0;
      lineasBases = 0;
      lineasAgregadas = 0;
      lineasBorradas = 0;
      lineasTotales = 0;
      items = 0;
      nombreClase = nombre;
      tipo = " ";
    }
    ~Lectora(){
      archivo.close();
    }
///Funcion que obtiene el valor de las lineas en blanco
//.i
    int getLineasModificadas(){
    return lineasModificadas;
    }
    //.i
    ///Funcion que obtiene el valor de los codigos
    int getlineasAgregadas(){
      lineasAgregadas = lineasTotales - lineasBases + lineasBorradas;
      return lineasAgregadas;
    }
    //.i
    int getLineasBases(){
      return lineasBases;
    }
    //.i
    int getLineasBorradas(){
      return lineasBorradas;
    }
    //.i
    int getLineasTotales(){
      return lineasTotales;
    }
    //.i
    int getItems(){
      return items;
    }
    //.i
    string getTipo(){
      if (lineasBases > 0 && (lineasModificadas > 0 || lineasBorradas > 0 || lineasAgregadas > 0)) {
        tipo = "BASE";
      }
      else if (lineasBases == 0 && lineasModificadas == 0 && lineasBorradas == 0 && lineasAgregadas > 0){
        tipo = "NUEVA";
      }
      else if (lineasBases > 0 && lineasModificadas == 0 && lineasBorradas == 0 && lineasAgregadas == 0){
        tipo = "REUSADA";
      }
      else {
        tipo = "ERROR";
      }
      return tipo;
    }
    //.i
    string getNombreClase(){
      string aux = nombreClase;
      int target = aux.find('.');
      aux = aux.substr(0, target);
      return aux;
    }
    //.i
    int getContadorGlobal(){
      return contador;
    }
    ///Funcion que verifica si el archivo esta vacio
    //.i
    bool vacioArchivo(){
      if (archivo.peek() != '\0') {
        return true;
      }
      else {
        return false;
      }
    }
    //.i
    ///Funcion que verifica si el archivo existe o no
    bool existeArchivo(){
      if (archivo.is_open()) {
        return true;
      }
      else {
        return false;
      }
    }

    ///Funcion que cuenta las lineas del documento
    //.i
    void contarLineas(){
    string Linea;
    bool Multi_Coment = false;
    ///Abre el archivo a leer
    if (archivo.is_open()){
      while (!archivo.eof()) {
        getline(archivo,Linea);

        //Se borra los tab's y los espaciados mediante un trim
        Linea.erase(std::remove(Linea.begin(), Linea.end(), '\t'), Linea.end());
        Linea.erase(std::remove(Linea.begin(), Linea.end(), ' '), Linea.end());

        //If que lee si en la primera linea se encuentra un multicomentario
        if (Linea[0] == '/' && Linea[1] == '*') {
          Multi_Coment = true;
        }
        //If que lee las lineas de codigo
        if (Multi_Coment == false) {
          if (Linea[0] != '/' && Linea[1] != '/') {  //.m
            if (Linea.length() > 2) {
              lineasTotales++;
              contador++;
              //if que checa la etiqueta m y suma o resta uno dependiendo si esta en comillas o no
              if(Linea.find("//.m") != -1){
                lineasModificadas++;
                if (Linea.find('"') < Linea.find("//.m")){
                    Linea.erase(remove(Linea.begin(), Linea.end(), '"'), Linea.end());
                  if (Linea.find('"') > Linea.find("//.m")){
                    lineasModificadas--;
                  }
                }
              }
            }
          }
          //Busca el punto para luego leer las etiquetas
          if (Linea[2] == '.') {
            //Se lee la etiqueta B y convierte a int para sumarlo
            if (Linea[3] == 'b') {
              string aux;
              int target = Linea.find('=');
              aux = Linea.substr(target+1, aux.length()-1);
              int i = atoi(aux.c_str());
              lineasBases = lineasBases + i;
            }
            //Lee la etiqueta i
            if (Linea[3] == 'i') {
              items++;
            }
            //Lee la etiqueta d y convierte a int para sumarlo
            if (Linea[3] == 'd') {
              string aux;
              int target = Linea.find('=');
              aux = Linea.substr(target+1, aux.length()-1);
              int i = atoi(aux.c_str());
              lineasBorradas = lineasBorradas + i;
            }
          }
        }
        //If que lee si se acaba el multicomentario
        else if (Linea[Linea.length()-2] == '*' && Linea[Linea.length()-1] == '/') {
          Multi_Coment = false;
        }

      }
    }
    }


};
#endif // LECTORA_H
