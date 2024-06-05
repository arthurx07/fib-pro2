#include <iostream>
#include <string>

using namespace std;

#include "BinTree.hh"

string evaluate_prefix_aux(BinTree<string> t, int n, bool reverse)
{
  if (t.empty()) return "";

  if (t.value() == "Reverse")
    return evaluate_prefix_aux(t.left(), n, not reverse);

  if (t.value() == "Concat")
  {
    string word;
    if (reverse)
    {
      word = evaluate_prefix_aux(t.right(), n, reverse);

      if (word.length() < n) {
        word += evaluate_prefix_aux(t.left(), n - word.length(), reverse);
      }
    }
    else
    {
      word = evaluate_prefix_aux(t.left(), n, reverse);

      if (word.length() < n) {
        word += evaluate_prefix_aux(t.right(), n - word.length(), reverse);
      }
    }
    return string(word, 0, n);
  }

  if (reverse)
  {
    string word = t.value();
    for (int i = 0; i < word.length()/2; ++i)
      swap(word[i], word[word.length()-1-i]);
    return string(word, 0, n);
  }
  else
    return string(t.value(), 0, n);
}

// Pre:  t és un arbre no buit que representa una expressió correcta
//       sobre strings de lletres minúscules i els operadors Concat, Reverse.
//       n>=0
// Post: Retorna el prefix de longitut n de l'avaluació de l'expressió representada per t.
//       En cas que n sigui més gran que la longitut d'aquesta avaluació,
//       llavors retorna només l'avaluació, cap caràcter més.
string evaluatePrefix(BinTree<string> t, int n)
{
  if (n > 0) return evaluate_prefix_aux(t, n, false);
  else return "";
}
