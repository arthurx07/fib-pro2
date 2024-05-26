.fam H \# Set font to Helvetica
.ss 12 0 \# interword spacing, should be equal to font size
.nr PS 12 \# point size
.nr VS 14 \# vertical spacing (leading)
.nr PD 0.4v \# paragraph distance, extra vertical space between paragraphs (default value)
.nr PS 10
.nr GROWPS 3

\# WARNING: HAVE EXCHANGED COLOR 2 WITH 0
.defcolor groffhl_2 rgb 0.133333f 0.545098f 0.133333f
.defcolor groffhl_1 rgb 0.000000f 0.000000f 0.803922f
.defcolor groffhl_0 rgb 0.000000f 0.000000f 0.000000f
.defcolor groffhl_3 rgb 0.545098f 0.000000f 0.545098f 
.defcolor groffhl_4 rgb 0.509804f 0.509804f 0.509804f
.defcolor groffhl_5 rgb 1.000000f 0.000000f 1.000000f

.LP
.mk
.ft B
Práctica: Comercio fluvial
.rj
.rt
Artur Leivar Guiu
.gcolor grey
.mk
Programación 2
.rj
.rt
Grado en Ingenieria Informática
\l'\n[.l]u\[rn]'
.gcolor
.LP
\# Método iterativo: especificación, invariante i justificación respecto a la invariante
\#  comerciar: justificar la operación que actualiza los inventarios de las ciudades
\# Método recursivo: especificación, hipótesis de inducción i justificación respecto a la hipótesis de inducción
\#  hacer_viaje: justificar la operación auxiliar que calcula la ruta. No hay que justificar el código de la
\#  actualización de inventarios una vez calculada la ruta
\# En AMBOS CASOS hay que justificar la finalización e las funciones mediante funciones de cota
\#  o equivalentes
\# Seguir los apuntes de 'Correctesa de Programes Iteratius i Programació Recursiva'
.NH
Método iterativo: Comerciar
.LP
\f[B]Precondición:\f[] cierto
.br
\f[B]Postcondición:\f[] El parámetro implícito le da a la Ciudad c todos los productos que le sobren hasta alcanzar, si es posible, los que necesita. Y viceversa.
.br
\f[B]Coste:\f[] Lineal respecto al tamaño más pequeño en relación al parámetro impícito y la Ciudad c.
.br
\f[B]Invariante:\f[] 
.br
\f[B]Función de cota:\f[] \f[C]it1\f[] és igual a \f[C]inventario.end()\f[]
o bien \f[C]it2\f[] és igual a \f[C]c.inventario.end().\f[]
.fam C
.TS
box center tab(|);
lw90.
T{
\m[groffhl_0]\m[]\m[groffhl_1]void\m[] \m[groffhl_0]\m[]\m[groffhl_2]Ciudad\m[]\m[groffhl_0]\m[]\m[groffhl_2]::\m[]\m[groffhl_0]\m[]\m[groffhl_2]comerciar\m[]\m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]Ciudad\m[] \m[groffhl_2]&\m[]\m[groffhl_0]c\m[]\m[groffhl_2])\m[]
\m[groffhl_0]\m[]\m[groffhl_2]{\m[]
\m[groffhl_0]  map\m[]\m[groffhl_2]<\m[]\m[groffhl_0]Producto\m[]\m[groffhl_2],\m[] \m[groffhl_0]Atributos\m[]\m[groffhl_2]>::\m[]\m[groffhl_0]iterator it1\m[] \m[groffhl_2]=\m[] \m[groffhl_0]inventario\m[]\m[groffhl_2].\m[]\m[groffhl_0]\m[]\m[groffhl_2]begin\m[]\m[groffhl_0]\m[]\m[groffhl_2]();\m[]
\m[groffhl_0]  map\m[]\m[groffhl_2]<\m[]\m[groffhl_0]Producto\m[]\m[groffhl_2],\m[] \m[groffhl_0]Atributos\m[]\m[groffhl_2]>::\m[]\m[groffhl_0]iterator it2\m[] \m[groffhl_2]=\m[] \m[groffhl_0]c\m[]\m[groffhl_2].\m[]\m[groffhl_0]inventario\m[]\m[groffhl_2].\m[]\m[groffhl_0]\m[]\m[groffhl_2]begin\m[]\m[groffhl_0]\m[]\m[groffhl_2]();\m[]
\m[groffhl_0]\m[]  \m[groffhl_3]while\m[] \m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]it1\m[] \m[groffhl_2]!=\m[] \m[groffhl_0]inventario\m[]\m[groffhl_2].\m[]\m[groffhl_0]\m[]\m[groffhl_2]end\m[]\m[groffhl_0]\m[]\m[groffhl_2]()\m[] \m[groffhl_0]\m[]\m[groffhl_3]and\m[] \m[groffhl_0]it2\m[] \m[groffhl_2]!=\m[] \m[groffhl_0]c\m[]\m[groffhl_2].\m[]\m[groffhl_0]inventario\m[]\m[groffhl_2].\m[]\m[groffhl_0]\m[]\m[groffhl_2]end\m[]\m[groffhl_0]\m[]\m[groffhl_2]())\m[]
\m[groffhl_0]\m[]  \m[groffhl_2]{\m[]
\m[groffhl_0]\m[]    \m[groffhl_3]if\m[] \m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]it1\m[]\m[groffhl_2]->\m[]\m[groffhl_0]first\m[] \m[groffhl_2]<\m[] \m[groffhl_0]it2\m[]\m[groffhl_2]->\m[]\m[groffhl_0]first\m[]\m[groffhl_2]) ++\m[]\m[groffhl_0]it1\m[]\m[groffhl_2];\m[]
\m[groffhl_0]\m[]    \m[groffhl_3]else if\m[] \m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]it2\m[]\m[groffhl_2]->\m[]\m[groffhl_0]first\m[] \m[groffhl_2]<\m[] \m[groffhl_0]it1\m[]\m[groffhl_2]->\m[]\m[groffhl_0]first\m[]\m[groffhl_2]) ++\m[]\m[groffhl_0]it2\m[]\m[groffhl_2];\m[]
\m[groffhl_0]\m[]    \m[groffhl_3]else\m[] \m[groffhl_0]\m[]\m[groffhl_4]// if (it1->first == it2->first)\m[]
\m[groffhl_0]\m[]    \m[groffhl_2]{\m[]
\m[groffhl_0]\m[]      \m[groffhl_1]int\m[] \m[groffhl_0]dar\m[] \m[groffhl_2]=\m[] \m[groffhl_0]it1\m[]\m[groffhl_2]->\m[]\m[groffhl_0]second\m[]\m[groffhl_2].\m[]\m[groffhl_0]posee\m[] \m[groffhl_2]-\m[] \m[groffhl_0]it1\m[]\m[groffhl_2]->\m[]\m[groffhl_0]second\m[]\m[groffhl_2].\m[]\m[groffhl_0]necesita\m[]\m[groffhl_2];\m[]
\m[groffhl_0]\m[]      \m[groffhl_1]int\m[] \m[groffhl_0]rec\m[] \m[groffhl_2]=\m[] \m[groffhl_0]it2\m[]\m[groffhl_2]->\m[]\m[groffhl_0]second\m[]\m[groffhl_2].\m[]\m[groffhl_0]necesita\m[] \m[groffhl_2]-\m[] \m[groffhl_0]it2\m[]\m[groffhl_2]->\m[]\m[groffhl_0]second\m[]\m[groffhl_2].\m[]\m[groffhl_0]posee\m[]\m[groffhl_2];\m[]
\m[groffhl_0]\m[]      \m[groffhl_3]if\m[] \m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]dar\m[] \m[groffhl_2]>\m[] \m[groffhl_0]\m[]\m[groffhl_5]0\m[] \m[groffhl_0]\m[]\m[groffhl_3]and\m[] \m[groffhl_0]rec\m[] \m[groffhl_2]>\m[] \m[groffhl_0]\m[]\m[groffhl_5]0\m[]\m[groffhl_0]\m[]\m[groffhl_2])\m[] \m[groffhl_0]rec\m[] \m[groffhl_2]=\m[] \m[groffhl_0]\m[]\m[groffhl_2]min\m[]\m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]dar\m[]\m[groffhl_2],\m[] \m[groffhl_0]rec\m[]\m[groffhl_2]);\m[]
\m[groffhl_0]\m[]      \m[groffhl_3]else if\m[] \m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]dar\m[] \m[groffhl_2]<\m[] \m[groffhl_0]\m[]\m[groffhl_5]0\m[] \m[groffhl_0]\m[]\m[groffhl_3]and\m[] \m[groffhl_0]rec\m[] \m[groffhl_2]<\m[] \m[groffhl_0]\m[]\m[groffhl_5]0\m[]\m[groffhl_0]\m[]\m[groffhl_2])\m[] \m[groffhl_0]rec\m[] \m[groffhl_2]=\m[] \m[groffhl_0]\m[]\m[groffhl_2]max\m[]\m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]dar\m[]\m[groffhl_2],\m[] \m[groffhl_0]rec\m[]\m[groffhl_2]);\m[]
\m[groffhl_0]\m[]      \m[groffhl_3]else\m[] \m[groffhl_0]rec\m[] \m[groffhl_2]=\m[] \m[groffhl_0]\m[]\m[groffhl_5]0\m[]\m[groffhl_0]\m[]\m[groffhl_2];\m[]
.sp
\m[groffhl_0]      it1\m[]\m[groffhl_2]->\m[]\m[groffhl_0]second\m[]\m[groffhl_2].\m[]\m[groffhl_0]posee\m[] \m[groffhl_2]-=\m[] \m[groffhl_0]rec\m[]\m[groffhl_2];\m[]
\m[groffhl_0]      it2\m[]\m[groffhl_2]->\m[]\m[groffhl_0]second\m[]\m[groffhl_2].\m[]\m[groffhl_0]posee\m[] \m[groffhl_2]+=\m[] \m[groffhl_0]rec\m[]\m[groffhl_2];\m[]
.sp
\m[groffhl_0]      peso_total\m[] \m[groffhl_2]-=\m[] \m[groffhl_0]it1\m[]\m[groffhl_2]->\m[]\m[groffhl_0]first\m[]\m[groffhl_2].\m[]\m[groffhl_0]\m[]\m[groffhl_2]consultar_peso\m[]\m[groffhl_0]\m[]\m[groffhl_2]()*\m[]\m[groffhl_0]rec\m[]\m[groffhl_2];\m[]
\m[groffhl_0]      volumen_total\m[] \m[groffhl_2]-=\m[] \m[groffhl_0]it1\m[]\m[groffhl_2]->\m[]\m[groffhl_0]first\m[]\m[groffhl_2].\m[]\m[groffhl_0]\m[]\m[groffhl_2]consultar_volumen\m[]\m[groffhl_0]\m[]\m[groffhl_2]()*\m[]\m[groffhl_0]rec\m[]\m[groffhl_2];\m[]
\m[groffhl_0]      c\m[]\m[groffhl_2].\m[]\m[groffhl_0]peso_total\m[] \m[groffhl_2]+=\m[] \m[groffhl_0]it2\m[]\m[groffhl_2]->\m[]\m[groffhl_0]first\m[]\m[groffhl_2].\m[]\m[groffhl_0]\m[]\m[groffhl_2]consultar_peso\m[]\m[groffhl_0]\m[]\m[groffhl_2]()*\m[]\m[groffhl_0]rec\m[]\m[groffhl_2];\m[]
\m[groffhl_0]      c\m[]\m[groffhl_2].\m[]\m[groffhl_0]volumen_total\m[] \m[groffhl_2]+=\m[] \m[groffhl_0]it2\m[]\m[groffhl_2]->\m[]\m[groffhl_0]first\m[]\m[groffhl_2].\m[]\m[groffhl_0]\m[]\m[groffhl_2]consultar_volumen\m[]\m[groffhl_0]\m[]\m[groffhl_2]()*\m[]\m[groffhl_0]rec\m[]\m[groffhl_2];\m[]
\m[groffhl_0]\m[]
\m[groffhl_0]\m[]      \m[groffhl_2]++\m[]\m[groffhl_0]it1\m[]\m[groffhl_2];\m[]
\m[groffhl_0]\m[]      \m[groffhl_2]++\m[]\m[groffhl_0]it2\m[]\m[groffhl_2];\m[]
\m[groffhl_0]\m[]    \m[groffhl_2]}\m[]
\m[groffhl_0]\m[]  \m[groffhl_2]}\m[]
.br
\m[groffhl_0]\m[]\m[groffhl_2]}\m[]\m[groffhl_0]\m[]

T}
.TE
.fam H
.nr test 0 1
.nr PI 3n
.ft B
Justificación del método con respecto a la invariante.
.IP \n+[test]
Cuando se llega al bucle por primera vez, I se cumple.
.IP \n+[test]
Suponemos I, y vemos que la condición del bucle se evalua en cierto. Entonces, después de
ejecutar el cuerpo del bucle, I se vuelve a cumplir.
.IP \n+[test]
Suponemos I, y que la condición de entrada al bucle falla. Entonces, vemos que la postcondición
se cumple.
.IP \n+[test]
Suponemos I, y que la condición de entrada al bucle se cumple. Entonces, después de ejecutar el
cuerpo del bucle la función de cota se evalua a algo estrictamente menor.
.IP \n+[test]
La invariante I implica que la función de cota no se evalua a algo menor que 0. El bucle no es infinito

.bp
.NH
Método recursivo: Hacer Viaje
.LP
\f[B]Precondición:\f[] cierto
.br
\f[B]Postcondición:\f[] Se busca la ruta más corta y más a la derecha (mirando río arriba) en la que el barco vende/compra todos sus productos, si no se cumple, en la que vende/compra más productos.
.br
\f[B]Coste:\f[] Lineal respecto al número de ciudades
.br
\f[B]Hipótesis de Inducción:\f[]
.br
\f[B]Función de cota:\f[] El árbol está vacío.
.fam C
.TS
box center tab(|);
lw90.
T{
\m[groffhl_0]\m[]\m[groffhl_1]void\m[] \m[groffhl_0]\m[]\m[groffhl_2]Cuenca\m[]\m[groffhl_0]\m[]\m[groffhl_2]::\m[]\m[groffhl_0]\m[]\m[groffhl_2]buscar_ruta_recursiva\m[]\m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]BinTree\m[]\m[groffhl_2]<\m[]\m[groffhl_0]string\m[]\m[groffhl_2]>\m[] \m[groffhl_0]t\m[]\m[groffhl_2],\m[] \m[groffhl_0]stack\m[]\m[groffhl_2]<\m[]\m[groffhl_0]string\m[]\m[groffhl_2]> &\m[]\m[groffhl_0]ruta\m[]\m[groffhl_2],\m[]
      \m[groffhl_0]\m[]\m[groffhl_1]int\m[] \m[groffhl_0]\m[]\m[groffhl_2]&\m[]\m[groffhl_0]comprar\m[]\m[groffhl_2],\m[] \m[groffhl_0]\m[]\m[groffhl_1]int\m[] \m[groffhl_0]\m[]\m[groffhl_2]&\m[]\m[groffhl_0]vender\m[]\m[groffhl_2])\m[] \m[groffhl_0]\m[]\m[groffhl_1]const\m[]
\m[groffhl_0]\m[]\m[groffhl_2]{\m[]
\m[groffhl_0]\m[]  \m[groffhl_3]if\m[] \m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]\m[]\m[groffhl_3]not\m[] \m[groffhl_0]t\m[]\m[groffhl_2].\m[]\m[groffhl_0]\m[]\m[groffhl_2]empty\m[]\m[groffhl_0]\m[]\m[groffhl_2]())\m[]
\m[groffhl_0]\m[]  \m[groffhl_2]{\m[]
\m[groffhl_0]\m[]    \m[groffhl_1]int\m[] \m[groffhl_0]idc\m[] \m[groffhl_2]=\m[] \m[groffhl_0]barco\m[]\m[groffhl_2].\m[]\m[groffhl_0]\m[]\m[groffhl_2]consultar_id_comprar\m[]\m[groffhl_0]\m[]\m[groffhl_2]();\m[]
\m[groffhl_0]\m[]    \m[groffhl_1]int\m[] \m[groffhl_0]idv\m[] \m[groffhl_2]=\m[] \m[groffhl_0]barco\m[]\m[groffhl_2].\m[]\m[groffhl_0]\m[]\m[groffhl_2]consultar_id_vender\m[]\m[groffhl_0]\m[]\m[groffhl_2]();\m[]
\m[groffhl_0]\m[]    \m[groffhl_3]if\m[] \m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]ciudades\m[]\m[groffhl_2].\m[]\m[groffhl_0]\m[]\m[groffhl_2]at\m[]\m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]t\m[]\m[groffhl_2].\m[]\m[groffhl_0]\m[]\m[groffhl_2]value\m[]\m[groffhl_0]\m[]\m[groffhl_2]()).\m[]\m[groffhl_0]\m[]\m[groffhl_2]tiene_producto\m[]\m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]productos\m[]\m[groffhl_2].\m[]\m[groffhl_0]\m[]\m[groffhl_2]at\m[]\m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]idc\m[]\m[groffhl_2])))\m[]
\m[groffhl_0]\m[]    \m[groffhl_2]{\m[]
\m[groffhl_0]      pair\m[]\m[groffhl_2]<\m[]\m[groffhl_0]\m[]\m[groffhl_1]int\m[]\m[groffhl_0]\m[]\m[groffhl_2],\m[] \m[groffhl_0]\m[]\m[groffhl_1]int\m[]\m[groffhl_0]\m[]\m[groffhl_2]>\m[] \m[groffhl_0]atributos\m[] \m[groffhl_2]=\m[] \m[groffhl_0]ciudades\m[]\m[groffhl_2].\m[]\m[groffhl_0]\m[]\m[groffhl_2]at\m[]\m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]t\m[]\m[groffhl_2].\m[]\m[groffhl_0]\m[]\m[groffhl_2]value\m[]\m[groffhl_0]\m[]\m[groffhl_2]()).\m[]\m[groffhl_0]\m[]\m[groffhl_2]consultar_producto\m[]\m[groffhl_0]\m[]\m[groffhl_2](
                      \m[]\m[groffhl_0]productos\m[]\m[groffhl_2].\m[]\m[groffhl_0]\m[]\m[groffhl_2]at\m[]\m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]barco\m[]\m[groffhl_2].\m[]\m[groffhl_0]\m[]\m[groffhl_2]consultar_id_comprar\m[]\m[groffhl_0]\m[]\m[groffhl_2]()));\m[]
.br
      \m[groffhl_4]// posee - necesita\m[]
\m[groffhl_0]\m[]      \m[groffhl_1]int\m[] \m[groffhl_0]diferencia\m[] \m[groffhl_2]=\m[] \m[groffhl_0]atributos\m[]\m[groffhl_2].\m[]\m[groffhl_0]first\m[] \m[groffhl_2]-\m[] \m[groffhl_0]atributos\m[]\m[groffhl_2].\m[]\m[groffhl_0]second\m[]\m[groffhl_2];\m[] \m[groffhl_0]\m[]
\m[groffhl_0]\m[]      \m[groffhl_3]if\m[] \m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]diferencia\m[] \m[groffhl_2]>\m[] \m[groffhl_0]\m[]\m[groffhl_5]0\m[]\m[groffhl_0]\m[]\m[groffhl_2])\m[] \m[groffhl_0]comprar\m[] \m[groffhl_2]-=\m[] \m[groffhl_0]\m[]\m[groffhl_2]min\m[]\m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]diferencia\m[]\m[groffhl_2],\m[] \m[groffhl_0]comprar\m[]\m[groffhl_2]);\m[]
\m[groffhl_0]\m[]    \m[groffhl_2]}\m[]
\m[groffhl_0]\m[]    \m[groffhl_3]if\m[] \m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]ciudades\m[]\m[groffhl_2].\m[]\m[groffhl_0]\m[]\m[groffhl_2]at\m[]\m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]t\m[]\m[groffhl_2].\m[]\m[groffhl_0]\m[]\m[groffhl_2]value\m[]\m[groffhl_0]\m[]\m[groffhl_2]()).\m[]\m[groffhl_0]\m[]\m[groffhl_2]tiene_producto\m[]\m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]productos\m[]\m[groffhl_2].\m[]\m[groffhl_0]\m[]\m[groffhl_2]at\m[]\m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]idv\m[]\m[groffhl_2])))\m[]
\m[groffhl_0]\m[]    \m[groffhl_2]{\m[]
\m[groffhl_0]      pair\m[]\m[groffhl_2]<\m[]\m[groffhl_0]\m[]\m[groffhl_1]int\m[]\m[groffhl_0]\m[]\m[groffhl_2],\m[] \m[groffhl_0]\m[]\m[groffhl_1]int\m[]\m[groffhl_0]\m[]\m[groffhl_2]>\m[] \m[groffhl_0]atributos\m[] \m[groffhl_2]=\m[] \m[groffhl_0]ciudades\m[]\m[groffhl_2].\m[]\m[groffhl_0]\m[]\m[groffhl_2]at\m[]\m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]t\m[]\m[groffhl_2].\m[]\m[groffhl_0]\m[]\m[groffhl_2]value\m[]\m[groffhl_0]\m[]\m[groffhl_2]()).\m[]\m[groffhl_0]\m[]\m[groffhl_2]consultar_producto\m[]\m[groffhl_0]\m[]\m[groffhl_2](
                      \m[]\m[groffhl_0]productos\m[]\m[groffhl_2].\m[]\m[groffhl_0]\m[]\m[groffhl_2]at\m[]\m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]barco\m[]\m[groffhl_2].\m[]\m[groffhl_0]\m[]\m[groffhl_2]consultar_id_vender\m[]\m[groffhl_0]\m[]\m[groffhl_2]()));\m[]
.br
      \m[groffhl_4]// necesita - posee\m[]
\m[groffhl_0]\m[]      \m[groffhl_1]int\m[] \m[groffhl_0]diferencia\m[] \m[groffhl_2]=\m[] \m[groffhl_0]atributos\m[]\m[groffhl_2].\m[]\m[groffhl_0]second\m[] \m[groffhl_2]-\m[] \m[groffhl_0]atributos\m[]\m[groffhl_2].\m[]\m[groffhl_0]first\m[]\m[groffhl_2];\m[] \m[groffhl_0]\m[]
\m[groffhl_0]\m[]      \m[groffhl_3]if\m[] \m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]diferencia\m[] \m[groffhl_2]>\m[] \m[groffhl_0]\m[]\m[groffhl_5]0\m[]\m[groffhl_0]\m[]\m[groffhl_2])\m[] \m[groffhl_0]vender\m[] \m[groffhl_2]-=\m[] \m[groffhl_0]\m[]\m[groffhl_2]min\m[]\m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]diferencia\m[]\m[groffhl_2],\m[] \m[groffhl_0]vender\m[]\m[groffhl_2]);\m[]
\m[groffhl_0]\m[]    \m[groffhl_2]}\m[]
\m[groffhl_0]\m[]
.sp
\m[groffhl_0]\m[]    \m[groffhl_4]// NOTE: always comprar >= 0 and vender >= 0;\m[]
\m[groffhl_0]\m[]    \m[groffhl_3]if\m[] \m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]comprar\m[] \m[groffhl_2]!=\m[] \m[groffhl_0]\m[]\m[groffhl_5]0\m[] \m[groffhl_0]\m[]\m[groffhl_3]and\m[] \m[groffhl_0]vender\m[] \m[groffhl_2]!=\m[] \m[groffhl_0]\m[]\m[groffhl_5]0\m[]\m[groffhl_0]\m[]\m[groffhl_2])\m[]
\m[groffhl_0]\m[]    \m[groffhl_2]{\m[]
\m[groffhl_0]\m[]      \m[groffhl_1]int\m[] \m[groffhl_0]ci\m[] \m[groffhl_2]=\m[] \m[groffhl_0]comprar\m[]\m[groffhl_2];\m[]
\m[groffhl_0]\m[]      \m[groffhl_1]int\m[] \m[groffhl_0]vi\m[] \m[groffhl_2]=\m[] \m[groffhl_0]vender\m[]\m[groffhl_2];\m[]
\m[groffhl_0]      stack\m[]\m[groffhl_2]<\m[]\m[groffhl_0]string\m[]\m[groffhl_2]>\m[] \m[groffhl_0]ruta_izquierda\m[]\m[groffhl_2];\m[]
\m[groffhl_0]\m[]      \m[groffhl_2]buscar_ruta_recursiva\m[]\m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]t\m[]\m[groffhl_2].\m[]\m[groffhl_0]\m[]\m[groffhl_2]left\m[]\m[groffhl_0]\m[]\m[groffhl_2](),\m[] \m[groffhl_0]ruta_izquierda\m[]\m[groffhl_2],\m[] \m[groffhl_0]ci\m[]\m[groffhl_2],\m[] \m[groffhl_0]vi\m[]\m[groffhl_2]);\m[]
\m[groffhl_0]\m[]
.sp
\m[groffhl_0]\m[]      \m[groffhl_1]int\m[] \m[groffhl_0]cd\m[] \m[groffhl_2]=\m[] \m[groffhl_0]comprar\m[]\m[groffhl_2];\m[]
\m[groffhl_0]\m[]      \m[groffhl_1]int\m[] \m[groffhl_0]vd\m[] \m[groffhl_2]=\m[] \m[groffhl_0]vender\m[]\m[groffhl_2];\m[]
\m[groffhl_0]      stack\m[]\m[groffhl_2]<\m[]\m[groffhl_0]string\m[]\m[groffhl_2]>\m[] \m[groffhl_0]ruta_derecha\m[]\m[groffhl_2];\m[]
\m[groffhl_0]\m[]      \m[groffhl_2]buscar_ruta_recursiva\m[]\m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]t\m[]\m[groffhl_2].\m[]\m[groffhl_0]\m[]\m[groffhl_2]right\m[]\m[groffhl_0]\m[]\m[groffhl_2](),\m[] \m[groffhl_0]ruta_derecha\m[]\m[groffhl_2],\m[] \m[groffhl_0]cd\m[]\m[groffhl_2],\m[] \m[groffhl_0]vd\m[]\m[groffhl_2]);\m[]
\m[groffhl_0]\m[]
.sp
\m[groffhl_0]\m[]      \m[groffhl_3]if\m[] \m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]\m[]\m[groffhl_3]not\m[] \m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]comprar\m[] \m[groffhl_2]==\m[] \m[groffhl_0]ci\m[] \m[groffhl_3]and\m[] \m[groffhl_0]ci\m[] \m[groffhl_2]==\m[] \m[groffhl_0]cd\m[] \m[groffhl_3]and\m[] \m[groffhl_0]vender\m[] \m[groffhl_2]==\m[] \m[groffhl_0]vi\m[] \m[groffhl_3]and\m[] \m[groffhl_0]vi\m[] \m[groffhl_2]==\m[] \m[groffhl_0]vd\m[]\m[groffhl_2]))\m[]
\m[groffhl_0]\m[]      \m[groffhl_2]{\m[]
\m[groffhl_0]\m[]        \m[groffhl_3]if\m[] \m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]ci\m[] \m[groffhl_2]+\m[] \m[groffhl_0]vi\m[] \m[groffhl_2]<\m[] \m[groffhl_0]cd\m[] \m[groffhl_2]+\m[] \m[groffhl_0]vd\m[]\m[groffhl_2])\m[]
\m[groffhl_0]\m[]        \m[groffhl_2]{\m[]
\m[groffhl_0]          comprar\m[] \m[groffhl_2]=\m[] \m[groffhl_0]ci\m[]\m[groffhl_2];\m[]
\m[groffhl_0]          vender\m[] \m[groffhl_2]=\m[] \m[groffhl_0]vi\m[]\m[groffhl_2];\m[]
\m[groffhl_0]          ruta\m[] \m[groffhl_2]=\m[] \m[groffhl_0]ruta_izquierda\m[]\m[groffhl_2];\m[]
\m[groffhl_0]\m[]        \m[groffhl_2]}\m[]

T}
.TE
.TS
box center tab(|);
lw90.
T{

\m[groffhl_0]\m[]        \m[groffhl_3]else if\m[] \m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]cd\m[] \m[groffhl_2]+\m[] \m[groffhl_0]vd\m[] \m[groffhl_2]<\m[] \m[groffhl_0]ci\m[] \m[groffhl_2]+\m[] \m[groffhl_0]vi\m[]\m[groffhl_2])\m[]
\m[groffhl_0]\m[]        \m[groffhl_2]{\m[]
\m[groffhl_0]          comprar\m[] \m[groffhl_2]=\m[] \m[groffhl_0]cd\m[]\m[groffhl_2];\m[]
\m[groffhl_0]          vender\m[] \m[groffhl_2]=\m[] \m[groffhl_0]vd\m[]\m[groffhl_2];\m[]
\m[groffhl_0]          ruta\m[] \m[groffhl_2]=\m[] \m[groffhl_0]ruta_derecha\m[]\m[groffhl_2];\m[]
\m[groffhl_0]\m[]        \m[groffhl_2]}\m[]
\m[groffhl_0]\m[]        \m[groffhl_3]else\m[] \m[groffhl_0]\m[]\m[groffhl_4]// if (ci + vi == cd + vd)\m[]
\m[groffhl_0]\m[]        \m[groffhl_2]{\m[]
\m[groffhl_0]\m[]          \m[groffhl_3]if\m[] \m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]ruta_izquierda\m[]\m[groffhl_2].\m[]\m[groffhl_0]\m[]\m[groffhl_2]size\m[]\m[groffhl_0]\m[]\m[groffhl_2]() <=\m[] \m[groffhl_0]ruta_derecha\m[]\m[groffhl_2].\m[]\m[groffhl_0]\m[]\m[groffhl_2]size\m[]\m[groffhl_0]\m[]\m[groffhl_2]())\m[]
\m[groffhl_0]\m[]          \m[groffhl_2]{\m[]
\m[groffhl_0]            comprar\m[] \m[groffhl_2]=\m[] \m[groffhl_0]ci\m[]\m[groffhl_2];\m[]
\m[groffhl_0]            vender\m[] \m[groffhl_2]=\m[] \m[groffhl_0]vi\m[]\m[groffhl_2];\m[]
\m[groffhl_0]            ruta\m[] \m[groffhl_2]=\m[] \m[groffhl_0]ruta_izquierda\m[]\m[groffhl_2];\m[]
\m[groffhl_0]\m[]          \m[groffhl_2]}\m[]
\m[groffhl_0]\m[]          \m[groffhl_3]else\m[]
\m[groffhl_0]\m[]          \m[groffhl_2]{\m[]
\m[groffhl_0]            comprar\m[] \m[groffhl_2]=\m[] \m[groffhl_0]cd\m[]\m[groffhl_2];\m[]
\m[groffhl_0]            vender\m[] \m[groffhl_2]=\m[] \m[groffhl_0]vd\m[]\m[groffhl_2];\m[]
\m[groffhl_0]            ruta\m[] \m[groffhl_2]=\m[] \m[groffhl_0]ruta_derecha\m[]\m[groffhl_2];\m[]
\m[groffhl_0]\m[]          \m[groffhl_2]}\m[]
\m[groffhl_0]\m[]        \m[groffhl_2]}\m[]
\m[groffhl_0]\m[]      \m[groffhl_2]}\m[]
\m[groffhl_0]\m[]    \m[groffhl_2]}\m[]
\m[groffhl_0]    ruta\m[]\m[groffhl_2].\m[]\m[groffhl_0]\m[]\m[groffhl_2]push\m[]\m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]t\m[]\m[groffhl_2].\m[]\m[groffhl_0]\m[]\m[groffhl_2]value\m[]\m[groffhl_0]\m[]\m[groffhl_2]());\m[]
\m[groffhl_0]\m[]  \m[groffhl_2]}\m[]
.br
\m[groffhl_0]\m[]\m[groffhl_2]}\m[]\m[groffhl_0]\m[]

T}
.TE
.fam H
.nr test 0 1
.nr PI 3n
.ft B
Justificación del método con respecto a la hipótesis de inducción.
.IP \n+[test]
Suponemos que la Pre es cierto si al principio de la ejecución de la función y que las instrucciones
nos traen los casos directos. Entonces se cumple la Post:
