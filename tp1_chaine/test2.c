# include<stdio.h>
# include <string.h>

void lecture(char *s){

  printf("nom: ");
  scanf("%s",s);
}

int comparaison(char *s){

  int v=0;
  if (strlen(s) > 10){
  	v=1;
  }
  return(v);
}

void main(){

  char t[20];
  int compteur=0; 
  lecture(t); 
  while( strcmp(t, "fin") != 0){
        if(comparaison(t) == 1){
		compteur++;
	}
  	lecture(t);	
   
  }

  printf("le nombre de mot ayant > 10 caracteres: %d \n", compteur);
}
