#include "numTwins.hh"

int numTwins(BinTree<int> t)
{
    if (t.empty()) return 0;

    int twins_sum = numTwins(t.left()) + numTwins(t.right());

    if (not (t.left().empty() or t.right().empty())
        and t.left().value() == t.right().value())
        return twins_sum + 1;
    else 
        return twins_sum;
}
