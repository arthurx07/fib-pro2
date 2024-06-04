#include "LlistaIOParInt.hh"

void LlegirLlistaParInt(list<ParInt>& l) {
  ParInt p;
  while (p.llegir()) {
    l.push_back(p);
    // No need to use an iterator
  }
}

void EscriureLlistaParInt(const list<ParInt>& l) {
  bool comma = false;
  for (list<ParInt>::const_iterator it = l.begin(); it != l.end(); ++it) {
    if (comma) cout << " , ";
    else comma = false;

    ParInt p = *it;
    p.escriure();
  }
}

// Warning: if parameter is a const, then we must use a const_iterator. Else,
// it shows this error:
// error: conversion from '_Safe_iterator<std::__cxx1998::_List_const_iterator<ParInt>,[...],[...]>'
// to non-scalar type '_Safe_iterator<std::__cxx1998::_List_iterator<ParInt>,[...],[...]>'
