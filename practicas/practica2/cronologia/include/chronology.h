#include <iostream>
#include "dinamicArray.h"
#include "historicDate.h"

#ifndef ChronologyH
#define ChronologyH


class Chronology{

 private:

  DinamicArray<HistoricDate> years;

 public:

  Chronology();

  HistoricDate operator [] (int i);
  const HistoricDate operator [] (int i) const;
  int getAmount() const;
  void insertYear(HistoricDate year);
  void operator+=(const Chronology & f);
  int findByYear(int year);
  Chronology split(int low, int high);
  Chronology containing(std::string);
  friend std::istream& operator >> (std::istream& is, Chronology &);
  //friend ostream& operator << (istream& os, const FechaHistorica &f);

};
#endif
