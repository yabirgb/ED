#ifndef dateHeader
#define dateHeader

#include <iostream>
#include "dinamicArray.h"

class HistoricDate{

 private:

  std::string separator;
  int year;
  DinamicArray<std::string> events;

  
 public:

  HistoricDate();

  ~HistoricDate();
  
  HistoricDate(int y,  DinamicArray<string> * e, string separator);
  std::string operator [] (int i);
  const std::string operator [] (int i) const;
  int getYear() const;
  int getAmount() const;
  
  void operator+=(const FechaHistorica & f);
  
  //const string * getEventos() const;
  
  friend istream& operator >> (istream& is, FechaHistorica &f);
  //friend ostream& operator << (istream& os, const FechaHistorica &f);

};
#endif
