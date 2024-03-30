#include <iostream>
#include "ParInt.hh"
#include "BinTree.hh"
#include "BinTreeIOParInt.hh"

using namespace std;

int search_bintree_parint(BinTree<ParInt> t, int& prof, int n)
{
  if (t.empty()) return -1;
  else if (t.value().primer() == n) return t.value().segon();
  else {
    int left_search = search_bintree_parint(t.left(), prof, n);
    if (left_search != -1) {
      ++prof;
      return left_search;
    }
    else {
      int right_search = search_bintree_parint(t.right(), prof, n);
      if (right_search != -1) ++prof;
      return right_search;
    }
  }
}

int main()
{
  BinTree<ParInt> t;
  read_bintree_parint(t);

  int n;
  while (cin >> n) {
    int profunditat = 0;
    int parell = search_bintree_parint(t, profunditat, n);
    if (parell != -1) cout << n << ' ' << parell << ' ' << profunditat << endl;
    else cout << parell << endl;
  }
}
