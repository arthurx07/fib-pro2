#include "removeAll.hh"

BT removeAll(const string &extension, const BT &t)
{
  // add ".", to not remove directories which have the same name as the extension
  if (t.empty() or t.value().find("." + extension) != string::npos) return BT();
  return BT(t.value(),
            removeAll(extension, t.left()),
            removeAll(extension, t.right()));
}


// npos:
// npos is a static member constant value with the greatest possible value for an element of type size_t.
// This value, when used as the value for a len (or sublen) parameter in string's member functions, means "until the end of the string".
// As a return value, it is usually used to indicate no matches.
// This constant is defined with a value of -1, which because size_t is an unsigned integral type, it is the largest possible representable value for this type.
