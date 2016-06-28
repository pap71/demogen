#include <gtk/gtk.h>
#include <string.h>
#include "genfen.h"

void boutpers(GtkWidget *widx, gpointer data);
void bok_pers(GtkWidget *widget, gpointer data);
void bcancel_pers(GtkWidget *widget, gpointer data);

typedef struct {
int Idi;
char Nom[32];
char Prenom[40];
char Sex;
int Sosa;
int Aged;
char DateNaiss[40];
char PlaceNaiss[40];
char DateDeces[40];
char PlaceDeces[40];
int Fams[6];
char FamilyS[40];
int FamilyC;
char Notes[1024];
} S_PERSON;
S_PERSON pers;

enum {
IDI,
NOM,
PREN,
SEX,
SOSA,
AGE,
DATNAIS,
DATDECE,
OUNAIS,
OUDECE,
IDFAM,
IDCOUPL,

};

#define lil 15
#define lis 10
#define co1 5
#define lil2 45
#define lis2 40
#define co2 280

#define DEPS(zz) (char*)&pers.zz-(char*)&pers
static DEF_S_FQ s_fpers[]= {
{co1+35,lis,IDI,DEPS(Idi),NULL,NULL,SAISINT,5,NULL,"%d"},
{co1+127,lis,SOSA,DEPS(Sosa),NULL,NULL,SAISINT,5,NULL,"%d"},
{co1+212,lis,SEX,DEPS(Sex),NULL,NULL,SAISCHAR,2,NULL,"%c"},
{co1+290,lis,AGE,DEPS(Aged),NULL,NULL,LIBINT,5,NULL,"%d"},
{co1+70,lis2,NOM,DEPS(Nom),NULL,NULL,SAISCHAR,20,NULL,"%s"},
{co2+40,lis2,PREN,DEPS(Prenom),NULL,NULL,SAISCHAR,29,NULL,"%s"},
{co1+120,lis2+30,DATNAIS,DEPS(DateNaiss),NULL,NULL,SAISCHAR,20,NULL,"%s"},
{co2+40,lis2+30,OUNAIS,DEPS(PlaceNaiss),NULL,NULL,SAISCHAR,29,NULL,"%s"},
//{co1+35,lis,IDI,0,NULL,NULL,LIBCHAR,32,NULL,"%s"},
{-1,-1,0,0,NULL,0,0,0,NULL,NULL}
};
#undef DEPS

static DEF_L_FQ lib_fpers[]= {
{co1,lil,NULL,0,"Num"},
{co1+90,lil,NULL,0,"Sosa"},
{co1+180,lil,NULL,0,"Sexe"},
{co1+260,lil,NULL,0,"Age deces"},
{co1,lil2,NULL,0,"NOM"},
{co2-30,lil2,NULL,0,"Prénoms"},
{co1,lil2+30,NULL,0,"Date naissance"},
{co2-5,lil2+30,NULL,0,"Lieu.N"},
{co1,lil2+60,NULL,0,"Date deces"},
{co2-5,lil2+60,NULL,0,"Lieu.D"},
{-1,-1,NULL,0,NULL}
};

FENQ fen_pers = {
NULL,//GtkWidget *win;
"Fiche Personne",	//char *fentit;
450,	//int fenlarg;	/*largeur fenetre*/
300,	//int fenhaut;	/*hauteur  fenetre*/
10,	//int posx;	/* coin gauche x*/
10,	//int posy;	/* coin gauche y*/
//0,	//int sizsvt;	// sizeof struct des variables
&s_fpers[0],	// pointeur sur definition zones saisie
&lib_fpers[0],	// pointeur sur definition libelle
&boutpers	// fonction ajout de bouton
};

void boutpers(GtkWidget *widx, gpointer data)
{
GtkWidget *bpers;
GtkWidget *bcancel;
//GtkWidget *bchoix;
GdkColor   colortabs;
colortabs.red=30000;//65535;
colortabs.green=45000;//65535;
colortabs.blue=0;

/* bchoix =  gtk_button_new_with_label("Choix");
  gtk_widget_set_size_request(bchoix, 80, 25);
  gtk_fixed_put(GTK_FIXED(widx), bchoix,330,13);
*/
 bpers = gtk_button_new_from_stock(GTK_STOCK_SAVE);
//  gtk_widget_set_size_request(bpers, 60, 25);
  gtk_fixed_put(GTK_FIXED(widx), bpers,200,290);
 bcancel =  gtk_button_new_from_stock(GTK_STOCK_CANCEL);
  gtk_fixed_put(GTK_FIXED(widx), bcancel,100,290);

gtk_widget_modify_bg (bpers, GTK_STATE_NORMAL, &colortabs);
gtk_widget_modify_bg (bcancel, GTK_STATE_NORMAL, &colortabs);
//gtk_widget_modify_bg (bchoix, GTK_STATE_NORMAL, &colortabs);

g_signal_connect(G_OBJECT(bpers), "clicked", G_CALLBACK (bok_pers),NULL);
g_signal_connect(G_OBJECT(bcancel), "clicked", G_CALLBACK (bcancel_pers),NULL);
  g_signal_connect_swapped(G_OBJECT(fen_pers.win), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(fen_pers.win));
//g_signal_connect(G_OBJECT(bchoix), "clicked", G_CALLBACK (bchoix_pers),NULL);
}


void bok_pers(GtkWidget *widget, gpointer data)
{
printf("Id= %d Sosa=%d Sexe=%c\n",pers.Idi,pers.Sosa,pers.Sex);
printf("Nom= %s Prenom=%s\n",pers.Nom,pers.Prenom);
//gtk_widget_destroy(fen_pers.win);
//fen_pers.win = NULL;
}

void bcancel_pers(GtkWidget *widget, gpointer data)
{
gtk_widget_destroy(fen_pers.win);
fen_pers.win = NULL;
}

/*void affi_pers()
{
char zn[12];
init_pers();
char *pnf = NULL;
//bloqchfq=1;
//pnf = strrchr (pers.fimipa, '/');
pnf = strrchr (pers.fimipa, SLAF);
if ( pnf != NULL)
  gtk_label_set_text(GTK_LABEL(s_fpers[MIPA].wdg),pnf+1);
sprintf(zn,"%d",pers.lifa);
gtk_entry_set_text(GTK_ENTRY (s_fpers[LIFA].wdg),zn);
//bloqchfq=0;
//   gtk_widget_grab_focus (bcancel);
}*/

int main(int argc, char** argv)
{
  gtk_init(&argc, &argv);
  crefenq ((FENQ*) &fen_pers, (void*) &pers);
// affi_pers();
 gtk_widget_show_all(fen_pers.win);
  gtk_main();
 return 0;
}

