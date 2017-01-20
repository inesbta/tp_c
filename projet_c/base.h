#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct article
{
  int code_ar;
  char desg[30];
  char type[1];
  int code_fournis;
  float prix_achat;
  struct  article * nexta;
};
typedef struct article ARTICLE;

struct fournis
{
  int codef;
  char raisonsocial[30];
  struct fournis *nextf;
};
typedef struct fournis FOURNIS;

/*struct data
{
  int code_compose;
  float quantite;
};
typedef struct data DATA;

struct compos
{
  DATA d;
  struct compos * frere;
  struct compos * fils;
};
typedef struct compos COMPOS;

struct liste
{
  DATA d;
  struct liste * nextl;
};
typedef struct liste LISTE;

struct fiche
{
  int code_compose;
  int quantite;
  float prix;
  float total;
  struct fiche * nextfi;
};
typedef struct fiche FICHE;

struct fiche1
{
  char desg[30];
  float cout_tot;
  struct fiche1 * nextc;
};
typedef struct fiche1 FICHE1;*/

ARTICLE * load_article()
{
  ARTICLE * firsta; ARTICLE * pa; FILE * fp; char s[100];
  firsta=NULL;
  {
    if(fp=fopen("article.txt","r"))
    {
    while(fgets(s,100,fp))
    {
      pa = (ARTICLE*)malloc(sizeof(ARTICLE));
      sscanf(s,"%3d%30s%1s%3d%4f\n",&(pa->code_ar),(pa->desg),(pa->type),&(pa->code_fournis),&(pa->prix_achat));
      pa->nexta = firsta;
      firsta = pa;
    }
  }
  else
      printf("fichier inaccessible");
  fclose(fp);
  return(firsta);
 }
}

FOURNIS * load_fournis()
{
 FOURNIS * firstf; FOURNIS * pf; FILE * fp1; char s1[100];
 firstf=NULL;
 if(fp1=fopen("fournisseur.txt","r"))
 {
   while(fgets(s1,100,fp1))
   {
    pf = (FOURNIS*)malloc(sizeof(FOURNIS));
    sscanf(s1,"%3d%30s",&(pf->codef),(pf->raisonsocial));
    pf->nextf = firstf;
    firstf = pf;
   }
 }
 else
   printf("fichier inaccessible");
fclose(fp1);
return(firstf);
}
/*void coder_data(char s3[100],int code_compose,int code_composant,)




COMPOS * load_compos()
{
  if(fp2 = fopen("compostion.txt","r"))
  {
    /*fgets(s2,100,fp2);
    pc = (COMPOS*)malloc(sizeof(COMPOS));
    sscanf(s2,"%3d%3d%10ld",&(pc->code_compose),&(pc->code_composant),&(pc->quantite));
  fseek(fp2,512L,SEEK_SET );

  }
}

LISTE * load_pgm_prod()
{
  FILE * fp3; LISTE * first; LISTE * pp;char s3[100];
  first = NULL;
  if(fp3 = fopen("pgm.txt","r"))
  {
    while(fgets(s3,100,fp3))
    {
      pp = (LISTE*)malloc(sizeof(LISTE));
      sscanf("%3d%5f",&(pp->d.code_compose),&(pp->quantite));
      pp->nextl = first;
      first = pp;
    }
  }
  else
   printf("fichier inaccessible");
  fclose(pf3);
  return(first);
}
char get_choix()
{
  char c;
  printf("choisir une alternative parmis les suivantes \n tappez 1 pour afficher la liste des matieres premieres d'un comoposé de votre choix \n tappez 2 pour afficher la liste cout matires premieres d'un composé de votre choix \n tappez 3 pour lister pour chaque article son cout \n tappez 4 pour afficher la liste des fournisseurs qui n'interviennent pas dans la composition d'articles formés \n tappez 5 pour afficher la liste des besoins\n");
  c = getchar();
  return(c);
}*/
