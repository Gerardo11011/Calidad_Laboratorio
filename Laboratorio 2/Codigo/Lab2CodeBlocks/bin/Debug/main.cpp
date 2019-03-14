///////////////////////////////////////////////////
///Problema 2                                   ///
///Autor: Gerardo Aldair Ponce Gomez A00818934  ///
///Clase main: manda a clase lectora el archivo ///
///Las lineas del codigo del archivo solicitado ///
///////////////////////////////////////////////////
#include <iostream>
#include "Lectora.h"
#include "Imprimir.h"
#include "Estructura.h"
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

//.b=34
using namespace std;

extern int contador;



int main()
{
  struct estructura datos;
  string nombre;
  int tamanno;
  bool encontrado = false;
  string nombreArchivo;
  int cantidad = 0, anadidos = 0;
  vector <estructura> myVector;
  cout << "cuantos archivos va a ingresar: ";
  cin >> cantidad;

  if (cantidad == 0) {
    cout << "No se annadio ningun archivo" << endl;
    return 0;
  }

//For que realiza las diferentes iteracion para ingresar el archivo
  for (int j = 0; j < cantidad; j++) {
    cout << "Nombre del archivo: ";
    cin >> nombreArchivo;
    //Encontrado: Sirve para saber si el archivo se encuentra en el vector
    encontrado = false;
    //Inicializa la clase lectora con el objeto lector
    Lectora lector (nombreArchivo);
    lector.contarLineas();
    //anadidos sirve para verificar que haya minimo un elemento en el vector
    if (anadidos >= 1) {
      tamanno = myVector.size();
      //For para explorar el vector y encontrar si la clase habia sido a�andida anteriormente
      for (int i = 0; i < tamanno; i++) {
        //Comprueba que la nueva clase sea igual a una dentro del vector
        if (lector.getNombreClase() == myVector[i].nombreClase){
          //cout << "Encontro otro objeto con su mismo nombre";
          encontrado = true;
          myVector[i].lineasBases = lector.getLineasBases() + myVector[i].lineasBases;
          myVector[i].lineasBorradas = lector.getLineasBorradas() + myVector[i].lineasBorradas;
          myVector[i].lineasModificadas = lector.getLineasModificadas() + myVector[i].lineasModificadas;
          myVector[i].lineasTotales = lector.getLineasTotales() + myVector[i].lineasTotales;
          myVector[i].items = lector.getItems() + myVector[i].items;
          myVector[i].lineasAgregadas = lector.getlineasAgregadas() + myVector[i].lineasAgregadas;
          myVector[i].tipo = lector.getTipo();
        }

      }
      //If que sirve para ingresar una clase nueva que no estaba en el vector
      if (encontrado == false) {
      //cout << "entro a encontrado == false" << endl;
      //cout << "hola" << endl;
      datos.nombreClase = lector.getNombreClase();
      datos.lineasBases = lector.getLineasBases();
      datos.lineasBorradas = lector.getLineasBorradas();
      datos.lineasModificadas = lector.getLineasModificadas();
      datos.lineasTotales = lector.getLineasTotales();
      datos.items = lector.getItems();
      datos.lineasAgregadas = lector.getlineasAgregadas();
      datos.tipo = lector.getTipo();
      myVector.push_back(datos);


      }
    }
    //If que sirve para agregar la primera clase al vector
    else if (anadidos == 0) {

      //cout << "Entro a anadidos == 0" << endl;
      datos.nombreClase = lector.getNombreClase();
      datos.lineasBases = lector.getLineasBases();
      datos.lineasBorradas = lector.getLineasBorradas();
      datos.lineasModificadas = lector.getLineasModificadas();
      datos.lineasTotales = lector.getLineasTotales();
      datos.items = lector.getItems();
      datos.lineasAgregadas = lector.getlineasAgregadas();
      datos.tipo = lector.getTipo();
      myVector.push_back(datos);
      anadidos++;
    }
  }

  Imprimir final;
  ofstream myFile;
  myFile.open("ConteoLDC.txt");
  cout << endl;
  for (int i = 0; i < myVector.size(); i++) {
    if (myVector[i].tipo == "ERROR") {
      cout << "ERROR: el archivo no pertenece a ningun tipo de parte (Base, Nueva, Reusada)"<< endl;
      system("pause");
      return 0;
    }
  }
  //Imprime en documento
  myFile << "PARTES BASE:" << endl;
  //Imprime en pantalla
  cout << "PARTES BASE:" << endl;
  for (int i = 0; i < myVector.size(); i++) {
    if (myVector[i].tipo == "BASE") {
      final.imprimeBASE(myVector[i].nombreClase, myVector[i].lineasTotales, myVector[i].items, myVector[i].lineasBases, myVector[i].lineasBorradas, myVector[i].lineasModificadas, myVector[i].lineasAgregadas, myFile);
    }
  }
  final.imprimeLINEAS(myFile);

  //Imprime en documento
  myFile << "PARTES NUEVAS:" << endl;
  //Imprime en pantalla
  cout << "PARTES NUEVAS:" << endl;
  for (int i = 0; i < myVector.size(); i++) {
    if (myVector[i].tipo == "NUEVA") {
      final.imprimeNUEVAS(myVector[i].nombreClase, myVector[i].lineasTotales, myVector[i].items, myFile);
    }
  }
  final.imprimeLINEAS(myFile);

  //Imprime en documento
  myFile << "PARTES REUSADAS:" << endl;
  //Imprime en pantalla
  cout << "PARTES REUSADAS:" << endl;
  for (int i = 0; i < myVector.size(); i++) {
    if (myVector[i].tipo == "REUSADA") {
      final.imprimeREUSADAS(myVector[i].nombreClase, myVector[i].lineasTotales, myVector[i].items, myVector[i].lineasBases, myFile);
    }
  }

  final.imprimeLINEAS(myFile);
  final.imprimeTOTAL(contador, myFile);
  myFile.close();
  cout << endl;
  system("pause");
  return 0;
}
