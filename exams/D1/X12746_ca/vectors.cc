// Vectors amb resize, i push i pop a front i back
// Observació: cost O(mlog(m)) amb m el nombre d'elements al vector +-
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
  map<int, int> v; // v as in vector
  int first_index = 0; // index (key) of first_index element in map
  int vecsize = 0; // current size of vector
  string command;
  while (cin >> command) {
    if (command == "v.push_back(") {
      int val;
      cin >> val;
      string ending;
      cin >> ending; // This consumes the ");"
      // If vector not empty, add value to last position
      // The index of the last position is: vector size + index relative to the first_index position
      if (not v.empty()) {
        v[vecsize + first_index] = val;
      } else v[0] = val;
      ++vecsize;

    } else if (command == "v.push_front(") {
      int val;
      cin >> val;
      string ending;
      cin >> ending; // This consumes the ");"
      // If vector not empty, add value to last position
      // The index of the last position is: vector size + index relative to the first_index position
      if (not v.empty()) v[--first_index] = val;
        // --first_index: decrements the value of first_index immediately and returns the decremented value
      else v[0] = val;
      ++vecsize;

    } else if (command == "v.pop_front();") {
      // Pre: we assume map is not empty
      v.erase(first_index); // erase front value of map (has index 'first_index')
      if (vecsize > 1 and v.count(++first_index) == 0) // ++first_index: increments the value of first_index immediately and returns the incremented value
        v[first_index] = 0; // here first_index is already incremented (in one relative to v.erase(first_index))
      --vecsize;

    } else if (command == "v.pop_back();") {
      // Pre: we assume map is not empty
      if (vecsize < v.size()) { // if (vecsize > v.size()) means the vector has 0 in the last position and it's not assigned in map [due to resizes]
        map<int, int>::iterator it = v.end();
        int last_index = (--it)->first; // last_index is the index, relative to first_index_index, of the last element of the map
        // we can also do: (--v.end())->first
        // --it: decrements the value of it immediately and returns the decremented value
        v.erase(last_index);
      }
      --vecsize;

    } else if (command == "v.resize(") {
      int newsize;
      cin >> newsize;
      string ending;
      cin >> ending; // This consumes the ");"
      // If vecsize < newsize we just increase the count of vecsize, as we'll
      //  output '0' if the demanded index is not explicitly in the map
      if (vecsize > newsize) {
        int last_index = first_index + newsize;
        // create an element in position last_index if it doesn't already exists (for the sake of practicity)
        if (not v.count(last_index)) v[last_index] = 0;
        v.erase(v.find(last_index), v.end());
      }
      vecsize = newsize;

    } else if (command == "cout<<v[") {
      int index;
      cin >> index;
      string ending;
      cin >> ending; // This consumes the "];"
      int current_index = first_index + index;
      cout << v[current_index] << endl; // if index is not in map outputs '0'

    } else if (command == "cout<<v;") {
      for (int i = 0; i < vecsize; ++i) { // For each element of the vector
        // If the index is explicit in map, output its value, otherwise output 0
        if (v.count(first_index + i)) cout << v[first_index+i];
        else cout << '0';
        if (i != vecsize - 1) cout << ','; // if not last element, print a comma
      } 
      cout << endl;

    } else if (command == "v[") {
      int index;
      cin >> index;
      string mid;
      cin >> mid; // This consumes the "]="
      int val;
      cin >> val;
      string ending;
      cin >> ending; // This consumes the ";"
      // The index to assign the element in map (current_index) is the given index but 
      //  relative to the first_index
      int current_index = first_index + index;
      v[current_index] = val;

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
// note: abnormal program termination execution error in jutge was due to
//  accessing at invalid positions of the map
