#include "numNegative.hh"
#include "utils.hh"

int evaluate(BinTree<string> t, int& s)
{
  if (t.empty()) return 0;
  else if (isNumber(t.value())) {
    if (mystoi(t.value()) < 0) ++s;
    return mystoi(t.value());
  }
  else {
    int left = evaluate(t.left(), s);
    int right = evaluate(t.right(), s);
    int eval = 0;
    if (t.value() == "*") eval = left*right;
    else if (t.value() == "+") eval = left+right;
    else if (t.value() == "-") eval = left-right;

    if (eval < 0) ++s;
    return eval;
  }
}

int numNegative(BinTree<string> t)
{
  int sum = 0;
  evaluate(t, sum);
  return sum;
}

// is it possible to do without auxiliary function?
