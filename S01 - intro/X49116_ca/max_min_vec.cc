#include <vector>
#include <iostream>
#include "vectorIOint.hh"
using namespace std;

struct parint {int prim, seg;};

parint max_min1(const vector<int>& v)
  /* Pre: v.size()>0 */
  /* Post: el primer componente del resultado es el valor maximo de v;
    el segundo componente del resultado es el valor minimo de v */
{
  parint s;
  s.prim = s.seg = v[0];
  for (int i = 1; i < v.size(); ++i) {
    if (v[i] > s.prim) s.prim = v[i];
    else if (v[i] < s.seg) s.seg= v[i];
  }
  return s;
}

pair<int,int> max_min2(const vector<int>& v)
  /* Pre: v.size()>0 */
  /* Post: el primer componente del resultado es el valor maximo de v;
    el segundo componente del resultado es el valor minimo de v */
{
  pair<int, int> r(v[0], v[0]);
  for (int i = 1; i < v.size(); ++i) {
    if (v[i] > r.first) r.first = v[i];
    else if (v[i] < r.second) r.second = v[i];
  }
  return r;
}

void max_min3(const vector<int>& v, int& x, int& y)
  /* Pre: v.size()>0 */
  /* Post: x es el valor maximo de v;  y es el valor minimo de v */
{
  x = y = v[0];
  for (int i = 1; i < v.size(); ++i) {
    if (v[i] > x) x = v[i];
    else if (v[i] < y) y = v[i];
  }
}

int main() {
  vector<int> t;
  leer_vector_int(t);

  parint s = max_min1(t);
  cout << "máximo: " << s.prim << ", mínimo: " << s.seg << endl;

  pair<int,int> p = max_min2(t);
  // .first es la primera componente, .second es la segunda componente
  cout << "máximo: " << p.first << ", mínimo: " << p.second << endl;

  int x, y;
  max_min3(t, x, y);
  cout << "máximo: " << x << ", mínimo: " << y << endl;
}
