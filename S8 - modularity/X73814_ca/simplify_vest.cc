#include "Estudiant.hh"
#include <vector>
using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<Estudiant> inp(n);
  vector<Estudiant> out;

  double higher = 0;
  for (int i = 0; i < n; ++i) {
    inp[i].llegir();
    if (i != 0 and inp[i-1].consultar_DNI() == inp[i].consultar_DNI())
    {
      if (inp[i-1].te_nota() and inp[i].te_nota())
        higher = max(inp[i-1].consultar_nota(), inp[i].consultar_nota());
      else if (inp[i].te_nota())
        higher = inp[i].consultar_nota();

      if (out[out.size() - 1].te_nota())
        out[out.size() - 1].modificar_nota(higher);
      else
        out[out.size() - 1].afegir_nota(higher);
    }
    else
    {
      Estudiant est = Estudiant(inp[i].consultar_DNI());
      if (inp[i].te_nota())
      {
        higher = inp[i].consultar_nota();
        est.afegir_nota(higher);
      }
      out.push_back(est);
    }
  }

  for (int j = 0; j < out.size(); ++j)
    out[j].escriure();
}
