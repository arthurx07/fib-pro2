T max_suma_cami(const node_arbre* node) const
{
  if (node == NULL) return 0;

  T suma_esq = max_suma_cami(node->segE);
  T suma_dre = max_suma_cami(node->segD);

  return node->info + max(suma_esq, suma_dre);
}

T max_suma_cami() const
/* Pre: el parametre implicit no es buit */
/* Post: el resultat es la suma del cami de suma maxima del parametre implicit */
{
  return max_suma_cami(primer_node);
}
