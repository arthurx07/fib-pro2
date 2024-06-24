#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

#if __has_include("program.hh")
#include "program.hh"
#else
#if __has_include("stack.hh")
#include "stack.hh"
#endif
#endif

struct Container {
public:
    string word;
    Container() {
        word = "";
    }
    Container(const Container &c)
    {
    	word = c.word;
    }
    Container(const string s)
    {
        word = s;
    }
    Container(const int x)
    {
        if (x != 0) {
            cout << "Error: invalid initialization from int to string container" << endl;
            exit(1);
        }
    	word = "";
    }
	Container &operator=(const Container &c)
	{
        if (this == &c) return *this;
    	word = c.word;
        return *this;
	}
	Container &operator+=(const Container &c)
	{
    	word += c.word;
        return *this;
	}
	Container &operator=(const int x)
	{
        if (x != 0) {
            cout << "Error: invalid assignment from int to string container" << endl;
            exit(1);
        }
    	word = "";
        return *this;
	}
	Container &operator=(const string s)
	{
    	word = s;
        return *this;
    }
};

istream &operator>>(istream &is, Container &c)
{
    is >> c.word;
    return is;
}

ostream &operator<<(ostream &os, Container c)
{
    os << c.word;
    return os;
}

Container operator+(Container c1, Container c2)
{
    Container c;
    c.word = c1.word+c2.word;
    return c;
}

int getIdStack(string s)
{
  return atoi(s.substr(1).c_str());
}

void die(string message) {
    cout << message << endl;
    exit(1);
}

int main()
{
  string s1, s2, s3, s4, s5, s6, s7;
  int numstacks = 1;
  cin >> s1;
  for (cin >> s1 >> s2; s2 != ";"; cin >> s1 >> s2) numstacks++;
  vector<Stack<Container> > s(numstacks);
  while (cin >> s1) {
    if (s1[0] == 's') {
      int idstack = getIdStack(s1);
      cin >> s2;
      if (s2 == ".push(") {
          cin >> s3 >> s4;
          Container value = s3.substr(1, int(s3.size())-2);
          s[idstack].push(value);
      } else if (s2 == ".pop();") {
          s[idstack].pop();
      } else if (s2 == ".take(") {
          cin >> s3 >> s4 >> s5 >> s6;
          int idstack2 = getIdStack(s3);
          int k = atoi(s5.c_str());
          s[idstack].take(s[idstack2], k);
      } else {
          cout << "WRONG METHOD " << s2 << endl;
      }
    } else if (s1 == "cout<<") {
      cin >> s2 >> s3;
      int idstack = getIdStack(s2);
      if (s3 == "<<endl;") {
	cout << s[idstack] << endl;
      } else if (s3 == ".size()<<endl;") {
	cout << s[idstack].size() << endl;
      } else if (s3 == ".top()<<endl;") {
	cout << s[idstack].top() << endl;
      } else {
	cout << "WRONG ENDING " << s3 << endl;
      }
    } else if (s1 == "exit(0);") {
      exit(0);
    } else {
      cout << "WRONG COMMAND " << s1 << endl;
    }
  }
}