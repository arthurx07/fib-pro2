/** @file Ciudad.hh
    @brief Especificación de la clase Ciudad
*/

#ifndef CIUDAD_HH
#define CIUDAD_HH

#include "Producto.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <ostream>
#include <utility>
#endif

/*
 * Clase Ciudad
 */

/** @class Ciudad
    @brief Representa la información y las operaciones asociadas a una Ciudad.

    Ofrece operaciones para comerciar entre dos ciudades, añadir nuevos productos a una ciudad, y quitar y modificar los ya existentes. Además se pueden consultar los productos que posee y necesita, como también el valor del peso y el volumen del conjunto de todos los productos. La operación de escritura está definida.
*/

using namespace std;

class Ciudad {

private:
  /** @brief Peso total de la ciudad */
  int peso_total;
  /** @brief Volumen total de la ciudad */
  int volumen_total;
  /** @brief Atributos de un producto de la ciudad, en el que se define la cantidad de los que posee y necesita */
  struct Atributos {
    int posee, necesita;
  };
  /** @brief Inventario de productos de la ciudad, con todos los productos existentes en la ciudad y de cada uno definidas la cantidad que quiere y necesita */
  map<Producto, Atributos> inventario;

public:
  // Constructora
  /** @brief Creadora por defecto
      \pre cierto
      \post El resultado es una ciudad de inventario, peso y volumen nulos
      \coste Constante
  */
  Ciudad();

  // Modificadoras

  /** @brief Modificadora del producto
      \pre necesita > 0 y posee >= 0
      \post Cierto si el parámetro implícito tiene el Producto p, entonces se procede a modificar las cantidades en posesión y de necesidad con respecto a este
      \coste Logarítmico respecto al tamaño del parámetro implícito
  */
  bool modificar_producto(const Producto &p, int posee, int necesita);

  /** @brief Adición de un nuevo producto
      \pre necesita > 0 y posee >= 0
      \post Cierto si el parámetro implícito no tiene el Producto p, entonces se prodece a añadir en el inventario, con las cantidades definidas en posesión y de necesidad
      \coste Logarítmico respecto al tamaño del parámetro implícito
  */
  bool poner_producto(const Producto &p, int posee, int necesita);

  /** @brief Eliminación de un producto
      \pre cierto
      \post Cierto si el parámetro implícito tiene el Producto p, entonces se procede a eliminarse del inventario.
      \coste Logarítmico respecto al tamaño del parámetro implícito
  */
  bool quitar_producto(const Producto &p);

  /** @brief Comercio con otra ciudad
      \pre cierto
      \post El parámetro implícito le da a la Ciudad c todos los productos que le sobren hasta alcanzar, si es posible, los que necesita. Y viceversa.
      \coste Lineal respecto al tamaño más pequeño en relación al parámetro impícito y la Ciudad c.
  */
  void comerciar(Ciudad &c);

  // Consultoras

  /** @brief Consultora del tamaño
      \pre cierto
      \post El resultado es el tamaño del parámetro implícito
      \coste Constante
  */
  int size() const;

  /** @brief Consultora del peso total
      \pre cierto
      \post El resultado es el peso total del parámetro implícito
      \coste Constante
  */
  int consultar_peso() const;

  /** @brief Consultora del volumen total
      \pre cierto
      \post El resultado es el volumen total del parámetro implícito
      \coste Constante
  */
  int consultar_volumen() const;

  /** @brief Consultora de existencia de un producto
      \pre cierto
      \post Cierto si el inventario del parámetro implícito contiene el Producto p
      \coste Logarítmico respecto al tamaño del parámetro implícito
  */
  bool tiene_producto(const Producto &p) const;

  /** @brief Consultora de un producto
      \pre cierto
      \post El resultado es un par de enteros (cantidad en posesión, cantidad que necesita) del Producto p. Si la ciudad no tiene el Producto p, se devuelve un par de enteros (-1, -1).
      \coste Logarítmico respecto al tamaño del parámetro implícito
  */
  pair<int, int> consultar_producto(const Producto &p) const;

  // Escritura

  /** @brief Operación de escritura
      \pre cierto
      \post Por cada producto en el inventario se escribe en el canal de escritura su identificador, la cantidad en posesión y la cantidad que necesita el parámetro implícito. Finalmente, se escribe el peso total seguido del volumen total del parámetro implícito.
      \coste Lineal respecto al tamaño del parámetro implícito
  */
  friend ostream &operator<<(ostream &os, const Ciudad &c);
};
#endif
