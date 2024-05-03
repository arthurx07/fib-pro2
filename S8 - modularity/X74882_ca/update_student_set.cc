#include "Estudiant.hh"
#include "Cjt_estudiants.hh"
using namespace std;

int main()
{
  Cjt_estudiants cest, cest2;
  cest.llegir();
  cest2.llegir();

  for (int i = 1; i <= cest2.mida(); ++i)
  {
    Estudiant e;
    Estudiant e2 = cest2.consultar_iessim(i);
    if (cest.existeix_estudiant(e2.consultar_DNI()))
    {
      e = cest.consultar_estudiant(e2.consultar_DNI());
      bool greater = (e2.te_nota() and e.te_nota()
                      and e2.consultar_nota() > e.consultar_nota())

      if (greater)
        cest.modificar_estudiant(e2);
      else if (e2.te_nota() and not e.te_nota())
        cest.modificar_estudiant(e2);
    }
    else if (e2.te_nota()) {
      cest.afegir_estudiant(e2);
    }
  }

  cest.escriure();
}
