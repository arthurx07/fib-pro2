// int size(node_arbre* node) const
// {
//   if (node == NULL) return 0;
//   return 1 + size(node->segE) + size(node->segD);
// }

node_arbre* sub_arrel(node_arbre* node, const T& x, int& size)
{
  if (node == NULL) return NULL;
  if (node->info == x) return copia_node_arbre(node);

  int lsize, rsize;
  lsize = rsize = ++size;
  node_arbre* ne = sub_arrel(node->segE, x, lsize);
  node_arbre* nd = sub_arrel(node->segD, x, rsize);
  
  if (ne != NULL and rsize >= lsize) return ne;
  else return nd;
}

void sub_arrel(Arbre& asub, const T& x)
/* Pre: p.i. = A, asub es buit */
/* Post: si A conte x, asub es el subarbre d'A resultat de la cerca;
  si A no conte x, asub es buit */
{
  int s = 0;
  asub.primer_node = sub_arrel(primer_node, x, s);
}
