#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct article
{
  int code_ar;
  char desg[30];
  char type;
  int code_fournis;
  int prix_achat;
  article * nexta;
};
typedef struct article ARTICLE;

struct fournis
{
  int code_f;
  char raison_social[30];
  fournis *nextf;
};
typedef struct fournis FOURNIS;

struct data
{
  int code_compose;
  float quantite;
};
typedef struct data DATA;

struct compos
{
  d DATA;
  compos * frere;
  compos * fils;
};
typedef struct compos COMPOS;


ARTICLE * load_article()
{
  ARTICLE * firsta; ARTICLE * pa; FILE * fp; char s[100];
  firsta=NULL;
  {
    if(fp=fopen("article.txt","r"))
    while(fgets(s,100,fp))
    {
      pa = (ARTICLE*)malloc(sizeof(ARTICLE));
      sscanf(s,"%3d%30s%1s%3d%4d",&(pa->code_ar),pa->desg,pa->type,&(pa->code_fournis),&(pa->prix_achat));
      pa->nexta = firsta;
      firsta = pa;
    }
  }
  else
      printf("fichier inaccessible");
  fclose(fp);
  return(firsta);
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
    sscanf(S1,"%3d%30S",&(pf->code_f),pf->raison_social);
    pf->nextf = firstf;
    firstf = pf;
   }
 }
 else
   printf("fichier inaccessible");
fclose(fp1);
return(firstf);
}
void coder_data(char s3[100],int code_compose,int code_composant,)




COMPOS * load_compos()
{
  if(fp2 = fopen("compostion.txt","r"))
  {
    /*fgets(s2,100,fp2);
    pc = (COMPOS*)malloc(sizeof(COMPOS));
    sscanf(s2,"%3d%3d%10ld",&(pc->code_compose),&(pc->code_composant),&(pc->quantite));
  fseek(fp2,512L,SEEK_SET );*/

  }
}
