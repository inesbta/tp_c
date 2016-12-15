#include<stdio.h>
#include<string.h>
char* saisie(char* s)
{
  printf("saisir une chaine");
  scanf("%s",s);
  return(s);
}
void affiche(char* s)
{ int i;
  for(i=0;i<strlen(s);i++)
  putchar(*(s+i));
}
char* inverse(char* s)
{ int i; int j;
  for(i=strlen(s),j=0;i>0;i--,j++)
  {
  *(s+j)=*(s+i);
  }
  return(s);
}
int mots(char* s)
{ int n=0; int i; int j;
  char* s1;
  for(i=0,j=0;i<strlen(s);j++)
  {
*(s1+j)=*(s+i);
if (*(s+i)==*(s+i+1)==' '){
i+=2;
}
else
if (*(s+i)!=' ')
*(s1+j)=*(s+i);
}
for (j=0;j<strlen(s1);j++)
{
  if(s1[0]==' ')
  j=1;
  if(*(s1+j)==' ')
  n++;
}
return(n);
}
void main()
{ char mot;
  char* s;
  printf("choisir une alternative parmis les suivantes:saisir=>s,afficher=>a,inverse=>i,mots=>m\n");
  mot=getchar();
  while(mot!='q')
  {
  switch(mot)
   {
    case's':saisie(s);break;
    case'a':affiche(s);break;
    case'i':inverse(s);break;
    case'm':mots(s);break;
   }
  printf("frappez une touche pour revenir au menu et frapper q pour quitter");
 }
}
