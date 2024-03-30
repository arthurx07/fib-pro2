#include "treeOfSizes.hh"

BinTree<int> treeOfSizes(BinTree<int> t)
{
  if (t.empty()) return BinTree<int>();

  BinTree<int> left_sizes = treeOfSizes(t.left());
  BinTree<int> right_sizes = treeOfSizes(t.right());

  int size = 1;
  if (not left_sizes.empty() and not right_sizes.empty())
    size += left_sizes.value() + right_sizes.value();
  else if (not left_sizes.empty()) size += left_sizes.value();
  else if (not right_sizes.empty()) size += right_sizes.value();

  return BinTree<int>(size, left_sizes, right_sizes);
}
