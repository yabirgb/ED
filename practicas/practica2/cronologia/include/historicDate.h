#ifndef dateHeader
#define dateHeader

#include <iostream>
#include "dinamicArray.h"

using namespace std;

class HistoricDate{

 private:

  int year;
  DinamicArray<string> *events;

  
 public:

  HistoricDate();

  ~HistoricDate();
  
  HistoricDate(int y,  DinamicArray<string> * e);

  int getDate() const;
  
  void operator+=(const FechaHistorica & f);
  
  //const string * getEventos() const;
  void pushEvent(string nombre);
  
  //friend istream& operator >> (istream& is, FechaHistorica &f);
  //friend ostream& operator << (istream& os, const FechaHistorica &f);

};
#endif
