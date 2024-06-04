// Input: list of pairs (code, word). If code is 'a', increments the frequency
//  of the word; if code is 'e', decrements the frequency of the word; if code
//  is 'f', prints the frequency of the word.
// Output: when code is 'f', print the frequency of the word.

#include <iostream>
#include <map>
using namespace std;

int main() {
  char c;
  string s;
  map<string, int> m;
  map<string, int>::iterator it;
  while (cin >> c >> s) {
    if (c == 'a') ++m[s];
    else if (c == 'e' and m[s] != 0) --m[s];
    else if (c == 'f') cout << m[s] << endl;
  }
}
