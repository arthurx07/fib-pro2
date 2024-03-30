#include "evaluate.hh"

void swap(char& a, char& b)
{
  char c = a;
  a = b;
  b = c;
}

string evaluate(BinTree<string> t)
{
  if (t.value() == "Reverse") {
    string s = evaluate(t.left());
    for (int i = 0; i < s.length()/2; ++i)
      swap(s[i], s[s.length() - 1 -i]);
    return s;
  }
  else if (t.value() == "Concat") 
    return evaluate(t.left()) + evaluate(t.right());

  return t.value();
}
