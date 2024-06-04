#include <iostream>
#include "Estudiant.hh"
using namespace std;

int main()
{
  Estudiant est(1234);
  cout << est.te_nota() << endl;
  est.afegir_nota(2.3);
  cout << est.te_nota() << endl;
  cout << est.consultar_nota() << endl;
}
