#include <iostream>
#include <sstream>
#include <fstream>
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
  //cout << "First: " << test[0] << endl;
  //cout << "Second: " << test[1] << endl;

  timeline.insertYear(test);
  cout << "Inserted test 1" << endl;
  cout << "Amount: " << timeline.getAmount() << endl;
  timeline.insertYear(test2);
  cout << "Inseted test2" << endl;
  cout << "Year: " << timeline[0].getYear() << endl;
  cout << "Year: " << timeline[1].getYear() << endl;


  int pos, pos2, pos3;

  pos = timeline.posByYear(2001);
    pos2 = timeline.posByYear(2002);
    pos3 = timeline.posByYear(2003);
    cout << "Position of 2001: " << pos << endl;
    cout << "Position of 2002: " << pos2 << endl;
    cout << "Position of 2003: " << pos3 << endl;

    string nombre = "/home/yabir/Documents/ED/practicas/practica2/cronologia/datos/test.txt";
    string nombre2 = "/home/yabir/Documents/ED/practicas/practica2/cronologia/datos/test2.txt";

    ifstream f (nombre);
    ifstream g (nombre2);

    if (!f){
      cout<<"No puedo abrir el fichero "<< nombre <<endl;
      return 0;
    }

    Chronology cien, algs;

    f >> cien;
    g >> algs;

    cout << cien << endl;
    cout << "----------!" << endl;
    cout << algs << endl;
    cout << "----------!" << endl;
    cien += algs;

    cout << cien;
    cout << "----------!" << endl;
    cout << cien[1][0] << endl;
    cout << cien[1][1] << endl;


    Chronology mi_cronologia;
    f>>mi_cronologia; //Cargamos en memoria la cronología.

    cout << mi_cronologia;

    Chronology subchronology = mi_cronologia.split(1990, 2020);

    for(int i =0; i < subchronology.getAmount(); i++){
      cout << "SUB - " << subchronology[i].getYear() << endl;
    }

    Chronology films, films2, films3;

    films = mi_cronologia.containing("Wars");

    for(int i =0; i < films.getAmount(); i++){
      cout << "Wars - " << films[i].getYear() << endl;
    }

    films2 = mi_cronologia.containing("Blind");

    for(int i =0; i < films2.getAmount(); i++){
      cout << "Blind - " << films2[i].getYear() << endl;
    }

    cout << "==========" << endl;
    cout << "Before amount/size: " << films2.getAmount() << endl;
    cout << "Adition of chronologies: " << endl;
    films2 += films;
    cout << "New amount/size: " << films2.getAmount() << endl;
    for(int i =0; i < films2.getAmount(); i++){
      cout << "Year - " << films2[i].getYear() << endl;
    }

    cout << "Test overwrite: " << endl;
    films3 += films2;
    for(int i =0; i < films3.getAmount(); i++){
      for(int j =0; j < films3[i].getAmount(); j++){
        cout << "Year - " << films3[i].getYear() << " - " << films3[i][j] << endl;
      }
    }

    cout << "--------" << endl;

    cout << films3;
}
