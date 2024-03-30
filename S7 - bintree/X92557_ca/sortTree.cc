#include "sortTree.hh"

BinTree<int> sortTreeaux(BinTree<int> t, int& sum)
{
  if (t.empty()) {
    sum = 0;
    return BinTree<int>();
  }
  
  int sums_left, sums_right;
  BinTree<int> left = sortTreeaux(t.left(), sums_left);
  BinTree<int> right = sortTreeaux(t.right(), sums_right);

  sum = t.value() + sums_left + sums_right;

  if (sums_right < sums_left) return BinTree<int>(t.value(), right, left);
  else return BinTree<int>(t.value(), left, right);
}

BinTree<int> sortTree(BinTree<int> t)
{
  int s;
  return sortTreeaux(t, s);
}
