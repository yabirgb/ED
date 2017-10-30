#include <iostream>
#include <sstream>
#include <fstream>
#include "chronology.h"

using namespace std;

int main(int argc, char * argv[]){

  ifstream f (argv[1]);
  if (!f){
   cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
   return 0;
  }

  Chronology oh, no, yes;

  f >> oh;
  no = oh;

  cout << no;

  ifstream g (argv[2]);

  g >> yes;

  oh += yes;

  cout << "----------" << endl;
  cout << oh;

}
