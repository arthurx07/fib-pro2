#include "BinTree.hh"
#include "BinTreeIOint.hh"

int aux(const BinTree<int> &a, BinTree<int> &agd, int depth)
{
  if (a.empty()) return depth;

  BinTree<int> left, right;
  int left_depth = aux(a.left(), left, depth);
  int right_depth = aux(a.right(), right, depth);

  agd = BinTree<int>(left_depth - right_depth, left, right);

  return max(left_depth, right_depth)+1;
}

/* Pre: a=A */
/* Post: agd es un arbre amb la mateixa estructura que A on cada
  node conté el grau de desequilibri del subarbre d'A corresponent */
void arbre_graus_desequilibri(const BinTree<int> &a, BinTree<int> &agd)
{
  aux(a, agd, 0);
}
