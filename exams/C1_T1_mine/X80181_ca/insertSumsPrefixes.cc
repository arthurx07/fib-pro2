#include "insertSumsPrefixes.hh"
#include <iostream>

void insertSumsPrefixes(list<int> &l)
{
    list<int>::iterator it = l.begin();
    int sum = *it;
    ++it;
    while (it != l.end())
    {
        l.insert(it, sum);
        sum += *it;
        ++it;
    }
    l.insert(l.end(), sum);
}
