#ifndef BIB_TP1_H_INCLUDED
#define BIB_TP1_H_INCLUDED

typedef struct sk_maillon
 {
struct 	sk_maillon* haut ;// pointe le niveau sup�rieur
struct 	sk_maillon* bas ;// pointe le niveau inferieur
struct 	sk_maillon* suivant ;// pointe l'�l�ment suivant
 	int valeur ;// contient la valeur
 	int num ;// le niveau du noeud



 }sk_maillon;
 typedef sk_maillon * ptr_sk_maillon ;// pointeur vers sk maillon


 int comple=0;



/// ************************************************************************** MACHINE ABSTRAITE *******************************************************************
/////////////////////////////////////////////////////////////////////////////// allocation         /////////////////////////////////////////////////////////////////
 void allouer_sk_maillon ( struct sk_maillon** tete , sk_maillon** queue   )
 {
 	int i = 1 ;
  sk_maillon* q ;
  sk_maillon* p ;
  q=(sk_maillon*)malloc(sizeof(sk_maillon));
  *tete = q ;
  (*tete)->bas =  NULL ;
 (*tete)->num = 0 ;
 (*tete)->suivant = NULL ;

  while( rand()%2 != 0 )// cette boucle genere le nombre de face successif afin de determiner le niveau de l'element
  {
  	p = (sk_maillon*) malloc(sizeof(sk_maillon)) ;
  	q->haut = p ;
  	p->bas=q;
  	q=p ;
  	q->suivant = NULL ;
  	q->num = i ;
  	i++;
  }
  q->haut = NULL ;
  *queue = q ;
 }
 ////////////////////////////////////////////////////////////////////procedure affectation des valeurs///////////////////////////////////////////////////
 void aff_val(sk_maillon* t_ptr , int val )
 {
 	while(t_ptr!= NULL)
 	{
 		t_ptr->valeur = val ;
 		t_ptr=t_ptr->haut ;
	 }
 }
 //////////////////////////////////////////////////////////////////affectation du suivant /////////////////////////////////////////////////////////////////
 void aff_suiv(ptr_sk_maillon * p,ptr_sk_maillon q)
 {
     (*p)->suivant=q;
 }
 /////////////////////////////////////////////////////////////////affectation du champs haut////////////////////////////////////////////////////////
  void aff_haut(ptr_sk_maillon * p,ptr_sk_maillon q)
 {
     (*p)->haut=q;
 }
 ////////////////////////////////////////////////////////////////////affectation du champs haut ////////////////////////////////
 void aff_bas(ptr_sk_maillon * p,ptr_sk_maillon q)
 {
     (*p)->bas=q;
 }
 ////////////////////////////////////////////////////////////////////affectation du champs niveau ////////////////////////////////
 void aff_niv(ptr_sk_maillon * p,int n)
 {
     (*p)->num=n;
 }
 //////////////////////////////////////////////////////////////////renvoie l'adresse du niveau haut/////////////////////////////////////////////////////////////
 ptr_sk_maillon haut_de(ptr_sk_maillon pk)
 {
     return pk->haut;
 }
 //////////////////////////////////////////////////////////////////renvoie l'adresse du niveau bas/////////////////////////////////////////////////////////////
 ptr_sk_maillon bas_de(ptr_sk_maillon pk)
 {
     return pk->bas;
 }
//////////////////////////////////////////////////////////////////renvoie l'adresse du suivant /////////////////////////////////////////////////////////////
 ptr_sk_maillon suivant_de(ptr_sk_maillon pk)
 {
     return pk->suivant;
 }
 //////////////////////////////////////////////////////////////////renvoie la valeur du maillon /////////////////////////////////////////////////////////////
 ptr_sk_maillon val_de(ptr_sk_maillon pk)
 {
     return pk->valeur;
 }
//////////////////////////////////////////////////////////////////renvoie le niveau du maillon /////////////////////////////////////////////////////////////
 ptr_sk_maillon niv_de(ptr_sk_maillon pk)
 {
     return pk->num;
 }
///***************************************************************************************************************************************************************
///////////////////////////////////////////////////////////////////////////////allocation des niveaux    ///////////////////////////////////////////////////////////
 void ajouter_niveau(sk_maillon** ptr )
{// cette procedure est utiliser pour ajouter un niveau � la tete � (quand le nouveau �l�ment est de niveau sup�rieur � celui de la tete)
	sk_maillon* p ;

	p=(sk_maillon*)malloc(sizeof(sk_maillon));
	p->num = ((*ptr)->num + 1 ) ;
	(*ptr)->haut = p ;
	p->bas = *ptr  ;


	*ptr = p ;
	(*ptr)->suivant = NULL ;






 }


 /////////////////////////////////////////////////////////////////////////////////  creer skip list ////////////////////////////////////////////////////////

void creer_skip_list(sk_maillon** t_niveau , sk_maillon** q_niveau )
 {// cr�e une skip liste al�atoire (tri�e)
    int i,j ;
    int n ;
    int v ;
 	sk_maillon* pk ;
 	sk_maillon* queue ;
 	printf(" veuillez saisir le nomre des elements : ");

 	scanf("%d", &n);

 	v = rand()%10;

 	allouer_sk_maillon(&pk , &queue);

 	aff_val(pk,v);

 //	printf(" les valeur de v sont %d : \n", v );



    *t_niveau = (sk_maillon* ) malloc(sizeof(sk_maillon));
    (*t_niveau)->num = 0 ;
    (*t_niveau)->suivant = pk ;
    (*t_niveau)->bas=NULL;
     *q_niveau = *t_niveau ;




     pk=pk->haut;


    while(pk!=NULL)
    {
    	ajouter_niveau(&*q_niveau) ;
    	(*q_niveau)->suivant = pk ;
    	pk=pk->haut ;

	}



   for (i=0 ; i < n ; i++)
   {


   	     v = v + rand()%10 + 1 ;

   allouer_sk_maillon(&pk , &queue);

   aff_val(pk,v) ;



//printf("val %d\n",i);


   if ((*q_niveau)->num < queue->num)
   {

   	int def = (queue->num) - (*q_niveau)->num ;


   	for (j=1 ; j <=def ;j++)
   	   {

   		ajouter_niveau(&*q_niveau);

	   }
}


sk_maillon* qlq = *q_niveau ;


sk_maillon* q = queue ;


 while ( qlq != NULL  )
 {

 	if ( qlq->suivant == NULL &&  (qlq->num ) == (q->num )    )
 	{

 		qlq->suivant = q  ;
 	     qlq =	qlq->bas ;
 	     q = q->bas ;

 	}

 	else
 	{
 		if ( qlq->suivant != NULL  )
 		{
 			qlq = qlq->suivant ;
		 }
		 else
		 {
		 	qlq = qlq->bas ;
		 }




	 }
}
}

}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void insertion_valeur(ptr_sk_maillon * niv_max_tete,int v)
{
    ptr_sk_maillon sauv,tete=*niv_max_tete,t,q;
    allouer_sk_maillon(&t,&q);
    printf("niveau  %d\n",q->num);
   aff_val(t,v);
    while(tete->num < q->num)// dans le cas ou le niveau maximale du maillon ins�rer d�passe celui de la tete
    {
        ajouter_niveau(&tete);
    }

    sauv=tete;
    while(sauv->num > q->num)// renvoie l'adresse du premier maillon � chainer avec le maillon inser�
    {//DTQ 2
        comple++;
        if(sauv->suivant!=NULL && sauv->suivant->valeur<v)
        {
            sauv=sauv->suivant;
        }else
        {
            sauv=sauv->bas;
        }

    }//FTQ 2
    while(sauv!=NULL)// fait le chainage du maillon inser� avec la liste
    {//DTQ 3
     comple++;
        if(sauv->suivant==NULL || sauv->suivant->valeur>v )
        {
            q->suivant=sauv->suivant;
            sauv->suivant=q;
            q=q->bas;
            sauv=sauv->bas;
        }else
        {
           sauv= sauv->suivant;
        }

    }//FTQ 3
*niv_max_tete=tete;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void rech_val(ptr_sk_maillon  niv_max_tete,  ptr_sk_maillon * adr ,ptr_sk_maillon * prec  ,bool *existe,  int v)
{
    ptr_sk_maillon p=niv_max_tete,q;
    *existe=false;
    while(p!=NULL && !(*existe))
    {   comple ++;
        if( p->suivant==NULL || p->suivant->valeur>v )
        {
            p=p->bas;
        }else
        {
            *existe=(p->suivant->valeur==v);
            q=p;
            p=p->suivant;
        }
    }

*adr=p;
*prec=q;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void liberer(ptr_sk_maillon *adr)
{
    ptr_sk_maillon prec;
    while(*adr!=NULL)
    {
      prec=*adr;
      *adr=(*adr)->haut;
      free(prec)  ;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mis_ajour_tete(ptr_sk_maillon *t)
{// role: dans le cas ou le niveau du  maillon supprem� est  le seul du niveau max on fait decendre le niveau de la tete
    ptr_sk_maillon prec=*t;
while((*t)->suivant==NULL)
{
    prec=*t;
(*t)=prec->bas;
  free(prec);
  (*t)->haut=NULL;

}

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void suppr_val(ptr_sk_maillon *niv_max_tete,int v,bool *existe)
{
    ptr_sk_maillon tete=*niv_max_tete,sauv,adr,prec;

    rech_val(tete,&adr,&sauv,&*existe,v);
    if(*existe)
    {
        while(sauv!=NULL)
        {
            if(sauv->suivant==adr)// on commpare avec adr(pas avec la valeur) pour etre sur que c'est le meme �l�ment
            {
                sauv->suivant=adr->suivant;
                sauv=sauv->bas;
                prec=adr;
                adr=adr->bas;
                free(prec);
            }else
            {
               sauv=sauv->suivant;
            }
        }
        mis_ajour_tete(&*niv_max_tete);
    }

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////SSS
suppr_tt_occu(ptr_sk_maillon * tete,int v)//supprime toutes les occurence d'une valeur donn�e
{
    bool existe=true;
    while(existe)
    {
        suppr_val(&*tete,v,&existe);
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void color(int text, int fond) //Couleurs pour console windows
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,fond*16+text);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void parcour_niv(ptr_sk_maillon tt,ptr_sk_maillon qq)
{int ch;
ptr_sk_maillon p;

    color(14,0);printf("\n                   Entrer le niveau que vous souhaiter afficher sa liste :");
    color(12,0);printf("\n                   NB!:pour parcourir la liste du niveau max entrez -1\n");color(15,0);
    scanf("  %d",&ch);
    p=tt;
    if(ch==-1)
    {
        p=qq;
    }else
    {
        while(p!=NULL && p->num!=ch)
    {
        p=p->haut;
    }

    }

     if(p==NULL)
    {
        printf("le niveau est superieur au niveau max (niveau max = %d)\n",qq->num);
    }else
    {
        p=p->suivant;
       while(p!=NULL)
      {

        printf("| %d",p->valeur);
        p=p->suivant;
      }
       printf("\n");
    }


}
///////////////////////////////////////////////////////////////////////////////////fonctions d'affichages///////////////////////////////////////////////////////////////////
void menu()
{
    int i=50;
    color(3,0);
printf("\n\t\t\t\t\t /$$      /$$ /$$$$$$$$ /$$   /$$ /$$   /$$");Sleep(i);
printf("\n\t\t\t\t\t| $$$    /$$$| $$_____/| $$$ | $$| $$  | $$");Sleep(i);
printf("\n\t\t\t\t\t| $$$$  /$$$$| $$      | $$$$| $$| $$  | $$");Sleep(i);
printf("\n\t\t\t\t\t| $$ $$/$$ $$| $$$$$   | $$ $$ $$| $$  | $$");color(15,0);Sleep(i);
printf("\n\t\t\t\t\t| $$  $$$| $$| $$__/   | $$  $$$$| $$  | $$");Sleep(i);
printf("\n\t\t\t\t\t| $$\\  $ | $$| $$      | $$\\  $$$| $$  | $$");Sleep(i);
printf("\n\t\t\t\t\t| $$ \\/  | $$| $$$$$$$$| $$ \\  $$|  $$$$$$/");Sleep(i);
printf("\n\t\t\t\t\t|__/     |__/|________/|__/  \\__/ \\______/ ");Sleep(i);


        //printf("VEUILLEZ ENTRER VOTRE CHOIX");
color(14,0);
        printf("\n\n                                         1\\Creer une skip liste aleatoire.");Sleep(i);
        printf("\n\n                                         2\\Rechercher une valeur dans la skip liste.");Sleep(i);
        printf("\n\n                                         3\\Inserer une valeur dans la skip liste.");Sleep(i);
        printf("\n\n                                         4\\Supprimer une valeur dans la skip liste.");Sleep(i);
        printf("\n\n                                         5\\Parcourir la skip liste.");Sleep(i);
        printf("\n\n                                         6\\Quitter le programme.");Sleep(i);
        printf("\n\n");color(6,0);
        printf("   VEUILLEZ ENTRER VOTRE CHOIX:");color(15,0);


}
void tp1llc()
{
                    int i=50,tp1=3,llc=15;
                    color(tp1,0);printf("\n                 /$$$$$$$$ /$$$$$$$         /$$$$$$    /$$  ");color(llc,0);    printf("     /$$       /$$        /$$$$$$ ");Sleep(i);
                    color(tp1,0);printf("\n                 |__  $$__/| $$__  $$       /$$$_  $$ /$$$$ ");color(llc,0);    printf("    | $$      | $$       /$$__  $$");Sleep(i);
                    color(tp1,0);printf("\n                   | $$   | $$  \\ $$      | $$$$\\ $$|_  $$  ");color(llc,0);  printf(" /$$| $$      | $$      | $$  \\__/");Sleep(i);
                    color(tp1,0);printf("\n                   | $$   | $$$$$$$/      | $$ $$ $$  | $$  ");color(llc,0);    printf("|__/| $$      | $$      | $$      ");Sleep(i);
                    color(tp1,0);printf("\n                   | $$   | $$____/       | $$\\ $$$$  | $$  ");color(llc,0);   printf("    | $$      | $$      | $$      ");Sleep(i);
                    color(tp1,0);printf("\n                   | $$   | $$            | $$ \\ $$$  | $$  ");color(llc,0);   printf(" /$$| $$      | $$      | $$    $$");Sleep(i);
                    color(tp1,0);printf("\n                   | $$   | $$            |  $$$$$$/ /$$$$$$");color(llc,0);    printf("|__/| $$$$$$$$| $$$$$$$$|  $$$$$$/");Sleep(i);
                    color(tp1,0);printf("\n                   |__/   |__/             \______/ |______/");color(llc,0);    printf("    |________/|________/ \\______/ ");Sleep(i);
                   // color(tp1,0);printf("\n                                                            ");color(llc,0);    printf(" ");
      color(15,0);printf("\n.\n\t\t\t     Annee Universitaire 2022-2023 | Semestre 2\n");Sleep(i);
                    color(14,0);printf("\n                                         Realiser par: \n");Sleep(i);
                    color(14,0);printf("\n                                               -BECHARAI MOHAMED KHALIL\n ");Sleep(i);
                    color(14,0);printf("\n                                               -NEMAMECHA OUSSAMA\n ");Sleep(i);
                    color(14,0);printf("\n                                                G10 ");Sleep(i);
                    color(12,0);printf("\n\n\n                             APPUIER SUR [ENTRER] POUR ALLER AU MENU PRINCIPALE \n");color(15,0); getchar();
    color(15,0);
}
void test_esi()
{system("cls");
    int e=3,si=15,ecole=15,pc=6,tp1=3,llc=15;
   color(63,0);

       color(e,0);printf("  ______  ");color(si,0);printf(" _____   _____ ");color(ecole,0);printf("              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
     color(e,0);printf("\n |  ____| ");color(si,0);printf("/ ____| |_   _|");color(ecole,0);printf("               Ecole Nationale superieure d'informatique  ");
     color(e,0);printf("\n | |__    ");color(si,0);printf("| (___    | |  ");color(ecole,0);printf("              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
     color(e,0);printf("\n |  __|   ");color(si,0);printf("|___  |   | |  ");color(ecole,0);
     color(e,0);printf("\n | |____  ");color(si,0);printf("____) |  _| |_ ");color(ecole,0);
     color(e,0);printf("\n |______| ");color(si,0);printf("|_____/ |_____|");color(ecole,0);

     color(15,0);printf("\n.\n.");

}
void tp_goodbye(void) // Cette fonction imprime le splashscreen du tp
{
    int i=50;
    system("cls");
    color(6,0); \
    printf("\n\n\n\n\n\n\t\t\t");
                                                         printf("\n\t\t\t            /$$      /$$ /$$$$$$$$ /$$$$$$$   /$$$$$$  /$$$$$$");Sleep(i);
                                                         printf("\n\t\t\t           | $$$    /$$$| $$_____/| $$__  $$ /$$__  $$|_  $$_/");Sleep(i);
                                                         printf("\n\t\t\t           | $$$$  /$$$$| $$      | $$  \\ $$| $$  \\__/  | $$  ");Sleep(i);
                                                         printf("\n\t\t\t           | $$ $$/$$ $$| $$$$$   | $$$$$$$/| $$        | $$  ");Sleep(i);
                                                         printf("\n\t\t\t           | $$  $$$| $$| $$__/   | $$__  $$| $$        | $$  ");Sleep(i);
                                                         printf("\n\t\t\t           | $$\\  $ | $$| $$      | $$  \\ $$| $$    $$  | $$  ");Sleep(i);
                                                         printf("\n\t\t\t           | $$ \\/  | $$| $$$$$$$$| $$  | $$|  $$$$$$/ /$$$$$$");Sleep(i);
                                                         printf("\n\t\t\t           |__/     |__/|________/|__/  |__/ \______/ |______/");Sleep(i);


    printf("\n\n\t\t\t Goodbye.");
    color(6,0);
    printf("\n\n\n Appuyez sur [ENTREE] pour quitter...");
    getchar();
    getchar();
    color(15,0);
    //printf("\n\n");
    //system("PAUSE");
    system("cls");

}


#endif // BIB_TP1_H_INCLUDED
