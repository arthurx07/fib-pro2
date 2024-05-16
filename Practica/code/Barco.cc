#include "Barco.hh"

istream &operator>>(istream &is, Barco &b)
{
  int idc, cantc, idv, cantv;
  is >> idc >> cantc >> idv >> cantv;
  b.comprar = make_pair(idc, cantc);
  b.vender = make_pair(idv, cantv);
  return is;
}

void Barco::modificar(int id_compra, int id_venta, int cantidad_compra, int cantidad_venta)
{
  if (id_compra == id_venta) cerr << "error: no se puede comprar y vender el mismo producto" << endl;
  else if ((cantidad_compra == 0 and cantidad_venta == 0) or cantidad_compra < 0 or cantidad_venta < 0) cerr << "error: condiciones cantidad barco" << endl;
  else
  {
    vender = make_pair(id_venta, cantidad_venta);
    comprar = make_pair(id_compra, cantidad_compra);
  }
}

void Barco::agregar_viaje(string id)
{
  viajes.push_back(id);
}

pair<int, int> Barco::consultar_vender() const
{
  return vender;
}
pair<int, int> Barco::consultar_comprar() const
{
  return comprar;
}

ostream &operator<<(ostream &os, const Barco &b)
{
  os << b.comprar.first << ' ' << b.comprar.second << ' ' << b.vender.first << ' ' << b.vender.second << endl;
  if (not b.viajes.empty())
  {
    for (list<string>::const_iterator it = b.viajes.begin(); it != b.viajes.end(); ++it)
    {
      os << *it << endl;
    }
  }
  return os;
}
