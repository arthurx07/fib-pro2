#include "maximumTree.hh"

BinTree<int> maximumTree(BinTree<int> a1, BinTree<int> a2)
{
  if (a1.empty() and a2.empty()) return BinTree<int>();
  else if (a1.empty()) return a2;
  else if (a2.empty()) return a1;
  else {
    BinTree<int> left = maximumTree(a1.left(), a2.left());
    BinTree<int> right = maximumTree(a1.right(), a2.right());
    if (a1.value() > a2.value())
      return BinTree<int>(a1.value(), left, right);
    else
      return BinTree<int>(a2.value(), left, right);
  }
}
