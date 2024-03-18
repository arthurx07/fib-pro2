#include <iostream>
#include <list>

using namespace std;

void write_error()
{
  cout << "error" << endl;
}

// int get_mid_value(const list<int>& l)
// {
//   list<int>::const_iterator cit = l.cbegin();
//   for (int j = 0; cit != l.cend(); ++cit, ++j) {
//     if (j == (int(l.size())/2)) return *cit;
//   }
//   return -1;
// }

int main()
{
  list<int> l;
  list<int>::iterator it = l.begin();

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
        // int mid = get_mid_value(l);
        // cout << mid << endl;
        // cout << *it << endl;
      }
      else write_error();
    }
  }
}

// implement with switch case?

// Solution works with get_mid_value, but not for efficiency.
// Idea: have an iterator which always points to the middle of the 
// list; moving along with pushes and pops. Problem: a lot of errors
// with ends, begins and shits like that.
