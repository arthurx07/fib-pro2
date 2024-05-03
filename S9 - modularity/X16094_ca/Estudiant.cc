#include "Estudiant.hh"

/* Constants */

const char *ER1 = "No te nota";
const char *ER2 = "Valor de la nota entre 0 a 10";
const char *ER3 = "Ja te nota";
const char *ER4 = "El DNI es incorrecte";

Estudiant::Estudiant(){
  dni=0;
  nota = -1;
}

Estudiant::Estudiant(int dni)
{
  if (dni<0) throw PRO2Excepcio(ER4);
  this->dni = dni;
  nota = -1;
}

void Estudiant::afegir_nota(double nota)
{
  if (this->nota != -1) 
    throw PRO2Excepcio(ER3);
  if ((nota<0 or nota>MAX_NOTA) and nota != -1)
    throw PRO2Excepcio(ER2); 
  
  this->nota = nota; 
}

void Estudiant::modificar_nota(double nota)
{ 				
  if (this->nota == -1) 
    throw PRO2Excepcio(ER1);
  if ((nota<0 or nota>MAX_NOTA) and nota != -1)
    throw PRO2Excepcio(ER2);
  this->nota = nota;
}

bool Estudiant::te_nota() const
{
  return (nota != -1);
}

double Estudiant::consultar_nota() const
{
  if (nota == -1) throw PRO2Excepcio(ER1);
  return nota;
}

int Estudiant::consultar_DNI() const
{
  return dni;
}

double Estudiant::nota_maxima()
{
  return MAX_NOTA;
}

// static ... ?
bool Estudiant::comp(const Estudiant& e1, const Estudiant& e2)
{
  return (e1.dni < e2.dni); // same as return (e1.consultar_DNI() < e2.consultar_DNI());
}

// Declare as a member function with only one argument
//  We add Estudiant:: as we have an implicit "`this` object" passed,
//  making it 2 arguments instead of 1.
bool Estudiant::operator==(const Estudiant& est) const
{
  return (dni == est.dni); // same as: return (dni == est.consultar_DNI());
}

bool Estudiant::operator!=(const Estudiant& est) const
{
  return (dni != est.dni); // same as: return (dni != est.consultar_DNI());
}

void Estudiant::llegir()
{
  cin >> dni;
  if (dni<0) throw PRO2Excepcio(ER4);
  double x;
  cin >> x;
  if (x >= 0 and x <= MAX_NOTA) {
    nota = x; 
  }
  else nota = -1;
}

void Estudiant::escriure() const
{
  if (nota != -1)
    cout << dni << " " << nota << endl;
  else
    cout << dni <<" NP" << endl;
}
