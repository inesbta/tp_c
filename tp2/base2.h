#include<stdio.h>
#include<string.h>
#include <stdlib.h>
struct produit
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
  char designation[30];
  struct famille * nextf;
};
typedef struct famille FAMILLE;

PRODUIT * load_produit()
{
  PRODUIT ** firstp;
  PRODUIT * pp;
  FILE * fp;
  char s[100];
  PRODUIT * nextp;

  fp=fopen("produit.txt","r");

  if(fp)
  {
    while(fgets(s,100,fp))
    {
      pp=(PRODUIT*)malloc(sizeof(PRODUIT));
      sscanf(s,"%4d%30s%30s%10f%10ld",&(pp->code),(pp->desig),(pp->famille),&(pp->cout_achat),&(pp->quantit_stock));
/*      strncpy(pp->code,s,4);
      strncpy(pp->desig,s+4,30);
      strncpy(pp->famille,s+34,30);
      strncpy(pp->cout_achat,s+64,10);
      strncpy(pp->quantit_stock,s+74,10);
      pp->nextp= *firstp;
      *firstp =pp;
      return(*firstp);*/
    }
  }
  else

   printf("erreur");

  fclose(fp);
}


 FAMILLE * load_famille()
{
 FAMILLE **firstf;FAMILLE * pf; char s1[100];FILE * fp1; FAMILLE * nextf;
  fp1=fopen("famille.txt","r");
  printf("hello");
  if(fp1)
  {
    while(fgets(s1,100,fp1))
    {
      pf=(FAMILLE*)malloc(sizeof(FAMILLE));
      //strncpy(pf->designation,s1,30);
      sscanf(s1,"%s",pf->designation);
      pf->nextf=*firstf;
      *firstf=pf;
      return(*firstf);
    }
  }
  else
  printf("erreur");
fclose(fp1);
}
 void fn_entet()
{
  char * entet; char s2[200]; FILE * fp2;
  fp2=fopen("entet.txt","r");
  if(fp2)
  {
  while(fgets(s2,200,fp2));
   {
  strncpy(entet,s2,30);
   }
  printf("%s",entet);
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
  PRODUIT * pp; long total;
  fn_entet();
  printf("=================ETAT DU STOCK GLOBALE=================");
  printf("code |         designation          |            famille            |cout_achat |qunt_stock |total");
  for(pp=firstp,total=0;pp;pp=pp->nextp)
  {
    printf("%5d|",pp->code);
    printf("%30s|",pp->desig);
    printf("%30s|",pp->famille);
    printf("%10f|",pp->cout_achat);
    printf("%10ld|",pp->quantit_stock);
    total = total+pp->quantit_stock;
  }
  printf("%ld\n",total);
}
void stock_famille(PRODUIT * firstp,char fam[30])
{
   long total=0; PRODUIT * pp;

  fn_entet();
  printf("==================ETAT DU STOCK DE LA FAMILLE %s===================",fam);
  for(pp=firstp;pp && strcmp(pp->famille,fam);pp->nextp)
  ;
  printf("code |          designation          |cout_achat |qunt_stock |total");
  printf("%5d",pp->code);
  printf("%30s",pp->desig);
  printf("%10f",pp->cout_achat);
  printf("%10ld",pp->quantit_stock);
  total=total+pp->quantit_stock;
  printf("%ld \n",total);
}
void recap_famille(PRODUIT * firstp)
{
  PRODUIT * pp; float val;
  fn_entet();
  printf("============LE RECAP DES FAMILLES==========");
  printf("          famille              |valeur stock");
  for(pp=firstp;pp;pp=pp->nextp )
  {
    printf("%30s|",pp->famille);
    val =(float)  ((pp->cout_achat) * (pp->quantit_stock));
    printf("%f",val);
  }
}
void delete_node(PRODUIT * p,PRODUIT * prev )
{
  prev->nextp = p->nextp;
  free(p);
}
void supprime_Pfamille(PRODUIT * firstp,char fam[30])
{
  PRODUIT * p;PRODUIT *q; PRODUIT * prev;
  for(p=firstp;p!=NULL;prev = p,p=p->nextp)
  {
    if(strcmp(p->famille,fam)==0)
  {
    if(p==firstp)
    {
      firstp=firstp->nextp;
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
void supprime_famille(FAMILLE * firstf,char fam[30])
{ FAMILLE *p;FAMILLE *q; FAMILLE * prev;

  for(p=firstf;p!=NULL;prev=p,p=p->nextf)
  {
    if(strcmp(p->designation,fam)==0)
    {
      if(p==firstf)
      {
        firstf=firstf->nextf;
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
