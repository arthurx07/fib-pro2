// Input: ADD (to add person + money), DELETE (to delete person), NUMPEOPLE money
// Output: NUMPEOPLE (to print number of people with the current amount of 'money' asked by input)
#include <iostream>
#include <map>
using namespace std;

int main()
{
  string s;
  map<string, int> people;
  map<int, int> numpeople;
  while (cin >> s) {
    if (s == "NUMPEOPLE") {
      int money;
      cin >> money;
      // int sum = 0;
      // for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it)
      //   if (it->second == money) ++sum;
      cout << numpeople[money] << endl;
    }
    else if (s == "ADD") {
      int money;
      string name;
      cin >> name >> money;
      people[name] = money;
      ++numpeople[money];
    }
    else if (s == "DELETE") {
      string name;
      cin >> name;
      --numpeople[people[name]];
      people.erase(people.find(name));
    }
  }
}

// is it the best solution? don't think so, as it's using two maps
// is it straightforward and the best i could think of? yes :)
