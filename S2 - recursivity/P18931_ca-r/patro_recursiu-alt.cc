// REVISE
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<string> calcula(int n) {
  if (n == 1) return vector<string> (1, "#");
  else
  {
    vector<string> w = calcula(n - 1);
    vector<string> v;
    v.push_back(w[0] + "#" + w[0]);
    for (int i = 1; i < w.size(); ++i) v.push_back(w[i] + "." + w[i]);
    v.push_back("#" + string(pow(2, n) - 3, '.') + "#");
    for (int i = 0; i < w.size() - 1; ++i) v.push_back(w[i] + "." + w[i]);
    v.push_back(w[w.size() - 1] + "#" + w[w.size() - 1]);
    return v;
  }
}

int main()
{
  int n;
  cin >> n;
  vector<string> v;
  v = calcula(n);
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }
}
