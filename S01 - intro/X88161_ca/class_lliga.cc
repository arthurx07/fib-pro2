// Input: Un enter N ≥ 2 seguit dels parells de la matriu m (escrits sense parèntesis ni comes) des 
//  de la primera fila fins la N-èsima i, dins de cada fila, des de la primera columna fins la N-èsima.

// Output: N línies corresponents als equips on cada línia conté el número de l’equip, el nombre 
//  total de punts, els gols marcats i els rebuts. Les línies han d’aparèixer per ordre decreixent 
//  dels punts; quan hi ha empat, per ordre decreixent dels gols marcats menys els rebuts i, si 
//  persisteix l’empat, per ordre creixent del número d’equip.

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef vector< vector<int> > Matrix;

struct Team {
  // numbero_equip, punts_totals, gols_marcats, gols_rebuts
  int number, points, gf, ga; // goal for, goal against
};

bool cmp(const Team& a, const Team& b) {
  if (a.points == b.points) {
    int agd = a.gf - a.ga;
    int bgd = b.gf - b.ga;
    if (agd == bgd) return a.number < b.number;
    return agd > bgd;
  }
  return a.points > b.points;
}

int main() {
  int N;
  cin >> N;

  vector<Team> v(N);
  for (int i = 0; i < N; ++i) {
    v[i].number = i + 1; // to just do this assignment once
    for (int j = 0; j < N; ++j) {
      int goals_i, goals_j;
      cin >> goals_i >> goals_j;
      if (i != j) {
        if (goals_i > goals_j) v[i].points += 3;
        else if (goals_i < goals_j) v[j].points += 3;
        else {
          ++v[i].points;
          ++v[j].points;
        }

        v[i].gf += goals_i;
        v[j].gf += goals_j;

        v[i].ga += goals_j;
        v[j].ga += goals_i;
      }
    }
  }

  sort(v.begin(), v.end(), cmp);
  for (int i = 0; i < N; ++i) {
    cout << v[i].number << ' ' << v[i].points << ' ' << v[i].gf << ' ';
    cout << v[i].ga << endl;
  }
}
