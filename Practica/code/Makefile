OPCIONES = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

program.exe: program.o Barco.o Ciudad.o Cuenca.o Producto.o
	g++ -o program.exe program.o Barco.o Ciudad.o Cuenca.o Producto.o $(OPCIONES)

Barco.o: Barco.cc Barco.hh
	g++ -c Barco.cc $(OPCIONES)

Ciudad.o: Ciudad.cc Ciudad.hh Producto.hh
	g++ -c Ciudad.cc $(OPCIONES)

Cuenca.o: Cuenca.cc Cuenca.hh Barco.hh Ciudad.hh Producto.hh BinTree.hh
	g++ -c Cuenca.cc $(OPCIONES)

Producto.o: Producto.cc Producto.hh
	g++ -c Producto.cc $(OPCIONES)

program.o: program.cc Cuenca.hh Producto.hh
	g++ -c program.cc $(OPCIONES)

doxygen: Doxyfile Barco.cc Barco.hh Ciudad.cc Ciudad.hh Cuenca.cc Cuenca.hh Producto.cc Producto.hh program.cc
	doxygen && zip -r html html

justificacion: justificacion.ms
	preconv justificacion.ms | tbl | refer -PS -e | groff -me -ms -T pdf > justificacion.pdf

tar: Barco.cc Barco.hh Ciudad.cc Ciudad.hh Cuenca.cc Cuenca.hh Makefile Producto.cc Producto.hh program.cc Doxyfile doxygen justificacion
	tar -cvf practica.tar Barco.cc Barco.hh Ciudad.cc Ciudad.hh Cuenca.cc Cuenca.hh Makefile Producto.cc Producto.hh program.cc Doxyfile html.zip justificacion.pdf

clean:
	rm *.o
	rm *.exe
