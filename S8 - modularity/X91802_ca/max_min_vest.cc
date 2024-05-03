#include "Estudiant.hh"
#include <vector>
using namespace std;

/* Pre: v no conte repeticions de dni  */
/* Post: si existeix a v algun estudiant amb nota, la primera component del
  resultat es la posicio de l'estudiant de nota maxima de v i la segona
  component es la posicio de l'estudiant de nota minima de v (si hi ha
  empats, s'obte en cada cas la posicio de l'estudiant amb minim DNI); si no
  hi ha cap estudiant amb nota, totes dues components valen -1 */
pair<int, int> max_min_vest(const vector<Estudiant>& v)
{
  pair<int, int> max_min (0, 0);
  bool first = true;
  for (int i = 0; i < v.size(); ++i)
  {
    if (v[i].te_nota()) {
      if (first) { // don't like this
        first = false;
        max_min = make_pair(i, i);
      }

      if (v[i].consultar_nota() > v[max_min.first].consultar_nota())
        max_min.first = i;
      if (v[i].consultar_nota() == v[max_min.first].consultar_nota()) {
        if (v[i].consultar_DNI() < v[max_min.first].consultar_DNI())
          max_min.first = i;
      }

      if (v[i].consultar_nota() < v[max_min.second].consultar_nota())
        max_min.second = i;
      if (v[i].consultar_nota() == v[max_min.second].consultar_nota()) {
        if (v[i].consultar_DNI() < v[max_min.second].consultar_DNI())
          max_min.second = i;
      }
    }
  }
  if (first) return make_pair(-1, -1);
  else return max_min;
}
