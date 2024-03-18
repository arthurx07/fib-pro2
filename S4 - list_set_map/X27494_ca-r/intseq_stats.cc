// Input: pair (code, name) ending with 0 0
// Output: max, min and avg of the valid elements
// If code is -1: name is valid. If code is -2: name is invalid for latest previous
// appearance in sequence.
#include <iostream>
#include <list>

using namespace std;

void recalculate(list<int>& l, int n, int& max, int& min, int& sum)
{
  bool found = false;
  list<int>::iterator it = l.begin();
  while (not found and it != l.end()) {
    if (*it == n) {
      it = l.erase(it);
      found = true;
    } else ++it;
    // it = l.erase(it) automatically moves it to the next, so we just have
    // to ++it; in the other cases (if not gives error in the end())
  }

  if (found) sum -= n;

  if ((max == n or min == n) and not l.empty()) {
    list<int>::iterator it = l.begin();
    max = *it; min = *it;
    while (it != l.end()) {
      max = std::max(*it, max);
      min = std::min(*it, min);
      ++it;
    }
  }
}

int main()
{
  list<int> l;
  int c, n;
  int sum = 0, max = 0, min = -1;
  while (cin >> c >> n and (c != 0 and n != 0)) {
    if (c == -1) {
      list<int>::iterator it = l.end();
      l.insert(it, n);
      max = std::max(n, max);
      if (min > 0) min = std::min(n, min);
      else min = n; // just for first iteration
      sum += n;
    }
    else if (c == -2 and not l.empty()) {
      recalculate(l, n, max, min, sum);
    }

    if (not l.empty()) cout << min << ' ' << max << ' ' << double(sum)/double(l.size()) << endl;
    else cout << '0' << endl;
  }
}
