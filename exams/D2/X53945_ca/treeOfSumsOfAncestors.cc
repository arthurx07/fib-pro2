#include "treeOfSumsOfAncestors.hh"

typedef BinTree<int> BT;

// Pre:
// Post: Retorna un arbre d'enters t' amb la mateixa estructura que t.
//       Per a cada posició p, el valor guardat a t' a posició p és igual a la suma
//       dels valors guardats a t a posició p i a posicions ancestres de p.
BinTree<int> treeOfSumsOfAncestors(const BinTree<int> t)
{
  if (t.empty()) return BT();

  BT left;
  if (not t.left().empty()) {
    left = BT(t.value() + t.left().value());
    if (not t.left().left().empty()) left = BT(left.value(), t.left().left(), left.right());
    if (not t.left().right().empty()) left = BT(left.value(), left.left(), t.left().right());
  }

  BT right;
  if (not t.right().empty()) {
    right = BT(t.value() + t.right().value());
    if (not t.right().left().empty()) right = BT(right.value(), t.right().left(), right.right());
    if (not t.right().right().empty()) right = BT(right.value(), right.left(), t.right().right());
  }

  BT new_left = treeOfSumsOfAncestors(left);
  BT new_right = treeOfSumsOfAncestors(right);
  return BT(t.value(), new_left, new_right);
}

// alternative approach:
//  use auxiliary function aux(BinTree<int> t, int sum)
//    sum += t.value();
//    left = aux(t.left(), sum);
//    right = aux(t.right(), sum);
//    return BT(sum, left, right);

// alternative approach: with list ¿?
