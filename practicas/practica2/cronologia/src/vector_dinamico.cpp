#include <iostream>
#include "vector_dinamico.h"

template<class T>
VectorDinamico<T>::VectorDinamico(): elements(0), max_elements(0), datos(0){}

template<class T>
VectorDinamico<T>::VectorDinamico(const Vector_Dinamico<T>& original){

  elements = original.used();
  size = original.size();

  data = new T [size];

  for (int i = 0; i < n; i++){
    data[i] = original[i];
  }

}

template<class T>
VectorDinamico<T>::~Vector_Dinamico<T>(){
  destroy();
}

template<class T>
void VectorDinamico<T>::destroy(){
  
  if(data != 0)
    delete[] data;
  
  elements = 0;
  max_elements = 0;
}

template<class T>
int VectorDinamico<T>::size(){
  return max_elements;
}

template<class T>
int VectorDinamico<T>::used(){
  return elements;
}


template<class T>
T& VectorDinamico<T>::operator[](int i){
  return data[i];
}

template<class T>
const T& VectorDinamico<T>::operator[](int i) const{
  return data[i];
}


template<class T>
T& VectorDinamico<T>::operator=(const Vector_Dinamico<T>& original){
  if (this == &t)
    return *this;

  delete [] data;
  elements = original.used();
  max_elements = original.size();

  data = new T [max_elements];

  for (int i = 0; i < n; i++)
    data[i] = original[i];

}
