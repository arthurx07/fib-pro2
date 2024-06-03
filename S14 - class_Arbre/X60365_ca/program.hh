bool buscar(const node_arbreGen* node, const T& x) const
{
  if (node == NULL) return false;

  bool found = (node->info == x);
  for (int i = 0; not found and i < node->seg.size(); ++i)
    found = buscar(node->seg[i], x);

  return found;
}

bool buscar(const T& x) const
/* Pre: cert */
/* Post: el resultat indica si x es troba al p.i. o no */
{
  return buscar(primer_node, x);
}
