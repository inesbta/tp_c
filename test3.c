# include<stdio.h>
# include <string.h>
void lecture(char * s)
{
  printf("nom: ");
  scanf("%s",s);
}
int comparaison(char *s)
{ int v=0;
  if (strlen(s) > 4)
  {
  v=1;
}
  return(v);
}
void main()
{
  int s=0;
  char t[20];
lecture(t);
  while ( strcmp(t,"fin"))
{
/* if (strlen(t)<20)*/

 if (comparaison(t)==1)
 {
 s ++;
 }

lecture(t);
 }
 printf("%d \n",s);
 }
