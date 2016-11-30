#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sgrep(char *s,int argc,char* argv[],int nb_ligne)
{
  int i; int j;
  for(i=0;i<argc;i++) {
  for(j=0;j<strlen(s);){
  if(!(memcmp(s+j,argv[i],strlen(argv[i]))))
  {
    printf("ligne: %d,colonne:%d,le mot %s",nb_ligne,j,argv[i]);
    j+=strlen(argv[i]);
  }
  else
  j++;
}
 }
  }
  void main(int argc,char* argv[])
  {
    int nb=1; FILE* fof; FILE* fp; char lin[100]; char ligne[500];char fichier[100];
    if (argc < 2)
    {
      printf("nombre de parametres insuffisant");
      exit(0);
    }
    system("ls /home/ines/argv[0] > fof.txt");
    fof=fopen("fof.txt","r");
    while(fgets(lin,100,fof)) {
    memcpy(fichier,lin,strlen(lin)-1);
    if (fichier!="fof.txt"){
    if (fp=fopen("fichier","r"))
    while(fgets(ligne,500,fp))
    {
      sgrep(ligne,argc,argv,nb);
      nb++;
    }
    fclose(fp);
   }
   }
   fclose(fof);
   }
