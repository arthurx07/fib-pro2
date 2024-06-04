#include "Estudiant.hh"
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool cmp(const Estudiant& a, const Estudiant& b)
{
  if (a.consultar_nota() == b.consultar_nota())
    return a.consultar_DNI() < b.consultar_DNI();
  return a.consultar_nota() > b.consultar_nota();
}

// ostream &operator<<(ostream &os, Estudiant e)
// {
//   os << e.consultar_DNI() << ' ' << e.consultar_nota();
//   return os;
// }

int main()
{
  int m, n, s; // m = estudiants, n = assignatures, s = assignatures seleccionades
  cin >> m >> n >> s;

  set<int> v;
  // use set as indexes may not be given in ascending order, would use a vector otherwise
  for (int i = 0; i < s; ++i) {
    int bi;
    cin >> bi;
    v.insert(bi);
  }

  vector<Estudiant> vest(m);
  for (int i = 0; i < m; ++i)
  {
    int dni;
    cin >> dni;
    double average = 0;

    for (int j = 0; j < n; ++j)
    {
      double mark;
      cin >> mark;
      if (v.count(j+1))
        average += mark;
    }
    vest[i] = Estudiant(dni);
    vest[i].afegir_nota(average/s);
  }

  sort(vest.begin(), vest.end(), cmp);
  for (int i = 0; i < m; ++i)
    vest[i].escriure();
    // cout << vest[i] << endl;
}
