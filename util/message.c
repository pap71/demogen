#include <gtk/gtk.h>
//#include <string.h>
//#include "genfen.h"

typedef struct  {
int num;
char* messag;
} S_MES;

static S_MES tlmes[] = {
{0,"Enregistrement refusé erreur de saisie non corrigée"},
{1,"zone saisie trop longue"},
{2,"On efface le graphe ?"},
{3,"Ouverture d'un fichier ?"},
{4,"cette zone ne peut pas rester a blanc (vide)"},
{5,""},
{6,"blanc=consultation, c(reation), m(odification), s(uppression) "},
{7,""},
{8,"inconnu"},
{9,"pas de blanc en debut de saisie"},
{10,""},
{11," "},
{12,""},
{13,"Erreur de date"},
{52," "}
}; 
gboolean message(int num)
{
GtkWidget *pAbout;
//gchar *smes = "http://www.gtk-fr.org";
    /* Creation de la boite de message */
    /* Type : Information -> GTK_MESSAGE_INFO */
    /* Bouton : 1 OK -> GTK_BUTTONS_OK */
//pAbout = gtk_message_dialog_new (GTK_WINDOW(data),
pAbout = gtk_message_dialog_new (NULL,
   GTK_DIALOG_MODAL,
   GTK_MESSAGE_INFO,
   GTK_BUTTONS_CLOSE, //OK,
   " MD\n%s",
   tlmes[num].messag);
    /* Affichage de la boite de message */
gtk_dialog_run(GTK_DIALOG(pAbout));
    /* Destruction de la boite de message */
gtk_widget_destroy(pAbout);
return FALSE;
}


gboolean messavar(char* vmes)
{
GtkWidget *pAbout;
//pAbout = gtk_message_dialog_new (GTK_WINDOW(winp),
pAbout = gtk_message_dialog_new (NULL,
   GTK_DIALOG_MODAL,
   GTK_MESSAGE_INFO,
   GTK_BUTTONS_OK, //CLOSE, //OK,
   "INFO\n%s",
   vmes);
    /* Affichage de la boite de message */
gtk_dialog_run(GTK_DIALOG(pAbout));
gtk_widget_destroy(pAbout);
return FALSE;
}

int question(int num)
{
GtkWidget *pDialog;
int ret=0;
pDialog = gtk_message_dialog_new(NULL, 
	GTK_DIALOG_MODAL,
	GTK_MESSAGE_QUESTION,
	GTK_BUTTONS_YES_NO,
	"Que faire ?\n%s",
	tlmes[num].messag);
switch(gtk_dialog_run(GTK_DIALOG(pDialog)))
{
case GTK_RESPONSE_YES:
 ret = 0;  
   break;
 case GTK_RESPONSE_NO:
 ret = -1;  
   break;
 default:
 ret = -1;  
   break;
    }
gtk_widget_destroy(pDialog);
return ret;
}

