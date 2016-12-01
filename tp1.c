#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int chercheMot(char *tableau, char* nom_fichier)
{
    char car = 0;   //Contient temporairement chaque caractère du fichier dico.txt
    int i = 0, ligne=1, colonne=1;
	printf("\n>>> Dans le fichier %s \n", nom_fichier);
    FILE* fichier = fopen(nom_fichier, "r");
    while(car != EOF)
    {
        car = fgetc(fichier);   //On lit un caractère de dico.txt
        colonne++;
	if (car == '\n'){
		ligne++;
		colonne=1;
 		
	}
        if(tableau[i] == car)   //Si le 1er caractère correspond, on augmente i pour tester le second caractère au tour suivant
        {
            i++;
            if(tableau[i] == '\0' && fgetc(fichier) == '\n') //Si cette condition est vraie, c'est que la chaine est déja dans le dico
            {
                printf("ligne %d colonne %ld dans le fichier %s \n", ligne, colonne-strlen(tableau), nom_fichier);
		//return 1;
		
            }
        }
 
        else
        {
            i = 0;
        }
    } 
    fclose(fichier); 
    return 0;   //Si on a rien trouvé, on retourne 0
}
  void main(int argc,char* argv[])
  {
    char cmd[20]; FILE* fof; FILE* fp; char lin[100], lin2[100];int i;char chemin_fichier[100];
  //  char *lin3 = malloc(100 * sizeof(char));
    if (argc < 2)
    {
      printf("nombre de parametres insuffisant");
      exit(0);
    }
   
    strcpy(cmd,"ls ");
    strcat(cmd,argv[1]);
    strcat(cmd," > fof.txt");
    system(cmd);
    for (i=2; i < argc; i++){
	printf("\n===== recherche du mot %s ======= \n", argv[i]);
	fof=fopen("fof.txt", "r");
	while(fgets(lin,100,fof)){
          char *lin3 = malloc(100 * sizeof(char));
          strncpy(lin3,lin, strlen(lin)-1);
          strcpy(chemin_fichier, argv[1]);
          strcat(chemin_fichier, lin3);
          int o = chercheMot(argv[i], chemin_fichier );
          free(lin3);	  
	}
        fclose(fof);
    }
    
   }
