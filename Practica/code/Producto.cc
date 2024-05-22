#include "Producto.hh"

Producto::Producto()
{
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

istream &operator>>(istream &is, Producto &p)
{
  is >> p.peso >> p.volumen;
  return is;
}

ostream &operator<<(ostream &os, const Producto &p)
{
  if (p.id != 0) os << p.id << ' ';
  os << p.peso << ' ' << p.volumen;
  return os;
}

bool operator<(const Producto &p1, const Producto &p2)
{
  return p1.id < p2.id;
}

bool operator>(const Producto &p1, const Producto &p2)
{
  return p2 < p1;
}

bool operator==(const Producto &p1, const Producto &p2)
{
  return (p1.id == p2.id) and (p1.peso == p2.peso) and (p1.volumen == p2.volumen);
}
