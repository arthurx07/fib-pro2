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
