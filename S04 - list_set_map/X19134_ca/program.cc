#include "LlistaIOParInt.hh"
#include "ParInt.hh"
#include <iostream>
#include <list>

int main()
{
  list<ParInt> l; 
  LlegirLlistaParInt(l);

  int n;
  cin >> n;

  int count = 0;
  int buddy_sum = 0;
  for (list<ParInt>::const_iterator it = l.begin(); it != l.end(); ++it) {
    ParInt p = *it;
    if (p.primer() == n) {
      ++count;
      buddy_sum += p.segon();
    }
  }

  cout << n << ' ' << count << ' ' << buddy_sum << endl;
}

/* Alternative exercise:
Dado un número y una lista de pares de números enteros, comprobad si dicho número aparece como
primer elemento de algún par de la lista y, en caso de éxito, escribid el par completo. Suponed
que en la lista no existen repeticiones de los primeros elementos.

int main()
{
  list<ParInt> l;
  LlegirLlistaParInt(l);

  int n;
  cin >> n;

  bool found = false;
  for (list<ParInt>::const_iterator it = l.begin(); it != l.end() and not found; ++it) {
    ParInt p = *it;
    if (p.primer() == n) {
      found = true;
      p.escriure();
    }
  }
}
*/
