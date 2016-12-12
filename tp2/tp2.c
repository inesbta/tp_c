#include"base2.h"

void main()
{
  PRODUIT * first_produit;
  FAMILLE * first_famille;
  char choix;
  char fam[31];

  first_produit=load_produit();
  first_famille=load_famille();

  while( (choix=get_choix()) != '0')
  {
    switch (choix)
    {
      case '1': stock_global(first_produit);break;
      case '2' : {
        printf("saisir une famille fam\n");
        scanf("%s",fam);
        stock_famille(first_produit,fam);
        break;
      }
      case '3' :recap_famille(first_produit);
                break;
      case '4' :{
        printf("saisir une famille fam\n");
        scanf("%s",fam);
        supprime_Pfamille(&first_produit,fam);
        supprime_famille(&first_famille,fam);
        break;
      }
    }

  }
  free(first_produit);
  free(first_famille);

}
