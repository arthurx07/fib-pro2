#include <iostream>
#include <map>
#include <set>

using namespace std;

int main()
{
    map<string, unsigned int > people;
    map<unsigned int, set<string> > birthdays;
    string s;
    while (cin >> s) {
        if (s == "NEWPERSON")
        {
            string person;
            unsigned int natural;
            cin >> person >> natural;

            people[person] = natural;
            birthdays[natural].insert(person);
        }
        else if (s == "BIRTHDAY")
        {
            string person;
            cin >> person;
            ++people[person];
            birthdays[people[person]].insert(person);
            birthdays[people[person]-1].erase(person); 
        }
        else if (s == "NUMBERWITHAGE")
        {
            unsigned int natural;
            cin >> natural;
            cout << int(birthdays[natural].size()) << endl;
        }
        else if (s == "PEOPLEWITHAGE")
        {
            unsigned int natural;
            cin >> natural;
            // set<string>::iterator last = birthdays[natural].end();
            for (set<string>::iterator it = birthdays[natural].begin();
                it != birthdays[natural].end();)
            {
                cout << *it;
                if (++it != birthdays[natural].end()) cout << ' ';
            }
            cout << endl;
        }
    }
}
