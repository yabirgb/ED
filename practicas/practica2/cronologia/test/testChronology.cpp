#include <iostream>
#include <sstream>
#include "chronology.h"

using namespace std;

int main(){

  Chronology timeline;

  HistoricDate test;
  HistoricDate test2;

  istringstream c("2002#Star Theatre#Scrooge, or, Marley's Ghost");
  istringstream b("2001#The first draft of the human genome is completed");

  c >> test;
  b >> test2;

  cout << "Year: " << test.getYear() << endl;
  cout << "First: " << test[0] << endl;
  cout << "Second: " << test[1] << endl;

  timeline.insertYear(test);
  cout << "Inserted test 1" << endl;
  cout << "Amount: " << timeline.getAmount() << endl;
  timeline.insertYear(test2);

  cout << "Year: " << timeline[0].getYear() << endl;
  cout << "Year: " << timeline[1].getYear() << endl;


    int pos, pos2, pos3;

    pos = timeline.findByYear(2001);
    pos2 = timeline.findByYear(2002);
    pos3 = timeline.findByYear(2003);
    cout << "Position of 2001: " << pos << endl;
    cout << "Position of 2002: " << pos2 << endl;
    cout << "Position of 2003: " << pos3 << endl;
}
