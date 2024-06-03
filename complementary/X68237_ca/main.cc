#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#include "BinTree.hh"

struct IntItem
{
  int value = 0;
  int sum = 0;
  int size = 0;
};

ostream& operator<<(ostream& os, const IntItem& ii)
{
  os << ii.value;
  return os;
}

int getIdVar(string s)
{
 return atoi(s.substr(1).c_str());
}

// int size(BinTree<int> t) //
// {
//   if (t.empty()) return 0;
//   return 1 + size(t.left()) + size(t.right());
// }
//
// int sum(BinTree<int> t) // 
// {
//   if (t.empty()) return 0;
//   return t.value() + sum(t.left()) + sum(t.right());
// }

int main()
{
 string s1, s2, s3, s4, s5, s6, s7;
 int numvars;
 cin >> s1 >> numvars >> s2; // numvars= n ;
 vector<BinTree<IntItem>> v (numvars); //

 while (cin >> s1 >> s2) {
  if (s1[0] == 't') {
   int idvar = getIdVar(s1);
   if (s2 == "=BinTree(") { // tx =BinTree(
    int value;
    cin >> value >> s3 >> s4 >> s5 >> s6 >> s7; // n , ty , tz );
    int idvar1 = getIdVar(s4);
    int idvar2 = getIdVar(s6);

    IntItem left; //
    if (not v[idvar1].empty()) left = v[idvar1].value(); //
    IntItem right; //
    if (not v[idvar2].empty()) right = v[idvar2].value(); //

    IntItem item; //
    item.value = value; //
    item.sum = left.sum + right.sum + value; //
    item.size = left.size + right.size + 1; //
    v[idvar] = BinTree<IntItem>(item, v[idvar1], v[idvar2]); //

   } else if (s2 == "=") { // tx = ty
    cin >> s3 >> s4;
    int idvar1 = getIdVar(s3);
    if (s4 == ".left();") {
     v[idvar] = v[idvar1].left(); //
    } else {
     v[idvar] = v[idvar1].right(); //
    }
   }
  } else if (s1 == "cout<<") {
   int idvar = getIdVar(s2);
   cin >> s3;
   v[idvar].setOutputFormat(BinTree<int>::INLINEFORMAT); //
   cout << v[idvar] << endl; //
  } else if (s1 == "cout<<size(") {
   int idvar = getIdVar(s2);
   cin >> s3;
   // cout << size(v[idvar]) << endl; //
   if (not v[idvar].empty()) cout << v[idvar].value().size << endl; //
   else cout << 0 << endl; //
  } else if (s1 == "cout<<sum(") {
   int idvar = getIdVar(s2);
   cin >> s3;
   // cout << sum(v[idvar]) << endl; //
   if (not v[idvar].empty()) cout << v[idvar].value().sum << endl; //
   else cout << 0 << endl; //
  }
 }
}
