#include "evaluate.hh"
#include "utils.hh"

int evaluate(map<string,int> &variable2value, BinTree<string> t)
{
  // isVariable, isNumber
  if (t.empty()) return 0;
  else if (isVariable(t.value())) return variable2value[t.value()];
  else if (isNumber(t.value())) return mystoi(t.value());
  else {
    if (t.value() == "+")
      return evaluate(variable2value, t.left()) + evaluate(variable2value, t.right());
    else if (t.value() == "-")
      return evaluate(variable2value, t.left()) - evaluate(variable2value, t.right());
    else // if (t.value() == "*")
      return evaluate(variable2value, t.left()) * evaluate(variable2value, t.right());
  }
}
