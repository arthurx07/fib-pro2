#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Pre: stack with at least m elements
// Post: stack with the top m elements removed
void stack_rm(stack<string> &s, int m)
{
  for (int i = 0; i < m; ++i) s.pop();
}

// Create and print a new copy of the given stack, to not destroy the original
void print_stack(stack<string> s)
{
  while (not s.empty()) {
    cout << s.top() << endl;
    s.pop();
  }
  cout << endl;
}

int main()
{
  int n;
  cin >> n;

  int c, x; // declare x here, or in each if?
  vector< stack<string> > vcat(n);
  while (cin >> c and c != -4)
  {
    if (c == -1) {
      string name;
      cin >> name >> x;
      vcat[x-1].push(name);
    }
    else if (c == -2) {
      int m;
      cin >> m >> x;
      stack_rm(vcat[x-1], m);
    }
    else if (c == -3) {
      cin >> x;
      cout << "Pila de la categoria " << x << endl;
      print_stack(vcat[x-1]);
    }
  }
}
