#include "sumAtDepthEven.hh"

int sumAtDepthOdd(BinTree<int> t);

int sumAtDepthEven(BinTree<int> t)
{
  if (t.empty()) return 0;
  return t.value() + sumAtDepthOdd(t.left()) + sumAtDepthOdd(t.right());
}

int sumAtDepthOdd(BinTree<int> t)
{
  if (t.empty()) return 0;
  return sumAtDepthEven(t.left()) + sumAtDepthEven(t.right());
}

// The root (0) is of even depth.
// What this recursive solution does is:
//  (0) sum and go to next position
//  (1) go to next positon
//  (2) sum and go to next position
//  (3) go to next position
//  etc.
