// Input: pair list of (code, word). If code is a, increment the frequency of the word
//  that follows. If code is f, output the current frequency of the word.
// Output: frequency of the word, when code is f.

#include <iostream>
#include <map>
using namespace std;

int main() {
  char c;
  string s;
  map<string, int> m;
  while (cin >> c >> s) {
    if (c == 'a') ++m[s];
    else if (c == 'f') cout << m[s] << endl;
  }
}
