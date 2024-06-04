#include "BinTreeIOParInt.hh"

// Pre: a és buit; el canal estandar d’entrada conté un nombre
// parell d’enters, que representa un arbre binari en preordre,
// on el parell 0 0 representa un arbre buit
// Post: a conté l’arbre que hi havia al canal estandar d’entrada
void read_bintree_parint(BinTree<ParInt>& a) {
  ParInt value;
  if (value.llegir()) {
    BinTree<ParInt> left, right;
    read_bintree_parint(left);
    read_bintree_parint(right);

    a = BinTree<ParInt>(value, left, right);
  }
}

// Pre: a = A
// Post: s’han escrit al canal estandar de sortida els elements
// d’a recorrreguts en inordre, a = A
void write_bintree_parint(const BinTree<ParInt>& a) {
  if (not a.empty()) {
    write_bintree_parint(a.right());
    write_bintree_parint(a.left());
    a.value().escriure();
  }
}
