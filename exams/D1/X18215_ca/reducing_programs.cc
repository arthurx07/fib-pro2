#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

bool applyOneRule(vector<char> &v, char follow)
{
  int n = v.size();
  if (v[n-1] == 'v' and (follow != '=')) { // v -> E (si no ve seguida de =)
    v[n-1] = 'E';
    return true;
  } 
  else if (v[n-1] == 'n') { // n -> E
    v[n-1] = 'E';
    return true;
  }
  else if (n >= 3 and (v[n-3] == 'E' and v[n-2] == '*' and v[n-1] == 'E')) { // E*E -> E
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.push_back('E');
    return true;
  }
  else if (n >= 3 and v[n-3] == 'E' and v[n-2] == '+' and v[n-1] == 'E' and (follow != '*')) { // E+E -> E (si no ve seguida de *)
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.push_back('E');
    return true;
  }
  else if (n >= 3 and v[n-3] == 'E' and v[n-2] == '<' and v[n-1] == 'E' and (follow != '*' and follow != '+')) { // E<E -> E (si no ve seguida de * o +)
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.push_back('E');
    return true;
  }
  else if (n >= 4 and v[n-4] == 'v' and v[n-3] == '=' and v[n-2] == 'E' and v[n-1] == ';') { // v=E; -> I
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.push_back('I');
    return true;
  }
  else if (n >= 3 and // (E) -> E (si no ve precedida de i o w)
           v[n-3] == '(' and v[n-2] == 'E' and v[n-1] == ')' and
           (n == 3 or (v[n-4] != 'i' and v[n-4] != 'w'))) {
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.push_back('E');
    return true;
  } 
  else if (n >= 5 and v[n-5] == 'i' and v[n-4] == '(' and v[n-3] == 'E' and v[n-2] == ')'
          and v[n-1] == 'I' and (follow != 'e')) { // i(E)I -> I (si no ve seguida de e)
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.push_back('I');
    return true;
  }
  else if (n >= 7 and v[n-7] == 'i' and v[n-6] == '(' and v[n-5] == 'E' and v[n-4] == ')'
          and v[n-3] == 'I' and v[n-2] == 'e' and v[n-1] == 'I') { // i(E)IeI -> I
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.push_back('I');
    return true;
  }
  else if (n >= 5 and v[n-5] == 'w' and v[n-4] == '(' and v[n-3] == 'E' and v[n-2] == ')'
          and v[n-1] == 'I') { // w(E)I -> I
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.push_back('I');
    return true;
  }
  else if (n >= 2 and v[n-2] == 'L' and v[n-1] == 'I') { // LI -> L
    v.pop_back(); // xd
    return true;
  }
  else if (v[n-1] == 'I' and (n == 1 or (v[n-2] != ')' and v[n-2] != 'L'))) { // I -> L (si no ve precedida de ) o L)
    v.pop_back();
    v.push_back('L');
    return true;
  }
  else if (n >= 3 and v[n-3] == '{' and v[n-2] == 'L' and v[n-1] == '}') { // {L} -> I
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.push_back('I');
    return true;
  }
  else if (n == 1 and v[0] == 'L' and follow == ' ') { // L -> P (només si L és l'únic caràcter restant)
    // si follow = ' ', vol dir que no hi ha cap caràcter que el segueix a l'string s (veure l.125)
    v.pop_back();
    v.push_back('P');
    return true;
  }
  return false;
}

int main()
{
  string s;
  while (cin >> s) {
    vector<char> v;
    // manté la part ja tractada de s (se li han aplicat totes les regles)
    // a cada pas, afegim a v un nou paràmetre d'entrada i la funció applyOneRul
    // intenta aplicar una regla sobre v (només cal final, la resta ja està normal).
    // paràmetre follow per saber el següent caràcter, per comprovar restriccions
    for (int i = 0; i < int(s.size()); i++) {
      v.push_back(s[i]);
      char follow = ' '; // per a que pugui entrar a applyOneRule() [' ' no afecta al correcte funcionament]
      if (i+1 < int(s.size()))
        follow = s[i+1];
      while (applyOneRule(v, follow)); // aplicar totes les regles possible sobre v
    }
    string sol;
    for (int i = 0; i < int(v.size()); i++)
      sol += v[i];
    cout << sol << endl;
  }
}

// Observation: there could be less 'else if' as most of them do the same things
//  but under different conditions. Won't change.
