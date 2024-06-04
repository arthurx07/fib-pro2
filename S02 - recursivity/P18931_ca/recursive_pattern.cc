// Input: natural 1<=n<=11
// Output: write a square ((2^n)-1)*((2^n)-1)
// Obs: the pattern for n>1 is the pattern for n-1 repeated four times
#include <iostream>
#include <vector>
#include <cmath> // for pow()
using namespace std;

vector<string> recursive_square(int n)
{
  // base case
  if (n == 1) return vector<string> (1, "#"); // vector of strings of size 1: "#"

  // induction
  int size = pow(2, n) - 1; // size x size matrix of chars
  vector<string> v(size);
  vector<string> w = recursive_square(n-1); // recursive call;

  int mid = pow(2, n - 1) - 1; // middle position
  // fill interior of matrix with squares (n-1):
  for (int i = 1; i < w.size(); ++i) {
    v[i] = (w[i] + "." + w[i]); // i, the contrary of below
    v[mid + i] = (w[i-1] + "." + w[i-1]);
      // i-1, as starting from 1 and we want the first line "###" and not
      // the last line "###"
  }

  v[0] = string(size, '#'); // v first line, full of #
  v[mid] = "#" + string(size - 2, '.') + "#"; // v middle line, #.#
  v[size - 1] = string(size, '#'); // v last line, full of #
  return v;
}

int main()
{
  int n;
  cin >> n;
  
  vector<string> v = recursive_square(n);
 
  // print matrix
  for (int i = 0; i < v.size(); ++i)
    cout << v[i] << endl;
}
