#include "treeOfSums.hh"

BinTree<int> treeOfSums(BinTree<int> t)
{
  if (t.empty()) return BinTree<int>();

  BinTree<int> left_sums = treeOfSums(t.left());
  BinTree<int> right_sums = treeOfSums(t.right());

  int value = t.value();
  if (not left_sums.empty() and not right_sums.empty())
    value += left_sums.value() + right_sums.value();
  else if (not left_sums.empty()) value += left_sums.value();
  else if (not right_sums.empty()) value += right_sums.value();
  return BinTree<int>(value, left_sums, right_sums);
}
