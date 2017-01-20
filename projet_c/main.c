#include "base.h"
#include "base1.h"
#include "base3.h"
#include "base4.h"
#include "base5.h"
#include "base6.h"
void  main()
{
  ARTICLE * firsta; FOURNIS * firstp; COMPOS * racine;
  int code; char choix;

firsta = load_article();
firstp = load_fournis();
racine = load_compos();
while((choix = get_choix ()) != '0')
{
  switch(choix)
  {
    case '1':{
      printf("saisir un code");
      scanf("%d", &code);
      liste_matiere_necessaire(racine,code);
      break;
    }
    case '2' :{
      printf("saisir un code");
      scanf("%d", &code);
      liste_cout_matiere(racine,code);
      break;
    }
    case '3':liste_cout_total(firsta,racine); break;
    case '4':liste_non_fournis(firsta,firstf);
    case '5':liste_besoin(racine,firsta);
  }
 }
}
