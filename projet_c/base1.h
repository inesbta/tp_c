void insert(LISTE ** firstl,DATA d)
{
  LISTE * pp;
pp = (LISTE*)malloc(sizeof(LISTE));
pp->d =d;
pp->nextl = *firstl;
*firstl = pp;
}
void load_liste(COMPOS * racine,LISTE * firstl)
{
  COMPOS * pr;
  pr = racine;
  if(pr)
  {
  if(!(pr->fils))
   insert(&firstl,pr->d);
  else
   load_liste(pr->fils);
   if(pr->frere)
   load_liste(pr->frere);
   }
}

COMPOS * seek_noeud(COMPOS * racine, int key_compose)
{
  if(racine)
 {
if((racine->d.code_compose) == key_compose)
  return(racine);
if(pk = seek_noeud(racine->frere,key_compose))
  return(pk);
return(seek_noeud(racine->fils,key_compose));
 }
return(NULL);
}

LISTE * load_matiere_necessaire(COMPOS * racine,int key_compose)
{
  LISTE * firstl;COMPOS * ps; COMPOS * pc;
  firstl = NULL;
if(ps = seek_noeud(racine,key_compose))
{
  if(pc = ps->fils)
  {
  load_liste(pc,firstl);
  return(firstl);
  }
  printf("ce produit est une matiere premiere");
  return(NULL);
}
printf("ce code ne correspond à aucun produit");
return(NULL);
}
LISTE * get_prev(LISTE * firstl,LISTE *p)
{
for(prev=firstl,p1=firstl->nextl;p1;p1 = p1->nextl,prev = prev->nextl)
{
  if(p1 == p)
  return(prev);
}
return(NULL);
}

void delete_noeud(LISTE ** firstl,LISTE * p)
{
   LISTE * prev;
 prev = get_prev(*firstl,p)
 prev->nextl = p->nextl;
 free(p);
}

void load_liste_sans_redo(LISTE * firstl)
{
  int s; LISTE * p; LISTE * pp;
  for(p = firstl; p ;p = p->nextl)
  {
    s=0;
    for(pp=p->nextl;pp;pp=pp->nextl)
    {
    if((p->d.code_compose) == (pp->d.code_compose))
    s += pp->quantite;
    delete_noeud(&firstl,pp);
  }
  p->d.quantite +=s;
  }
}
void liste_matiere_necessaire(COMPOS * racine,int key_compose)
{
  LISTE * firstl;
firstl = load_matiere_necessaire(racine,key_compose);
if(firstl)
 {
 load_liste_sans_redo(firstl);
  printf("Les matieres premiers necessaires pour former le composé %d sont \n",key_compose);
  for(p=first;p;p = p->nextl)
  {
    printf("%d du composant %d\n",p->d.quantite,p->d.code_compose);
  }
 }
}
