#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>
#include "bib_tp1.h"


 int main()

 {
 	int i,ch=0 ,v,a=14;
 	sk_maillon* head ;
    sk_maillon* queue ;
    sk_maillon* tt =NULL;
    sk_maillon* qq=NULL ;
    ptr_sk_maillon p,q;
    bool existe;
test_esi();
tp1llc();

   while(ch!=6)
   {
       test_esi();
         menu();
       color(15,0); scanf("%d",&ch);color(a,0);
   switch(ch)
   {
   case 1:
    creer_skip_list(&tt,&qq);

    color(12,0);printf(" APPUIER SUR [ENTRER] POUR REVENIR AU MENU PRINCIPALE \n");color(15,0);
  getchar();getchar();
    break;
   case 2 :
       // creer_skip_list(&tt,&qq);

       if(qq!=NULL)
       {
            printf("entrer une valeur ");
           color(15,0);printf(":") ;scanf("%d",&v);color(a,0);
          rech_val(qq,&q,&p,&existe,v);
          if(existe)
          {
          printf("\n la valeur est  trouvee en niveau %d\n",p->num);
          if(val_de(p)==0)
          printf("le maillon  qui la pointe est la tete\n");
          else
            printf("le maillon  qui la pointe est %d\n",p->valeur);
          }else
          printf("la valeur n'existe pas\n");

       }else{
        color(12,0);printf("!! VOUS DEVEZ D'ABORD CREER LA LISTE \n\n");color(15,0);
       }
   color(12,0);printf(" APPUIER SUR [ENTRER] POUR REVENIR AU MENU PRINCIPALE \n");color(15,0);
  getchar();getchar();
    break;
   case 3:
        if(qq!=NULL)
       {comple=0;
            printf("entrer une valeur a inserer ");
           color(15,0);printf(":") ;scanf("%d",&v);color(a,0);
         insertion_valeur(&qq,v);

       }else{
        color(12,0);printf("!! VOUS DEVEZ D'ABORD CREER LA LISTE \n");color(15,0);
       }
  color(12,0);printf(" APPUIER SUR [ENTRER] POUR REVENIR AU MENU PRINCIPALE \n");color(15,0);

  getchar();getchar();
    break;
   case 4:
     if(qq!=NULL)
       {
            printf("entrer une valeur a supprimer ");
           color(15,0);printf(":") ;scanf("%d",&v);color(a,0);
        suppr_val(&qq,v,&existe);
        if(existe)
        {
            printf("la valeur a ete supprimer \n");
        }else
          printf("la valeur n'existe pas\n");

       }else{
        color(12,0);printf("!! VOUS DEVEZ D'ABORD CREER LA LISTE \n");color(15,0);
       }
       color(12,0);printf(" APPUIER SUR [ENTRER] POUR REVENIR AU MENU PRINCIPALE \n");color(15,0);
  getchar();getchar();
       break;
   case 5:
     if(qq!=NULL)
       {

         parcour_niv(tt,qq);

       }else{
        color(12,0);printf("!! VOUS DEVEZ D'ABORD CREER LA LISTE \n");color(15,0);
       }
        color(12,0);printf(" APPUIER SUR [ENTRER] POUR REVENIR AU MENU PRINCIPALE \n");color(15,0);
  getchar();getchar();

    break;
    color(12,0);printf(" APPUIER SUR [ENTRER] POUR REVENIR AU MENU PRINCIPALE \n");color(15,0);
  getchar();getchar();
   case 6 :
    break;


   }

   }


tp_goodbye();

}











