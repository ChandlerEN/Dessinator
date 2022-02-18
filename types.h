/***********************************************************************/
/* Projet Dessinator                                                   */
/*---------------------------------------------------------------------*/
/* Module : types.h                                                    */
/* Numéro de version : 0.1                                             */
/* Date : 20/12/2020                                                   */
/* Auteurs : Chandler NGUYEN                                           */
/*---------------------------------------------------------------------*/
/* Ce module contient la définition des constantes symboliques et des  */
/* qui sont utilisés dans d'autres modules.                            */
/***********************************************************************/


#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

#define ROUGE   1.0f, 0.0f, 0.0f
#define VERT    0.0f, 1.0f, 0.0f
#define BLEU    0.0f, 0.0f, 1.0f
#define MAGENTA 1.0f, 0.0f, 1.0f
#define CYAN    0.0f, 1.0f, 1.0f
#define JAUNE   1.0f, 1.0f, 0.0f
#define BLANC   1.0f, 1.0f, 1.0f
#define GRIS    0.5f, 0.5f, 0.5f
#define NOIR    0.0f, 0.0f, 0.0f
#define FIGURE         0
#define POINT          1
#define SEGMENT        2
#define RECTANGLE      3
#define CERCLE         4
#define ARC_DE_CERCLE  5

typedef struct
{
    double rouge;
    double vert;
    double bleu;
}Couleur;

typedef struct
{
    unsigned int type;
    Couleur color;
    double x;
    double y;
}Point2D;

typedef struct
{
    unsigned int type;
    Couleur color;
    double departX;
    double departY;
    double arriveeX;
    double arriveeY;
}Segment2D;

typedef struct
{
    unsigned int type;
    Couleur color;
    double Ax;
    double Ay;
    double Bx;
    double By;
    double dimension;
}Rectangle2D;

typedef struct
{
    unsigned int type;
    Couleur color;
    double centre_X;
    double centre_Y;
    double rayon;
}Cercle2D;

typedef struct
{
    unsigned int type;
    Couleur color;
    double centre_X;
    double centre_Y;
    double rayon;
    double angleDepart;
    double angleArrivee;
}Arc2D;

typedef union
{
    unsigned int type;
    Point2D point;
    Segment2D segment;
    Rectangle2D rectangle;
    Cercle2D cercle;
    Arc2D arc;
}Figure2D;

Figure2D* creerPoint (double x,
                      double y,
                      double rouge,
                      double vert,
                      double bleu);

Figure2D* creerSegment (double departX,
                        double departY,
                        double arriveeX,
                        double arriveeY,
                        double rouge,
                        double vert,
                        double bleu);

Figure2D* creerRectangle (double Ax,
                          double Ay,
                          double Bx,
                          double By,
                          double dimension,
                          double rouge,
                          double vert,
                          double bleu);

Figure2D* creerCercle (double centreX,
                       double centreY,
                       double rayon,
                       double rouge,
                       double vert,
                       double bleu);

Figure2D* creerArcDeCercle (double centreX,
                            double centreY,
                            double rayon,
                            double angleDepart,
                            double angleArrivee,
                            double rouge,
                            double vert,
                            double bleu);

void supprimerFigure (Figure2D* figure);

#endif // TYPES_H_INCLUDED
