#include "historicDate.h"
#include "dinamicArray.h"
#include "chronology.h"

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
