/*
If we know we are working with matrices containing a lot of zeroes, we can
 save space and time by representing them in a compact or sparse form, in a
 way we only save the values which are not zero.
We can use a vector of lists, where each position represents a row of the
 matrix. In the list of the position i there will be saved the pairs
 (j, x) such that m[i][j] = x and x != 0. The pairs of the same row will be
 ordered in ascending order according to its first component (that is to say,
 the index of the corresponding column).

Example:
      0 6 2 0       would be represented as:  row 0: (1,6), (2,2) 
      0 0 0 0                                 row 1: [empty]
  m = 0 1 0 2                                 row 2: (1,1), (3,2)
      0 0 5 0                                 row 3: (2,5)

However, there is an structural inefficiency when implementing any operation out
  of the class, as the access to the position (i,j) of a matrix requires to
  iterate the list of the row i until finding or passing the column j.
  So it's recommended to implement the greatest quantity of possible operations
  inside of the class, to leverage the access to its fields and not lose efficiency.
To implement operations (without losing efficiency):
  - sum: it needs an iterator for each matrices (m1, m2 and result).
  - product: needs an iterator for m1, another for the result and a
      vector of iterators for m2.
*/

// TO-DO: implement sum and product of sparse matrices

#include <iostream>
#include <vector>
#include <list>

/* Pre: the user has written rowxcol elements in stdin */
/* Post: matrix m */
template <typename T>
void read_matrix(std::vector<std::list<std::pair<int, T>>>& m, int row, int col) // pass by reference, to avoid copying the matrix
{
  std::cout << "Write the elements of the matrix in order:" << std::endl;
  for (int i = 0; i < row; ++i)
  {
    std::cout << " row " << i + 1 << ": ";
    for (int j = 0; j < col; ++j)
    {
      T value;
      std::cin >> value;
      if (value) m[i].insert(m[i].end(), std::make_pair(j, value)); // if value is not zero (null)
    }
  }
}

/* Pre: true */
/* Post: the matrix is written to stdout */
template <typename T>
void write_matrix(const std::vector<std::list<std::pair<int, T>>>& m, int col)
{
  for (int i = 0; i < m.size(); ++i)
  {
    typename std::list<std::pair<int, T>>::const_iterator it = m[i].begin();
    for (int j = 0; j < col; ++j) {
      if (it != m[i].end() and it->first == j) {
        std::cout << it->second;
        ++it;
      }
      else std::cout << 0;
      if (j != col - 1) std::cout << ' ';
    }
    std::cout << std::endl;
  }
}


int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    std::cout << "Error: parameters row col were expected but not found" << std::endl;
    exit(1);
  }
  int row = atoi(argv[1]);
  int col = atoi(argv[2]);
  std::cout << "Write a matrix A of dimensions " << row << 'x' << col << '.' << std::endl;
  std::vector< std::list<std::pair<int, int>> > a(row);
  // std::vector<std::list<std::pair<int, double>>> a(row);
  read_matrix(a, row, col);
  std::cout << std::endl << "The written matrix is:" << std::endl;
  write_matrix(a, col);
}
