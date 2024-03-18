// Input: different cases. each case is a natural n in separate lines.
// Output: watch for the examples
// Obs: implement a recursive function which receives n and returns a vector of
//  strings with the desired output. Write the output function outside the recursive 
//  function.
#include <iostream>
#include <vector>
using namespace std;

void print_vector(const vector<string> &v)
{
  for (int i = 0; i < v.size(); ++i) cout << v[i] << endl;
}

vector<string> trees(vector<string> &v, int n)
{
  if (n == 0 or n == 1) v[0] = "*";
  else {
    .
  }
}

int main() {
  int n;
  while (cin >> n)
  {
    vector<string> v(?);
    v = trees(v, n);

    print_vector(v);
  }
}
