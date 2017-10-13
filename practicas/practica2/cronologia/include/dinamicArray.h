#ifndef DinamicArray_H
#define DinamicArray_H

template<class T>

class DinamicArray{

 private:
  T * data;
  int elements;
  int max_elements;

  void destroy();
  
 public:
  DinamicArray<T>();
  DinamicArray<T>(int n);
  DinamicArray<T>(const DinamicArray<T>& original);
  ~DinamicArray<T>();
  int used() const;
  int size() const;
  T& operator [] (int i);
  const T& operator [] (int i) const;
  DinamicArray<T>& operator=(const DinamicArray<T>& original);
  void push (T e);
  void boost(int size);
  bool insert(T e, int pos);
};

#endif

