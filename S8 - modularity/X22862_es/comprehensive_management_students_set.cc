// -1: add a new student (if it's possible)
// -2: consult the grade of an student with its DNI (if it's possible)
// -3: modify the grade of an student (if it's possible)
// -4: round the grade, to the nearest tenth, for all students in the set
// -5: write the set of students
// -6: end the program
#include "Cjt_estudiants.hh"
#include "Estudiant.hh"

double round(double r) // given by the statement
{  
  return int(10.*(r + 0.05)) / 10.0;
}

int main()
{
  Cjt_estudiants cest;
  cest.llegir();

  int n;
  while (cin >> n and n != -6)
  {
    if (n == -1)
    {
      int dni;
      double grade;
      cin >> dni >> grade;
      if (not cest.existeix_estudiant(dni))
      {
        Estudiant e = Estudiant(dni);
        if (grade >=0 and grade <= 10) e.afegir_nota(grade);
        cest.afegir_estudiant(e);
      }
      else cout << "el estudiante " << dni << " ya estaba" << endl << endl;
    }
    else if (n == -2)
    {
      int dni;
      cin >> dni;
      if (cest.existeix_estudiant(dni)) {
        if (cest.consultar_estudiant(dni).te_nota())
          cout << "el estudiante " << dni << " tiene nota "
               << cest.consultar_estudiant(dni).consultar_nota() << endl << endl;
        else 
          cout << "el estudiante " << dni << " no tiene nota" << endl << endl;
      }
      else cout << "el estudiante " << dni << " no esta" << endl << endl;
    }
    else if (n == -3)
    {
      int dni;
      double grade;
      cin >> dni >> grade;
      if (cest.existeix_estudiant(dni))
      {
        Estudiant e = Estudiant(dni);
        e.afegir_nota(grade);
        cest.modificar_estudiant(e);
      }
      else cout << "el estudiante " << dni << " no esta" << endl << endl;
    }
    else if (n == -4)
    {
      for (int i = 1; i <= cest.mida(); ++i)
      {
        Estudiant e = cest.consultar_iessim(i);
        if (e.te_nota())
          e.modificar_nota(round(e.consultar_nota()));
        cest.modificar_iessim(i, e);
      }
    }
    else if (n == -5)
    {
      cest.escriure();
      cout << endl;
    }
  }
}
