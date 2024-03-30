// Input: First a list of all the players, ending with a dot. Then an integer
//  which indicates the number of programmed activities, followed by as many as
//  lists as programmed activities are showing its players, all ending with a dot.
// Output: the text "Totes les activitats: " followed by the list of players,
//  and the text "Cap activitat: " followed by the list of players.

#include <iostream>
#include <set>
using namespace std;

int main() {
  set<string> players;
  {
    string player;
    while (cin >> player and player != ".") players.insert(players.end(), player);
  }

  set<string> allacts = players;
  set<string> noacts = players;

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string player;
    set<string> newallacts;
    while (cin >> player and player != ".") {
      if (allacts.count(player)) newallacts.insert(player);
      noacts.erase(player);
    }
    allacts = newallacts; // soy un puto crack :y
  }

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
