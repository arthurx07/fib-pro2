#include <iostream>
#include "BinTree.hh"
using namespace std;

// Pre: a is a tree, without repetitions. x is an integer
// Post: True if x is in the tree, otherwise False. If True, x has been deleted
//  as well as its successors.
bool poda_subarbre(BinTree<int> &a, int x)
{
  if (a.empty()) return false;
  else if (a.value() == x) {
    a = BinTree<int>();
    return true;
  }
  else {
    BinTree<int> left = a.left();
    BinTree<int> right = a.right();
    if (poda_subarbre(left, x) or poda_subarbre(right, x)) {
      // for example: if a.left().value() equals x, then left will be empty
      //  and we'll have pruned this branch.
      a = BinTree<int>(a.value(), left, right);
      return true;
    }
    return false;
  }
}

int main()
{
  int x;
  string format;
  cin >> format >> x;
  BinTree<int> t;
  t.setInputOutputFormat(format=="INLINEFORMAT" ? BinTree<int>::INLINEFORMAT : BinTree<int>::VISUALFORMAT);
  while (cin >> t and not t.empty()) {
    cout << poda_subarbre(t, x);
    cout << ", ";
    cout << t << endl;
  }
}
