#include <iostream>
#include <vector>

// #define NDEBUG // disables execution of assert
#include <cassert> // for debugging

typedef std::vector< std::vector<int> > int_matrix;
typedef std::vector< std::vector<double> > double_matrix;

/* Pre: the user has written rowxcol elements in stdin */
/* Post: matrix m */
template <typename T>
std::vector<std::vector<T>> read_matrix(int n)
{
  int row, col;
  std::cout << "Write the dimensions of the matrix: " << std::endl;
  std::cout << "  number of rows: ";
  std::cin >> row;
  std::cout << "  number of columns: ";
  std::cin >> col;

  std::vector<std::vector<T>> m(row, std::vector<T>(col));
  std::cout << "Write the elements of the matrix " << n << " in order:" << std::endl;
  for (int i = 0; i < row; ++i)
  {
    std::cout << " row " << i + 1 << ": ";
    for (int j = 0; j < col; ++j)
      std::cin >> m[i][j];
  }
  return m;
}

/* Pre: true */
/* Post: the matrix is written to stdout */
template <typename T>
void write_matrix(const std::vector<std::vector<T>>& m)
{
  for (int i = 0; i < m.size(); ++i)
  {
    // truco para saber el número de columnas, sólo util si todas son de la misma dimensión 
    for (int j = 0; j < m[0].size(); ++j) {
      std::cout << m[i][j];
      if (j != m[0].size() - 1) std::cout << ' ';
    }
    std::cout << std::endl;
  }
}

/* Pre: A and B are two matrixes of orders a1xa2 and 
 *  b1xb2. Where a2 = b1 (the number of columns of A is equal
 *  to the number of rows of B) */
/* Post: C is AB, of dimension a1xb2 */
template <typename T>
std::vector<std::vector<T>> product(const std::vector<std::vector<T>>& a,
                             const std::vector<std::vector<T>>& b)
{
  int row = a.size(), col = b[0].size(), n = a[0].size();
  std::vector<std::vector<T>> c(row, std::vector<T>(col));

  assert(n == b.size() and "Comprovació de mida: Les matrius no són de mida mxn i nxp");

  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j)
      for (int k = 0; k < n; ++k) c[i][j] += a[i][k]*b[k][j];
  // to review: (for :) loop or (for n in 1:N) loop
  return c;
}

int main()
{
  std::cout << "Write two matrixes A and B of dimensions mxn and nxp." << std::endl;
  int_matrix a = read_matrix<int>(1);
  int_matrix b = read_matrix<int>(2);
  // double_matrix a = read_matrix<double>(1);
  // double_matrix b = read_matrix<double>(2);

  std::cout << std::endl << "The product matrix AB is:" << std::endl;
  write_matrix( product(a, b) );
}
