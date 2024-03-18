// Preliminars: seqüència ben parentitzada és:
//  - tot prefix de s té més o igual parèntesis d'obrir que de tancar
//  - s en total té la mateixa quantitat de parèntesis d'obrir que de tancar
//  Entrada: nombre arbitrari de casos, un per línia, de strings ben parentitzats
//  Sortida: mateix string, però afegint darrere de cada parèntesis un número:
//    cada parèntesi d'obrir està identificat començant per l'1 i creixent d'un
//    en un, i els seus corresponents parèntesis de tancar estan identificat
//    pel mateix número
#include <iostream>
#include <stack>
using namespace std;

int main()
{
  string str;
  while (cin >> str)
  {
    int idn = 1;
    stack<int> s;
    // stack keeps track of the latest opening parenthesis identifier (which is 
    //  the same as saying: the next closest parenthesis identifier), while idn
    //  keeps track of the next opening parenthesis identifier
    for (int i = 0; i < str.length(); ++i)
    {
      if (str[i] == '(') {
        s.push(idn);
        cout << str[i] << s.top(); // s.top() == idn
        ++idn;
      } else {
        cout << str[i] << s.top(); // s.top() != idn
        s.pop();
      }
    }
    cout << endl;
  }
}
