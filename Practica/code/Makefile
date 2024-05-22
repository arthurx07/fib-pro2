OPCIONES = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

program.exe: program.o Barco.o Ciudad.o Cuenca.o Producto.o
	g++ -o program.exe program.o Barco.o Ciudad.o Cuenca.o Producto.o $(OPCIONES)

Barco.o: Barco.cc Barco.hh
	g++ -c Barco.cc $(OPCIONES)

Ciudad.o: Ciudad.cc Ciudad.hh
	g++ -c Ciudad.cc $(OPCIONES)

Cuenca.o: Cuenca.cc Cuenca.hh
	g++ -c Cuenca.cc $(OPCIONES)

Producto.o: Producto.cc Producto.hh
	g++ -c Producto.cc $(OPCIONES)

program.o: program.cc
	g++ -c program.cc $(OPCIONES)

tar: Barco.cc Barco.hh Ciudad.cc Ciudad.hh Cuenca.cc Cuenca.hh Makefile Producto.cc Producto.hh program.cc
	tar -cvf practica.tar Barco.cc Barco.hh Ciudad.cc Ciudad.hh Cuenca.cc Cuenca.hh Makefile Producto.cc Producto.hh program.cc

clean:
	rm *.o
	rm *.exe
