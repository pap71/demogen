Aide à la création et (surtout) modification de fenêtres GTK pour des applications de gestion avec beaucoup de données textes à saisir (libellés, montant, dates, etc).

Le module de démonstration est demogenfq.c qui définit une fenêtre (fiche) de saisie ( et d'affichage) d'une personne pour une application de généalogie.

demogenfq.c utilise les modules utilitaires du répertoire 'util'.
Ici on a besoin d'une fenêtre quelconque, c'est à dire que les zones à saisir peuvent être positionnées n'importe où.

======Définir la structure des données à saisir et éventuellement de travail.
mémorise le résultat de la saisie
typedef struct {
int Idi;
char Nom[32];
char Prenom[40];
...etc
} S_PERSON;
S_PERSON pers;
 
===****===Définition de la fenêtre GTK
Il faut renseigner les 3 structures suivantes en les laissant dans le même ordre que l'exemple.

====Enumération des données à saisir (trés utile par la suite)
enum {
IDI,
NOM,
PREN,
etc..
};

====Détail de chaque donnée à saisir (Edit GTK)
macro indispensable reliant à la structure donnée (ici  pers)
#define DEPS(zz) (char*)&pers.zz-(char*)&pers
Chaque ligne définit une donnée à saisir
typedef struct  {	//def zones saisie
int cox;		// colonne
int lyg;		// ligne
int idcol;		// ident colonne (numéro)
int deps;		// deplacement dans structure
GtkWidget *wdg;		// entry
void *memcell;		// adresse absolue de memorisation de la variable
int typ;		// type de donnée
int laf;		// longueur zone en caractere
int (*fonc)();		// fonction utilisateur controle action
char *forma;		// format affichage
} DEF_S_FQ;

static DEF_S_FQ s_fpers[]= {
{co1+35,lis,IDI,DEPS(Idi),NULL,NULL,SAISINT,5,NULL,"%d"},
{co1+127,lis,SOSA,DEPS(Sosa),NULL,NULL,SAISINT,5,NULL,"%d"},
{co1+216,lis,SEX,DEPS(Sex),NULL,NULL,SAISCHAR,2,NULL,"%c"},
etc ...
// dernière ligne obligatoire
{-1,-1,0,0,NULL,0,0,0,NULL,NULL}
};
#undef DEPS

====Détail des libellés
typedef struct  {	//def libelle
int cox;
int lyg;
GtkWidget *wdgl;	//  libel
int typ;		// normal ou separateur 0,1
char *libel;		// libelle
} DEF_L_FQ;

static DEF_L_FQ lib_fpers[]= {
{co1,lil,NULL,0,"Num"},
{co1+90,lil,NULL,0,"Sosa"},
{co1+180,lil,NULL,0,"Sexe"},
etc ..
// dernière ligne obligatoire
{-1,-1,NULL,0,NULL}
};

====La fenêtre
FENQ fen_pers = {
NULL,//GtkWidget *win;
"Fiche Personne",	//char *fentit;
450,	//int fenlarg;	/*largeur fenetre*/
300,	//int fenhaut;	/*hauteur  fenetre*/
10,	//int posx;	/* coin gauche x*/
10,	//int posy;	/* coin gauche y*/
&s_fpers[0],	// pointeur sur definition zones saisie
&lib_fpers[0],	// pointeur sur definition libelle
&boutpers	// fonction ajout de bouton
};


