#include <stack>
#include <iostream>
using namespace std;

int main()
{
  string c;
  stack<char> s;
  while (cin >> c)
  {
    for (int i = 0; i < c.length(); ++i)
    {
      if (s.empty() or (s.top() != c[i] - 'a' + 'A' and s.top() != c[i] - 'A' + 'a')) s.push(c[i]);
      else s.pop();
    }

    // print stack
    string z = "";
    while (not s.empty()) {
      z += s.top();
      s.pop();
    }

    for (int i = z.length() - 1; i >= 0; --i) cout << z[i];
    cout << endl;
  }
}
