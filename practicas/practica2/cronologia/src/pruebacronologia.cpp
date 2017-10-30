#include "chronology.h"
#include "historicDate.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){

  if (argc!=2){
      cout<<"Dime el nombre del fichero con la cronologia"<<endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }

   Chronology mi_cronologia;
   f>>mi_cronologia; //Cargamos en memoria la cronología.

   cout << "Número de eventos en la cronología: " << mi_cronologia.getAmount() << endl;

   /* Exhibir aquí la funcionalidad programada para el TDA Cronologia / TDA FechaHistorica */

   // Test busqueda por año
   int year;

   cout << "Introduzca un año para conseguir los eventos acontecidos en él: ";
   cin >> year;

   cout << "Eventos correspondientes a dicha fecha: " << endl;
   cout << mi_cronologia.find(year);

   //Cronologia de eventos con palabra;

   string busqueda;
   cout << "Introduzca una palabra clave para buscar: ";
   cin >> busqueda;

   cout << "Cronología de eventos corerspondiente a dicha fecha: " << endl;
   cout << mi_cronologia.containing(busqueda);

   // Subcronología entre fechas;

   int start, end;

   cout << "Introduzca fecha inferior para una obtener una subcronología: ";
   cin >> start;

   cout << endl << "Introduzca fecha superior: ";
   cin >> end;

   cout << mi_cronologia.split(start, end);

}
