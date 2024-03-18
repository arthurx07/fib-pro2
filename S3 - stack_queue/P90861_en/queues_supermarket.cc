// Input: number of queues n∈N+. Follow n lines, one per queue, each one with
//  its customers (name) in the arrival order. Follows an empty line.
//  Follows descriptions of events, one per line: ENTERS name queue; or
//  LEAVES name queue. queue is an integer number 0<queue<=n
// Output: First, print the name of the customers in order of departure. Then
//  print the final content of the n queues.

#include <iostream>
#include <sstream>
#include <queue>
using namespace std;

void print_queues(vector< queue<string> > vq)
{
  for (int i = 0; i < vq.size(); ++i) {
    cout << "queue " << i+1 << ":";
    while (not vq[i].empty()) {
      cout << " " << vq[i].front();
      vq[i].pop();
    }
    cout << endl;
  }
}

int main()
{
  int n;
  cin >> n;

  vector< queue<string> > vq(n);
  string line;
  getline(cin, line); // discard first line (n has already been read)
  for (int i = 0; i < n; ++i) {
    getline(cin, line); // read line
    istringstream iss(line); // initialize stringstream with read line
    string customer;
    while (iss >> customer) vq[i].push(customer); // push customers to the queue, in order of arrival
  }

  cout << "DEPARTS" << endl << "-------" << endl;

  string event;
  while (cin >> event)
  {
    int m;
    if (event == "ENTERS") {
      string customer;
      cin >> customer >> m;
      if (m > 0 and m <= vq.size()) vq[m-1].push(customer);
    }
    else if (event == "LEAVES") {
      cin >> m;
      if (m > 0 and m <= vq.size() and not vq[m-1].empty()) {
        cout << vq[m-1].front() << endl;
        vq[m-1].pop();
      }
    }
  }

  cout << endl << "FINAL CONTENTS" << endl << "--------------" << endl;
  print_queues(vq);
}

// WHY DO WE USE ISTRINGSTREAM? (diff between istringstream and stringstream?)
// - cin skips whites as well as newlines, so it's not an option
// - we use getline(cin, line) to get the whole line
// - then, for each line, we separate each variable with istringstream,
//   which is just like a cin which reads from a string. (more or less)
