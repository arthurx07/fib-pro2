#include <iostream>
#include <map>
#include <set>
using namespace std;

int main()
{
  string s;
  map<string, int> people;
  set<string> inred;
  while (cin >> s)
  {
    if (s == "TRANSACTION")
    {
      string name;
      int n;
      cin >> name >> n;
      people[name] += n;
      if (people[name] < 0)
        inred.insert(name); // *Note
      else if (inred.count(name) and people[name] >= 0)
        inred.erase(name);
    }
    else if (s == "NUMBERINRED")
    {
      cout << inred.size() << endl; 
    }
    else if (s == "PEOPLEINRED")
    {
      bool white = false;
      for (set<string>::iterator it = inred.begin(); it != inred.end(); ++it)
      {
        if (white) cout << ' ';
        white = true;
        cout << *it;
      }
      cout << endl;
    }
  }
}
// Note:
// Because elements in a set are unique, the insertion operation checks
// whether each inserted element is equivalent to an element already in
// the container, and if so, the element is not inserted, returning an
// iterator to this existing element (if the function returns a value).
