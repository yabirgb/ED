#include <iostream>
#include "dinamicArray.h"
#inlcude "dinamicArray.cpp"

using namespace std;

bool testCreation(){

  bool success = true;
  int test_size = 3;

  DinamicArray<int> test1;

  if (test1.size() == 0 && test1.used() == 0)
    cout << "Success crating empty array";
  else{
    cout << "Failded crating empty array";
    success = false;
  }
  
  DinamicArray<int> test2 (test_size);

  if (test2.size() == test_size && test2.used() == 0)
    cout << "Success crating reserved array";
  else{
    cout << "Failded crating reserved array";
    success = false;
  }

  return success;

}


int main(){


  cout << "Creacion: " << testCreation() << endl;
  

}
