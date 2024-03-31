#include "evaluate.hh" 

bool evaluate(const BinTree<string> t)
{
  // els casos base són: t.value() és true o és false
  if (t.value() == "true") return true;
  else if (t.value() == "false") return false;

  if (t.value() == "not")
    return not evaluate(t.left());
  else if (t.value() == "and")
    return evaluate(t.left()) and evaluate(t.right());
  else //if (t.value() == "or")
    return evaluate(t.left()) or evaluate(t.right());
}
