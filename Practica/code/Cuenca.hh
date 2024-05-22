/** @file Cuenca.hh
    @brief Especificación de la clase Cuenca
*/

#ifndef _CUENCA_HH_
#define _CUENCA_HH_

#include "Barco.hh"
#include "Producto.hh"
#include "Ciudad.hh"

#include <map>
#include <list>
#include <utility>
#include "BinTree.hh"
#include <iostream>

class Cuenca {

private:
  map<int, Producto> productos;
  map<string, Ciudad> ciudades;
  BinTree<string> estructura; // cambiar nombre?
  Barco barco; // como los viajes realizados dependen de la cuenca, se declara aquí.

  BinTree<string> leer_estructura_recursiva();
  void redistribuir_recursiva(BinTree<string> t);
  void buscar_ruta_recursiva(BinTree<string> t, list<string> &ruta, int &comprar, int &vender) const;

public:
  // Modificadoras
  void leer_estructura();
  void leer_ciudad(string id);
  void agregar_producto(Producto &p);
  void modificar_barco(int idc, int cantc, int idv, int cantv);

  void poner_prod(string idc, int idp, int posee, int necesita);
  void modificar_prod(string idc, int idp, int posee, int necesita);
  void quitar_prod(string idc, int idp);

  int hacer_viaje();
  void redistribuir();
  void comerciar(string idc1, string idc2);

  // Consultoras
  int consultar_num_prod() const;
  bool existe_producto(int id) const;
  bool existe_ciudad(string id) const;
  pair<int, int> consultar_prod(string idc, int idp) const;

  void escribir_barco() const;
  void escribir_producto(int id) const;
  void escribir_ciudad(string id) const;

};
#endif
