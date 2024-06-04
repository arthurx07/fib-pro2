#include "evaluate.hh"
#include "utils.hh"
using namespace std;

int evaluate(BinTree<string> t) {
  if (t.empty()) return 0;

  else if (isNumber(t.value())) return mystoi(t.value()); // isNumber() and mystoi() are from utils.hh

  else {
    int eval_left = evaluate(t.left());
    int eval_right = evaluate(t.right());

    if (t.value() == "+")
      return eval_left + eval_right;
    else if (t.value() == "-")
      return eval_left - eval_right;
    else // if (t.value() == "*")
      return eval_left*eval_right;
  }
}
