// Input: First a list of all the players, ending with a dot. Then an integer
//  which indicates the number of programmed activities, followed by as many as
//  lists as programmed activities are showing its players, all ending with a dot.
// Output: the text "Totes les activitats: " followed by the list of players,
//  and the text "Cap activitat: " followed by the list of players.

#include <iostream>
#include <set>
using namespace std;

int main() {
  set<string> allacts;
  set<string> noacts;
  {
    string player;
    while (cin >> player and player != ".") {
      allacts.insert(player);
      noacts.insert(player);
    }
  }

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    set<string> current_act = allacts; // eficiencia (asign. de sets) ?
    string player;
    while (cin >> player and player != ".") {
      current_act.erase(player);
      noacts.erase(player);
    }
    for (set<string>::iterator it = current_act.begin(); it != current_act.end(); ++it) {
      allacts.erase(*it);
    }
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
