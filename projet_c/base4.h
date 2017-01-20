void insert_non_fournis(FOURNIS ** firstfo,int code,char raison[30])
{
  FOURNIS * pfo;
  pfo = (FOURNIS*)malloc(sizeof(FOURNIS));
  pfo ->codef = code;
  sscanf(raison,"%30s",pfo ->raisonsocial);
  pfo ->nextf = *firstfo;
  *firstfo = pfo;
}

FOURNIS *load_non_fournis(ARTICLE * firsta,FOURNIS * firstf)
{
 FOURNIS * firstfo; int v; FOURNIS * pf; ARTICLE * pa;
 firstfo = NULL;
 for(pf = firstf;pf;pf = pf->nextf)
 {
   for(pa = firsta;pa,v;pa = pa->nexta)
   {
     if(pf->codef == pa->code_fournis)
      v =0;
   }
   if (pa == NULL)
   insert_non_fournis(&firstfo,pf->codef,pf->raisonsocial);
 }
 return(firstfo);
}

void liste_non_fournis(ARTICLE * firsta,FOURNIS * firstf)
{
  FOURNIS * firstfo; FOURNIS * pfo;
  firstfo = load_non_fournis(firsta,firstf);
  if(firstfo)
  {
    printf("===========La liste des fournisseurs qui n'interviennent pas dans la composition des articles formés==========");
    printf("|   Code   |          Designation         |\n");
    for(pfo = firstfo;pfo;pfo = pfo->nextf)
    {
      printf("%10d|%30s\n",pfo->codef,pfo->raisonsocial);
    }
  }
  else
   printf("Tout les fournisseurs interviennet dans la compositions des articles");
}
