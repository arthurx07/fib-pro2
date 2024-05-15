#include "Cuenca.hh"

BinTree<string> Cuenca::leer_estructura_recursiva()
{
  string value;
  cin >> value;
  ciudades[value];

  if (value == "#") return BinTree<string>();

  BinTree<string> left = leer_estructura_recursiva();
  BinTree<string> right = leer_estructura_recursiva();
  return BinTree<string>(value, left, right);
}

void Cuenca::leer_estructura()
{
  map<string, Ciudad> ciudades = map<string, Ciudad>(); // empty map
  estructura = leer_estructura_recursiva();
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
  if (not existe_ciudad(id)) cerr << "error: no existe la ciudad" << endl;
}

void Cuenca::modificar_barco(int idc, int idv, int cantc, int cantv)
{
  if (not existe_producto(idc) or not existe_producto(idv)) cerr << "error: no existe el producto" << endl;
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
    else cerr << "error: no existe la ciudad" << endl;
  }
  else cerr << "error: no existe el producto" << endl;
}

void Cuenca::modificar_prod(string idc, int idp, int posee, int necesita)
{
  if (existe_producto(idp))
  {
    if (existe_ciudad(idc)) {
      if (ciudades[idc].modificar_producto(productos[idp], posee, necesita))
        cout << ciudades[idc].consultar_peso() << ' ' << ciudades[idc].consultar_volumen() << endl;
    }
    else cerr << "error: no existe la ciudad" << endl;
  }
  else cerr << "error: no existe el producto" << endl;
}

void Cuenca::quitar_prod(string idc, int idp)
{
  if (existe_producto(idp))
  {
    if (existe_ciudad(idc)) {
      if (ciudades[idc].quitar_producto(productos[idp]))
        cout << ciudades[idc].consultar_peso() << ' ' << ciudades[idc].consultar_volumen() << endl;
    }
    else cerr << "error: no existe la ciudad" << endl;
  }
  else cerr << "error: no existe el producto" << endl;
}

void Cuenca::comerciar(string idc1, string idc2)
{
  if (idc1 == idc2) cerr << "error: ciudad repetida" << endl;
  else if (not existe_ciudad(idc1) or not existe_ciudad(idc2)) cerr << "error: no existe la ciudad" << endl;
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

BinTree<string> Cuenca::buscar_ruta_recursiva(BinTree<string> t)
{
  if (t.empty()) return t; // ??
  // int comprar_ciudad = t.value().; // etc
  return t;
}

pair<int, int> Cuenca::hacer_viaje()
{
  // int idc, idv, cantc, cantv;
  // idc = barco.consultar_comprar().first;
  // idv = barco.consultar_vender().first;
  // cantc = barco.consultar_comprar().second;
  // cantv = barco.consultar_vender().second;

  // ver apuntes libreta

  buscar_ruta_recursiva(estructura);

  cout << "hacer viaje" << endl;
  int comprados = 0, vendidos = 0;
  return make_pair(comprados, vendidos);
}

pair<int, int> Cuenca::consultar_prod(string idc, int idp) const
{
  if (existe_producto(idp))
  {
    if (existe_ciudad(idc)) {
      return ciudades.at(idc).consultar_producto(productos.at(idp));
    }
    else cerr << "error: no existe la ciudad" << endl;
  }
  else cerr << "error: no existe el producto" << endl;
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
  else cerr << "error: no existe el producto" << endl;
}

void Cuenca::escribir_ciudad(string id) const
{
  if (existe_ciudad(id)) cout << ciudades.at(id) << endl;
  else cerr << "error: no existe la ciudad" << endl;
}
