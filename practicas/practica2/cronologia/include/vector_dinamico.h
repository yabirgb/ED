#ifndef _vectorDinamico_h
#define _vectorDinamico_h

template<class T>

class VectorDinamicoD{

 private:
  T * data;
  int elements;
  int max_elements;

  void destruir();
  
 public:
  Vector_Dinamico<T>(int n);
  Vector_Dinamico<T>(const Vector_Dinamico<T>& original);
  ~Vector_Dinamico<T>();
  int used() const;
  int size() const;
  T& operator[](int i);
  const T& operator[](int i) const;
  void resize(int n);
  Vector_Dinamico<T>& operator = (const Vector_Dinamico<T>& original);
  
}

#endif
