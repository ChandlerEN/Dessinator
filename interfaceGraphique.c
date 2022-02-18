/***********************************************************************/
/* Projet Dessinator                                                   */
/*---------------------------------------------------------------------*/
/* Module : interfaceGraphique.c                                       */
/* Numéro de version : 0.1                                             */
/* Date : 13/06/2021                                                   */
/* Auteurs : Chandler NGUYEN                                           */
/*---------------------------------------------------------------------*/
/* Ce module contient l'implémentation des fonctions dont la signature */
/* a été écrite dans le fichier d'entête.                              */
/***********************************************************************/

#include "interfaceGraphique.h"

ListeChainee* dessin;
GtkWidget* fenetre;


void ouvrirLaFenetreGraphique (int x,
                               int y,
                               int largeur,
                               int hauteur,
                               char* titre,
                               int* argc,
                               char*** argv)
{
    dessin = creerListe ("Dessin");

    gtk_init (argc, argv);  // &argc, &argv

//    GtkWidget* fenetre;
    GtkWidget* canvas;
    GtkWidget* vBox;
    GtkWidget* barreDeMenu;

    GtkWidget* Fichier;
    GtkWidget* itemFichier;
    GtkWidget* itemOuvrir;
    GtkWidget* itemSauvegarder;
    GtkWidget* itemExporter;
    GtkWidget* itemQuitter;

    GtkWidget* Dessiner;
    GtkWidget* itemDessiner;
    GtkWidget* itemPoint;
    GtkWidget* itemSegment;
    GtkWidget* itemRectangle;
    GtkWidget* itemCercle;
    GtkWidget* itemArc;
    GtkWidget* itemCouleur;

//    GtkWidget* label;

    fenetre     = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    canvas      = gtk_drawing_area_new ();
    vBox        = gtk_vbox_new(FALSE, 0);
    barreDeMenu = gtk_menu_bar_new ();

    Fichier         = gtk_menu_new ();
    itemFichier     = gtk_menu_item_new_with_label ("Fichier");
    itemOuvrir      = gtk_menu_item_new_with_label ("Ouvrir");
    itemSauvegarder = gtk_menu_item_new_with_label ("Sauvegarder");
    itemExporter    = gtk_menu_item_new_with_label ("Exporter");
    itemQuitter     = gtk_menu_item_new_with_label ("Quitter");

    Dessiner        = gtk_menu_new ();
    itemDessiner    = gtk_menu_item_new_with_label ("Dessiner");
    itemPoint       = gtk_menu_item_new_with_label ("Point");
    itemSegment     = gtk_menu_item_new_with_label ("Segment");
    itemRectangle   = gtk_menu_item_new_with_label ("Rectangle");
    itemCercle      = gtk_menu_item_new_with_label ("Cercle");
    itemArc         = gtk_menu_item_new_with_label ("Arc");
    itemCouleur     = gtk_menu_item_new_with_label ("Couleur");

    gtk_menu_item_set_submenu   (GTK_MENU_ITEM  (itemFichier), Fichier);
    gtk_menu_shell_append       (GTK_MENU_SHELL (barreDeMenu), itemFichier);
    gtk_menu_shell_append       (GTK_MENU_SHELL (Fichier)    , itemOuvrir);
    gtk_menu_shell_append       (GTK_MENU_SHELL (Fichier)    , itemSauvegarder);
    gtk_menu_shell_append       (GTK_MENU_SHELL (Fichier)    , itemExporter);
    gtk_menu_shell_append       (GTK_MENU_SHELL (Fichier)    , itemQuitter);

    gtk_menu_item_set_submenu   (GTK_MENU_ITEM  (itemDessiner), Dessiner);
    gtk_menu_shell_append       (GTK_MENU_SHELL (barreDeMenu) , itemDessiner);
    gtk_menu_shell_append       (GTK_MENU_SHELL (Dessiner)    , itemPoint);
    gtk_menu_shell_append       (GTK_MENU_SHELL (Dessiner)    , itemSegment);
    gtk_menu_shell_append       (GTK_MENU_SHELL (Dessiner)    , itemRectangle);
    gtk_menu_shell_append       (GTK_MENU_SHELL (Dessiner)    , itemCercle);
    gtk_menu_shell_append       (GTK_MENU_SHELL (Dessiner)    , itemArc);
    gtk_menu_shell_append       (GTK_MENU_SHELL (Dessiner)    , itemCouleur);

    gtk_box_pack_start (GTK_BOX (vBox), barreDeMenu, FALSE, FALSE, 0);
    gtk_box_pack_end   (vBox, canvas, TRUE, TRUE, 0);

//    gtk_box_pack_start (GTK_BOX (vBox), label, TRUE, TRUE, 0);
//    label = gtk_label_new ("Bonjour");

    gtk_window_set_position      (GTK_WINDOW (fenetre), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size  (GTK_WINDOW (fenetre), largeur, hauteur);
    gtk_window_set_title         (GTK_WINDOW (fenetre), titre);

    gtk_window_move(GTK_WINDOW(fenetre), x, y);

    gtk_container_add (GTK_CONTAINER(fenetre), vBox);

    g_signal_connect (G_OBJECT (fenetre), "destroy", G_CALLBACK (on_destroy_event), NULL);
    g_signal_connect (G_OBJECT (canvas) , "draw"   , G_CALLBACK (on_draw_event)   , NULL);

    g_signal_connect (G_OBJECT(itemOuvrir)      , "activate", G_CALLBACK (on_ouvrir_event)      , NULL);
    g_signal_connect (G_OBJECT(itemSauvegarder) , "activate", G_CALLBACK (on_sauvegarder_event) , NULL);
    g_signal_connect (G_OBJECT(itemExporter)    , "activate", G_CALLBACK (on_exporter_event)    , NULL);
    g_signal_connect (G_OBJECT(itemQuitter)     , "activate", G_CALLBACK (on_destroy_event)     , NULL); //on_quitter_activation

    g_signal_connect (G_OBJECT(itemPoint)       , "activate", G_CALLBACK (on_dessin_event)  , POINT);
    g_signal_connect (G_OBJECT(itemSegment)     , "activate", G_CALLBACK (on_dessin_event)  , SEGMENT);
    g_signal_connect (G_OBJECT(itemRectangle)   , "activate", G_CALLBACK (on_dessin_event)  , RECTANGLE);
    g_signal_connect (G_OBJECT(itemCercle)      , "activate", G_CALLBACK (on_dessin_event)  , CERCLE);
    g_signal_connect (G_OBJECT(itemArc)         , "activate", G_CALLBACK (on_dessin_event)  , ARC_DE_CERCLE);
    g_signal_connect (G_OBJECT(itemCouleur)     , "activate", G_CALLBACK (on_couleur_event) , NULL);

    gtk_widget_show_all (fenetre);

//    printf("ouvrirLaFenetreGraphique \n");
}

void fermerLaFenetreGraphique ()
{
    printf("fermerLaFenetreGraphique \n");

    detruireListe(dessin);

//    afficherListe (dessin);

    gtk_main_quit();
}

void gererLesEvenements ()
{
//    printf("gererLesEvenements \n");

    gtk_main();
}

void dessiner_Point (double x,
                     double y,
                     double rouge,
                     double vert,
                     double bleu)
{
    ajouterPoint (dessin, x, y, rouge, vert, bleu);
}

void dessiner_Segment (double x1,
                       double y1,
                       double x2,
                       double y2,
                       double rouge,
                       double vert,
                       double bleu)
{
    ajouterSegment (dessin, x1, y1, x2, y2, rouge, vert, bleu);
}

void dessiner_Rectangle (double x1,
                         double y1,
                         double x2,
                         double y2,
                         double autreDimension,
                         double rouge,
                         double vert,
                         double bleu)
{
    ajouterRectangle (dessin, x1, y1, x2, y2, autreDimension, rouge, vert, bleu);
}

void dessiner_Cercle (double x,
                      double y,
                      double rayon,
                      double rouge,
                      double vert,
                      double bleu)
{
    ajouterCercle (dessin, x, y, rayon, rouge, vert, bleu);
}

void dessiner_ArcDeCercle (double x,
                           double y,
                           double rayon,
                           double angleDeDepart,
                           double angleDArrivee,
                           double rouge,
                           double vert,
                           double bleu)
{
    ajouterArcDeCercle (dessin, x, y, rayon, angleDeDepart, angleDArrivee, rouge, vert, bleu);
}

void on_destroy_event (GtkWidget* pWidget, gpointer pData)
{
//    printf("on_destroy_event \n");

    fermerLaFenetreGraphique(dessin);
}

gboolean on_draw_event (GtkWidget* widget, cairo_t* contexte, gpointer user_data)
{
//    printf("on_draw_event \n");

    Noeud* temp = dessin->premier;

    while (temp != NULL)
    {
        dessiner_Figure(temp->contenu, contexte);

        temp = temp->suivant;
    }

    return FALSE;
}

void dessiner_Figure (gpointer figure, gpointer contexte)
{
    Figure2D* f = (Figure2D*) figure;
    cairo_t*  c = (cairo_t*)  contexte;

//    printf("dessiner_Figure \n");

    switch (f->type)
    {
    case POINT:         cairo_set_source_rgb (c,
                                              f->point.color.rouge,
                                              f->point.color.vert,
                                              f->point.color.bleu);
                        cairo_arc (c,
                                   f->point.x,
                                   f->point.y,
                                   1,
                                   0.1,
                                   2 * M_PI);
                        cairo_stroke (c);
                        break;

    case SEGMENT:       cairo_set_source_rgb (c,
                                              f->segment.color.rouge,
                                              f->segment.color.vert,
                                              f->segment.color.bleu);
//                        cairo_set_line_width (c, 1.0);
                        cairo_set_line_join (c, CAIRO_LINE_JOIN_MITER); // CAIRO_LINE_JOIN_BEVEL ou CAIRO_LINE_JOIN_ROUND

                        cairo_move_to (c, f->segment.departX, f->segment.departY);
                        cairo_line_to (c, f->segment.arriveeX, f->segment.arriveeY);
                        cairo_stroke  (c);
                        break;

    case RECTANGLE:     cairo_set_source_rgb (c,
                                              f->rectangle.color.rouge,
                                              f->rectangle.color.vert,
                                              f->rectangle.color.bleu);

//                        cairo_move_to     (c, f->rectangle.Ax, f->rectangle.Ay);
//                        cairo_rel_line_to (c, f->rectangle.dimension, -(f->rectangle.By - f->rectangle.Ay));
//                        cairo_rel_line_to (c,(f->rectangle.Bx - f->rectangle.Ax), (f->rectangle.By - f->rectangle.Ay));
//                        cairo_rel_line_to (c,-f->rectangle.dimension, (f->rectangle.By - f->rectangle.Ay));
//                        cairo_close_path  (c);

                        cairo_rectangle (c,
                                         f->rectangle.Ax,
                                         f->rectangle.Ay,
                                         f->rectangle.dimension,
//                                        (f->rectangle.Bx - f->rectangle.Ax),
                                        (f->rectangle.By - f->rectangle.Ay));

                        cairo_stroke (c);
                        break;

    case CERCLE:        cairo_set_source_rgb (c,
                                              f->cercle.color.rouge,
                                              f->cercle.color.vert,
                                              f->cercle.color.bleu);
                        cairo_arc (c,
                                   f->cercle.centre_X,
                                   f->cercle.centre_Y,
                                   f->cercle.rayon,
                                   0,
                                   2 * M_PI);
                        cairo_stroke (c);
                        break;

    case ARC_DE_CERCLE: cairo_set_source_rgb (c,
                                              f->arc.color.rouge,
                                              f->arc.color.vert,
                                              f->arc.color.bleu);
                        cairo_arc (c,
                                   f->arc.centre_X,
                                   f->arc.centre_Y,
                                   f->arc.rayon,
                                   f->arc.angleDepart,
                                  (f->arc.angleArrivee * (M_PI / 180)));
                        cairo_stroke (c);
                        break;
    }
    gtk_widget_queue_draw (fenetre);
}

//--------------------//

void on_ouvrir_event (GtkWidget *pWidget, gpointer pData)
{
    printf ("Ouvrir \n");
}

void on_sauvegarder_event (GtkWidget *pWidget, gpointer pData)
{
    printf ("Sauvegarder \n");
}

void on_exporter_event (GtkWidget *pWidget, gpointer pData)
{
    printf ("Exporter \n");
}

void on_couleur_event (GtkWidget *pWidget, gpointer pData)
{
    printf ("Couleur \n");
}

void on_dessin_event (GtkWidget *pWidget, int pData)
{
    switch(pData){
        case POINT          : printf("Point \n");          dessiner_Point          (10, 20,                ROUGE    ); break;
        case SEGMENT        : printf("Segment \n");        dessiner_Segment        (30, 40, 50, 60,        VERT     ); break;
        case RECTANGLE      : printf("Rectangle \n");      dessiner_Rectangle      (70, 80, 90, 100, 50,   BLEU     ); break;
        case CERCLE         : printf("Cercle \n");         dessiner_Cercle         (130, 140, 50,          BLANC    ); break;
        case ARC_DE_CERCLE  : printf("Arc de cercle \n");  dessiner_ArcDeCercle    (160, 170, 50, 0, 45,   MAGENTA  ); break;
    }
}

//void on_quitter_activation (GtkWidget *pWidget, gpointer pData)
//{
//    gtk_main_quit();
//}
