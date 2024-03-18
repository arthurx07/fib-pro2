// Input: integer n, followed by an integer sequence of length n
// Output: write "SI" or "NO", if the sequence is palindrome or not
#include <iostream>
#include <stack>
using namespace std;

int main()
{
  int n;
  cin >> n;

  stack<int> s;
  for (int i = 0; i < n/2; ++i) {
    int t;
    cin >> t;
    s.push(t);
  }

  int m;
  bool equal = true;
  if (n%2 != 0) cin >> m; // ignore middle term, if n is odd
  while (equal and cin >> m) { // as declared by the statement, the input are only n integers
    equal = (m == s.top());
    s.pop();
  }

  if (equal) cout << "SI" << endl;
  else cout << "NO" << endl;
}
