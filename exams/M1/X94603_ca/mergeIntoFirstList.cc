#include "mergeIntoFirstList.hh"
#include <iostream>

void mergeIntoFirstList(list<int> &l1, list<int> l2)
{
  list<int>::iterator it1 = l1.begin();
  list<int>::iterator it2 = l2.begin();
  while (it2 != l2.end())
  {
    if (it1 == l1.end() or *it1 >= *it2) {
      l1.insert(it1, *it2);
      ++it2;
    }
    else if (*it1 < *it2) ++it1;
  }
}
