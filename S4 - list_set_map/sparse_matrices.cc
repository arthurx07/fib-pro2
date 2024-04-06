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

/* Pre: A and B are two sparse matrices of orders a1xa2 and 
 *  b1xb2. Where a1 = b1 and a2 = b2. */
/* Post: C is a+b */
template <typename T>
void sum(const std::vector<std::list<std::pair<int, T>>>& a,
         const std::vector<std::list<std::pair<int, T>>>& b,
         std::vector<std::list<std::pair<int, T>>>& c, int col)
{
  // assert(a.size() == b.size() and col);
  c = std::vector<std::list<std::pair<int, T>>>(a.size());
  for (int i = 0; i < c.size(); ++i)
  {
    typename std::list<std::pair<int, T>>::const_iterator ita = a[i].begin();
    typename std::list<std::pair<int, T>>::const_iterator itb = b[i].begin();
    for (int j = 0; j < col; ++j) {
      T value = 0;
      if (ita != a[i].end() and ita->first == j) {
        value += ita->second;
        ++ita;
      }
      if (itb != b[i].end() and itb->first == j) {
        value += itb->second;
        ++itb;
      }
      if (value != 0) c[i].insert(c[i].end(), std::make_pair(j, value));
    }
  }
}

/* Pre: A and B are two sparse matrices of orders a1xa2 and 
 *  b1xb2. Where a2 = b1 (the number of columns of A is equal
 *  to the number of rows of B) */
/* Post: C is AB, of dimension a1xb2 */
template <typename T>
void product(const std::vector<std::list<std::pair<int, T>>>& a,
             const std::vector<std::list<std::pair<int, T>>>& b,
             std::vector<std::list<std::pair<int, T>>>& c, int bcol)
{
  // assert (acol == b.size())
  c = std::vector<std::list<std::pair<int, T>>> (a.size());

  for (int i = 0; i < c.size(); ++i) // c.size() == a.size() == rows of C
  {
    typename std::list<std::pair<int, T>>::iterator itc = c[i].begin();
 
    // vector of iterators of matrix B
    std::vector< typename std::list<std::pair<int, T>>::const_iterator > vitb(b.size()); // b.size() == rows of B == columns of A
    for (int idx = 0; idx < b.size(); ++idx) vitb[idx] = b[idx].begin(); // reset all iterators of vector<iterator> to begin()

    for (int j = 0; j < bcol; ++j) // c[0].size() == b[0].size == bcol == columns of C
    {
      T value = 0;
      typename std::list<std::pair<int, T>>::const_iterator ita = a[i].begin();
      for (int k = 0; k < b.size(); ++k) { // b.size() == a[0].size() == rows of B == columns of A
        bool a_empty = not (ita != a[i].end() and ita->first == k);
        bool b_empty = not (vitb[k] != b[k].end() and vitb[k]->first == j);

        if (not a_empty and not b_empty)
          value += (ita->second)*(vitb[k]->second);
        if (not a_empty) ++ita;
        if (not b_empty) ++vitb[k];
      }
      if (value != 0) c[i].insert(c[i].end(), std::make_pair(j, value));
    }
  }
}

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    std::cout << "Error: parameters sum or product were expected but not found." << std::endl;
    exit(1);
  }
  else if (std::string(argv[1]) == "sum")
  {
    if (argc != 4)
    {
      std::cout << "Error: parameters row col were expected but not found." << std::endl;
      exit(1);
    }
    int row = atoi(argv[2]);
    int col = atoi(argv[3]);
    std::cout << "Write a matrix A and B of dimensions " << row << 'x' << col << '.' << std::endl;
    
    std::vector< std::list<std::pair<int, int>> > a(row);
    // std::vector<std::list<std::pair<int, double>>> a(row);
    read_matrix(a, row, col);
    std::vector< std::list<std::pair<int, int>> > b(row);
    read_matrix(b, row, col);

    // std::cout << std::endl << "The written matrix is:" << std::endl;
    // write_matrix(a, col);

    std::vector< std::list<std::pair<int, int>> > c(row);
    sum(a, b, c, col);
    std::cout << std::endl << "The sum matrix A+B is:" << std::endl;
    write_matrix(c, col);
  }
  else if (std::string(argv[1]) == "product")
  {
    int row, col;

    std::cout << "Write the dimensions of the matrix A: " << std::endl;
    std::cout << "  number of rows: ";
    std::cin >> row;
    std::cout << "  number of columns: ";
    std::cin >> col;
    std::vector< std::list<std::pair<int, int>> > a(row);
    // std::vector<std::list<std::pair<int, double>>> a(row);
    read_matrix(a, row, col);

    std::cout << "Write the dimensions of the matrix A: " << std::endl;
    std::cout << "  number of rows: ";
    std::cin >> row;
    std::cout << "  number of columns: ";
    std::cin >> col;
    std::vector< std::list<std::pair<int, int>> > b(row);
    // std::vector<std::list<std::pair<int, double>>> b(row);
    read_matrix(b, row, col);

    std::vector< std::list<std::pair<int, int>> > c(row);
    product(a, b, c, col);
    std::cout << std::endl << "The product matrix AB is:" << std::endl;
    write_matrix(c, col);
  }
}
