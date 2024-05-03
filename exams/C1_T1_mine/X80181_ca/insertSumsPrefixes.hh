#include <list>

using namespace std;

// Pre: Sigui [x0,x1,x2,...,x{n-1}] el valor inicial de l.
// Post: El valor de l és [x0, x0, x1, x0+x1 ,x2 ,x0+x1+x2 ,..., x{n-1}, x0+...+x{n-1}].
//       A més a més, els elements inicials de la llista han persistit i
//       no han canviat de valor, i ocupen les posicions parells (indexant des de 0).
void insertSumsPrefixes(list<int> &l);
