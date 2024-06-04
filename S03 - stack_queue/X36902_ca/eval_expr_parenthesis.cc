// Input: Sequence of parenthesis (,),[,] ended with a dot.
// Output: Write "Correcte" or "Incorrecte". If it's not correct, write the
//  index of the last position which needs to be visited to confirm it.
#include <iostream>
#include <stack>
using namespace std;

pair<bool, int> eval()
{
  int i = 0;
  char c;
  stack<char> s;
  bool found = false;

  while (not found and cin >> c and c != '.')
  {
    if (c == '(' or c == '[') s.push(c);
    else if (c == ')') {
      if (s.empty()) return make_pair(false, i+1);
      else {
        found = (s.top() != '(');
        s.pop();
      }
    }
    else if (c == ']') {
      if (s.empty()) return make_pair(false, i+1);
      else {
        found = (s.top() != '[');
        s.pop();
      }
    }
    ++i;
  }
  return make_pair(not found and s.empty(), i);
}

int main()
{
  pair<bool, int> assess = eval();
  // assess is a pair formed by: a bool returning true/false if the expression
  //  is correct/incorrect, and an integer indicating the incorrect position if
  //  it's the case.
  if (assess.first) cout << "Correcte" << endl;
  else cout << "Incorrecte " << assess.second << endl;
}
