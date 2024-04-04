// Input: natural 1<=n<=11
// Output: write a square ((2^n)-1)*((2^n)-1)
// Obs: the pattern for n>1 is the pattern for n-1 repeated four times
#include <iostream>
#include <vector>
#include <cmath> // for pow()
using namespace std;

typedef vector< vector<char> > Matrix;

void print_matrix(const Matrix &m) {
  for (int i = 0; i < m.size(); ++i) 
  {
    for (int j = 0; j < m[0].size(); ++j) cout << m[i][j];
    cout << endl;
  }
}

Matrix recursive_square(Matrix &m, int n, int i, int j)
{
  if (n == 1) m[i][j] = '#';
  else
  {
    int ns = pow(2, n) - 1;
    recursive_square(m, n - 1, i + 0, j + 0);
    recursive_square(m, n - 1, i + 0, j + ns/2 + 1);
    recursive_square(m, n - 1, i + ns/2 + 1, j + 0);
    recursive_square(m, n - 1, i + ns/2 + 1, j + ns/2 + 1);
    
    for (int k = 1; k < ns - 1; ++k) m[i + k][j + ns/2] = '.';
    for (int k = 1; k < ns - 1; ++k) m[i + ns/2][j + k] = '.';
    // literalmente 1h, solo por confundir una i con una j. :0

    m[i + 0][j + ns/2] = '#';
    m[i + ns/2][j + 0] = '#';
    m[i + ns - 1][j + ns/2] = '#';
    m[i + ns/2][j + ns - 1] = '#';
  }
  return m;
}

int main()
{
  int n;
  cin >> n;
  
  const int s = pow(2, n) - 1;
  Matrix m(s, vector<char> (s));
  m = recursive_square(m, n, 0, 0);
 
  print_matrix(m);
}

// EE: time limit exceeded (bomba)
