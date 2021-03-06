///////////////////////////////////////////////
///Problema 1
///Autor: Gerardo Aldair Ponce Gomez A00818934
///Main que contiene las llamadas a las clases
///////////////////////////////////////////////
#include <iostream>
#include "Lectora.h"
#include "Imprimir.h"
#include <fstream>

using namespace std;


int main()
{

    string nombreArchivo;
    fstream archivo;
    cout << "Nombre del archivo: ";
    cin >> nombreArchivo;
    Lectora lector(nombreArchivo);
    if (lector.existeArchivo()== true) {
      if (lector.vacioArchivo() == true){
        lector.contarLineas();
        Imprimir imprime(lector.getLineaBlancas(), lector.getLineaComentarios(), lector.getLineaCodigo());
        imprime.desplegar();
        system("pause");
      }
      else{
        cout << "Archivo Vacio";
      }
    }
    else {
      cout << "El archivo no existe o no se encuentra en la carpeta";
    }
    return 0;
}
