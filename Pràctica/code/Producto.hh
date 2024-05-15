/** @file Producto.hh
    @brief Especificación de la clase Producto 
*/

#ifndef _PRODUCTO_HH_
#define _PRODUCTO_HH_

#include <iostream>

using namespace std;

class Producto {

private:
  int id, peso, volumen;

public:
  // Constructoras
  Producto();
  Producto(int id, int peso, int volumen);

  // Consultoras
  int consultar_id() const;
  int consultar_peso() const;
  int consultar_volumen() const;
  friend istream &operator>>(istream &is, Producto &p);
  friend ostream &operator<<(ostream &os, const Producto &p);
  friend bool operator<(const Producto &p1, const Producto &p2);
  friend bool operator>(const Producto &p1, const Producto &p2);
  friend bool operator==(const Producto &p1, const Producto &p2);

};
#endif
