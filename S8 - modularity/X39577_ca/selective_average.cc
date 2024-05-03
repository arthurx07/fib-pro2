#include "Estudiant.hh"
#include <iostream>
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

  for (int i = 0; i < m; ++i)
  {
    int dni;
    cin >> dni;
    double average = 0;

    for (int j = 1; j <= n; ++j)
    {
      double mark;
      cin >> mark;
      if (v.count(j))
        average += mark;
    }
    cout << dni << ' ' << average / s << endl;
  }
}
