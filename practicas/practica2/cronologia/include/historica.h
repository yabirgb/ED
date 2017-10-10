#ifndef __HISTORICA
#define __HISTORICA

#include <iostream>
#include "vector_dinamico.h"

using namespace std;

/*
 * @brief T.D.A Fecha historica
 * @

*/

class FechaHistorica {

 private:

  int year;
  Vector_Dinamico<string> *eventos;

  
 public:

  FechaHistorica();

  ~FechaHistorica();
  
  FechaHistorica(int y,  Vector_Dinamico<string> * e);

  int getFecha() const;
  int getElementos() const;
  int getCapacidad() const;

  void operator+=(const FechaHistorica & f);
  
  //const string * getEventos() const;
  void pushEvento(string nombre);
  string getPos(int pos) const;
  
  //friend istream& operator >> (istream& is, FechaHistorica &f);
  //friend ostream& operator << (istream& os, const FechaHistorica &f);

};
#endif
