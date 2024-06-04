#include <iostream>
#include <queue>
using namespace std;

struct info {
  int max, min, sum = 0; // initialize sum to zero
  double avg;
};

void print_stats(int min, int max, double avg)
{
  cout << "min " << min << "; max " << max << "; media " << avg << endl;
}

void recalculate(queue<int> q, int& max, int& min) {
  while (not q.empty()) {
    max = std::max(q.front(), max); // if (q.front() > max) max = q.front();
    min = std::min(q.front(), min); // if (q.front() < min) min = q.front();
    q.pop();
  }
}

int main()
{
  int n;
  info st;
  queue<int> q;

  while (cin >> n and n >= -1001 and n <= 1000) {
    if (n != -1001) {
      if (not q.empty()) {
        st.min = min(st.min, n); // if (n < st.min) st.min = n;
        st.max = max(st.max, n); // if (n > st.max) st.max = n;
      } else st.min = st.max = n;
      q.push(n);
      st.sum += n;
      print_stats(st.min, st.max, double(st.sum)/double(q.size()));
    }

    else if (not q.empty()) {
      int front = q.front();
      q.pop();
      st.sum -= front;
      if (not q.empty()) {
        if (front == st.max or front == st.min) {
          st.min = st.max = q.front();
          recalculate(q, st.max, st.min);
        }
        print_stats(st.min, st.max, double(st.sum)/double(q.size()));
      } else cout << '0' << endl;
    } 

    else cout << '0' << endl;
  }
}
