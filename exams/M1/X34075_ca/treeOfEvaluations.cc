#include "treeOfEvaluations.hh"

BinTree<bool> treeOfEvaluations(BinTree<string> t)
{
  // if (t.empty()) return BinTree<bool>(); // empty-safe
  if (t.value() == "true") return BinTree<bool>(true);
  else if (t.value() == "false") return BinTree<bool>(false);

  BinTree<bool> left = treeOfEvaluations(t.left());
  if (t.value() == "not")
    return BinTree<bool>(not left.value(), left, BinTree<bool>());

  BinTree<bool> right = treeOfEvaluations(t.right());
  if (t.value() == "and")
    return BinTree<bool>(left.value() and right.value(), left, right);
  else // if (t.value() == "or")
    return BinTree<bool>(left.value() or right.value(), left, right);
}
