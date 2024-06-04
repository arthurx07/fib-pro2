#include <iostream>
#include <list>

using namespace std;

void write_error()
{
  cout << "error" << endl;
}

int main()
{
  list<int> l;

  string s;
  while (cin >> s) {
    if (s == "push_front") {
      int x;
      cin >> x;
      l.push_front(x);
    }
    else if (s == "push_back") {
      int x;
      cin >> x;
      l.push_back(x);
    }
    else if (s == "pop_front") {
      if (not l.empty()) l.pop_front();
      else write_error();
    }
    else if (s == "pop_back") {
      if (not l.empty()) l.pop_back();
      else write_error();
    }
    else if (s == "get_mid_value") {
      if (int(l.size())%2 == 1) {
        list<int>::iterator it = l.begin();
        for (int i = 0; i < int(l.size())/2; ++i) ++it; // :\.
        cout << *it << endl;
      }
      else write_error();
    }
  }
}

// implement with switch case?
