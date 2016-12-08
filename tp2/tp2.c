#include"base2.h"
void main()
{
  PRODUIT * first_produit;FAMILLE * first_famille;char choix; char fam[30];
  first_produit=load_produit();
  first_famille=load_famille();
  while(choix=get_choix())
  {
    switch (choix)
    {
      case '1': stock_global(first_produit);
      case '2' : {
        printf("saisir une famille fam");
        scanf("%s",fam);
        stock_famille(first_produit,fam);
      }
      case '3' :recap_famille(first_produit);
      case '4' :{
        printf("saisir une famille fam");
        scanf("%s",fam);
        supprime_Pfamille(first_produit,fam)
        supprime_famille(first_famillet,fam);
      }
    }

  }
  free(first_produit);
  free(first_famille);
}
