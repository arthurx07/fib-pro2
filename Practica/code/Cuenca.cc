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

list<string> Cuenca::buscar_ruta_recursiva(BinTree<string> t, int &comprados, int &vendidos)
{
  int idc, idv, cantc, cantv;
  idc = barco.consultar_comprar().first;
  idv = barco.consultar_vender().first;
  cantc = barco.consultar_comprar().second;
  cantv = barco.consultar_vender().second;

  // cout << "idc, idv, cantc, cantv: " << idc << ' ' << idv << ' ' << cantc << ' ' << cantv << ' ' << endl;

  if (t.empty()) return list<string>();

  pair<int, int> a, b;
  a = b = make_pair(-1, -1);
  if (ciudades[t.value()].tiene_producto(productos[idc]))
    a = ciudades[t.value()].consultar_producto(productos[idc]);
  if (ciudades[t.value()].tiene_producto(productos[idv]))
    b = ciudades[t.value()].consultar_producto(productos[idv]);

  if (a != make_pair(-1, -1)) {
    int cpos = a.first, cnec = a.second;
    int cdif = cpos - cnec;
    if (cdif >= 0) comprados += cdif;
  }
  if (b != make_pair(-1, -1)) {
    int vpos = b.first, vnec = b.second;
    int vdif = vnec - vpos;
    if (vdif >= 0) vendidos += vdif;
  }
  // cout << t.value() << endl;
  // cout << "comprados: " << comprados << ", vendidos: " << vendidos << endl;
  if (comprados == cantc and vendidos == cantv) return list<string>(1, t.value());

  int ci = comprados, vi = vendidos;
  list<string> ruta_izquierda = buscar_ruta_recursiva(t.left(), ci, vi);
  ruta_izquierda.push_front(t.value());

  int cd = comprados, vd = vendidos;
  list<string> ruta_derecha = buscar_ruta_recursiva(t.right(), cd, vd);
  ruta_derecha.push_front(t.value());

  if (comprados == ci and ci == cd and vendidos == vi and vi == vd) {
    // if not (sell or buy) on any next node, return shortest path (it's the done until now)
    return list<string>(1, t.value());
  }
  else if (ci == cantc and vi == cantv) {
    // return left path FIRST on condition
    comprados = ci; vendidos = vi;
    return ruta_izquierda;
  }
  else if (cd == cantc and vd == cantv) {
    // return right path on condition
    comprados = cd; vendidos = vd;
    return ruta_derecha;
  }
  // return the most sell+buy path
  else if (ci + vi >= cd + vd) {
    comprados = ci; vendidos = vi;
    return ruta_izquierda;
  }
  else {
    comprados = cd; vendidos = vd;
    return ruta_derecha;
  }
}

int Cuenca::hacer_viaje()
{
  int comprados = 0, vendidos = 0;
  list<string> ruta = buscar_ruta_recursiva(estructura, comprados, vendidos);

  if (comprados + vendidos != 0) {
    list<string>::iterator idfin = ruta.end();
    barco.agregar_viaje(*--idfin);

    int cantc = barco.consultar_comprar().second;
    int cantv = barco.consultar_vender().second;
    for (list<string>::iterator it = ruta.begin(); it != ruta.end(); ++it)
    {
      // IDEA: las ciudades son las que compran y venden al barco cuando este pasa por ellas.
      // vende productos al barco, hasta agotar existencias o que el barco no pida más
      Producto pv = productos[barco.consultar_comprar().first];
      if (ciudades[*it].tiene_producto(pv))
      {
        pair<int, int> atributos = ciudades[*it].consultar_producto(pv);
        if (atributos.first > atributos.second) // pos > nec
        {
          int vender = atributos.first - atributos.second; // posee - necesita

          int post_vender = atributos.second;
          if (cantv >= vender) {
            cantv -= vender;
          }
         else {
            post_vender += vender - cantv; // post = necesita + (a_vender - cantv);
            cantv = 0;
          }
            
          ciudades[*it].modificar_producto(pv, post_vender, atributos.second);
        }
      }

      // compra productos del barco, hasta rellenar existencias o que el barco no tenga más
      Producto pc = productos[barco.consultar_vender().first];
      if (ciudades[*it].tiene_producto(pc))
      {
        pair<int, int> atributos = ciudades[*it].consultar_producto(pc);
        if (atributos.second > atributos.first) // nec > pos
        {
          int comprar = atributos.second - atributos.first; // necesita - posee

          int post_comprar = atributos.first;
          if (cantc >= comprar) {
            cantc -= comprar;
            post_comprar += comprar;
          }
          else {
            post_comprar += cantc;
            cantc = 0;
          }
          ciudades[*it].modificar_producto(pc, post_comprar, atributos.second);
        }
      }
    }
  }

  return comprados + vendidos;
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
