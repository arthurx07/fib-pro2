#include <iostream>
#include <string>
#include <vector>
// ...

using namespace std;

// Add auxiliary functions if you wish.
// ...

// Pre: not empty vector v=x0,x1...x(n-1)
// Post: v=x1...x(n-1)
void pop_front(vector<int> &v)
{
  for (int i = 0; i < v.size()-1; ++i) { // v.size()-1, as we don't need last elem.
    v[i] = v[i+1];
  }
  v.pop_back();
}

// Pre: vector v=x1...x(n-1)
// Post: v=x0x1...x(n-1)
void push_front(vector<int> &v, int val)
{
  v.push_back(v[v.size()-1]);
  int prev = v[0], act;
  for (int i = 1; i < v.size() - 1; ++i) { // v.size()-1, 
    act = v[i];
    v[i] = prev;
    prev = act;
  }
  v[0] = val;
}

// Pre: vector of size v.size()
// Post: vector of size newsize, adding 0 or removing existing elements from the back
void resize(vector<int> &v, int newsize)
{
  if (v.size() < newsize) {
    for (int i = v.size(); i < newsize; ++i) {
      v.push_back(0);
    }
  }
  else if (v.size() > newsize) {
    for (int i = v.size(); i > newsize; --i) {
      v.pop_back();
    }
  }
}

// Pre: not empty vector
// Post: prints the vector as v0,v1,...,v(n-1)
void print_vector(vector<int> &v)
{
  for (int i = 0; i < v.size(); ++i) {
    cout << v[i];
    if (i != v.size()-1) cout << ',';
  }
  cout << endl;
}

int main()
{
  vector<int> v;
  // Declare and initialise more data if you wish.
  // ...
  string command;
  while (cin >> command) {
    if (command == "v.push_back(") {
      int val;
      cin >> val;
      string ending;
      cin >> ending; // Això consumeix el ");"
      // ...
      v.push_back(val); 
    } else if (command == "v.push_front(") {
      int val;
      cin >> val;
      string ending;
      cin >> ending; // Això consumeix el ");"
      // ...
      push_front(v, val);
    } else if (command == "v.pop_front();") {
      // ...
      pop_front(v);
    } else if (command == "v.pop_back();") {
      // ...
      v.pop_back();
    } else if (command == "v.resize(") {
      int newsize;
      cin >> newsize;
      string ending;
      cin >> ending; // Això consumeix el ");"
      // ...
      resize(v, newsize);
    } else if (command == "cout<<v[") {
      int index;
      cin >> index;
      string ending;
      cin >> ending; // Això consumeix el "];"
      // ...
      cout << v[index] << endl;
    } else if (command == "cout<<v;") {
      // ...
      print_vector(v);
    } else if (command == "v[") {
      int index;
      cin >> index;
      string mid;
      cin >> mid; // Això consumeix el "]="
      int val;
      cin >> val;
      string ending;
      cin >> ending; // Això consumeix el ";"
      // ...
      v[index] = val;
    } else if (command == "//") {
      string comment;
      getline(cin, comment);
      cout << "//" << comment << endl;
    } else {
      cout << "Wrong command '" << command << "'" << endl;
      string discard;
      getline(cin, discard);
    }
  }
}
