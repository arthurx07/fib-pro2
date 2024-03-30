#include "numberOfLeaves.hh"

int numberOfLeaves(BinTree<int> t)
{
  if (t.empty()) return 0;

  int left_leaves = numberOfLeaves(t.left());
  int right_leaves = numberOfLeaves(t.right());
  if (left_leaves == 0 and right_leaves == 0)
    return 1;
  else
    return left_leaves + right_leaves;
}
