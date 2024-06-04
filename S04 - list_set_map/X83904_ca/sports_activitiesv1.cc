// Input: First a list of all the players, ending with a dot. Then an integer
//  which indicates the number of programmed activities, followed by as many as
//  lists as programmed activities are showing its players, all ending with a dot.
// Output: the text "Totes les activitats: " followed by the list of players,
//  and the text "Cap activitat: " followed by the list of players.

#include <iostream>
#include <set>
using namespace std;

int main() {
  set<string> player_list;
  {
    string player;
    while (cin >> player and player != ".") player_list.insert(player_list.end(), player);
  }

  int n;
  cin >> n;

  set< set<string> > activity_list;
  for (int i = 0; i < n; ++i) {
    string player;
    set<string> players;
    while (cin >> player and player != ".") players.insert(players.end(), player);
    activity_list.insert(activity_list.end(), players);
  }

  // Iterate over players
  for (set<string>::iterator pl = player_list.begin(); pl != player_list.end(); ++pl) {

    // ?
    set<string>::iterator it;
    set< set<string> >:: iterator new_it;
    for(new_it=activity_list.begin();new_it!=activity_list.end();new_it++) {
      for(it = new_it->begin(); it!=new_it->end(); ++it)
    }

  }
}
