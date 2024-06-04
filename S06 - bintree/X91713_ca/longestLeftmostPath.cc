#include "longestLeftmostPath.hh"

// list<int> longestLeftmostPath(BinTree<int> t)
// {
//   if (t.empty()) return list<int>();
//   
//   list<int> l (1, t.value()); // l.push_back(t.value());
//   list<int> left = longestLeftmostPath(t.left());
//   list<int> right = longestLeftmostPath(t.right());
//   if (left.size() >= right.size()) l.splice(l.end(), left);
//   else l.splice(l.end(), right);
//   return l;
// }

// a.splice(iterator position, list& x)
//  Transfers elements from x into the container, inserting them at position.
//
//  This effectively inserts those elements into the container and removes 
//  them from x, altering the sizes of both containers. The operation does 
//  not involve the construction or destruction of any element. They are 
//  transferred, no matter whether x is an lvalue or an rvalue, or whether 
//  the value_type supports move-construction or not.
//
//  a.splice(a.end(), x) is of cost O(1), since it just involves adjusting a 
//  couple of pointers in the linked lists.

// Alternative version:
list<int> longestLeftmostPath(BinTree<int> t)
{
  if (t.empty()) return list<int>();

  list<int> left = longestLeftmostPath(t.left());
  list<int> right = longestLeftmostPath(t.right());
  if (left.size() >= right.size()) {
    left.push_front(t.value());
    return left;
  }
  else {
    right.push_front(t.value());
    return right;
  }
}
