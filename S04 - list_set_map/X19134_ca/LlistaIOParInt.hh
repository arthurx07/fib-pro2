#ifndef LLISTA_IO_PARINT 
#define LLISTA_IO_PARINT

#include "ParInt.hh"
#include <iostream>
#include <list>
using namespace std;

void LlegirLlistaParInt(list<ParInt>& l);
// Pre: l és buida; el canal estandar d’entrada conté un nombre
// parell d’enters, acabat pel parell 0 0
// Post: s’han afegit al final de l els parells llegits fins al 0 0 (no inclòs)

void EscriureLlistaParInt(const list<ParInt>& l); //(opcional)
// Pre: cert
// Post: s’han escrit al canal estandar de sortida els elements de l

#endif
