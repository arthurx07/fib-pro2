#include <utility>
#include <iostream>
#include "Cuenca.hh"
#include "Producto.hh"

using namespace std;

int main()
{
  Cuenca c;

  // LECTURA DE PRODUCTOS
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    Producto p;
    cin >> p;
    c.agregar_producto(p); // cuenca asigna el id
  }

  // LECTURA DE ESTRUCTURA DE LA CUENCA
  c.leer_estructura();

  // LECTURA DEL BARCO
  int idc, cantc, idv, cantv;
  cin >> idc >> cantc >> idv >> cantv;
  c.modificar_barco(idc, idv, cantc, cantv);

  // LECTURA DE COMANDOS
  string command;
  while (cin >> command and command != "fin")
  {
    if (command == "leer_rio" or command == "lr") //
    {
      cout << '#' << command << endl;
      c.leer_estructura();
    }
    else if (command == "leer_inventario" or command == "li")
    {
      string id;
      cin >> id;
      cout << '#' << command << ' ' << id << endl;
      c.leer_ciudad(id);
    }
    else if (command == "leer_inventarios" or command == "ls")
    {
      cout << '#' << command << endl;

      string id;
      while (cin >> id and id != "#")
      {
        c.leer_ciudad(id);
      }
    }
    else if (command == "modificar_barco" or command == "mb")
    {
      int idc, cantc, idv, cantv;
      cin >> idc >> cantc >> idv >> cantv;

      cout << '#' << command << endl;
      c.modificar_barco(idc, idv, cantc, cantv);
    }
    else if (command == "escribir_barco" or command == "eb") //
    {
      cout << '#' << command << endl;
      c.escribir_barco();
    }
    else if (command == "consultar_num" or command == "cn")
    {
      cout << '#' << command << endl;
      cout << c.consultar_num() << endl;
    }
    else if (command == "agregar_productos" or command == "ap")
    {
      int n;
      cin >> n; // n > 0

      cout << '#' << command << ' ' << n << endl;
      for (int i = 0; i < n; ++i)
      {
        Producto p;
        cin >> p;
        c.agregar_producto(p);
      }
    }
    else if (command == "escribir_producto" or command == "ep")
    {
      int id;
      cin >> id;

      cout << '#' << command << ' ' << id << endl;
      c.escribir_producto(id);
    }
    else if (command == "escribir_ciudad" or command == "ec")
    {
      string id;
      cin >> id;

      cout << '#' << command << ' ' << id << endl;
      c.escribir_ciudad(id);
    }
    else if (command == "poner_prod" or command == "pp")
    {
      string idc;
      int idp, posee, necesita; // necesita > 0
      cin >> idc >> idp >> posee >> necesita;

      cout << '#' << command << ' ' << idc << ' ' << idp << endl;
      c.poner_prod(idc, idp, posee, necesita);
    }
    else if (command == "modificar_prod" or command == "mp")
    {
      string idc;
      int idp, posee, necesita;
      cin >> idc >> idp >> posee >> necesita;

      cout << '#' << command << ' ' << idc << ' ' << idp << endl;
      c.modificar_prod(idc, idp, posee, necesita);
    }
    else if (command == "quitar_prod" or command == "qp")
    {
      string idc;
      int idp;
      cin >> idc >> idp;

      cout << '#' << command << ' ' << idc << ' ' << idp << endl;
      c.quitar_prod(idc, idp);
    }
    else if (command == "consultar_prod" or command == "cp")
    {
      string idc;
      int idp;
      cin >> idc >> idp;

      cout << '#' << command << ' ' << idc << ' ' << idp << endl;
      pair<int, int> p = c.consultar_prod(idc, idp);
      if (p != make_pair(-1, -1)) cout << p.first << ' ' << p.second << endl;
    }
    else if (command == "comerciar" or command == "co")
    {
      string idc1, idc2;
      cin >> idc1 >> idc2;

      cout << '#' << command << ' ' << idc1 << ' ' << idc2 << endl;
      c.comerciar(idc1, idc2);
    }
    else if (command == "redistribuir" or command == "re")
    {
      cout << '#' << command << endl;
      c.redistribuir();
    }
    else if (command == "hacer_viaje" or command == "hv")
    {
      cout << '#' << command << endl;
      cout << c.hacer_viaje() << endl;
    }
    else // if (command == "//")
    {
      string s;
      getline(cin, s);
    }
  }
}
