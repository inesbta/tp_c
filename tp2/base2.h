#include<stdio.h>
#include<string.h>
#include <stdlib.h>                                  //Iben Taarit ines
struct produit                                       //IF3 B
{
  int code;
  char desig[31];
  char famille[31];
  float cout_achat;
  long quantit_stock;
  struct produit * nextp;
};
typedef struct produit PRODUIT;

struct famille
{
  char designation[31];
  struct famille * nextf;
};
typedef struct famille FAMILLE;

PRODUIT * load_produit()
{
  PRODUIT * firstp;
  PRODUIT * pp;
  FILE * fp;
  char s[100];
  PRODUIT * nextp;

  firstp=NULL;
  fp=fopen("produit.txt","r");
  if(fp)
  {
    while(fgets(s,100,fp))
    {
      pp=(PRODUIT*)malloc(sizeof(PRODUIT));
      sscanf(s,"%4d%30s%30s%10f%10ld\n",&(pp->code),(pp->desig),(pp->famille),&(pp->cout_achat),&(pp->quantit_stock));
      pp->nextp= firstp;
      firstp = pp;
    }
  }
  else

   printf("erreur");

  fclose(fp);
  return(firstp);
}


 FAMILLE * load_famille()
{
 FAMILLE *firstf;FAMILLE * pf; char s1[100];FILE * fp1; FAMILLE * nextf;
  firstf=NULL;
  fp1=fopen("famille.txt","r");
  if(fp1)
  {
    while(fgets(s1,100,fp1))
    {
      pf=(FAMILLE*)malloc(sizeof(FAMILLE));
      //strncpy(pf->designation,s1,30);
      sscanf(s1,"%s",pf->designation);
      pf->nextf= firstf;
      firstf=pf;
    }
  }
  else
  printf("erreur");
fclose(fp1);
return(firstf);
}
 void fn_entet()
{
  char * entet; char s2[200]; FILE * fp2;
  fp2=fopen("entet.txt","r");
  if(fp2)
  {
  while(fgets(s2,200,fp2))
   {
   printf("%s",s2);
   }
  }
  else
  printf("erreur");
  fclose(fp2);
 }

char get_choix()
{
  char c;
printf("choisir une option parmis les suivantes:\n tapez 1 pour afficher le stock global \n tapez 2 pour afficher le stock par famille \n tapez 3 pour afficher le récap par famille \n tapez 4 pour supprimer une famille \n tapez 5 pour sauvegarder \n tapez 0 pour quitter ");
c=getchar();
return(c);
}
void stock_global(PRODUIT* firstp)
{
  PRODUIT * pp; float total;
  fn_entet();
  printf("=================ETAT DU STOCK GLOBALE=================\n\n");
  printf("code |         designation          |             famille          |cout_achat|qunt_stock|total  \n");
  for(pp=firstp;pp;pp=pp->nextp)
  {
    printf("%5d|",pp->code);
    printf("%30s|",pp->desig);
    printf("%30s|",pp->famille);
    printf("%10.5f|",pp->cout_achat);
    printf("%10ld|",pp->quantit_stock);
    total = (float)(pp->cout_achat)*(pp->quantit_stock);
    printf("%lf \n",total);
  }
}
void stock_famille(PRODUIT * firstp,char fam[30])
{
   float total; PRODUIT * pp;

  fn_entet();
  printf("==================ETAT DU STOCK DE LA FAMILLE %s===================\n\n",fam);
  printf("code |          designation         |cout_achat|qunt_stock|total \n");
  for(pp=firstp;pp;pp=pp->nextp){
  if(!strcmp(pp->famille,fam)){
  printf("%5d|",pp->code);
  printf("%30s|",pp->desig);
  printf("%10.5f|",pp->cout_achat);
  printf("%10ld|",pp->quantit_stock);
  total=(float)(pp->cout_achat)*(pp->quantit_stock);
  printf("%lf \n",total);
}
}
}
void recap_famille(PRODUIT * firstp)
{
  PRODUIT * pp; float val;
  fn_entet();
  printf("============LE RECAP DES FAMILLES==========\n\n");
  printf("          famille             |valeur stock\n");
  for(pp=firstp;pp;pp=pp->nextp )
  {
    printf("%30s|",pp->famille);
    val =(float)  ((pp->cout_achat) * (pp->quantit_stock));
    printf("%f \n",val);
  }
}
void delete_node(PRODUIT * p,PRODUIT * prev )
{
  prev->nextp = p->nextp;
  free(p);
}
void supprime_Pfamille(PRODUIT ** firstp,char fam[30])
{
  PRODUIT * p;PRODUIT *q; PRODUIT * prev;
  for(p=*firstp;p!=NULL;prev = p,p=p->nextp)
  {
    if(strcmp(p->famille,fam)==0)
  {
    if(p==(*firstp))
    {
      *firstp=(*firstp)->nextp;
      q=p;
      free(q);
    }
    else
    {
      delete_node(p,prev);
    }
  }
 }
}
void supprime_famille(FAMILLE ** firstf,char fam[30])
{ FAMILLE *p;FAMILLE *q; FAMILLE * prev;

  for(p=*firstf;p!=NULL;prev=p,p=p->nextf)
  {
    if(strcmp(p->designation,fam)==0)
    {
      if(p==(*firstf))
      {
        *firstf=(*firstf)->nextf;
        q=p;
        free(q);
      }
    else{
    prev->nextf=p->nextf;
    free(p);
      }
    }
  }
}
void sauvegarde_modif(PRODUIT * firstp, FAMILLE * firstf)
{
  FILE * fp;
  FILE * fp1;
  PRODUIT * pp;
  FAMILLE * pf;
  fp = fopen("produit.txt","w");
  fp1 = fopen("famille.txt","w");
  for(pp=firstp;pp;pp=pp->nextp)
  {
    fprintf(fp,"%4d%30s%30s%10f%ld\n",(pp->code),(pp->desig),(pp->famille),(pp->cout_achat),(pp->quantit_stock));
  }
  for(pf=firstf;pf;pf=pf->nextf)
  {
    fprintf(fp1,"30%s\n",(pf->designation));
  }
  fclose(fp);
  fclose(fp1);
}
void free_PF(PRODUIT ** firstp,FAMILLE ** firstf)
{
  PRODUIT * pp;
  FAMILLE * pf;
  while(pp = *firstp)
  {
    *firstp = (*firstp)->nextp;
    free(pp);
  }
  while(pf = *firstf)
  {
    *firstf = (*firstf)->nextf;
    free(pf);
  }
}
