// Input: Línea con dos enteros n > 0 y x. A cont, n secuencias de enteros separadas
//  por saltos de línea. Todas las secuencias contienen el valor x.
// Output: Paara cada secuencia, la suma de todos los elementos que preceen a la
//  primera aparición de x.
#include <iostream>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  for (int i = 1; i <= n; ++i) { // la primera secuencia es 1
    int e;
    int suma = 0;
    while (cin >> e and e != x) suma += e; // sumar enteros de la línea hasta encontrar x

    string resto_linea;
    getline(cin, resto_linea); // leer el contenido de la línea después de x (no se usan para nada en este ejercicio)
    cout << "La suma de la secuencia " << i << " es " << suma << endl;
  }
}
