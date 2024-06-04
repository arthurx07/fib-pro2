// We want an operation to obtain the intersection of two ordered lists of 
// integers, without visiting innecessary elements and using auxiliar structures.
// Observation, use the following specification: 
//  void inter(list<int>& uno, const list<int>& dos )
//  /* Pre: uno = U */
//  /* Post: uno pasa a ser la interseccion de U y dos */

#include <iostream>
#include <list>
using namespace std;

/* Pre: uno = U */
/* Post: uno pasa a ser la interseccion de U y dos */
void inter(list<int>& uno, const list<int>& dos)
{
  list<int>::iterator it1 = uno.begin();
  list<int>::const_iterator it2 = dos.begin();

  while (it1 != uno.end()) {
    if (it2 == dos.end() or *it1 < *it2)
      it1 = uno.erase(it1); // deletes + assigns it1 to the next
    else if (*it1 == *it2) {
      ++it1;
      ++it2;
    } else if (it2 != dos.end()) ++it2; // if *it2 > *it1
  }
}

/* Pre: uno = U */
/* Post: tres pasa a ser la interseccion de U y dos */
/* Alternative version
void inter(const list<int>& uno, const list<int>& dos, list<int>& tres)
{
  list<int>::const_iterator it1 = uno.begin();
  list<int>::const_iterator it2 = dos.begin();

  while (it1 != uno.end()) {
    if (it2 == dos.end() or *it1 < *it2) ++it1;
    else if (*it1 == *it2) {
      tres.insert(tres.end(), *it1);
      ++it1;
      ++it2;
    }
    else if (it2 != dos.end()) ++it2; // if *it2 > *it1
  }
}
*/

// Example of main:
int main() {
  list<int> l1;
  list<int> l2;

  int n;
  while (cin >> n and n != 0) {
    l1.insert(l1.end(), n);
  }

  int m;
  while (cin >> m and m != 0) {
    l2.insert(l2.end(), m);
  }

  inter(l1, l2);

  for (list<int>::iterator it = l1.begin(); it != l1.end(); ++it) {
    cout << *it << endl;
  }
}
