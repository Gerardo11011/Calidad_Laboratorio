///////////////////////////////////////////////////
///Problema 1                                   ///
///Autor: Gerardo Aldair Ponce Gomez A00818934  ///
///////////////////////////////////////////////////
#ifndef LECTORA_H
#define LECTORA_H

#include <fstream>
#include <algorithm>
#include <cctype>
#include <iostream>
using namespace std;

class Lectora {
private:
    fstream archivo;
    int lineaBlancas;
    int lineaComentarios;
    int lineaCodigo;
public:
    ///Lee el archivo y  inicializa las variables
    //.i
    Lectora(string nombre){
      archivo.open(nombre.c_str());
      lineaBlancas = 0;
      lineaComentarios = 0;
      lineaCodigo = 0;
    }
    ~Lectora(){
      archivo.close();
    }
///Funcion que obtiene el valor de las lineas en blanco
//.i
    int getLineaBlancas(){
    return lineaBlancas;
    }
    ///Funcion que obtiene el valor de los comentarios
    //.i
    int getLineaComentarios(){
    return lineaComentarios;
    }
    ///Funcion que obtiene el valor de los codigos
    //.i
    int getLineaCodigo(){
    return lineaCodigo;
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

    ///Funcion que verifica si el archivo existe o no
    //.i
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

        if (Linea[0] == '/' && Linea[1] == '*'){
        Multi_Coment = true;
        }
        if (Multi_Coment == false){
          if (Linea[0] >= 'A' && Linea[0] <= '}'){
            lineaCodigo++;
            cout << Linea << endl;
          }
          if (Linea[0] == '/' && Linea[1] == '/'){
            lineaComentarios++;
            //cout << Linea << endl;
          }
          if (Linea[0] == NULL){
            lineaBlancas++;
          }
        }
        else if (Linea[Linea.length()-2] == '*' && Linea[Linea.length()-1] == '/'){
          lineaComentarios++;
          Multi_Coment = false;
          //cout << Linea << endl;
        }
        else {lineaComentarios++;}
      }
    archivo.close();
    }
  }
};
#endif // LECTORA_H
