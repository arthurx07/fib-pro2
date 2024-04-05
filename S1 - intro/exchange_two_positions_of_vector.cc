#include <iostream>
#include <vector>

/* Pre: 0 <= i, j < v.size() */
/* Post: v[i] and v[j] have their values exchanged in relation to the originals */
template <typename T> void change_vect(std::vector<T>& v, int i, int j)
{
  T t = v[i];
  v[i] = v[j];
  v[j] = t;
}

/* Pre: There's an integer N greater than 0 and N elements of type T*/
/* Post: Return a vector of type T with the elements read from stdin,
 *  in same the order they were read */
template <typename T> std::vector<T> read_vector()
{
  std::cout << "Write the size of the vector, followed by its elements: ";
  int size;
  std::cin >> size;
  std::vector<T> v(size);

  for (int i = 0; i < size; ++i)
    std::cin >> v[i];

  return v;
}

/* Pre: true */
/* Post: all vector elements have been written to stdout */
template <typename T> void write_vector(const std::vector<T> &v)
{
  for (int i = 0; i < int(v.size()); ++i) {
    std::cout << v[i];
    if (i != v.size() - 1) std::cout << ' ';
  }
  std::cout << std::endl;
}

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    std::cout << "Error: parameters i, j were expected but not found" << std::endl;
    exit(1);
  }
  int i = atoi(argv[1]); // ascii to integer
  int j = atoi(argv[2]);

  std::vector<int> v = read_vector<int>();
  // std::vector<char> v = read_vector<char>();
  write_vector(v);
  change_vect(v, i, j);
  write_vector(v);
}
