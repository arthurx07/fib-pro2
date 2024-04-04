// Input: different cases. each case is a natural n in separate lines.
// Output: watch for the examples
// Obs: implement a recursive function which receives n and returns a vector of
//  strings with the desired output. Write the output function outside the recursive 
//  function.
#include <iostream>
#include <vector>
using namespace std;

vector<string> fibonacci_tree(int n)
{
  // base case
  if (n == 0 or n == 1) return vector<string> (1, "*");

  // induction
  vector<string> v = fibonacci_tree(n-2);
  vector<string> w = fibonacci_tree(n-1);
  vector<string> u(v.size() + w.size() + 1);

  int index = 0;
  bool found = false;
  for (int i = 0; i < v.size(); ++i) {
    if (not found and n != 2 and n != 3) {
      u[index] = "  " + v[i];
      found = (v[i+1][0] == '-');
    }
    else u[index] = " |" + v[i]; // after |-
    ++index;
  }

  u[index] = "-|"; // middle position

  found = false;
  for (int i = 0; i < w.size(); ++i) {
    ++index;
    if (not found) {
      u[index] = " |" + w[i];
      found = (w[i][0] == '-'); // before |-
    }
    else u[index] = "  " + w[i];
  }

  return u;
}

int main()
{
  int n;
  while (cin >> n)
  {
    vector<string> vec = fibonacci_tree(n);
    for (int i = 0; i < vec.size(); ++i)
      cout << vec[i] << endl;
    cout << endl;
  }
}
