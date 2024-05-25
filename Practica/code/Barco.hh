/** @file Barco.hh
    @brief Especificación de la clase Barco
*/

#ifndef BARCO_HH
#define BARCO_HH

#ifndef NO_DIAGRAM
#include <list>
#include <utility>
#include <iostream>
#endif

using namespace std;

/*
 * Clase Barco
 */

/** @class Barco
    @brief Representa la información y las operaciones asociadas a un Barco.

    Un barco se caracteriza por tener el objetivo de vender un producto n veces y comprar otro producto diferente m veces.
    En ser un barco que viaja por un espacio, ya sea un mar, una cuenca, un mundo, este tiene la capacidad de guardar un historial del último lugar en el que ha estado en cada uno de sus viajes.

    Ofrece las operaciones de modificación del barco, adición de nuevos viajes y la eliminación de todos los viajes realizados. Además se definen las operaciones de lectura y escritura de un barco.
*/

class Barco {

private:

  /** @brief Par de enteros con first = identificador del producto a comprar, y second = cantidad de unidades a comprar */
  pair<int, int> comprar;
  /** @brief Par de enteros con first = identificador del producto a vender, y second = cantidad de unidades a vender */
  pair<int, int> vender;
  /** @brief Lista de strings que guarda los lugares donde ha finalizado sus viajes */
  list<string> viajes;

public:

  // Constructora
  /** @brief Creadora por defecto
      \pre cierto
      \post El resultado es un barco vacío, con ningún producto a comprar ni vender, ni ningún viaje realizado
      \coste Constante
  */
  Barco();

  // Modificadoras

  /** @brief Modificadora del barco
      \pre id_compra != id_venta, cantidad_compra*cantidad_venta > 0, cantidad_compra + cantidad_venta > 0
      \post El parámetro implícito pasa a tener un nuevo identificador de producto a comprar, identificador de producto a vender y nuevas cantidades del producto a comprar y del producto a vender
      \coste Constante
  */
  void modificar(int id_compra, int id_venta, int cantidad_compra, int cantidad_venta);

  /** @brief Adición de un nuevo viaje
      \pre cierto
      \post El parámetro implícito pasa a tener a <em>id</em> como identificador de la ciudad a la que ha viajado en su último viaje
      \coste Constante
  */
  void agregar_viaje(string id);

  /** @brief Eliminación de los viajes realizados
      \pre cierto
      \post El barco olvida todos los viajes que ha realizado
      \coste Constante
  */
  void olvidar();

  // Consultoras
  
  /** @brief Consultora del identificador a comprar
      \pre cierto
      \post El resultado es el identificador del producto que el barco quiere comprar
      \coste Constante
  */
  int consultar_id_comprar() const;

  /** @brief Consultora de la cantidad a comprar
      \pre cierto
      \post El resultado es la cantidad de productos iguales que barco quiere comprar
      \coste Constante
  */
  int consultar_cantidad_comprar() const;

  /** @brief Consultora del identificador a vender 
      \pre cierto
      \post El resultado es el identificador del producto que el barco quiere vender 
      \coste Constante
  */
  int consultar_id_vender() const;

  /** @brief Consultora de la cantidad a vender
      \pre cierto
      \post El resultado es la cantidad de productos iguales que el barco quiere vender 
      \coste Constante
  */
  int consultar_cantidad_vender() const;

  // Entrada / Salida

  /** @brief Operación de lectura
      \pre El canal de entrada contiene cuatro enteros: el identificador del producto a comprar, la cantidad de productos iguales a comprar, el identificador del prodcuto a vender y la cantidad de productos iguales a vender
      \post El parámetro b procede a tener las propiedades definidas en el canal de entrada
      \coste Constante
  */
  friend istream &operator>>(istream &is, Barco &b);

  /** @brief Operación de escritura
      \pre cierto
      \post Se ha escrito por el canal de salida el identificador del producto a comprar, la cantidad de productos iguales a comprar, el identificador del prodcuto a vender y la cantidad de productos iguales a vender. Finalmente se han escrito las últimas ciudades visitadas en los viajes realizados
      \coste Lineal respecto al número de viajes realizados
  */
  friend ostream &operator<<(ostream &os, const Barco &b);
};
#endif
