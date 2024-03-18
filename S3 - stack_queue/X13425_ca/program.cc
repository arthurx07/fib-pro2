#include <queue>
#include <iostream>
#include "ParInt.hh"
#include "CuaIOParInt.hh"

using namespace std;

void separate_queues(queue<ParInt> &q, queue<ParInt> &q1, queue<ParInt> &q2)
{
  ParInt pi;
  int q1sum = 0, q2sum = 0;
  while (not q.empty()) {
    pi = q.front();
    if (q1sum <= q2sum) {
      q1.push(pi);
      q1sum += pi.segon();
    }
    else {
      q2.push(pi);
      q2sum += pi.segon();
    }
    q.pop();
  }
}

int main()
{
  queue<ParInt> q;
  llegirCuaParInt(q);

  queue<ParInt> q1;
  queue<ParInt> q2;
  separate_queues(q, q1, q2);

  escriureCuaParInt(q1);
  cout << endl;
  escriureCuaParInt(q2);
}
