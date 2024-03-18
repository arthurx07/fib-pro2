#include <vector>
#include <iostream>
// are <vector> and <iostream> includes necessary, as they are also included in "vectorIOint.hh" ?
// YES, each c[++] file is a separate program on its own and needs to compile independly from others.
// (https://stackoverflow.com/questions/46008637/if-you-include-something-in-the-h-file-do-you-have-to-include-the-same-thing-ag)
// (https://stackoverflow.com/questions/6963143/headers-include-in-multiple-c-files)

#include "vectorIOint.hh" // comillas, está en el mismo directorio que el .cc
using namespace std;

int busqueda_lin(const vector<int>& v, int x) {
  /* Pre: cierto */
  /* Post: si el resultado es v.size(), x no esta en v;
     en caso contrario, indica la posicion de la primera aparicion de x en v */
  int n = int(v.size()); // WHY USES INT(V.SIZE()) ¿?
  for (int i = 0; i < n; ++i) {
    if(v[i] == x) return i;
  }
  return n;
}

int main() {
  vector<int> t;
  leer_vector_int(t); // from vectorIOint.hh
  // escribir_vector_int(t);

  int x;
  cin >> x;

  int r = busqueda_lin(t, x);
  if (r != t.size()) cout << "la posicion de " << x << " es " << r << '.' << endl;
  else cout << x << " no está en el vector" << endl;
}
