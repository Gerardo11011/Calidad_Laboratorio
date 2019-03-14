///////////////////////////////////////////////////
///Problema 3                                   ///
///Autor: Gerardo Aldair Ponce Gomez A00818934  ///
///////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <iomanip>
#include "Lectora.h"
#include "Calcular.h"
#include "Imprimir.h"
using namespace std;
//.b=28
vector<float>NumerosX;
vector<float>NumerosY;
extern bool vacioArch; //.m
//.d=8

int main() {
    string nombreArchivo;
    cout << "Introduzca el nombre el archivo a leer: ";
    cin >> nombreArchivo;
    Lectora lector (nombreArchivo);
    Calcular calcu;


    if(lector.existeArchivo() == true){ //.m
        lector.Contar(NumerosX,NumerosY);
        calcu.Correlacion(NumerosX, NumerosY, lector.getTotales());
        calcu.Regresion(NumerosX, NumerosY, lector.getTotales());
        Imprimir imp;
        int N = lector.getTotales();
        int xK = lector.getxK();
        float corre = calcu.getcorrelation();
        float correa2 = corre * corre;
        float b0 = calcu.getB0();
        float b1 = calcu.getB1();
        float yk = calcu.getB0()+(calcu.getB1()*lector.getxK());
        imp.vacioArchivo(vacioArch, N, xK, corre, correa2, b0, b1, yk);
    }
    else {
      cout << "El archivo no existe" << endl;
    }

    system("pause");
    return 0;
}
