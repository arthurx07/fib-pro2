#include "inorderTree.hh"

BinTree<int> aux(BinTree<int> t, int& count)
{
    if (t.empty()) return BinTree<int>();

    BinTree<int> left = aux(t.left(), count);
    ++count;
    int value = count;
    BinTree<int> right = aux(t.right(), count);

    return BinTree<int>(value, left, right);
}

BinTree<int> inorderTree(BinTree<int> t)
{
    int count = 0;
    return aux(t, count);
}
