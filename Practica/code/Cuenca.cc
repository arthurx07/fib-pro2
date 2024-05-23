/** @file Cuenca.cc
    @brief Implementación de la clase Cuenca
*/

#include "Cuenca.hh"

Cuenca::Cuenca()
{
  productos = map<int, Producto>();
  ciudades = map<string, Ciudad>();
  estructura = BinTree<string>();
  barco = Barco();
}

BinTree<string> Cuenca::leer_estructura_recursiva()
{
  string value;
  cin >> value;

  if (value != "#") ciudades[value];
  else return BinTree<string>();

  BinTree<string> left = leer_estructura_recursiva();
  BinTree<string> right = leer_estructura_recursiva();
  return BinTree<string>(value, left, right);
}

void Cuenca::leer_estructura()
{
  ciudades = map<string, Ciudad>(); // vaciar el mapa
  estructura = leer_estructura_recursiva();
  barco.olvidar();
}

void Cuenca::leer_ciudad(string id)
{
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    int idp, posee, necesita;
    cin >> idp >> posee >> necesita;
    if (existe_ciudad(id)) ciudades[id].poner_producto(productos[idp], posee, necesita);
  }
  if (not existe_ciudad(id)) cout << "error: no existe la ciudad" << endl;
}

void Cuenca::agregar_producto(Producto &p)
{
  int id = consultar_num_prod() + 1;
  productos[id] = Producto(id, p.consultar_peso(), p.consultar_volumen());
}

void Cuenca::modificar_barco(int idc, int idv, int cantc, int cantv)
{
  if (not existe_producto(idc) or not existe_producto(idv)) cout << "error: no existe el producto" << endl;
  else barco.modificar(idc, idv, cantc, cantv);
}

void Cuenca::poner_prod(string idc, int idp, int posee, int necesita)
{
  if (existe_producto(idp))
  {
    if (existe_ciudad(idc)) {
      if (ciudades[idc].poner_producto(productos[idp], posee, necesita))
        cout << ciudades[idc].consultar_peso() << ' ' << ciudades[idc].consultar_volumen() << endl;
    }
    else cout << "error: no existe la ciudad" << endl;
  }
  else cout << "error: no existe el producto" << endl;
}

void Cuenca::modificar_prod(string idc, int idp, int posee, int necesita)
{
  if (existe_producto(idp))
  {
    if (existe_ciudad(idc)) {
      if (ciudades[idc].modificar_producto(productos[idp], posee, necesita))
        cout << ciudades[idc].consultar_peso() << ' ' << ciudades[idc].consultar_volumen() << endl;
    }
    else cout << "error: no existe la ciudad" << endl;
  }
  else cout << "error: no existe el producto" << endl;
}

void Cuenca::quitar_prod(string idc, int idp)
{
  if (existe_producto(idp))
  {
    if (existe_ciudad(idc)) {
      if (ciudades[idc].quitar_producto(productos[idp]))
        cout << ciudades[idc].consultar_peso() << ' ' << ciudades[idc].consultar_volumen() << endl;
    }
    else cout << "error: no existe la ciudad" << endl;
  }
  else cout << "error: no existe el producto" << endl;
}

void Cuenca::comerciar(string idc1, string idc2)
{
  if (not existe_ciudad(idc1) or not existe_ciudad(idc2)) cout << "error: no existe la ciudad" << endl;
  else if (idc1 == idc2) cout << "error: ciudad repetida" << endl;
  else
  {
    ciudades[idc1].comerciar(ciudades[idc2]);
  }
}

void Cuenca::redistribuir_recursiva(BinTree<string> t)
{
  if (not t.empty()) {
    if (not t.left().empty()) {
      comerciar(t.value(), t.left().value());
      redistribuir_recursiva(t.left()); // ciudad río arriba a mano derecha
    } // debería funcionar igual sin incluir red_rec en el if

    if (not t.right().empty()) {
      comerciar(t.value(), t.right().value());
      redistribuir_recursiva(t.right());
    }
  }
}

void Cuenca::redistribuir()
{
  redistribuir_recursiva(estructura);
}

// note: think to implement it as: void func(list<string> &l) or list<string> func();
void Cuenca::buscar_ruta_recursiva(BinTree<string> t, list<string> &ruta, int &comprar, int &vender) const
{
  if (not t.empty())
  {
    int idc = barco.consultar_id_comprar();
    int idv = barco.consultar_id_vender();
    if (ciudades.at(t.value()).tiene_producto(productos.at(idc)))
    {
      pair<int, int> atributos = ciudades.at(t.value()).consultar_producto(productos.at(barco.consultar_id_comprar()));
      int diferencia = atributos.first - atributos.second; // posee - necesita
      if (diferencia > 0) comprar -= min(diferencia, comprar);
    }
    if (ciudades.at(t.value()).tiene_producto(productos.at(idv)))
    {
      pair<int, int> atributos = ciudades.at(t.value()).consultar_producto(productos.at(barco.consultar_id_vender()));
      int diferencia = atributos.second - atributos.first; // necesita - posee
      if (diferencia > 0) vender -= min(diferencia, vender);
    }

    // NOTE: always comprar >= 0 and vender >= 0;
    if (comprar == 0 and vender == 0)
      ruta.push_front(t.value());
    else
    {
      int ci = comprar;
      int vi = vender;
      list<string> ruta_izquierda;
      buscar_ruta_recursiva(t.left(), ruta_izquierda, ci, vi);

      int cd = comprar;
      int vd = vender;
      list<string> ruta_derecha;
      buscar_ruta_recursiva(t.right(), ruta_derecha, cd, vd);

      if (not (comprar == ci and ci == cd and vender == vi and vi == vd))
      {
        if (ci + vi == cd + vd)
        {
          if (ruta_izquierda.size() <= ruta_derecha.size())
          {
            comprar = ci;
            vender = vi;
            ruta = ruta_izquierda;
          }
          else
          {
            comprar = cd;
            vender = vd;
            ruta = ruta_derecha;
          }
        }
        else if (ci + vi < cd + vd)
        {
          comprar = ci;
          vender = vi;
          ruta = ruta_izquierda;
        }
        else // if (cd + vd < ci + vi)
        {
          comprar = cd;
          vender = vd;
          ruta = ruta_derecha;
        }
      }
      ruta.push_front(t.value());
    }
  }
}

int Cuenca::hacer_viaje()
{
  list<string> ruta;

  int cantc, cantv, comprar, vender;
  cantc = comprar = barco.consultar_cantidad_comprar();
  cantv = vender = barco.consultar_cantidad_vender();
  buscar_ruta_recursiva(estructura, ruta, comprar, vender);

  if (comprar != cantc or vender != cantv)
  {
    list<string>::iterator idfin = ruta.end();
    barco.agregar_viaje(*--idfin);

    for (list<string>::iterator it = ruta.begin(); it != ruta.end(); ++it)
    {
      Producto pc = productos[barco.consultar_id_comprar()];
      if (ciudades[*it].tiene_producto(pc))
      {
        pair<int, int> atributos = ciudades[*it].consultar_producto(pc);
        int diferencia = atributos.first - atributos.second;
        if (diferencia > 0)
        {
          int temp = min(diferencia, cantc);
          ciudades[*it].modificar_producto(pc, atributos.first - temp, atributos.second);
          cantc -= temp;
        }
      }
      Producto pv = productos[barco.consultar_id_vender()];
      if (ciudades[*it].tiene_producto(pv))
      {
        pair<int, int> atributos = ciudades[*it].consultar_producto(pv);
        int diferencia = atributos.second - atributos.first;
        if (diferencia > 0)
        {
          int temp = min(diferencia, cantv);
          ciudades[*it].modificar_producto(pv, atributos.first + temp, atributos.second);
          cantv -= temp;
        }
      }
    }
  }

  return barco.consultar_cantidad_comprar() + barco.consultar_cantidad_vender() - comprar - vender;
}

pair<int, int> Cuenca::consultar_prod(string idc, int idp) const
{
  if (existe_producto(idp))
  {
    if (existe_ciudad(idc)) {
      return ciudades.at(idc).consultar_producto(productos.at(idp));
    }
    else cout << "error: no existe la ciudad" << endl;
  }
  else cout << "error: no existe el producto" << endl;
  return make_pair(-1, -1);
}

int Cuenca::consultar_num_prod() const
{
  return productos.size();
}

bool Cuenca::existe_producto(int id) const
{
  return productos.count(id);
}

bool Cuenca::existe_ciudad(string id) const
{
  return ciudades.count(id);
}

void Cuenca::escribir_barco() const
{
  cout << barco << endl;
}

void Cuenca::escribir_producto(int id) const
{
  if (existe_producto(id)) cout << productos.at(id) << endl;
  else cout << "error: no existe el producto" << endl;
}

void Cuenca::escribir_ciudad(string id) const
{
  if (existe_ciudad(id)) cout << ciudades.at(id) << endl;
  else cout << "error: no existe la ciudad" << endl;
}
