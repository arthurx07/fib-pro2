#include "reverseTree.hh"

BinTree<int> reverseTree(BinTree<int> t)
{
  if (t.empty()) return BinTree<int>();
  BinTree<int> left = reverseTree(t.left());
  BinTree<int> right = reverseTree(t.right());
  return BinTree<int>(t.value(), right, left);
}
