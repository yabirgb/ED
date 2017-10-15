#include "historicDate.h"
#include "dinamicArray.h"
#include "chronology.h"

#include <sstream>

Chronology::Chronology(){}

int Chronology::getAmount() const{
  return years.used();
}

void Chronology::insertYear(HistoricDate year){
  bool inserted = false;

  if(getAmount() == 0)
    years.push(year);
  else{
    int pos = 0;
    do{
      if(years[pos].getYear() > year.getYear()){
        years.insert(year, pos);
        inserted = true;
      }

      pos++;
    }while(!inserted && pos < years.used());

    if(!inserted)
      years.push(year);
  }
}

HistoricDate Chronology::operator [] (int i){
  return years[i];
}

const HistoricDate Chronology::operator [] (int i) const{
  return years[i];
}

/*
void Chronology::operator+=(const Chronology &f){
  if (f.getYear() == getYear()){
    for(int i=0; i < used(); i++)
      pushEvent(f[i]);
  }
}
*/

int Chronology::findByYear(int y){
  int start=0, end=getAmount()-1;
  int mid=(start+end)/2;

  while(start<=end && years[mid].getYear()!=y){
    if(years[mid].getYear() < y)
      start=mid+1;
    else
      end=mid-1;

    mid=(start+end)/2;
  }

  if(years[mid].getYear()==y)
    return mid;
  else
    return -1;

}

std::istream& operator>> (std::istream& is, Chronology& f){

  while( is.good() )
  {
    std::string input;
    HistoricDate nuevo;
    getline(is, input, '\n');

    std::istringstream c(input);

    c >> nuevo;

    f.insertYear(nuevo);
  }

  return is;

}

Chronology Chronology::split(int low, int high){
  Chronology output;

  for(int i = 0; i < getAmount(); i++){
    //We dont make a binary search because the low and high years has no reason
    //to be in the Chronology.
    if(years[i].getYear() >= low && years[i].getYear() <= high){
      output.insertYear(years[i]);
    }
  }

  return output;

}

Chronology Chronology::containing(std::string match){
  Chronology output;
  for(int i =0; i < getAmount(); i++){
    if(years[i].contains(match))
      output.insertYear(years[i]);
  }

  return output;
}
