#include "searchInBST.hh"

// BST:= Binary Search Tree
// In these types of trees:
// - t.value() is strictly greater than each of the elements in its left subtree
// - t.value() is strictly smaller than each of the elements in its right subtree
bool searchInBST(BinTree<int> t, int x)
{
  if (t.empty()) return false;
  else if (t.value() == x) return true;
  else if (t.value() < x) return searchInBST(t.right(), x);
  else if (t.value() > x) return searchInBST(t.left(), x);
  return false;
}
