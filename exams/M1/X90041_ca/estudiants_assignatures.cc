#include <iostream>
#include <map>
#include <set>

using namespace std;

int main()
{
  map<string, set<string>> students;
  map<string, set<string>> subjects;
  string s;
  while (cin >> s) {
    if (s == "ENROLL") {
      string student, subject;
      cin >> student >> subject;
      students[student].insert(subject);
      subjects[subject].insert(student);
    }
    else if (s == "QUIT") {
      string student, subject;
      cin >> student >> subject;
      students[student].erase(subject);
      subjects[subject].erase(student);
    }
    else if (s == "SUBJECTSOFSTUDENT") {
      string student;
      cin >> student;
      
      bool writespace = false;
      for (set<string>::iterator it = students[student].begin();
          it != students[student].end(); ++it) {
        if (writespace) cout << ' ';
        writespace = true;
        cout << *it;
      }
      cout << endl;
    }
    else if (s == "STUDENTSOFSUBJECT") {
      string subject;
      cin >> subject;

      bool writespace = false;
      for (set<string>::iterator it = subjects[subject].begin();
          it != subjects[subject].end(); ++it) {
        if (writespace) cout << ' ';
        writespace = true;
        cout << *it;
      }
      cout << endl;
    }
  }
}
