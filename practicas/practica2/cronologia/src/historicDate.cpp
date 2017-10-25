#include "historicDate.h"
#include "dinamicArray.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>

HistoricDate::HistoricDate(): separator('#'),year(0){}

HistoricDate::~HistoricDate(){
  year = 0;
}

HistoricDate::HistoricDate(int y, DinamicArray <std::string> & e, char spacer){
  year = y;
  events = e;
  separator = spacer;
}

void HistoricDate::operator += (const HistoricDate & origin){
  if (getYear() == origin.getYear()){
    for(int i = 0; i < origin.getAmount(); i++){
      pushEvent(origin[i]);
    }
  }
}

std::string HistoricDate::operator [] (int i){
  if(i < 0 || i > events.used())
    throw std::out_of_range("Error in access to HistoricDate");
  return events[i];
}

const std::string HistoricDate::operator [] (int i) const{
  if(i < 0 || i > events.used())
    throw std::out_of_range("Error in access to HistoricDate");
  return events[i];
}

int HistoricDate::getYear() const{
  return year;
}

int HistoricDate::getAmount() const{
  return events.used();
}

char HistoricDate::getSeparator(){
  return separator;
}

void HistoricDate::pushEvent(std::string nombre){
  events.push(nombre);
}

void HistoricDate::setYear(int y){
  year = y;
}

std::istream& operator>> (std::istream& is, HistoricDate& f){

  std::string year;
  char sep;
  int year_save;

  sep = f.getSeparator();
  getline(is, year, sep);

  year_save = std::stoi (year);
  f.setYear(year_save);

  while( is.good() )
  {
      std::string substr;
      getline( is, substr,sep);
      f.pushEvent( substr );
  }

  return is;

}

std::ostream& operator<< (std::ostream& os, const HistoricDate &f){

  os << f.getYear() ;
  std::string out = "";
  for(int i =0; i < f.getAmount(); i++){
    out.append("#");
    out.append(f[i]);

    std::cout << "--> " << f[i] << "[]" << std::endl << out << std::endl;
  }

  os << out;
  std::cout << "--..--- " << std::endl;

  return os;
}

bool HistoricDate::contains(std::string substring){
  for(int i=0; i < getAmount(); i++){
    std::string event = events[i];
    std::size_t found = event.find(substring);
    if(found!=std::string::npos)
      return true;
  }

  return false;

}
