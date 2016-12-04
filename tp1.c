#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void chercheMot(char *mot, char* nom_fichier)
{
    char car = 0;  
    int i = 0, ligne=1, colonne=1;
	printf("\n>>> Dans le fichier %s \n", nom_fichier);
    FILE* fichier = fopen(nom_fichier, "r");
    while(car != EOF)
    {
        car = fgetc(fichier);   
        colonne++;
	if (car == '\n'){
		ligne++;
		colonne=1;
 		
	}
        if(mot[i] == car)  
        {
            i++;
            if(mot[i] == '\0' && i == strlen(mot))
            {
                printf("ligne %d colonne %ld  \n", ligne, colonne-strlen(mot));
		//return 1;
		
            }
        }
 
        else
        {
            i = 0;
        }
    } 
    fclose(fichier); 
     
}
  void main(int argc,char* argv[])
  {
    char cmd[20]; FILE* fof; char lin[100];int i;char chemin_fichier[100];
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
          chercheMot(argv[i], chemin_fichier );
          free(lin3);	  
	}
        fclose(fof);
    }
    
   }
