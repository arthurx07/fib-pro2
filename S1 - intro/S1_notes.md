## Inclusiones
```c++
#include <module>
#include "module"
```
* <> extends the path to /usr/include/...
* "" extends the path to the file's directory .

Generally, and following what I've seen, if you want to use a module you include
it's header ```#include "module.hh"``` and not it's implementation. Also, you
include all the modules you are using in your file's code, ignoring if they have
already been included in other files you've included.
If you need to include a module in a module you're writing (header+implementation),
the includes always go in the header. The implementation just includes the header
```#include "module.hh"```.

## Headers / módulos
.cc is the implementation 
.hh is the specification/interface/header

The .hh files allow the creation of headers of the procedures which are written
in the .cc with the same name. Calling the file with ```#include "file.hh"```
doesn't add the definition/implementation of the procedures, only their declarations.
Due to this it's necessary to compile and link the .cc archive with the procedure
definitions.

A .hh archive is usually made up with:
```c++
#ifndef NAME
#define NAME

// includes, declarations (+explain what the procdure does), etc.

#endif
```
#ifndef checks if NAME is defined, and if it's not executes everything until
the #endif. It's needed to avoid declaring its procedures multiple times, if
the .hh file has been already called.

## Compilation

```sh
# ls: vectorIOint.cc vectorIOint.hh sol.cc
p2++ -c vectorIOint.cc # compile vectorIOint.cc (include vectorIOint.hh) -> vectorIOint.o
p2++ -c sol.cc # compile sol.cc (include vectorIOint.hh) -> sol.o
p2++ sol.o vectorIOint.o -o a.x # link objects and generate an executable sol.o vectorIOint.o -> sol.x
./a.x
```

## How to search/learn/use new classes
Go to "Standard Template Library (stl) containers" in 
https://cplusplus.com/reference/stl/, to learn/explore/use new classes, etc.

When searching for a new class, go to "constructor" to learn and see an example
of how it's used

## curiosity:
to show compiled code in assembly: ```gcc -S input.c -o output.asm -masm=intel```
(masm=intel is for intel syntax, and not at&t)

## Verification of iterative and recursive designs
See the code from this class (S1).
