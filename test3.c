# include<stdio.h>
# include <string.h>
void lecture(char * s)
{
  printf("nom: ");
  scanf("%s",s);
}
int comparaison(char *s)
{ int v;
  if (strlen(s) > 10);
  v=1;
  return(v);
}
void main()
{
  char t[20];
  int i=0; int j;
lecture(t);
  while ( strcmpr(*(t+i),"fin")) && (strlen(*(t+i))<20 ))
  {
  i++;
  lecture(t+i);
 }
 for (j=0;j<i;j++)
 {
 if comparaison((t+j))
 {
 printf(*(t+j));
}
}
}
