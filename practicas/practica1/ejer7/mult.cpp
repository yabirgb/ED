#include <iostream>
#include <ctime>    // Recursos para medir tiempos
#include <cstdlib>  // Para generacion de números pseudoaleatorios

using namespace std;

void show(int **v, int row, int col){

  for(int i = 0; i < row; i++){
      for(int j = 0; j < col; j++){
	cout << v[i][j] << " ";
      }
      cout << endl;
  }
}

void multiplicar(int **mult, int** matrix_a, int** matrix_b, int row_a, int  col_b, int col_a ){

  for(int i = 0; i < row_a; i++)
    for(int j = 0; j < col_b; ++j)
      for(int k = 0; k < col_a; k++)
	{
          mult[i][j] += matrix_a[i][k] * matrix_b[k][j];
        }
}

void set_random(int **matrix, int row, int col){

  const int MAX = 100;
  
  for(int i = 0; i < row; i++)
    for(int j = 0; j < col; j++){
      matrix[i][j] = rand() % MAX;
    }
}


void sintax(){}

int main(int argc, char * argv[]){

  int row_a, row_b, col_a, col_b;

  if (argc != 4)
    sintax();

  row_a = atoi(argv[1]);
  col_a = atoi(argv[2]);
  row_b = atoi(argv[3]);
  col_b = atoi(argv[4]);
  
  if(col_a != row_b)
    cerr << "Operacion no posible." << endl;
  
  int** matrix_a = new int*[row_a];
  int** matrix_b = new int*[row_b];
  int** mult = new int*[row_a];

  for (int i = 0; i < row_a; ++i)
    matrix_a[i] = new int[col_a];

  for (int i = 0; i < row_b; ++i)
    matrix_b[i] = new int[col_b];

  for (int i = 0; i < row_a; ++i)
    mult[i] = new int[col_b];

  /*
  cout << "Introduzca elementos de la matriz A:" << endl;
  for(int i = 0; i < row_a; i++)
    for(int j = 0; j < col_a; j++){
      cout << "Elemento: " << i << j  << " : ";
      cin >> matrix_a[i][j];
    }

  cout << "Introduzca elementos de la matriz B:" << endl;
  for(int i = 0; i < row_b; i++)
    for(int j = 0; j < col_b; j++){
      cout << "Elemento: " << i << j  << " : ";
      cin >> matrix_b[i][j];
    }
  */

  set_random(matrix_a, col_a, row_a);
  set_random(matrix_b, col_b, row_b);
  
  for(int i = 0; i < row_a; i++)
    for(int j = 0; j < col_b; j++)
      mult[i][j]=0;

  clock_t tini;    // Anotamos el tiempo de inicio
  tini=clock();
  multiplicar(mult, matrix_a, matrix_b, row_a, col_b, col_a );
  clock_t tfin;    // Anotamos el tiempo de finalización
  tfin=clock();

  // Mostramos resultados
  cout << col_a << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl;

  /*
  cout << endl;
  show(matrix_a, row_a, col_a);
  cout << endl;
  show(matrix_b, row_b, col_b);
  cout << endl;
  show(mult, row_a, col_b);
  */
  for (int w = 0; w < col_a; w++)
    delete[] matrix_a[w];
  for (int w = 0; w < col_b; w++)
    delete[] matrix_b[w];
  for (int w = 0; w < col_b; w++)
    delete[] mult[w];
  
  delete [] matrix_a;
  delete [] matrix_b;
  delete [] mult;
}
