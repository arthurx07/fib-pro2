node_arbreNari* arbsuma(node_arbreNari* node) const
{
  if (node == NULL) return NULL;

  node_arbreNari* n = new node_arbreNari;
  n->info = node->info;

  n->seg = vector<node_arbreNari*>(N);
  for (int i = 0; i < N; ++i)
  {
    // at this point n->seg[i] is always NULL, has just been declared
    n->seg[i] = arbsuma(node->seg[i]);
    // at this point we need to test if n->seg[i] is NULL
    if (n->seg[i] != NULL) n->info += n->seg[i]->info;
  }

  return n;
}

void arbsuma(ArbreNari& asum) const
/* Pre: cert */
/* Post: asum és un arbre amb la mateixa estructura que el p.i.
         i cada node és la suma del node corresponent al p.i
         i tots els seus descendents al p.i. */
{
  asum.primer_node = arbsuma(primer_node);
}
