#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
// Add more includes if you wish ...

using namespace std;

#include "BinTree.hh"

// This exercise could also be done with a pair<char, int>;
struct Item {
    char value;
    int size = 0;
};

typedef BinTree<Item> BT;


int getIdVar(string s)
{
    return atoi(s.substr(1).c_str());
}

// Add auxiliary functions if you wish ...

char getValueAtInorderPosition(BT t, int pos)
{
    if (t.empty()) return char(' '); // arbitrary character

   int current_position = t.value().size;
   if (not t.right().empty()) current_position -= t.right().value().size;

   if (pos < current_position) return getValueAtInorderPosition(t.left(), pos);
   else if (pos > current_position) return getValueAtInorderPosition(t.right(), pos - current_position);
   else return t.value().value;
}

ostream& operator<<(ostream& os, Item it)
{
    os << it.value;
    return os;
}

int main()
{
    string s1, s2, s3, s4, s5, s6, s7;
    int numvars;
    cin >> s1 >> numvars >> s2;
    vector<BT> t(numvars);
    while (cin >> s1 >> s2) {
        if (s1[0] == 't') {
            int idvar = getIdVar(s1);
            if (s2 == "=BinTree(") {
                Item it = Item();
                cin >> it.value >> s3 >> s4 >> s5 >> s6 >> s7;
                int idvar1 = getIdVar(s4);
                int idvar2 = getIdVar(s6);

                it.size = 1;
                if (not t[idvar1].empty()) it.size += t[idvar1].value().size;
                if (not t[idvar2].empty()) it.size += t[idvar2].value().size;
                t[idvar] = BT(it, t[idvar1], t[idvar2]);
            } else if (s2 == "=") {
                cin >> s3 >> s4;
                int idvar1 = getIdVar(s3);
                if (s4 == ".left();") {
                    t[idvar] = t[idvar1].left();
                } else {
                    t[idvar] = t[idvar1].right();
                }
            }
        } else if (s1 == "cout<<") {
            int idvar = getIdVar(s2);
            cin >> s3;
            t[idvar].setOutputFormat(BinTree<int>::INLINEFORMAT);
            cout << t[idvar] << endl;
        } else if (s1 == "cout<<valueAtInorderPosition(") {
            int idvar = getIdVar(s2);
            int pos;
            cin >> s3 >> pos >> s4;
            cout << getValueAtInorderPosition(t[idvar], pos) << endl;
        } else {
            cout << "Error: unexpected command '" << s1 << "'" << endl;
            exit(1);
        }
    }
}