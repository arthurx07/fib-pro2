#include <iostream>
#include <vector>

// #define NDEBUG // disables execution of assert
#include <cassert> // for debugging

typedef std::vector< std::vector<int> > int_matrix;
typedef std::vector< std::vector<double> > double_matrix;

/* Pre: the user has written rowxcol elements in stdin */
/* Post: matrix m */
template <typename T>
std::vector<std::vector<T>> read_matrix(int row, int col, int n)
{
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
 *  b1xb2. Where a1 = b1 and a2 = b2. */
/* Post: C is a+b */
template <typename T>
std::vector<std::vector<T>> sum(const std::vector<std::vector<T>>& a,
                             const std::vector<std::vector<T>>& b)
{
  int row = a.size(), col = a[0].size();
  std::vector<std::vector<T>> c(row, std::vector<T>(col));

  assert(row == b.size() and col == b[0].size() and "Comprovació de mida");

  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j)
      c[i][j] = a[i][j] + b[i][j];
  // to review: (for :) loop or (for n in 1:N) loop
  return c;
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
  std::cout << "Write two matrixes A and B of dimensions " << row << 'x' << col << '.' << std::endl;
  int_matrix a = read_matrix<int>(row, col, 1);
  int_matrix b = read_matrix<int>(row, col, 2);
  // double_matrix a = read_matrix<double>(row, col, 1);
  // double_matrix b = read_matrix<double>(row, col, 2);

  std::cout << std::endl << "The sum matrix A+B is:" << std::endl;
  write_matrix( sum(a, b) );
}
