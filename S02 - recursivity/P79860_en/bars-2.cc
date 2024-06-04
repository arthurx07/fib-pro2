// Input: natural number n > 0
// Output: Print 2^n - 1 lines, following the pattern given in the examples
#include <iostream>
using namespace std;

void print_bars(int n)
{
  if (n == 1) cout << '*' << endl;
  else {
    for (int i = 0; i < n; ++i) cout << '*';
    cout << endl;
    print_bars(n-1);
    print_bars(n-1);
  }
}

int main()
{
  int n;
  cin >> n;

  print_bars(n);
}

// literalmente he tardado 2 minutos
