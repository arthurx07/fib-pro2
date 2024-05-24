/** @file Cuenca.hh
    @brief Especificación de la clase Cuenca
*/

#ifndef _CUENCA_HH_
#define _CUENCA_HH_

#include "Barco.hh"
#include "Producto.hh"
#include "Ciudad.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <stack>
#include <utility>
#include "BinTree.hh"
#include <iostream>
#endif

/*
 * Clase Cuenca
 */

/** @class Cuenca
    @brief Representa la Cuenca donde se desarrollan los viajes del barco y las relaciones entre ciudades.

    Ofrece operaciones para leer la estructura de la cuenca, agregar productos a la cuenca, modificar el barco y añadir/modificar/quitar productos de los inventarios de las ciudades presentes en la cuenca. También se puede comerciar, hacer viajes y redistribuir, entre otros.

*/

class Cuenca {

private:

  /** @brief Map de productos */
  map<int, Producto> productos;
  /** @brief Map de ciudades */
  map<string, Ciudad> ciudades;
  /** @brief Estructura de la cuenca del río */
  BinTree<string> estructura;
  /** @brief Barco que realiza los viajes en el río */
  Barco barco;

public:
  // Constructora
  /** @brief Creadora por defecto
      \pre cierto
      \post El resultado es un conjunto de productos y ciudades vacíos, una estructura de la cuenca vacía y un barco vacío.
      \coste Constante
  */
  Cuenca();

  // Modificadoras
  
  /** @brief Adición de un producto a la cuenca
      \pre cierto
      \post El producto p se añade al conjunto de productos presentes en el parámetro implícito
      \coste Logarítmico respecto al número de productos
  */
  void agregar_producto(Producto &p);

  /** @brief Modificación del barco que viaja por la cuenca
      \pre id_compra != id_venta, cantidad_compra*cantidad_venta > 0, cantidad_compra + cantidad_venta > 0
      \post El barco de la cuenca pasa a tener un nuevo identificador de producto a comprar, identificador de producto a vender y nuevas cantidades del producto a comprar y del producto a vender
      \coste Constante
  */
  void modificar_barco(int id_compra, int cantidad_compra, int id_venta, int cantidad_venta);

  /** @brief Adición de un producto a una ciudad
      \pre necesita > 0
      \post Si la ciudad con identificador idc no tiene el producto con identificador idp, este se añade en su inventario y a posteriori se escriben el peso y volumen totales de la ciudad.
      \coste Logarítmico respecto al número de ciudades, y el tamaño de la ciudad idc
  */
  void poner_prod(string idc, int idp, int posee, int necesita);

  /** @brief Modificación de un producto de una ciudad
      \pre necesita > 0
      \post Si la ciudad con identificador idc tiene el producto con identificador idp, este se actualiza en su inventario con los nuevos valores y a posteriori se escriben el peso y volumen totales de la ciudad.
      \coste Logarítmico respecto al número de ciudades, y el tamaño de la ciudad idc
  */
  void modificar_prod(string idc, int idp, int posee, int necesita);

  /** @brief Eliminación de un producto de una ciudad
      \pre cierto
      \post Si la ciudad con identificador idc tiene el producto con identificador idp, este se elimina del inventario de su ciudad. A posteriori se escriben el peso y volumen totales de la ciudad.
      \coste Logarítmico respecto al número de ciudades, y el tamaño de la ciudad idc
  */
  void quitar_prod(string idc, int idp);

  /** @brief El barco viaja por la cuenca
      \pre cierto
      \post Se modifican los inventarios de las ciudades por las que el barco pasa. Éste busca la ruta más corta y más a la derecha (mirando río arriba) en la que vende/compra todos sus productos, si no se cumple, en la que vende/compra más productos.
      \coste Lineal respecto al número de ciudades, y por las que el barco ha pasado 
  */
  int hacer_viaje();

  /** @brief Redistribución de los productos a través de la cuenca
      \pre cierto
      \post Cada ciudad comercia, mirando río arriba, con la de su derecha y luego con la de su izquierda, hasta llegar a las ciudades de los nacimientos.
      \coste Lineal respecto al número de ciudades
  */
  void redistribuir();

  /** @brief Comercio entre dos ciudades
      \pre cierto
      \post La ciudad con identificador idc1 le da a la ciudad con identificador idc2 todos los productos que le sobren hasta alcanzar, si es posible, los que necesita idc2. Y viceversa.
      \coste Lineal respecto al tamaño más pequeño en relación a las ciudades idc1 y idc2
  */
  void comerciar(string idc1, string idc2);

  // Consultoras
  
  /** @brief Consultora del número de productos diferentes en la cuenca
      \pre cierto
      \post El resultado es el número de productos diferentes que existen en la cuenca.
      \coste Constante
  */
  int consultar_num_prod() const;

  /** @brief Consultora de la existencia de un producto
      \pre cierto
      \post Cierto si el producto existe en la cuenca.
      \coste Logarítmico respecto al número de productos
  */
  bool existe_producto(int id) const;

  /** @brief Consultora de la existencia de una ciudad
      \pre cierto
      \post Cierto si la ciudad existe en la cuenca.
      \coste Logarítmico respecto al número de ciudades
  */
  bool existe_ciudad(string id) const;

  /** @brief Consultora de un producto en una ciudad
      \pre cierto
      \post El resultado es un par de enteros (cantidad en posesión, cantidad que necesita) del Producto p. Si la ciudad no tiene el Producto p, se devuelve un par de enteros (-1, -1)..
      \coste Logarítmico respecto al tamaño de la ciudad
  */
  pair<int, int> consultar_prod(string idc, int idp) const;

  // Entrada / Salida

  /** @brief Lectura de la estructura de la cuenca
      \pre El canal estándard de entrada contiene la estructura del árbol binario de ciudades en preorden.
      \post La estructura del parámetro implícito es la leída del canal estándard de entrada
      \coste Lineal respecto al número de ciudades
  */
  void leer_estructura();

  /** @brief Lectura del inventario de una ciudad
      \pre El canal estándard de entrada contiene el número de productos, y para cada producto su id y cantidades en posesión y que necesita la ciudad.
      \post Se ha reemplazado el anterior inventario que tenía la ciudad por el leído del canal estándard de entrada
      \coste Logarítmico respecto al número de ciudades y al tamaño de la ciudad con identificador id
  */
  void leer_ciudad(string id);

  /** @brief Escritura del barco
      \pre cierto
      \post Se ha escrito por el canal estándard de salida el barco
      \coste Lineal respecto al número de viajes que el barco ha realizado
  */
  void escribir_barco() const;

  /** @brief Escritura de un producto
      \pre cierto
      \post Se ha escrito por el canal estándard de salida el producto con identificador id
      \coste Logarítmico respecto al número de productos
  */
  void escribir_producto(int id) const;

  /** @brief Escritura de una ciudad
      \pre cierto
      \post Se ha escrito por el canal estándard de salida la ciudad con identificador id
      \coste Lineal respecto al tamaño de la ciudad y Logarítmico respecto al número de ciudades
  */
  void escribir_ciudad(string id) const;

private:

  /** @brief Lectura recursiva de la estructura de la cuenca
      \pre ciudades es vacío
      \post ciudades contiene el árbol binario de ciudades leído del canal estándard de entrada, y estructura la forma de la cuenca.
      \coste Lineal respecto al número de ciudades del árbol leído
  */
  BinTree<string> leer_estructura_recursiva();

  /** @brief Redistribución recursiva
      \pre cierto
      \post Cada ciudad comercia, mirando río arriba, con la de su derecha y luego con la de su izquierda, hasta llegar a las ciudades de los nacimientos.
      \coste Lineal respecto al número de ciudades
  */
  void redistribuir_recursiva(BinTree<string> t);

  /** @brief Busca recursiva de la ruta a realizar por el barco
      \pre cierto
      \post Se busca la ruta más corta y más a la derecha (mirando río arriba) en la que el barco vende/compra todos sus productos, si no se cumple, en la que vende/compra más productos.
      \coste Lineal respecto al número de ciudades
  */
  void buscar_ruta_recursiva(BinTree<string> t, stack<string> &ruta, int &comprar, int &vender) const;
};
#endif
