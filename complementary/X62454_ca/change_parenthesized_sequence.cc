#include <iostream>
#include <stack>

using namespace std;

int main()
{
  string str;
  while (cin >> str)
  {
    int changes = 0;
    stack<char> s;
    for (int i = 0; i < str.length(); ++i) {
      char c = str[i];
      if (c == '(' or c == '[') s.push(c);
      else if (c == ')') {
        if (s.top() == '[') ++changes;
        s.pop();
      }
      else if (c == ']') {
        if (s.top() == '(') ++changes;
        s.pop();
      }
    }
    cout << changes << endl;
  }
}
