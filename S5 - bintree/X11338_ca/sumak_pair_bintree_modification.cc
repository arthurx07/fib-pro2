#include "ParInt.hh"
#include "BinTree.hh"

using namespace std;

/* Pre: a = A */
/* Post: a es com a A amb k sumat al segon component de cada node */
void sumak(BinTree<ParInt>& a, int k)
{
  if (not a.empty()) {
    // modification of top value:
    ParInt new_value = ParInt(a.value().primer(), a.value().segon() + k);

    // recursive modification of lower values:
    BinTree<ParInt> left = a.left();
    BinTree<ParInt> right = a.right();
    sumak(left, k);
    sumak(right, k);

    // assign to a
    a = BinTree<ParInt>(new_value, left, right);
    // we need to do this as BinTrees are immutable, we cannot do a.left() = ...
  }
}
