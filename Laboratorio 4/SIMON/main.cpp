//
//  main.cpp
//  Calidad_4
//
//  Created by Francisco Javier Simón Muñoz on 3/9/19.
//  Copyright © 2019 Francisco Simón. All rights reserved.
//

#include <iostream>
#include "Calcular.h"
#include "Gamma.h"
#include <iomanip>
//.i
using namespace std;
int main(int argc, const char * argv[]) {
    float iX = 0;
    float idof = 0;
    Calcular cal;
    cout << "Escribe x y luego dof " << endl;
    cin >> iX;
    cin >> idof;
    cout << "x = " << iX << endl;
    cout << "dof = " << idof << endl;
    cout << setprecision(5) << fixed;
    cout << "p = " << cal.calculaP(iX, idof) << endl;

}
