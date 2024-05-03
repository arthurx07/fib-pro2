#include "Estudiant.hh"
#include <vector>
using namespace std;

/* Pre: cert */
/* Post: els estudiants de v amb nota passen a tenir la seva nota arrodonida
a la decima mes propera */
void arrodonir_vector(vector<Estudiant>& v)
{
  for (int i = 0; i < v.size(); i++)
  {
    if (v[i].te_nota())
    {
      double nota = v[i].consultar_nota();
      nota = int(10.0 * (nota + 0.05)) / 10.0;
      v[i].modificar_nota(nota);
    }
  }
}
