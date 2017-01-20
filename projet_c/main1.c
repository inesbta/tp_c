#include"base.h"
#include"base4.h"
void main()
{
  FOURNIS * firstf; ARTICLE * firsta;
  firsta = load_article();
  firstf = load_fournis();
  liste_non_fournis(firsta,firstf);

}
