#include "historicDate.h"
#include "dinamicArray.h"
#include "chronology.h"

#include <sstream>
#include <assert.h>

Chronology::Chronology(){}

Chronology::Chronology(const Chronology &original){
  for(int i = 0; i < original.years.used(); i++){
    insertYear(original[i]);
  }
}

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
      if(years[pos].getYear() == year.getYear()){
        years[pos] += year;
        inserted = true; //In this case we have merged
      }else if(years[pos].getYear() > year.getYear()){
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
  if(i < 0 || i > years.used())
    throw std::out_of_range("Error in access to Chronology");
  return years[i];
}

const HistoricDate Chronology::operator [] (int i) const{
  if(i < 0 || i > years.used())
    throw std::out_of_range("Error in access to Chronology");
  return years[i];
}


HistoricDate& HistoricDate::operator=(const HistoricDate &original){

  if(&original != this){

    year = original.getYear();
    events = original.events;
  }
  return *this;
}

void Chronology::operator+=(const Chronology &f){
  for(int i=0; i < f.getAmount(); i++){
      insertYear(f[i]);
  }
}

int Chronology::posByYear(int y){
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

HistoricDate Chronology::find(int year){
  //If not found we return a empty HistoricDate;
  HistoricDate result;
  int y = posByYear(year);

  if(y != -1)
    return years[y];
  else
    return result;

}

std::istream& operator>> (std::istream& is, Chronology& f){

  std::string input;
  getline(is, input, '\n');

  while( is.eof() == 0 )
  {
    std::istringstream c(input);
    HistoricDate nuevo;
    c >> nuevo;
    f.insertYear(nuevo);
    getline(is, input, '\n');

  }

  return is;

}

std::ostream& operator<< (std::ostream& os, const Chronology &f){

  for(int i =0; i < f.getAmount(); i++)
    os << f[i] << std::endl;

  return os;
}

Chronology Chronology::split(int low, int high){
  Chronology output;
  fixInterval(low,high);
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
//Auxiliar functions

//Check wheter the interval [a,b] is well defined
//Takes as args a = lower limit
// b = upper limit
void Chronology::fixInterval(int &a, int &b){
  if (a > b){
    int temp = a;
    a = b;
    b = temp;
  }
}
