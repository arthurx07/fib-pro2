// Input: Dos enters N ≥ 2 i 1≤ M ≤ 2*(N−1) seguits de (N/2)*M resultats de partits.
// Output: N línies corresponents als equips on cada línia conté el número de 
//  l’equip, el nombre total de punts, els gols marcats i els rebuts. Les línies
//  han d’aparèixer per ordre decreixent dels punts; quan hi ha empat, per ordre
//  decreixent dels gols marcats menys els rebuts i, si persisteix l’empat, per
//  ordre creixent del número d’equip.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Team {
  // numero_equip, punts_totals, gols_marcats, gols_rebuts
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
  int N, M; // N equips, M jornades
  cin >> N >> M;
  // i j x y (equips i,j: i fa x gols, j fa y gols)
  // +3 guanyar, +1 empatar
  
  vector<Team> v(N);
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N/2; ++j) {
      int tm1, tm2, g1, g2;
      cin >> tm1 >> tm2 >> g1 >> g2;
      --tm1; // to adjust vector indexes
      --tm2;

      if (g1 > g2) v[tm1].points += 3;
      else if (g1 < g2) v[tm2].points += 3;
      else {
        ++v[tm1].points;
        ++v[tm2].points;
      }

      v[tm1].gf += g1;
      v[tm1].ga += g2;

      v[tm2].gf += g2;
      v[tm2].ga += g1;
    }
  }

  for (int i = 0; i < N; ++i) v[i].number = i+1; // IS IT UNNECESSARY ¿?

  sort(v.begin(), v.end(), cmp);
  for (int i = 0; i < N; ++i) {
    cout << v[i].number << ' ' << v[i].points << ' ' << v[i].gf << ' ';
    cout << v[i].ga << endl;
  }
}
