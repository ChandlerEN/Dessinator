/***********************************************************************/
/* Projet Dessinator                                                   */
/*---------------------------------------------------------------------*/
/* Module : affichageTexte.c                                           */
/* Numéro de version : 0.1                                             */
/* Date : 20/12/2020                                                   */
/* Auteurs : Chandler NGUYEN                                           */
/*---------------------------------------------------------------------*/
/* Ce module contient l'implémentation des fonctions dont la signature */
/* a été écrite dans le fichier d'entête.                              */
/***********************************************************************/

#include "affichageTexte.h"
#include <stdio.h>
#include <stdlib.h>

void printf_Point2D (Point2D p){
    printf ("Point 2D :\n");
    printf ("- abscisse : %.3f\n", p.x);
    printf ("- ordonnee : %.3f\n", p.y);

    printf ("- Rouge    : %.3f\n", p.color.rouge);
    printf ("- Vert     : %.3f\n", p.color.vert);
    printf ("- Bleu     : %.3f\n", p.color.bleu);
    printf ("\n");
 }

void printf_Segment2D (Segment2D s)
    {
        printf ("Segment 2D : \n");
        printf ("- Point de depart : (%.3lf , %.3lf) \n", s.departX, s.departY);
        printf ("- Point d'arrivee : (%.3lf , %.3lf) \n", s.arriveeX, s.arriveeY);

        printf ("- Rouge           : %.3f\n", s.color.rouge);
        printf ("- Vert            : %.3f\n", s.color.vert);
        printf ("- Bleu            : %.3f\n", s.color.bleu);
        printf ("\n");
    }

void printf_Rectangle2D (Rectangle2D r)
    {
        printf ("Rectangle 2D : \n");
        printf ("- Point A         : (%.3lf , %.3lf) \n", r.Ax, r.Ay);
        printf ("- Point B         : (%.3lf , %.3lf) \n", r.Bx, r.By);
        printf ("- Dimension       :  %.3lf \n", r.dimension);

        printf ("- Rouge           : %.3f\n", r.color.rouge);
        printf ("- Vert            : %.3f\n", r.color.vert);
        printf ("- Bleu            : %.3f\n", r.color.bleu);
        printf ("\n");
    }

void printf_Cercle2D (Cercle2D c)
    {
        printf ("Cercle 2D : \n");
        printf ("- Centre   : (%.3lf , %.3lf) \n", c.centre_X, c.centre_Y);
        printf ("- Rayon    :  %.3lf \n", c.rayon);

        printf ("- Rouge    : %.3f\n", c.color.rouge);
        printf ("- Vert     : %.3f\n", c.color.vert);
        printf ("- Bleu     : %.3f\n", c.color.bleu);
        printf ("\n");
    }

void printf_Arc2D (Arc2D a)
    {
        printf ("Arc de cercle 2D : \n");
        printf ("- Centre          : (%.3lf , %.3lf) \n", a.centre_X, a.centre_Y);
        printf ("- Rayon           :  %.3lf \n", a.rayon);
        printf ("- Angle de depart :  %.3lf \n", a.angleDepart);
        printf ("- Angle d'arrivee :  %.3lf \n", a.angleArrivee);

        printf ("- Rouge           : %.3f\n", a.color.rouge);
        printf ("- Vert            : %.3f\n", a.color.vert);
        printf ("- Bleu            : %.3f\n", a.color.bleu);
        printf ("\n");
    }

void printf_Figure2D (Figure2D* f)
    {
        if (f){     // (f != NULL)
            switch(f->type){
                case 1 : printf_Point2D (f->point);break;
                case 2 : printf_Segment2D (f->segment); break;
                case 3 : printf_Rectangle2D (f->rectangle); break;
                case 4 : printf_Cercle2D (f->cercle); break;
                case 5 : printf_Arc2D (f->arc); break;
            }
            printf ("\n");
        }
    }
