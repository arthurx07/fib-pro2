#include "Ciudad.hh"

Ciudad::Ciudad()
{
  peso_total = volumen_total = 0;
}

bool Ciudad::poner_producto(const Producto &p, int posee, int necesita)
{
  if (tiene_producto(p)) {
    cout << "error: la ciudad ya tiene el producto" << endl;
    return false;
  }
  Atributos at;
  at.posee = posee;
  at.necesita = necesita;
  inventario[p] = at;

  peso_total += p.consultar_peso()*posee;
  volumen_total += p.consultar_volumen()*posee;
  return true;
}

bool Ciudad::modificar_producto(const Producto &p, int posee, int necesita)
{
  if (not tiene_producto(p)) {
    cout << "error: la ciudad no tiene el producto" << endl;
    return false;
  }
  pair<int, int> producto_anterior = consultar_producto(p);

  Atributos at;
  at.posee = posee;
  at.necesita = necesita;
  inventario[p] = at;

  peso_total += p.consultar_peso()*(posee - producto_anterior.first);
  volumen_total += p.consultar_volumen()*(posee - producto_anterior.first);
  return true;
}


bool Ciudad::quitar_producto(const Producto &p)
{
  if (not tiene_producto(p)) {
    cout << "error: la ciudad no tiene el producto" << endl;
    return false;
  }
  int posee = inventario.at(p).posee;
  peso_total -= p.consultar_peso()*posee;
  volumen_total -= p.consultar_volumen()*posee;
  inventario.erase(p);
  return true;
}

void Ciudad::comerciar(Ciudad &c)
{
  map<Producto, Atributos>::iterator it1 = inventario.begin();
  map<Producto, Atributos>::iterator it2 = c.inventario.begin();
  while (it1 != inventario.end() and it2 != c.inventario.end())
  {
    if (it1->first == it2->first)
    {
      int dar = it1->second.posee - it1->second.necesita;
      int rec = it2->second.necesita - it2->second.posee;
      if (dar > 0 and rec > 0) {
        rec = min(dar, rec);
        it1->second.posee -= rec;
        it2->second.posee += rec;

        peso_total -= it1->first.consultar_peso()*rec;
        volumen_total -= it1->first.consultar_volumen()*rec;
        c.peso_total += it2->first.consultar_peso()*rec;
        c.volumen_total += it2->first.consultar_volumen()*rec;
      }
      else
      {
        dar = it2->second.posee - it2->second.necesita;
        rec = it1->second.necesita - it1->second.posee;
        if (dar > 0 and rec > 0) {
          rec = min(dar, rec);
          it1->second.posee += rec;
          it2->second.posee -= rec;

          peso_total += it1->first.consultar_peso()*rec;
          volumen_total += it1->first.consultar_volumen()*rec;
          c.peso_total -= it2->first.consultar_peso()*rec;
          c.volumen_total -= it2->first.consultar_volumen()*rec;
        }
      }

      ++it1;
      ++it2;
    }
    else if (it1->first > it2->first) ++it2;
    else if (it1->first < it2->first) ++it1;
  }
}

int Ciudad::size() const
{
  return inventario.size();
}

int Ciudad::consultar_peso() const
{
  return peso_total;
}
int Ciudad::consultar_volumen() const
{
  return volumen_total;
}

bool Ciudad::tiene_producto(const Producto &p) const
{
  return inventario.count(p);
}

pair<int, int> Ciudad::consultar_producto(const Producto &p) const
{
  if (not tiene_producto(p))
  {
    cout << "error: la ciudad no tiene el producto" << endl;
    return make_pair(-1, -1);
  }
  else
  {
    Atributos ab = inventario.at(p); // as p is const, use at.(key) which instead throws exception if key not present. [] may need to create a new element
    return make_pair(ab.posee, ab.necesita);
  }
}

ostream &operator<<(ostream &os, const Ciudad &c)
{
  for (map<Producto, Ciudad::Atributos>::const_iterator it = c.inventario.begin();
      it != c.inventario.end(); ++it)
  {
    os << it->first.consultar_id() << ' ' << it->second.posee << ' ' << it->second.necesita << endl;
  }
  os << c.peso_total << ' ' << c.volumen_total;
  return os;
}
