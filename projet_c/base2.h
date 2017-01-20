void insert_fiche(FICHE ** firstfi,int code,int quantite,int prix)
{
  long tot; FICHE * pfi;
  pfi = (FICHE*)malloc(sizeof(FICHE));
  pfi->code_compose = code;
  pfi->quantite = quantite;
  pfi->prix = prix;
  tot = prix * quantite;
  pfi->total = tot;
 pfi->nextfi = *firstfi;
 *firstfi = pfi;
}

FICHE *load_cout_matier(COMPOS * racine, int key_compose)
{
  LISTE * firstl; FICHE * firstfi; LISTE * p;
  firstl = load_matiere_necessaire(racine,key_compose);
  if(firstl)
  {
    load_liste_sans_redo(firstl);
    for(p = firstl;p;p = p->nextl)
    {
     for(ar=firsta;ar;ar = ar->nexta)
     if(p->d.code_compose == ar->code_ar)
     insert_fiche(&firsfi,ar->code_ar,p->d.quantite,ar->prix_achat)
    }
  return(firstfi);
  }
  return(NULL);
}

void liste_cout_matiere(COMPOS * racine,int key_compose)
{
  FICHE * pfi; float s; FICHE * firstfi;
  s=0;
firstfi = load_cout_matier(racine, key_compose)
if(firstfi)
{
  printf("====================La fiche cout matieres premieres du composé %d====================\n" ,key_compose)
  printf("| Copmosant | Quantite  |   Prix    |   Total   |\n")
  for(pfi = firstfi;pfi;pfi = pfi->nextfi)
  {
    s += (pfi->total);
    printf("%11d|%11d%11f%11f|\n",pfi->code_compose,pfi->quantite,pfi->prix,pfi->total);
  }
  printf("                                         TOTAL: %f",s);
}
printf("Erreur");
}
