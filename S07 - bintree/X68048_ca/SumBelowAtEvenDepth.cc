#include "SumBelowAtEvenDepth.hh"

BinTree<int> continueOddDepth(BinTree<int> t, int& sum)
{
  if (t.empty()) return BinTree<int>();

  BinTree<int> left = SumBelowAtEvenDepth(t.left());
  BinTree<int> right = SumBelowAtEvenDepth(t.right());

  sum += t.value();
  // to carry the sum of lower depths from an even position to the next
  //  even position.
  if (not left.empty()) sum += left.value();
  if (not right.empty()) sum += right.value();

  return BinTree<int>(t.value(), left, right);
}

BinTree<int> SumBelowAtEvenDepth(BinTree<int> t)
{
  if (t.empty()) return BinTree<int>();

  int sum = t.value();
  BinTree<int> left = continueOddDepth(t.left(), sum);
  BinTree<int> right = continueOddDepth(t.right(), sum);

  return BinTree<int>(sum, left, right);
}
