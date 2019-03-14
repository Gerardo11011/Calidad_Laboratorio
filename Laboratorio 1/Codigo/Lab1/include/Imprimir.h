///////////////////////////////////////////////
///Problema 1
///Autor: Gerardo Aldair Ponce Gomez A00818934
///Clase Imprimir: Imprime las linead de codigo
///Con el formato solicitado
///////////////////////////////////////////////
#ifndef IMPRIMIR_H
#define IMPRIMIR_H
using namespace std;

class Imprimir {

private:
    int lineaBlancas;
    int lineaComentarios;
    int lineaCodigo;
    int lineaTotales;
    fstream Archivo;

  public:
    ///Crea el objeto e inicializa las variables
    Imprimir(int blancoslineas, int comentarioslineas, int codigolineas){
    lineaCodigo = codigolineas;
    lineaBlancas = blancoslineas;
    lineaComentarios = comentarioslineas;

    lineaTotales = blancoslineas + comentarioslineas + codigolineas;
}

    ///Funcion que despliega el total de las lineas
    void desplegar(){
            cout << "-----------------------------------------------"<<endl;
            cout << "Cantidad de lineas en blanco: " << lineaBlancas << endl;
            cout << "Cantidad de lineas con comentarios: " << lineaComentarios << endl;
            cout << "Cantidad de lineas con codigo: " << lineaCodigo << endl;
            cout << "-----------------------------------------------" << endl;
            cout << "Cantidad total de lineas: " << lineaTotales << endl;
    }
};




#endif // IMPRIMIR_H
