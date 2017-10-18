/**
  * @file historicDate.h
  * @brief Fichero cabecera para la clase HistoricDate
  *
  * Se crea una abstracción para representar todos los eventos
  * que ocurren en un año.
  *
  */

#include <iostream>
#include "dinamicArray.h"

#ifndef dateHeader
#define dateHeader

/**
 * @brief HistoricDate
 *
 * Un objeto de la clase HistoricDate se crea usando el T.D.A @c DinamicArray
 * usando como tipo de dato @c strings
 *
 * La eficiencia en espacio es @e O(n) ya que almacenamos una cadena
 * de strings
 *
 * Un ejemplo de su uso:
 * @include testHistoric.cpp
 *
 */

class HistoricDate{

 private:

  char separator; /**< Elemento que separa los datos en la entrada de información */
  int year; /**< Año que representa el objeto */
  DinamicArray<std::string> events; /**< Vector que almacena los hechos ocurridos */


 public:+
 // ---------------  Constructores ----------------
 /**
  * @brief Constructor por defecto
  */
  HistoricDate();

  ~HistoricDate();

  // ---------------  Constructores ----------------
  /**
   * @brief Constructor por defecto
   * @param Un entero representando el años que se introduce,
   * un objeto de la clase @c DinamicArray con los eventos occuridos
   * y separator de tipo @c char que indica cual es el separador de la
   * cadena de strings.
   */
  HistoricDate(int y,  DinamicArray<std::string> & e, char separator);

  // ------------------ Métodos ---------------------
  /**
   * @brief Acceso al evento en la posición @i.
   * @param i entero que representa la posición que se quiere acceder. 0 <= i < size()
   * @return Una referencia al elemento de tipo @c string con el evento solicitado.
   */
  std::string operator [] (int i);

  /**
   * @brief Acceso al evento en la posición @i.
   * @param i entero que representa la posición que se quiere acceder. 0 <= i < size()
   * @return Una referencia al elemento de tipo @c string con el evento solicitado.
   */
  const std::string operator [] (int i) const;

  /**
   * @brief Información sobre el año que representa el objeto
   * @return Un elemento de tipo @c int que representa el año.
   */
  int getYear() const;

  /**
   * @brief Información sobre el número de eventos almacenados.
   * @return Un elemento de tipo @c int que representa la cantidad de eventos.
   */
  int getAmount() const;

  /**
   * @brief Metodo para extraer el separador que admite la clase
   * @return Un elemento de tipo @c char que representa el separador
   * que usa el objeto.
   */
  char getSeparator();
  void setYear(int y);
  void pushEvent(std::string nombre);
  bool contains(std::string);
  void operator+=(const HistoricDate &);

  friend std::istream& operator >> (std::istream& is, HistoricDate &);
  //friend ostream& operator << (istream& os, const FechaHistorica &f);

};
#endif
