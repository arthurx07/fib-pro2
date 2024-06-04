#include <iostream>
using namespace std;

int evaluate() {
  char c;
  cin >> c;
  if ('0' <= c and c <= '9') return int(c) - int('0'); // if char c is a number
    // int() - int () -> conversión explícita
    // c - '0' -> conversión implicita
    // són esencialmente lo mismo, pero uno se muestra más explícito
  else { // read five components: ( arg1 op arg2 )
    char par, op;
    // cin >> par;
    int arg1 = evaluate();
    // HI: arg1 is the result of evaluating the first arithmetical
    // expression which is after the first parenthesis
    cin >> op;
    int arg2 = evaluate();
    // HI: arg2 is the result of evaluating the first arithmetical
    // expression which is after the operator.
    cin >> par; // stops at second parenthesis
    if (op == '+') return arg1 + arg2;
    else if (op == '-') return arg1 - arg2;
    else return arg1 * arg2;
  }
}

int main() {
  cout << evaluate() << endl;
}
