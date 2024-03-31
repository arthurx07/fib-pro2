#include <iostream>
#include <stack>

using namespace std;

int main()
{
  string str;
  while (cin >> str) {
    stack<char> s;
    bool wrong = false;
    int checked_count = 0;
    int current_count = 0;
    for (int i = 0; i < str.length() and not wrong; ++i) {
      char c = str[i];
      if (c == '(' or c == '[') s.push(c);
      else if (c == ')') {
        if (s.empty() or s.top() == '[') wrong = true;
        else { // if (s.top() == '(')
          current_count += 2;
          s.pop();
        }
      }
      else if (c == ']') {
        if (s.empty() or s.top() == '(') wrong = true;
        else { //if (s.top() == '[')
          current_count += 2;
          s.pop();
        }
      }
      if (s.empty() and not wrong) {
        checked_count += current_count;
        current_count = 0;
      }
    }
    cout << checked_count << endl;
  }
}
