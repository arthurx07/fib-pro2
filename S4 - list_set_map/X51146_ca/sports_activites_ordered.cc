// Input: First a list of all the players, ending with a dot. Then an integer
//  which indicates the number of programmed activities, followed by as many as
//  lists as programmed activities are showing its players, all ending with a dot.
// Output: the text "Totes les activitats: " followed by the list of players,
//  and the text "Cap activitat: " followed by the list of players.

#include <iostream>
#include <set>
using namespace std;

int main() {
  set<string> noacts;
  {
    string player;
    while (cin >> player and player != ".") {
      noacts.insert(player);
    }
  }

  int n;
  cin >> n;

  set<string> allacts;
  // first match
  {
    string player;
    set<string>::iterator it = noacts.begin();
    while (cin >> player and player != ".")
    {
      allacts.insert(allacts.end(), player);
      while (it != noacts.end() and *it <= player)
      {
        if (*it < player) ++it; // *it remains in noacts
        else it = noacts.erase(it); // if (*it == player) erase player from noacts and go to next
      }
    }
    // this approach is efficient: we only need to iterate over the set once
  }

  // remaining matches
  for (int i = 1; i < n; ++i)
  {
    set<string>::iterator it1 = noacts.begin();
    set<string>::iterator it2 = allacts.begin();
    string player;
    while (cin >> player and player != ".")
    {
      while (it1 != noacts.end() and *it1 <= player)
      {
        if (*it1 < player) ++it1; // *it1 remains in noacts
        else it1 = noacts.erase(it1); // if (*it1 == player) erase player from noacts and go to next
      }
      while (it2 != allacts.end() and *it2 <= player)
      {
        if (*it2 < player) it2 = allacts.erase(it2); // erase all players between it2...player from allacts and go to next
        else ++it2; // (*it2 == player) and *it2 remains in allacts
      }
    }
    while (it2 != allacts.end()) it2 = allacts.erase(it2); // erase all players between it2...end()
  }

  // escritura
  cout << "Totes les activitats:";
  for (set<string>::iterator it = allacts.begin(); it != allacts.end(); ++it) {
    cout << ' ' << *it;
  }
  cout << endl;

  cout << "Cap activitat:";
  for (set<string>::iterator it = noacts.begin(); it != noacts.end(); ++it) {
    cout << ' ' << *it;
  }
  cout << endl;
}
