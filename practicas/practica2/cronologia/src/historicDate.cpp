#include "historicDate.h"
#include <iostream>

HistoricDate::HistoricDate():year(0), events(0){}

HistoricDate::~HistoricDate(){

  year = 0;
  ~events;

}

HistoricDate::HistoricDate(int y, DianamicArray * e){
  year = y;
  events = e;
}

int getYear() const{
  return year;
}

x
void pushEvent(string nombre){
  events.push(nombre);
}
