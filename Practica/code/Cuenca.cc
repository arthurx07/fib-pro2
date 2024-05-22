#include "Cuenca.hh"

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
  // map<string, Ciudad> 
  ciudades = map<string, Ciudad>(); // empty map
  estructura = leer_estructura_recursiva();
  barco.olvidar();
  // estructura.setOutputFormat(BinTree<string>::VISUALFORMAT);
  // cout << estructura;
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

void Cuenca::modificar_barco(int idc, int idv, int cantc, int cantv)
{
  if (not existe_producto(idc) or not existe_producto(idv)) cout << "error: no existe el producto" << endl;
  else barco.modificar(idc, idv, cantc, cantv);
}

void Cuenca::agregar_producto(Producto &p)
{
  int id = consultar_num() + 1;
  Producto prod(id, p.consultar_peso(), p.consultar_volumen());
  productos[id] = prod;
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
  if (idc1 == idc2) cout << "error: ciudad repetida" << endl;
  else if (not existe_ciudad(idc1) or not existe_ciudad(idc2)) cout << "error: no existe la ciudad" << endl;
  else
  {
    if (ciudades[idc1].medida() < ciudades[idc2].medida()) ciudades[idc1].comerciar(ciudades[idc2]);
    else ciudades[idc2].comerciar(ciudades[idc1]);
  }
}

void Cuenca::redistribuir_recursiva(BinTree<string> t)
{
  if (not t.empty()) {
    if (not t.left().empty()) comerciar(t.value(), t.left().value());
    redistribuir_recursiva(t.left()); // ciudad río arriba a mano derecha

    if (not t.right().empty()) comerciar(t.value(), t.right().value());
    redistribuir_recursiva(t.right());
  }
}

void Cuenca::redistribuir()
{
  redistribuir_recursiva(estructura);
}

// list<string> Cuenca::buscar_ruta_recursiva(BinTree<string> t, int &comprados, int &vendidos)
// {
//   int idc, idv, cantc, cantv;
//   idc = barco.consultar_comprar().first;
//   idv = barco.consultar_vender().first;
//   cantc = barco.consultar_comprar().second;
//   cantv = barco.consultar_vender().second;
//
//   // cout << "idc, idv, cantc, cantv: " << idc << ' ' << idv << ' ' << cantc << ' ' << cantv << ' ' << endl;
//
//   if (t.empty()) return list<string>();
//
//   pair<int, int> a, b;
//   a = b = make_pair(-1, -1);
//   if (ciudades[t.value()].tiene_producto(productos[idc]))
//     a = ciudades[t.value()].consultar_producto(productos[idc]);
//   if (ciudades[t.value()].tiene_producto(productos[idv]))
//     b = ciudades[t.value()].consultar_producto(productos[idv]);
//
//   if (a != make_pair(-1, -1)) {
//     int cpos = a.first, cnec = a.second;
//     int cdif = cpos - cnec;
//     if (cdif >= 0) comprados += cdif;
//   }
//   if (b != make_pair(-1, -1)) {
//     int vpos = b.first, vnec = b.second;
//     int vdif = vnec - vpos;
//     if (vdif >= 0) vendidos += vdif;
//   }
//
//   if (comprados == cantc and vendidos == cantv) return list<string>(1, t.value());
//
//   int ci = comprados, vi = vendidos;
//   list<string> ruta_izquierda = buscar_ruta_recursiva(t.left(), ci, vi);
//   ruta_izquierda.push_front(t.value());
//
//   int cd = comprados, vd = vendidos;
//   list<string> ruta_derecha = buscar_ruta_recursiva(t.right(), cd, vd);
//   ruta_derecha.push_front(t.value());
//
//   if (comprados == ci and ci == cd and vendidos == vi and vi == vd) {
//     // if not (sell or buy) on any next node, return shortest path (it's the done until now)
//     return list<string>(1, t.value());
//   }
//   else if (ci == cantc and vi == cantv and cd == cantc and vd == cantv)
//   {
//     if (ruta_izquierda.size() <= ruta_derecha.size())
//     {
//       comprados = ci; vendidos = vi;
//       return ruta_izquierda;
//     }
//     else
//     {
//       comprados = cd; vendidos = vd;
//       return ruta_derecha;
//     }
//   }
//   else if (ci == cantc and vi == cantv)
//   {
//     comprados = ci; vendidos = vi;
//     return ruta_izquierda;
//   }
//   else if (cd == cantc and vd == cantv)
//   {
//     comprados = cd; vendidos = vd;
//     return ruta_derecha;
//   }
//   else if (ci + vi >= cd + vd)
//   {
//     comprados = ci; vendidos = vi;
//     return ruta_izquierda;
//   }
//   else if (cd + vd > ci + vi)
//   {
//     comprados = cd; vendidos = vd;
//     return ruta_derecha;
//   }
//   else // ci + vi == cd + vd
//   {
//     if (ruta_izquierda.size() <= ruta_derecha.size())
//     {
//       comprados = ci; vendidos = vi;
//       return ruta_izquierda;
//     }
//     else
//     {
//       comprados = cd; vendidos = vd;
//       return ruta_derecha;
//     }
//   }
// }

// THINK IF IT'S MORE EFFICIENT (IN SPACE AND TIME) &LIST OR RETURN LIST
void Cuenca::buscar_ruta_recursiva(BinTree<string> t, list<string> &ruta, int &comprar, int &vender)
{
  if (not t.empty())
  {
    int idc = barco.consultar_comprar().first;
    int idv = barco.consultar_vender().first;
    if (ciudades[t.value()].tiene_producto(productos[idc]))
    {
      pair<int, int> atributos = ciudades[t.value()].consultar_producto(productos[barco.consultar_comprar().first]);
      int diferencia = atributos.first - atributos.second; // posee - necesita
      if (diferencia > 0) comprar -= min(diferencia, comprar);
    }
    if (ciudades[t.value()].tiene_producto(productos[idv]))
    {
      pair<int, int> atributos = ciudades[t.value()].consultar_producto(productos[barco.consultar_vender().first]);
      int diferencia = atributos.second - atributos.first; // necesita - posee
      if (diferencia > 0) vender -= min(diferencia, vender);
    }

    // NOTE: COMPRAR NEVER < 0 AND VENDER NEVER < 0
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

      // if (comprar != ci or ci != cd or vender != vi or vi != vd)
      if (not (comprar == ci and ci == cd and vender == vi and vi == vd))
      {
        if (ci + vi == cd + vd)
        {
          if (ruta_izquierda.size() <= ruta_derecha.size())
          {
            comprar = ci; vender = vi;
            ruta = ruta_izquierda;
          }
          else
          {
            comprar = cd; vender = vd;
            ruta = ruta_derecha;
          }
        }
        else if (ci + vi < cd + vd)
        {
          comprar = ci; vender = vi;
          ruta = ruta_izquierda;
        }
        else // if (cd + vd < ci + vi)
        {
          comprar = cd; vender = vd;
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

  int comprar = barco.consultar_comprar().second;
  int vender = barco.consultar_vender().second;
  buscar_ruta_recursiva(estructura, ruta, comprar, vender);

  int cantc = barco.consultar_comprar().second;
  int cantv = barco.consultar_vender().second;

  if (comprar != cantc or vender != cantv)
  {
    list<string>::iterator idfin = ruta.end();
    --idfin;
    barco.agregar_viaje(*idfin);

    for (list<string>::iterator it = ruta.begin(); it != ruta.end(); ++it)
    {
      Producto pc = productos[barco.consultar_comprar().first];
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
      Producto pv = productos[barco.consultar_vender().first];
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

  return barco.consultar_comprar().second + barco.consultar_vender().second - comprar - vender;
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

int Cuenca::consultar_num() const
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
  cout << barco; // << endl;
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
