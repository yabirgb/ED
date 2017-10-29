/**
  * @file chronology.h
  * @brief Fichero cabecera del  Chronology
  *
  * Abstrae el concepto de linea temporal.
  *
  */

#include <iostream>
#include "dinamicArray.h"
#include "historicDate.h"

#ifndef ChronologyH
#define ChronologyH


/**
 *  @brief Chronology
 *
 * Un objeto de la clase Chronology se crea usando el T.D.A @c DinamicArray
 * usando como tipo de dato @c HistoricDate
 *
 *
 * La eficiencia en espacio es @e O(n^2) ya que tenemos una matriz.
 *
 * Un ejemplo de su uso:
 * @include testChronology.cpp
 *
 */


class Chronology{

 private:


  DinamicArray<HistoricDate> years; /**< Array dinámico que representa una colección de años*/

  void fixInterval(int &a, int&b);
 public:
   // ---------------  Constructores ----------------
   /**
    * @brief Constructor por defecto
    */
  Chronology();

  /**
    * @brief Constructor copia de la clase.
    * @param original @c Chronology a copiar
    */
  Chronology(const Chronology &original);

  // ---------------  Métodos ----------------
  /**
   * @brief Acceso a una posición de memoria en modo escritura
   * @param Acepta un parámetro de tipo @c int que representa
   * la posición de memoria que se quiere acceder.
   * Deber verificar 0 <= i < getAmount()
   * @return Objeto de la clase @c HistoricDate que representa
   * todos los eventos de un año
   */
  HistoricDate operator [] (int i);

  /**
   * @brief Acceso a una posición de memoria en modo lectura
   * @param Acepta un parámetro de tipo @c int que representa
   * la posición de memoria que se quiere acceder.
   * Deber verificar 0 <= i < getAmount()
   * @return Objeto de la clase @c HistoricDate que representa
   * todos los eventos de un año
   */
  const HistoricDate operator [] (int i) const;

  /**
   * @brief Cantidad de años en la cronología
   * @return Devuelve un tipo @c int que representa la Cantidad
   * de años almacenados.
   */
  int getAmount() const;

  /**
   * @brief Añadir un elemento a la cronología. Se realiza una
   * insercción de manera ordenada.
   * @param Acepta un parámetro de tipo @c HistoricDate
   */
  void insertYear(HistoricDate year);

  /**
   * @brief Combinar dos cronologías de modo que la resultane
   * esté ordenada también.
   * @param Acepta un parámetro de tipo @c Chronology que representa
   * la cronología que se quiere añadir.
   */
  void operator+=(const Chronology & f);

  /**
   * @brief Determina si un año tiene representación en la cronología
   * @param Acepta un parámetro de tipo @c int que representa
   * el año que por el que se quiere buscar.
   * @return Devuelve un tipo @c int que representa la posición en el
   * array de datos del año que se quiere buscar. En caso de no encontrase
   * devuelve -1.
   */

  int posByYear(int year);

  /**
   * @brief Conseguir una sub-cronología a partir de otra seleccionando
   * un rango de años
   * @param Acepta dos parámetro de tipo @c int que representan
   * el límite inferior y el limite superior.
   * @return Devuelve un tipo @c Chronology con las fechas que se encuentran
   * entre los límites superiores e inferiores.
   */

  Chronology split(int low, int high);

  /**
   * @brief Conseguir una sub-cronología a partir de otra seleccionando
   * los años con eventos que contienen una palabara concreta.
   * @param Acepta un parámetro de tipo string que será la palabra
   * clave para realizar la búsqueda
   * @return Devuelve un tipo @c Chronology con las fechas almacenando
   * los resultados que coinciden con la búsqueda.
   */
  Chronology containing(std::string);
  friend std::istream& operator >> (std::istream& is, Chronology &);
  friend std::ostream& operator << (std::ostream& os, const Chronology &f);


  HistoricDate find(int year);

};
#endif
