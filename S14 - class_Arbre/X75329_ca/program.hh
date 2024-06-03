int freq(const node_arbre* node, const T& x) const {
  if (node == NULL) return 0;

  return (node->info == x) + freq(node->segE, x) + freq(node->segD, x);
}

int freq(const T& x) const
/* Pre: cert */
/* Post: el resultat indica el nombre d'aparicions de x en el p.i. */
{
  return freq(primer_node, x);
}
