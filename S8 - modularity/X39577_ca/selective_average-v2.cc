#include "Estudiant.hh"
#include <iostream>
#include <vector>
#include <set>
using namespace std;

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

  vector< vector<Estudiant> > vec(m, vector<Estudiant>(n));
  for (int i = 0; i < m; ++i)
  {
    int dni;
    cin >> dni;
    double average = 0;

    for (int j = 0; j < n; ++j)
    {
      double mark;
      cin >> mark;
      vec[i][j] = Estudiant(dni);
      vec[i][j].afegir_nota(mark);
      if (v.count(j+1))
        average += mark;
    }
    cout << dni << ' ' << average / s << endl;
  }
}
