#include "numIncreasing.hh"

// Pre:
// Post: Retorna el nombre de nodes de t que no son l'arrel de t i que guarden un valor
//       estríctament major que el valor guardat al seu node pare.
int numIncreasing(BinTree<int> t)
{
  if (t.empty()) return 0;

  int left = numIncreasing(t.left());
  int right = numIncreasing(t.right());

  if (not t.left().empty() and t.left().value() > t.value())
    ++left;
  if (not t.right().empty() and t.right().value() > t.value())
    ++right;

  return right+left;
}
