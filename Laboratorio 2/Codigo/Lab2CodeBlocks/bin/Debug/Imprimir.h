#ifndef IMRPRIMIR_H
#define IMRPRIMIR_H

#include <iostream>
#include <vector>
#include "Estructura.h"
#include <fstream>

class Imprimir {
private:
  string nombreClase;
  int lineasBases;
  int lineasBorradas;
  int lineasModificadas;
  int lineasAgregadas;
  int lineasTotales;
  int items;
  string tipo;

  public:
    ///Crea el objeto e inicializa las variables
    Imprimir(){
      string nombreClase = "";
      int lineasBases = 0;
      int lineasBorradas = 0;
      int lineasModificadas = 0;
      int lineasAgregadas = 0;
      int lineasTotales = 0;
      int items = 0;
      string tipo = "";
}

//.i
void imprimeBASE(string nombreClase, int lineasTotales, int items, int lineasBases, int lineasBorradas, int lineasModificadas, int lineasAgregadas, ofstream &myFile) {
  //Imprime en documento
  myFile << nombreClase << ": "  << "T=" << lineasTotales << ", " << "I=" << items << ", " << "B=" << lineasBases << ", " << "D=" << lineasBorradas << ", " << "M=" << lineasModificadas << ", " << "A=" << lineasAgregadas << endl;
  //Imprime en pantalla
  cout << nombreClase << ": "  << "T=" << lineasTotales << ", " << "I=" << items << ", " << "B=" << lineasBases << ", " << "D=" << lineasBorradas << ", " << "M=" << lineasModificadas << ", " << "A=" << lineasAgregadas << endl;
}

//.i
void imprimeNUEVAS(string nombreClase, int lineasTotales, int items, ofstream &myFile) {
  //Imprime en documento
  myFile << nombreClase << ": " << "T=" << lineasTotales << ", " << "I=" << items << endl;
  //Imprime en pantalla
  cout << nombreClase << ": " << "T=" << lineasTotales << ", " << "I=" << items << endl;
}

//.i
void imprimeREUSADAS(string nombreClase, int lineasTotales, int items, int lineasBases, ofstream &myFile) {
  //Imprime en documento
  myFile << nombreClase << ": " << "T=" << lineasTotales << ", " << "I=" << items << ", " << "B=" << lineasBases << endl;
  //Imprime en pantalla
  cout << nombreClase << ": " << "T=" << lineasTotales << ", " << "I=" << items << ", " << "B=" << lineasBases << endl;
}

//.i
void imprimeTOTAL(int total, ofstream &myFile) {
  //Imprime en documento
  myFile << "Total de LDC=" << total;
  //Imprime en pantalla
  cout << "Total de LDC=" << total;
}

//.i
void imprimeLINEAS(ofstream &myFile) {
  myFile << "-------------------------------------------" << endl;
  cout << "-------------------------------------------" << endl;
}

};

#endif
