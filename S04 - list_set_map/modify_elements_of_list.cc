#include <list>
#include <sstream>
#include <iostream>

void modify_list(std::list<std::pair<int, int>>& l, int k)
{
  for (std::list<std::pair<int, int>>::iterator it = l.begin(); it != l.end(); ++it)
    it->second += k; // it->second would translate to *(it).second
}

int main()
{
  std::list<std::pair<int, int>> l;

  std::cout << "Write a list of pairs, separated by spaces, in one line:" << std::endl;
  std::string line;
  getline(std::cin, line);

  std::istringstream iss(line);
  std::string first, second;
  while (iss >> first >> second)
    l.insert(l.end(), std::make_pair(std::stoi(first), std::stoi(second))); // stoi: string to int

  int k;
  std::cout << "Input amount k to sum to second value: ";
  std::cin >> k;
  std::cout << std::endl;
  modify_list(l, k);

  std::cout << "Modified list:" << std::endl;
  for (std::list<std::pair<int, int>>::iterator it = l.begin(); it != l.end(); ++it)
    std::cout << it->first << ' ' << it->second << std::endl;
}
