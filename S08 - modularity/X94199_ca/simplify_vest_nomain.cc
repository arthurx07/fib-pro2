#include "Estudiant.hh"
#include <vector>
using namespace std;

/* Pre: v=V, v.size() > 0 i les notes d'un mateix estudiant son consecutives */
/* Post: pos+1 es el nombre d'estudiants diferents de V; cada estudiant de V
  nomes hi apareix un cop a v[0..pos], amb la nota mes alta i en el mateix
  ordre que a V */
void simplificar_vector(vector<Estudiant>& v, int& pos)
{
  pos = 0;
  for (int i = 1; i < v.size(); ++i)
  {
    if (v[pos].consultar_DNI() != v[i].consultar_DNI()) { // same as (i != 0 and v[i-1]...)
      ++pos;
      v[pos] = move(v[i]); // ó v[pos] = v[i] ó swap(v[pos], v[i]). *Nota
    }
    else
    {
      if (v[i].te_nota() and v[pos].te_nota() and v[i].consultar_nota() > v[pos].consultar_nota())
        v[pos].modificar_nota(v[i].consultar_nota());
      else if (v[i].te_nota() and not v[pos].te_nota())
        v[pos].afegir_nota(v[i].consultar_nota());
    }
  }
}

/*
*Nota:
Se suposa que swap(v[pos], v[i]) és més eficient que v[pos] = v[i], ja que mentre
aquest últim ha de copiar els valors l'altre només ha de moure un parell de punters.

Tot i que ara que ho estic pensant, en aquest cas no té molt de sentit ja que els vectors estan
escrits en ordre a memòria. I potser el cost és el mateix (inclús més ja que un només
assignaria i l'altre (swap) haurà de fer més coses).

Es veu que a c++ 11, existeix move que està pensat per a casos quan es vol 'moure'
un valor d'un lloc a un altre (de manera similar a swap, només que es perd el valor
sobre el que s'escriu).

Resum: no se què és millor.
*/
