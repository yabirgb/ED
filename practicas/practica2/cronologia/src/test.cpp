#include "historica.h"
#include <iostream>

using namespace std;

int main(){

  string * lista = new string [2];
  lista[0] = "Hola";
  lista[1] = "Mundo";
  
  FechaHistorica c(1333, 2, lista), g;

  cout << g.getElementos() << "/" << g.getCapacidad() << endl;
  cout << c.getElementos() << "/" << c.getCapacidad() << endl;

  cout << c.getPos(1) << endl;
  
  g += c;
  cout << g.getElementos() << "/" << g.getCapacidad() << endl;
  cout << g.getPos(1);
  
  
}
