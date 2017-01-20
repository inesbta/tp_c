float cout_total(LISTE * firstl,ARTICLE * firsta)
{
 float s;
 s = 0;
for(pl = firstl;pl;pl = pl->nextl)
 {
  for(pa = firsta;pa;pa = pa->nexta)
  {
    if(pl->d.code_compose == pa->code_ar)
    {
    ct =(float)(pl->d.quantite) * (pa->prix_achat);
    }
  }
 s += ct;
 }
 return(s);
}

void insert_cout(FICHE1 ** firstc,float cout,char desg[30])
{
  pc = (FICHE1*)malloc(sizeof(FICHE1))
  pc->cout_tot = cout;
  pc->desg = desg;
  pc->nextc = *firstc;
  *firstc = pc;
}

FICHE1 * cout_articles_composes(ARTICLE * firsta,COMPOS * racine)
{
  ARTICLE * pa; LISTE * firstl; float cout; FICHE1 * firstc;
  firstc = NULL;
  for(pa = firsta;pa;pa = pa->nexta)
  {
    if (pa->type == F)
    {
      firstl = load_matiere_necessaire(racine,pa->code_ar);
      load_liste_sans_redo(firstl);
    }
    cout = cout_total(firstl,firsta);
    insert_cout(&firstc,cout,pa->desg);
  }
  return(firstc);
}

void liste_cout_total(ARTICLE * firsta,COMPOS * racine)
{
  FICHE1 * firstc; FICHE1 * pc;
firstc = cout_articles_composes(firsta,racine);
printf("====================La fiche cout matieres premieres de tout les composes====================");
printf("|         Designation          |             Cout             |\n");
for(pc = firstc;pc; pc = pa->nextc)
 {
  printf("|%30s|%30f|\n"pc->desg,pc->cout_tot);
 }
}
