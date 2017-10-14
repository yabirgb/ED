#include <iostream>
#include "dinamicArray.h"

#ifndef dateHeader
#define dateHeader


class HistoricDate{

 private:

  char separator;
  int year;
  DinamicArray<std::string> events;


 public:

  HistoricDate();

  ~HistoricDate();

  HistoricDate(int y,  DinamicArray<std::string> & e, char separator);
  std::string operator [] (int i);
  const std::string operator [] (int i) const;
  int getYear() const;
  int getAmount() const;
  char getSeparator();
  void setYear(int y);
  void pushEvent(std::string nombre);
  void operator+=(const HistoricDate & f);

  //const string * getEventos() const;

  friend std::istream& operator >> (std::istream& is, HistoricDate &);
  //friend ostream& operator << (istream& os, const FechaHistorica &f);

};
#endif
