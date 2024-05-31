INSTRUCCIONS:
- individual
- metodologia de disseny modular i produir una implementació eficient en C++
    (veure secció 2.3, **Metodologia del disseny modular**)
- contenidors: stack, queue, list, set, map, bintree
- **no fer servir:** punters, retornar referències (return *var), ni fer servir altres
    elements de C++ no vistos prèviament de les últimes sessions
- exemple documentació: **/assig/pro2/sessio10/SOL_BINTREE**
- documentació doxygen incompleta serà fortament penalitzada


ZEROS:
- no compila (lliurar MAKEFILE)
- no fa servir flag **-fno-extended-identifiers** al MAKEFILE
- no passa cap joc de proves
- té indicis clars de comportament fraudulent
- la nota manual (40%) és zero: l'absència de documentació generada amb doxygen,
    que incorpori tant l'especificació com la implementació.

AUTOMÀTICA
(10/m)*n/(2-p), p val 1 si el MAKEFILE usa correctament el flag **-D_GLIBCXX_DEBUG** (0 altrament)

DISSENY MODULAR I ESPECIFICACIÓ
- **especificació completa i correcta**
    - pre/post operacions importants
    - const, static, etc..
    - ús de tipus que ocupen molt l'espai en pas de paràmetres per valor o retorn de funcions
- **INDEPENDÈNCIA** especificació/implementació
- descomposició en classes lògica i clara i aplicar una mínima modularitat
- els mètodes pertanyen a les classes adequades
- bona distinció entre mètodes privats i públics

IMPLEMENTACIÓ
- elecció apropiada de la **representació de les classes**, el seu impacte als punts
    següents referits a l'**eficiència**
- eficiència en temps
- bon us de l'espai: evitar redundàncies / info innecessària
- bona descomposició funcionalitat i parametrització, impacte en la legibilitat
    del codi, facilitat per justificar-ne la correcció, reutilització del codi
    evitant redundàncies, etc.
- elecció apropiada d'**esquemes algorísmics** (recorregut, cerca o variants)
- la claretat, legibilitat i bona organització del codi
- de manera global: BON ÚS DEL **DOXYGEN** com a eina de documentació tant per a l'especificació
    dels mètodes públics i privats com per als atributs(privats).

JUSTIFICACIONS (20%)
- presentació de document que conté els dos mètodes, un iteratiu i l'altre recursiu
- iteratiu: especificació, invariant i justificació respecte l'invariant
- recursiu: especificació, hipòtesi d'inducció i justificació respecte l'hipòtesi d'inducció.
