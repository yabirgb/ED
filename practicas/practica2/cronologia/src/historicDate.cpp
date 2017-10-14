#include "historicDate.h"
#include <iostream>
#include <sstream>

HistoricDate::HistoricDate():year(0), separator(""){}

HistoricDate::~HistoricDate(){

  year = 0;
  ~events;

}

HistoricDate::HistoricDate(int y, DianamicArray<std::string> * e, std::string spacer){
  year = y;
  events = e;
  separator = spacer;
}

std::string HistoricDate::operator [] (int i){
  return events[i] 
}

const std::string HistoricDate::operator [] (int i) const{
  return events[i] 
}

int HistoricDate::getYear() const{
  return year;
}

int HistoricDate::getAmount() const{
  return events.used()
}

void HistoricDate::pushEvent(string nombre){
  events.push(nombre);
}

friend istream& HistoricDate::operator >> (istream& is, FechaHistorica &f){

  std::sting cadena;
  std::getline(is, cadena, separator);
  year = stoi(cadena);

  while(!is.eof()){
    
  }
  

}
