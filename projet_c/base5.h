void insert_pgm(LISTE ** firstp,int code, float besoin )
{
  LISTE * p1;
  p1 =(liste*)malloc(sizeof(LISTE));
  p1->d.code_compose = code;
  p1->d.quantite = besoin;
  p1->nextl = *firstp;
  *firstp = p1;
}
LISTE * load_besoin(COMPOS * racine)
{
  LISTE * first; LISTE * firstp; COMPOS *ra; LISTE * p; float besoin;
  firstp = NULL;
  first = load_pgm_prod()
  for (p = first; p; p = p->nextl)
  {
    if(ra = seek_noeud(racine,p->d.code_compose));
    {
      if((ra->d.quantite)<(p->d.quantite))
      {
      besoin = (p->d.quantite) - (ra->d.quantite);
      insert_pgm(&firstp,p->d.code_compose,besoin);
    }
   }
  }
  return(firstp);
}

void liste_besoin(COMPOS * racine,ARTICLE * firsta);
{
  ARTICLE * pa; LISTE * pp; float c; float som;
  firstp = load_besoin(racine);
  if(firstp)
  {
    printf("====================La fiche des besoins====================\n");
    printf("| Designation |   Quntite   |    Prix     |    Total    |\n");
    for(pp = firstp;pp;pp = pp->nextl)
    {
      for(pa = firsta;pa;pa= pa->nexta)
      {
        if(pp->d.code_compose == pa->code_ar)
        {
        c = (float)(pa->prix_achat)*(pp->d.quantite);
        som += c;
        printf("%13s|%12f|%13f|%13f|\n",pa->desg,pp->d.quantite,pa->prix_achat,c);
        }
      }
    }
    printf("                                                          TOTAL:%f",som);
  }
  else
  printf("On n'a pas besoin d'aucune qunatite supplémentaire");
}
