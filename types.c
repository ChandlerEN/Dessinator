/***********************************************************************/
/* Projet Dessinator                                                   */
/*---------------------------------------------------------------------*/
/* Module : types.c                                                    */
/* Numéro de version : 0.1                                             */
/* Date : 07/03/2021                                                   */
/* Auteurs : Chandler NGUYEN                                           */
/*---------------------------------------------------------------------*/
/* Ce module contient l'implémentation des fonctions dont la signature */
/* a été écrite dans le fichier d'entête.                              */
/***********************************************************************/

#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

Figure2D* creerPoint (double x,
                      double y,
                      double rouge,
                      double vert,
                      double bleu)
{
    Figure2D* F2D = (Figure2D*) malloc (sizeof(Figure2D));

    if (F2D == NULL)
    {
        perror("Erreur d'allocation");
        exit(-1);
    }

    F2D->type = POINT;

    F2D->point.type             = POINT;
    F2D->point.x                = x;
    F2D->point.y                = y;
    F2D->point.color.rouge      = rouge;
    F2D->point.color.vert       = vert;
    F2D->point.color.bleu       = bleu;

    return F2D;
}

Figure2D* creerSegment (double departX,
                        double departY,
                        double arriveeX,
                        double arriveeY,
                        double rouge,
                        double vert,
                        double bleu)
{
    Figure2D* F2D = (Figure2D*) malloc (sizeof(Figure2D));

    if (F2D == NULL)
    {
        perror("Erreur d'allocation");
        exit(-1);
    }

    F2D->type = SEGMENT;

    F2D->segment.type             = SEGMENT;
    F2D->segment.departX          = departX;
    F2D->segment.departY          = departY;
    F2D->segment.arriveeX         = arriveeX;
    F2D->segment.arriveeY         = arriveeY;
    F2D->segment.color.rouge      = rouge;
    F2D->segment.color.vert       = vert;
    F2D->segment.color.bleu       = bleu;

    return F2D;
}

Figure2D* creerRectangle (double Ax,
                          double Ay,
                          double Bx,
                          double By,
                          double dimension,
                          double rouge,
                          double vert,
                          double bleu)
{
    Figure2D* F2D = (Figure2D*) malloc (sizeof(Figure2D));

    if (F2D == NULL)
    {
        perror("Erreur d'allocation");
        exit(-1);
    }

    F2D->type = RECTANGLE;

    F2D->rectangle.type             = RECTANGLE;
    F2D->rectangle.Ax               = Ax;
    F2D->rectangle.Ay               = Ay;
    F2D->rectangle.Bx               = Bx;
    F2D->rectangle.By               = By;
    F2D->rectangle.dimension        = dimension;
    F2D->rectangle.color.rouge      = rouge;
    F2D->rectangle.color.vert       = vert;
    F2D->rectangle.color.bleu       = bleu;

    return F2D;
}

Figure2D* creerCercle (double centreX,
                       double centreY,
                       double rayon,
                       double rouge,
                       double vert,
                       double bleu)
{
    Figure2D* F2D = (Figure2D*) malloc (sizeof(Figure2D));

    if (F2D == NULL)
    {
        perror("Erreur d'allocation");
        exit(-1);
    }

    F2D->type = CERCLE;

    F2D->cercle.type             = CERCLE;
    F2D->cercle.centre_X         = centreX;
    F2D->cercle.centre_Y         = centreY;
    F2D->cercle.rayon            = rayon;
    F2D->cercle.color.rouge      = rouge;
    F2D->cercle.color.vert       = vert;
    F2D->cercle.color.bleu       = bleu;

    return F2D;
}

Figure2D* creerArcDeCercle (double centreX,
                            double centreY,
                            double rayon,
                            double angleDepart,
                            double angleArrivee,
                            double rouge,
                            double vert,
                            double bleu)
{
    Figure2D* F2D = (Figure2D*) malloc (sizeof(Figure2D));

    if (F2D == NULL)
    {
        perror("Erreur d'allocation");
        exit(-1);
    }

    F2D->type = ARC_DE_CERCLE;

    F2D->arc.type             = ARC_DE_CERCLE;
    F2D->arc.centre_X         = centreX;
    F2D->arc.centre_Y         = centreY;
    F2D->arc.rayon            = rayon;
    F2D->arc.angleDepart      = angleDepart;
    F2D->arc.angleArrivee     = angleArrivee;
    F2D->arc.color.rouge      = rouge;
    F2D->arc.color.vert       = vert;
    F2D->arc.color.bleu       = bleu;

    return F2D;
}

void supprimerFigure (Figure2D* figure)
{
    if (figure){
        free(figure);
    }
}
