/***********************************************************************/
/* Projet Dessinator                                                   */
/*---------------------------------------------------------------------*/
/* Module : ListeChaine.h                                              */
/* Numéro de version : 0.1                                             */
/* Date : 07/03/2021                                                   */
/* Auteurs : Chandler NGUYEN                                           */
/*---------------------------------------------------------------------*/
/* Ce module contient la définition des constantes symboliques et des  */
/* qui sont utilisés dans d'autres modules.                            */
/***********************************************************************/


#ifndef LISTECHAINE_H_INCLUDED
#define LISTECHAINE_H_INCLUDED

#include "types.h"

//--------------------//

typedef struct strNoeud Noeud;
typedef struct Dessin ListeChainee;

struct strNoeud
{
    Figure2D* contenu;
    Noeud* precedent;
    Noeud* suivant;
};

struct Dessin
{
    Noeud* premier;
    unsigned int taille;
    char* nom;
    Noeud* dernier;
};

//--------------------//

Noeud* creerNoeud (Figure2D* _figure);

void detruireNoeud (Noeud* n);

ListeChainee* creerListe (char* _nom);

void parcourirChaine (Noeud* p_c);

void detruireListe (ListeChainee* d_l);

void insererDansListe (ListeChainee* l_c, Figure2D* F2D, unsigned int point_insertion);

Figure2D* supprimerDansListe (ListeChainee* sdl, unsigned int point_suppression);

void afficherListe (ListeChainee* a_l);

void ajouterPoint (ListeChainee* des, double x, double y, double rouge, double vert, double bleu);

void ajouterSegment (ListeChainee* des, double departX, double departY, double arriveeX, double arriveeY, double rouge, double vert, double bleu);

void ajouterRectangle (ListeChainee* des, double Ax, double Ay, double Bx, double By, double dimension, double rouge, double vert, double bleu);

void ajouterCercle (ListeChainee* des, double centre_X, double centre_Y, double rayon, double rouge, double vert, double bleu);

void ajouterArcDeCercle (ListeChainee* des, double centre_X, double centre_Y, double rayon, double angleDepart, double angleArrivee, double rouge, double vert, double bleu);

//--------------------//

#endif // LISTECHAINE_H_INCLUDED
