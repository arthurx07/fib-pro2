/** @file Producto.hh
    @brief Especificación de la clase Producto 
*/

#ifndef PRODUCTO_HH
#define PRODUCTO_HH

// NO_DIAGRAM: esto hace que el Doxyfile de la sesión no
// incluya estas clases en los diagramas modulares, 
// mientras que el compilador de c++ 
// sí que las procesa correctamente
#ifndef NO_DIAGRAM
#include <iostream>
#endif

using namespace std;

/*
 * Clase Producto
 */

/** @class Producto
    @brief Representa el conjunto de características y operaciones definidas en un Producto.

    Ofrece las operaciones de lectura, escritura y comparacion de dos productos diferentes. Además de poder consultar las características de un cierto producto.
*/

class Producto {

private:
  
  /** @brief Identificar del producto */
  int id;
  /** @brief Peso del producto */
  int peso;
  /** @brief Volumen del producto */
  int volumen;

public:
  // Constructoras
  /** @brief Creadora por defecto
      \pre cierto
      \post El resultado es un producto vacío, con id, peso y volumen nulos.
      \coste Constante
  */
  Producto();
  /** @brief Creadora
      \pre id>1
      \post El resultado es un producto con id, peso y volumen dados.
      \coste Constante
  */
  Producto(int id, int peso, int volumen);

  // Consultoras
  
  /** @brief Consultora del identificador de un producto
      \pre cierto
      \post El resultado es el identificador del producto
      \coste Constante
  */
  int consultar_id() const;

  /** @brief Consultora del peso de un producto
      \pre cierto
      \post El resultado es el peso del producto
      \coste Constante
  */
  int consultar_peso() const;

  /** @brief Consultora del volumen de un producto
      \pre cierto
      \post El resultado es el volumen del producto
      \coste Constante
  */
  int consultar_volumen() const;

  // Operadores
  
  /** @brief Comparación 'menor que'
      \pre cierto
      \post El resultado indica si el primer producto es menor que el segundo
      \coste Constante
  */
  friend bool operator<(const Producto &p1, const Producto &p2);

  /** @brief Comparación 'mayor que'
      \pre cierto
      \post El resultado indica si el primer producto es mayor que el segundo
      \coste Constante
  */
  friend bool operator>(const Producto &p1, const Producto &p2);

  /** @brief Comparación de igualdad
      \pre cierto
      \post El resultado indica si ambos productos son el mismo
      \coste Constante
  */
  friend bool operator==(const Producto &p1, const Producto &p2);

  // Entrada / Salida

  /** @brief Operación de lectura
      \pre El canal de entrada contiene dos enteros: el peso y el volumen del producto.
      \post El parámetro p procede a tener el peso y el volumen leído del canal de entrada
      \coste Constante
  */
  friend istream &operator>>(istream &is, Producto &p);

  /** @brief Operación de escritura
      \pre cierto
      \post Se ha escrito por el canal de salida el identificador, si no es nulo, seguido por el peso y el volumen del producto
      \coste Constante
  */
  friend ostream &operator<<(ostream &os, const Producto &p);
};
#endif
