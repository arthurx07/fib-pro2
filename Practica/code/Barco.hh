/** @file Barco.hh
    @brief Especificación de la clase Barco
*/

#ifndef _BARCO_HH_
#define _BARCO_HH_

#include <list>
#include <iostream>

using namespace std;

class Barco {

private:
  pair<int, int> vender;
  pair<int, int> comprar;
  list<string> viajes;

public:
  // Modificadoras
  void modificar(int id_compra, int id_venta, int cantidad_compra, int cantidad_venta);
  void agregar_viaje(string id);
  void olvidar();

  // Consultoras
  pair<int, int> consultar_vender() const;
  pair<int, int> consultar_comprar() const;

  // Operadores
  friend istream &operator>>(istream &is, Barco &b);
  friend ostream &operator<<(ostream &os, const Barco &b);

};
#endif
