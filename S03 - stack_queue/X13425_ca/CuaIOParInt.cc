#include "CuaIOParInt.hh"

void llegirCuaParInt(queue <ParInt>& c)
{
  ParInt pi;
  while (pi.llegir()) c.push(pi);
}

void escriureCuaParInt(queue<ParInt> c)
{
  while (not c.empty()) {
    c.front().escriure();
    c.pop();
  }
}
