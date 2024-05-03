#include "postorderTree.hh"

BinTree<int> aux(BinTree<int> t, int& count)
{
  if (t.empty()) return BinTree<int>();
  
  BinTree<int> left = aux(t.left(), count);
  BinTree<int> right = aux(t.right(), count);
  ++count;

  return BinTree<int>(count, left, right);
}

BinTree<int> postorderTree(BinTree<int> t)
{
  int count = 0;
  return aux(t, count);
}
