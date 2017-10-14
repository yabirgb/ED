#include <iostream>
#include <sstream>
#include "dinamicArray.h"
#include "historicDate.h"

using namespace std;

int main(){

  HistoricDate test;

  istringstream c("1901#Star Theatre#Scrooge, or, Marley's Ghost");
  cout << "============" << endl;
  cout << test.getAmount() << endl;

  c >> test;

  cout << "Year: " << test.getYear() << endl;
  cout << "First: " << test[0] << endl;
  cout << "Second: " << test[1] << endl;

}
