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
      if (s.empty()) s.push(c[i]);
      else if (s.top() == '(' and c[i] == ')') s.pop();
      else if (s.top() == '[' and c[i] == ']') s.pop();
      else if (s.top() == '(' and c[i] == ']')
      {
        s.pop();
        --i; // que no es lo mismo que: s.push(c[i]);
      }
      else s.push(c[i]);
    }

    stack<char> t;
    while (not s.empty())
    {
      t.push(s.top());
      s.pop();
    }
    while (not t.empty())
    {
      cout << t.top();
      t.pop();
    }
    cout << endl;
  }
}
