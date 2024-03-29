#include "BinTree.hh"

using namespace std;

int sumOfTree(BinTree<int> t)
{
  if (t.empty()) return 0;
  int left_sum = sumOfTree(t.left());
  int right_sum = sumOfTree(t.right());

  return t.value() + left_sum + right_sum;
}
