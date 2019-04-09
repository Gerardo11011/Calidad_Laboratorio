#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{
  string linea = "477,73,43.68,43.23";
  string auxwk, auxyk, auxxk;
  float wk, xk, yk;
  vector<float> NumX;
  vector<float> NumY;
  vector<float> NumZ;
  vector<float> NumW;
  string X;
  string Y, Z, W,aux;


  W = linea.substr(0,linea.find(','));
NumW.push_back(atof(W.c_str()));
  X = linea.substr(linea.find(',') + 1, linea.find(','));
                NumX.push_back(atof(X.c_str()));
                aux = linea.substr(linea.find(',') + 1);
                Y = aux.substr(aux.find(',') + 1, linea.find_last_of(','));
                NumY.push_back(atof(Y.c_str()));
                Z = linea.substr(linea.find_last_of(',')+1);
                NumZ.push_back(atof(Z.c_str()));

  cout << "w: " << NumW[0] << endl;
  cout << "x: " << NumX[0] << endl;
  cout << "y: " << NumY[0] << endl;
   cout << "z: " << NumZ[0] << endl;
  return 0;
}
