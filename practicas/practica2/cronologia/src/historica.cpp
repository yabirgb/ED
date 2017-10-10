#include <iostream>
#include <cstring>
#include "historica.h"
#include "vector_dinamico.h"

using namespace std;

FechaHistorica::FechaHistorica(){
  anio = 0;
  num_elementos = 0;
  capacidad = 0;
  eventos = 0;
}

FechaHistorica::FechaHistorica(int y, int n, string * e){
  anio = y;
  num_elementos = n;
  eventos = new string [num_elementos];
  capacidad = n;
  
  for(int i = 0; i < n; i++){
    eventos[i] = e[i];
  }
}

FechaHistorica::~FechaHistorica(){
  destruir();
}

void FechaHistorica::operator+= (const FechaHistorica & f){
  resize(getElementos() + f.getElementos());
  for(int i = 0; i < f.getElementos(); i++){
    pushEvento(f.getPos(i));
  }
}

void FechaHistorica::destruir(){

  if(eventos != NULL)
    delete[] eventos;
  

  anio = 0;
  num_elementos = 0;
  capacidad = 0;
}

void FechaHistorica::resize(int size){
  string * nuevo = new string [size];

  int menor = size;
  if (size > getElementos())
    menor = getElementos();
  
  
  for(int i = 0; i < menor; i++)
    nuevo[i] = getPos(i);


  destruir();
  
  num_elementos = menor;
  capacidad = size;

  eventos = nuevo;
}

void FechaHistorica::pushEvento(string nombre){

  if (getElementos() + 1 > getCapacidad())
    resize(getCapacidad() + 1);
  
  eventos[getElementos()-1] = nombre;
  num_elementos++;
}

int FechaHistorica::getElementos() const {
  return num_elementos;
}

int FechaHistorica::getFecha() const{
  return anio;
}

int FechaHistorica::getCapacidad() const{
  return capacidad;
}

string FechaHistorica::getPos(int pos) const{
  if(pos < getElementos())
    return eventos[pos];

  return "";
} 
