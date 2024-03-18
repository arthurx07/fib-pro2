// Input: natura n in a different line for each case
// Output: look at the examples. each case is separated by a 10 digit hyphen line
// Obs: implement a recursive function which receives n and returns a vector of 
//  strings with the correct output. Write this output outside of the recursive
//  function
#include <iostream>
#include <vector>
#include <cmath> // ?
using namespace std;

vector<string> whitespaces(const vector<string> &v, int n)
{
  int m = v.size();
  vector<string> copy(m);
  // 2^(n-1) espacios delante
  for (int i = 0; i < m; ++i) copy[i] = string(pow(2, n - 1), ' ') + v[i];
  return copy;
}

vector<string> parse_vector(int n)
{
  if (n == 0)
  {
    vector<string> v(1);
    v[0] = "*";
    return v;
  }

  else
  {
    vector<string> prev = parse_vector(n - 1); // do for n-1 (size 2^(n-1))

    int m = prev.size();
    vector<string> v(2*m);
    vector<string> prev_whites = whitespaces(prev, n);

    if (n%2 == 0)
    {
      for (int i = 0; i < m; ++i) v[i] = prev[i];
      for (int i = m; i < 2*m; ++i) v[i] = prev_whites[i-m];
    }
    else if (n%2 == 1)
    {
      for (int i = 0; i < m; ++i) v[i] = prev_whites[i];
      for (int i = m; i < 2*m; ++i) v[i] = prev[i-m];
    }
    return v;
  }
}

void print_output(const vector<string> &v)
{
  for (int i = 0; i < v.size(); ++i) cout << v[i] << endl;
}

int main()
{
  int n;
  while (cin >> n)
  {
    print_output(parse_vector(n));
    cout << string(10, '-') << endl;
  }
}
