#include <iostream>
#include <string>

using namespace std;

// Pre: 0 <= i <= j < s.size(), identifiquen el substring no buit s[i..j]
// Post: the substring s[i..j] has been inverted. The rest of s has not changed.
void reverseSubstring(string &s, int i, int j) {
  // if (i == j) nothing needs to be done
  // given the Pre, i > j will never happen
  if (i < j) {
    // interchange the values of s[i] and s[j]
    char aux = s[i];
    s[i] = s[j];
    s[j] = aux;
    reverseSubstring(s, ++i, --j); // s[i+1..j-1] is inverted
  }
}

int main()  {
    string s;
    int i, j;
    while (cin >> s >> i >> j) {
        reverseSubstring(s, i, j);
        cout << s << endl;
    }
}
