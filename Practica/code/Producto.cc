/** @file Producto.cc
    @brief Implementación de la clase Producto
*/

#include "Producto.hh"

Producto::Producto()
{
  // Inicializa un producto con los valores privados nulos
  id = peso = volumen = 0;
}

Producto::Producto(int id, int peso, int volumen)
{
  this->id = id;
  this->peso = peso;
  this->volumen = volumen;
}

int Producto::consultar_id() const
{
  return id;
}

int Producto::consultar_peso() const
{
  return peso;
}
int Producto::consultar_volumen() const
{
  return volumen;
}

bool operator<(const Producto &p1, const Producto &p2)
{
  // La comparación 'menor que' se basa en comparar los identificadores de ambos productos
  return p1.id < p2.id;
}

bool operator>(const Producto &p1, const Producto &p2)
{
  return p2 < p1;
}

bool operator==(const Producto &p1, const Producto &p2)
{
  // Devuelve la comparación entre los diferentes valores privados de ambos productos
  return (p1.id == p2.id) and (p1.peso == p2.peso) and (p1.volumen == p2.volumen);
}

std::istream &operator>>(std::istream &is, Producto &p)
{
  is >> p.peso >> p.volumen;
  return is;
}

std::ostream &operator<<(std::ostream &os, const Producto &p)
{
  if (p.id != 0) os << p.id << ' ';
  os << p.peso << ' ' << p.volumen;
  return os;
}
