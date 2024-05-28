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
\# En AMBOS CASOS hay que justificar la finalización de las funciones mediante funciones de cota
\#  o equivalentes
\# Seguir los apuntes de 'Correctesa de Programes Iteratius i Programació Recursiva'
.NH
Método iterativo: Comerciar
.LP
.sp
\f[B]Precondición:\f[] \f[C]l1=L1\f[] (inventario del parámetro implícito) y \f[C]l2=L2\f[] (inventario de Ciudad &c).
.sp
\f[B]Postcondición:\f[] \f[C]l1\f[] y \f[C]l2\f[] son los inventarios resultantes de haber comerciado todos los productos
con la otra ciudad.
.sp
\f[B]Coste:\f[] Lineal respecto al tamaño más pequeño en relación al parámetro impícito y la Ciudad c.
.sp
\f[B]Invariante:\f[] \f[C]it1\f[] apunta a un elemento de \f[C]inventario\f[] o a \f[C]inventario.end()\f[].
Cada producto de \f[C]inventario\f[] des del inicio hasta la posición anterior a la que marca \f[C]it1\f[] ya
ha sido comerciado con la Ciudad c. A partir de \f[C]it1\f[] hasta el final del inventario los productos aún
no han sido comerciados. La invariante se define de manera análoga para \f[C]it2\f[] i \f[C]c.inventario\f[].
.sp
\f[B]Función de cota:\f[] A cada iteración decrece el tamaño de la sublista entre \f[C]it1\f[] y
\f[C]inventario.end()\f[] o entre \f[C]it2\f[] y \f[C]c.inventario.end()\f[].
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
.SH
.bp
Justificación del método con respecto a la invariante.
.nr test 0 1
.nr PI 3n
.IP \n+[test]
.ft B
Cuando se llega al bucle por primera vez, la invariante se cumple.
.ft
.br
Cuando se llega al bucle por primera vez, \f[C]it1=inventario.begin()\f[] y \f[C]it2=c.inventario.begin()\f[].
Por lo tanto, tal y como dice la invariante aún no se ha comerciado ningún producto entre las dos ciudades.
.sp
.IP \n+[test]
.ft B
Suponemos la invariante, y vemos que la condición del bucle se evalua en cierto. Entonces, después de
ejecutar el cuerpo del bucle, la invariante se vuelve a cumplir.
.ft
.br
Si los productos apuntados por \f[C]it1\f[] e \f[C]it2\f[] son el mismo se calculan los sobrantes para el inventario del parámetro implícito y el inventario
de la Ciudad c (\f[C]int dar\f[] e \f[C]int rec\f[], respectivamente). Entonces, se calcula quien tiene que
dar y recibir y las cantidades de productos y se realiza el cambio (asignaciones al mínimo/máximo/cero y resta/suma
de la variable \f[C]rec\f[]). A continuación se reajustan los pesos y volúmenes totales para ambas ciudades.
Finalmente se mueven \f[C]it1\f[] e \f[C]it2\f[] a la siguiente posición, y entonces se cumple la invariante de nuevo.
.br
Si los productos apuntados por \f[C]it1\f[] e \f[C]it2\f[] se mueve \f[C]it1\f[] o \f[C]it2\f[] a la siguiente
posición, según el producto apuntado con identificador menor, y se procede a cumplir de nuevo la invariante.
.sp
.IP \n+[test]
.ft B
Suponemos la invariante, y que la condición de entrada al bucle falla. Entonces, vemos que la postcondición
se cumple.
.ft
.br
Que la condición de entrada al bucle falle implica que o bien \f[C]it1\f[] o bien \f[C]it2\f[] son iguales al
final de su respectiva lista. Siguiendo la invariante esto quiere decir que se ha iterado por todos los productos
de la lista con menor tamaño, y todos ellos (los que también estan en la otra lista) han sido comerciados con la
otra ciudad. Por tanto la Postcondición se cumple.
.sp
.IP \n+[test]
.ft B
Suponemos la invariante, y que la condición de entrada al bucle se cumple. Entonces, después de ejecutar el
cuerpo del bucle la función de cota se evalua a algo estrictamente menor.
.ft
.br
A cada iteración del bucle o bien se mueve \f[C]it1\f[] o bien \f[C]it2\f[] a la siguiente posición de la lista.
Cosa que hace que la función de cota se evalúe a algo estrictamente menor.
.sp
.IP \n+[test]
.ft B
La invariante implica que la función de cota no se evalua a algo menor que 0. El bucle no es infinito
.ft
.br
La función de cota se evalua en cero cuando \f[C]it1=inventario.end()\f[]. Siguiendo la invariante la función
de cota no puede evaluarse a nada menor debido a que \f[C]it1\f[] no puede apuntar a nada más allá de la dirección
de memoria de \f[C]inventario.end()\f[]. Se define de manera análoga para \f[C]it2\f[].

.bp
.NH
Método recursivo: Hacer Viaje
.LP
.sp
\f[B]Precondición:\f[] comprar >= 0 y vender >= 0
.sp
\f[B]Postcondición:\f[] La pila \f[I]ruta\f[] es la ruta más corta y más a la derecha (mirando río arriba) en la que el barco vende/compra todos sus productos, si no se cumple, en la que vende/compra más productos.
.sp
\f[B]Coste:\f[] Lineal respecto al número de ciudades
.sp
\f[B]Hipótesis de Inducción:\f[] \f[I]ruta_izquierda\f[] y \f[I]ruta_derecha\f[] cumplen ambos la Postcondición del árbol, pero solo hasta el nodo actual.
.sp
\f[B]Función de cota:\f[] En cada paso recursivo el tamaño (número de nodos) del árbol \f[I]t\f[] se hace más pequeño, hasta llegar al árbol vacío (caso base).
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
\m[groffhl_0]\m[]    \m[groffhl_4]// nota: siempre comprar >= 0 y vender >= 0\m[]
\m[groffhl_0]\m[]    \m[groffhl_3]if\m[] \m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]comprar\m[] \m[groffhl_2]>\m[] \m[groffhl_0]\m[]\m[groffhl_5]0\m[] \m[groffhl_0]\m[]\m[groffhl_3]or\m[] \m[groffhl_0]vender\m[] \m[groffhl_2]>\m[] \m[groffhl_0]\m[]\m[groffhl_5]0\m[]\m[groffhl_0]\m[]\m[groffhl_2])\m[]
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

T}
.TE
.TS
box center tab(|);
lw90.
T{

\m[groffhl_0]\m[]      \m[groffhl_3]if\m[] \m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]\m[]\m[groffhl_3]not\m[] \m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]comprar\m[] \m[groffhl_2]==\m[] \m[groffhl_0]ci\m[] \m[groffhl_3]and\m[] \m[groffhl_0]ci\m[] \m[groffhl_2]==\m[] \m[groffhl_0]cd\m[] \m[groffhl_3]and\m[] \m[groffhl_0]vender\m[] \m[groffhl_2]==\m[] \m[groffhl_0]vi\m[] \m[groffhl_3]and\m[] \m[groffhl_0]vi\m[] \m[groffhl_2]==\m[] \m[groffhl_0]vd\m[]\m[groffhl_2]))\m[]
\m[groffhl_0]\m[]      \m[groffhl_2]{\m[]
\m[groffhl_0]\m[]        \m[groffhl_3]if\m[] \m[groffhl_0]\m[]\m[groffhl_2](\m[]\m[groffhl_0]ci\m[] \m[groffhl_2]+\m[] \m[groffhl_0]vi\m[] \m[groffhl_2]<\m[] \m[groffhl_0]cd\m[] \m[groffhl_2]+\m[] \m[groffhl_0]vd\m[]\m[groffhl_2])\m[]
\m[groffhl_0]\m[]        \m[groffhl_2]{\m[]
\m[groffhl_0]          comprar\m[] \m[groffhl_2]=\m[] \m[groffhl_0]ci\m[]\m[groffhl_2];\m[]
\m[groffhl_0]          vender\m[] \m[groffhl_2]=\m[] \m[groffhl_0]vi\m[]\m[groffhl_2];\m[]
\m[groffhl_0]          ruta\m[] \m[groffhl_2]=\m[] \m[groffhl_0]ruta_izquierda\m[]\m[groffhl_2];\m[]
\m[groffhl_0]\m[]        \m[groffhl_2]}\m[]
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
.SH
.bp
Justificación del método con respecto a la hipótesis de inducción.
.IP \n+[test]
.ft B
Suponemos que la Precondición es cierta al principio de la ejecución de la función y que las instrucciones
nos traen los casos directos. Entonces se cumple la Postcondición:
.ft
.br
Tenemos dos casos base:
.br
1. \f[B]El árbol está vacío\f[]: El método no hace nada y se cumple la Post.
.br
2. Después de ejecutar las instrucciones iniciales, donde se ajustan los valores de \f[C]comprar\f[] y
    \f[C]vender\f[] con respecto a la Ciudad del nodo actual \f[CB]comprar=0\f[] \f[B]y\f[] \f[CB]vender=0\f[]. En este punto se han
    comprado y vendido todas las unidades que el barco quería comprar/vender y por tanto solo queda
    añadir la Ciudad (nodo) actual a la cima de la pila \f[C]ruta\f[] para que se cumpla la Postcondición.
.sp
.IP \n+[test]
.ft B
Suponemos que la Precondición se cumple al principio de ejecutar la función y que las instrucciones nos llevan
al caso recursivo. Entonces vemos que se cumple la Precondición adaptada a los parámetros de la llamada.
.ft
.br
La precondición se cumple ya que el caso recursivo se ejecutará si solo si \f[C]comprar > 0\f[] o \f[C]vender > 0\f[].
.sp
.IP \n+[test]
.ft B
Suponemos que la Precondición se cumple al principio de la ejecución de la función y que las instrucciones
nos traen al caso recursivo. Entonces, suponiendo que por Hipótesis de Inducción la Postcondición adaptada a los
parámetros se cumple y que se ejecutan las instrucciones restantes después de la llamada recursiva, la Postcondición
se cumple.
.ft
.br
En el caso que no se haya comprado o vendido nada más allá del nodo actual, se añade la Ciudad (nodo) actual 
a la cima de la pila \f[C]ruta\f[] para que se cumpla la Postcondición.
.br
De manera contraria, si se ha comerciado con el barco más allá del nodo actual se asigna la ruta en la que se haya comerciado más con el barco
en total (ya sea la ruta del árbol izquierdo o derecho) a la ruta actual. Entonces, después de haber ajustado el número restante
de productos para comprar y vender se añade la Ciudad (nodo) actual a la cima de la pila \f[C]ruta\f[] para que
se cumpla la Postcondición.
.br
Finalmente, cabe la posibilidad de que ambas en la ruta izquierda y derecha queden al barco le queden el mismo número de productos
para comprar y vender (en total). En este caso se asigna la ruta más corta de ambas a la ruta actual. Entonces, después de haber ajustado el número restante
de productos para comprar y vender se añade la Ciudad (nodo) actual a la cima de la pila \f[C]ruta\f[] para que
se cumpla la Postcondición.
.sp
.IP \n+[test]
.ft B
Suponemos que la Precondición es cierta al principio de la ejecución de la función y que las instrucciones nos llevan al
caso recursivo. Entonces vemos que la función de cota para los parámetros de la llamada es menor que la
función de cota para los parámetros iniciales.
.ft
.br
Si se ejecuta el caso recursivo el parámetro de llamada sobre el que se realiza la recursión, el árbol \f[C]t\f[],
se divide en \f[C]t.left()\f[] y \f[C]t.right\f[]. Entonces, en ser el parámetro de llamada para la siguiente recursión
uno de estos dos árboles, con tamaño de una unidad menor respecto al árbol inicial, estos se acercan más al
tamaño de un árbol vacío (condición que se ha de cumplir para la que la función de cota se evalúe a cero).
.sp
.IP \n+[test]
.ft B
Suponemos la Precondición. Entonces la función de cota se evalúa a mayor o igual que cero.
.ft
.br
La función de cota se evalúa al tamaño de un árbol, que por la naturaleza de éste solo puede ser >= 0. La mínima
cantidad de nodos que pueden existir es que no exista ninguno, y por tanto que el árbol no exista (la función de cota se evalúa a cero).
