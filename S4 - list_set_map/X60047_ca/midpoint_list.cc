#include <iostream>
#include <list>

using namespace std;

int main()
{
  list<int> l;
  list<int>::iterator it = l.end();

  string s;
  while (cin >> s) {
    if (s == "push_front") {
      int x;
      cin >> x;
      l.push_front(x);
      if (l.size() == 1 or l.size()%2 == 0) --it;
    }
    else if (s == "push_back") {
      int x;
      cin >> x;
      l.push_back(x);
      if (l.size() == 1) --it; // fix attempt to increment a past-the-end iterator with p2++
      else if (l.size()%2 != 0) ++it;
    }
    else if (s == "pop_front") {
      if (not l.empty()) {
        if (l.size() == 1) it = l.end();
        else if (l.size()%2 == 0) ++it;
        l.pop_front();
      }
      else cout << "error" << endl;
    }
    else if (s == "pop_back") {
      if (not l.empty()) {
        if (l.size() == 1) it = l.end();
        else if (l.size()%2 != 0) --it;
        l.pop_back();
      }
      else cout << "error" << endl;
    }
    else if (s == "get_mid_value") {
      if (not l.empty() and l.size()%2 != 0)
        cout << *it << endl;
      else cout << "error" << endl;
    }
  }
}
