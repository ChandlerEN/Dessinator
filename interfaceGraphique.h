/***********************************************************************/
/* Projet Dessinator                                                   */
/*---------------------------------------------------------------------*/
/* Module : interfaceGraphique.h                                       */
/* Numéro de version : 0.1                                             */
/* Date : 13/06/2021                                                   */
/* Auteurs : Chandler NGUYEN                                           */
/*---------------------------------------------------------------------*/
/* Ce module contient la définition des constantes symboliques et des  */
/* qui sont utilisés dans d'autres modules.                            */
/***********************************************************************/

#ifndef INTERFACEGRAPHIQUE_H_INCLUDED
#define INTERFACEGRAPHIQUE_H_INCLUDED

#include "types.h"
#include "ListeChaine.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <cairo/cairo.h>
#include <cairo/cairo-pdf.h>
#include <cairo/cairo-svg.h>

#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <gdk/gdkkeysyms.h>


void ouvrirLaFenetreGraphique (int x,
                               int y,
                               int largeur,
                               int hauteur,
                               char* titre,
                               int* argc,
                               char*** argv);

void fermerLaFenetreGraphique ();

void gererLesEvenements ();

void dessiner_Point (double x,
                     double y,
                     double rouge,
                     double vert,
                     double bleu);

void dessiner_Segment (double x1,
                       double y1,
                       double x2,
                       double y2,
                       double rouge,
                       double vert,
                       double bleu);

void dessiner_Rectangle (double x1,
                         double y1,
                         double x2,
                         double y2,
                         double autreDimension,
                         double rouge,
                         double vert,
                         double bleu);

void dessiner_Cercle (double x,
                      double y,
                      double rayon,
                      double rouge,
                      double vert,
                      double bleu);

void dessiner_ArcDeCercle (double x,
                           double y,
                           double rayon,
                           double angleDeDepart,
                           double angleDArrivee,
                           double rouge,
                           double vert,
                           double bleu);

void on_destroy_event (GtkWidget* pWidget,
                       gpointer pData);

gboolean on_draw_event (GtkWidget* widget,
                        cairo_t* contexte,
                        gpointer user_data);

void dessiner_Figure (gpointer figure,
                      gpointer contexte);

//--------------------//

void on_ouvrir_event (GtkWidget *pWidget, gpointer pData);

void on_sauvegarder_event (GtkWidget *pWidget, gpointer pData);

void on_exporter_event (GtkWidget *pWidget, gpointer pData);

void on_couleur_event (GtkWidget *pWidget, gpointer pData);

void on_dessin_event (GtkWidget *pWidget, int pData);

//--------------------//

#endif // INTERFACEGRAPHIQUE_H_INCLUDED
