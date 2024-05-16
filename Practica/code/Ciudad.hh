/** @file Ciudad.hh
    @brief Especificación de la clase Ciudad
*/

#ifndef _CIUDAD_HH_
#define _CIUDAD_HH_

#include <map>
#include <ostream>
#include <utility>
#include "Producto.hh"

using namespace std;

class Ciudad {

private:
  int peso_total, volumen_total;
  struct Atributos {
    int posee, necesita;
  };
  map<Producto, Atributos> inventario;
  // ¿buscar otra implementación?: CLASE CONJUNTO DE PRODUCTOS (?)

public:
  // Constructoras
  Ciudad();

  // Modificadoras
  bool poner_producto(const Producto &p, int posee, int necesita);
  bool modificar_producto(const Producto &p, int posee, int necesita);
  bool quitar_producto(const Producto &p);
  void comerciar(Ciudad &c);

  // Consultoras
  int medida() const;
  int consultar_peso() const;
  int consultar_volumen() const;
  bool tiene_producto(const Producto &p) const;
  pair<int, int> consultar_producto(const Producto &p) const;
  friend ostream &operator<<(ostream &os, const Ciudad &c);

};
#endif
