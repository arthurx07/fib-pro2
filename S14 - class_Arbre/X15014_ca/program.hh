node_arbre* arb_sumes(node_arbre* node) const
{
  if (node == NULL) return NULL;

  node_arbre* n = new node_arbre;
  n->info = node->info;

  n->segE = arb_sumes(node->segE);
  if (n->segE != NULL) n->info += n->segE->info;
  n->segD = arb_sumes(node->segD);
  if (n->segD != NULL) n->info += n->segD->info;

  return n;
}

void arb_sumes(Arbre<int> &asum) const
/* Pre: cert */
/* Post: l'arbre asum és l'arbre suma del p.i. */
{
  asum.primer_node = arb_sumes(primer_node);
}
