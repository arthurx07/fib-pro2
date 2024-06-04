#include "treeOfHeights.hh"

BinTree<int> treeOfHeights(BinTree<int> t)
{
  if (t.empty()) return BinTree<int>();
  
  BinTree<int> left_heights = treeOfHeights(t.left());
  BinTree<int> right_heights = treeOfHeights(t.right());
  
  int greater = 0;
  if (not left_heights.empty() and not right_heights.empty())
    greater = (left_heights.value() > right_heights.value()) ? left_heights.value() : right_heights.value();
  else if (not left_heights.empty()) greater = left_heights.value();
  else if (not right_heights.empty()) greater = right_heights.value();
  return BinTree<int>(1 + greater, left_heights, right_heights);
}
