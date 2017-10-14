#include <iostream>
#include "dinamicArray.h"


using namespace std;

bool BaseTest(bool condition, string cadena){

  bool success = true;

  if(condition)
    cout << "Success " << cadena << endl;
  else{
    cout << "Failded " << cadena  << endl;
    success = false;
  }


  return success;

}

bool testCreation(){

  bool success = true;
  int test_size = 3;

  DinamicArray<int> test1;

  if (test1.size() == 0 && test1.used() == 0)
    cout << "Success crating empty array" << endl;
  else{
    cout << "Failded crating empty array" << endl;
    success = false;
  }
  
  DinamicArray<int> test2 (test_size);

  if (test2.size() == test_size && test2.used() == 0)
    cout << "Success crating reserved array" << endl;
  else{
    cout << "Failded crating reserved array" << endl;
    success = false;
  }
  test2[0] = 3;
  
  DinamicArray<int> test3 (test2);

  if (test2.size() == test_size && test2.used() == 0 && test2[0] == 3)
    cout << "Success crating copied array" << endl;
  else{
    cout << "Failded crating copied array" << endl;
    success = false;
  }

  
  return success;

}

bool testPush(){

  DinamicArray<int> test(2);

  test.push(2);
  test.push(1);
  test.push(10);

  bool success = BaseTest(test[2] == 10, "pushing to array");
  return success;

}

bool testBoost(){

  int size = 2;
  int boostSize = 1;
  
  DinamicArray<int> test(size);

  test.boost(boostSize);


  bool success = BaseTest(test.size() == size + boostSize, "updating size");
  return success;


}


bool testInsert(){

  int size = 3;

  DinamicArray<int> test(size);

  test.push(10);
  test.push(11);
  test.push(12);

  test.insert(20, 0);
  test.insert(5, 3);

  for(int i=0; i < test.used(); i++)
    cout << test[i] << endl;

  cout << test.used() << "/" << test.size() << endl;
  
  bool success = BaseTest(test[0] == 20, "insert at position");
  success = BaseTest(test[3] == 5, "insert at position 2");

  return success;

}

int main(){

  cout << "==================" << endl;
  cout << "Creation: " << testCreation() << endl;
  cout << "==================" << endl;
  cout << "Boost: " << testBoost() << endl;
  cout << "==================" << endl;
  cout << "Resize: " << testPush() << endl;
  cout << "==================" << endl;
  cout << "Insert: " << testInsert() << endl;
  cout << "==================" << endl;

}
