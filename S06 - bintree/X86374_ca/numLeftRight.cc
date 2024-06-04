#include "numLeftRight.hh"

BinTree<int> aux(BinTree<int> t, int nleft, int nright)
{
  if (t.empty()) return BinTree<int>();

  BinTree<int> left = aux(t.left(), nleft + 1, nright);
  BinTree<int> right = aux(t.right(), nleft, nright + 1);

  if (t.value() == -1)
    return BinTree<int>(nleft, left, right);
  else // if (t.value() == -2)
    return BinTree<int>(nright, left, right);
}

BinTree<int> numLeftRight(BinTree<int> t)
{
  if (t.empty()) return BinTree<int>();
  t = aux(t, 0, 0);
  return t;
}
