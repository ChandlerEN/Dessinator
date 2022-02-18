/***********************************************************************/
/* Projet Dessinator                                                   */
/*---------------------------------------------------------------------*/
/* Module : ListeChaine.c                                              */
/* Numéro de version : 0.1                                             */
/* Date : 07/03/2021                                                   */
/* Auteurs : Chandler NGUYEN                                           */
/*---------------------------------------------------------------------*/
/* Ce module contient l'implémentation des fonctions dont la signature */
/* a été écrite dans le fichier d'entête.                              */
/***********************************************************************/

#include "ListeChaine.h"
#include <stdio.h>
#include <stdlib.h>


Noeud* creerNoeud (Figure2D* _figure)
{
    if (_figure){
        Noeud* c_n = (Noeud*) malloc(sizeof(Noeud));

        c_n->contenu    = _figure;
        c_n->precedent  = NULL;
        c_n->suivant    = NULL;

        return c_n;
    }

    return 0;
}

void detruireNoeud (Noeud* d_n)
{
    if (d_n){
        if (d_n->contenu){
            supprimerFigure(d_n->contenu);
        }
        free(d_n);
    }
}

ListeChainee* creerListe (char* _nom)
{
    ListeChainee* c_l = (ListeChainee*) malloc (sizeof(ListeChainee));

    c_l->premier    = NULL;
    c_l->taille     = 0;
    c_l->nom        = _nom;
    c_l->dernier    = c_l->premier;

    return c_l;
}

void detruireListe (ListeChainee* d_l)
{
    if (d_l){
        if (d_l->premier){
            Noeud* temp = d_l->dernier;
            while (temp->precedent != NULL){
                temp = temp->precedent;
                detruireNoeud(temp->suivant);
            }
            detruireNoeud(d_l->premier);
        }
        free(d_l);
    }
}

void insererDansListe (ListeChainee* l_c, Figure2D* F2D, unsigned int point_insertion)
{
    if (l_c != NULL && point_insertion <= l_c->taille){

        Noeud* Nouveau = creerNoeud(F2D);

        Noeud* Courant = l_c->premier;

        if (point_insertion == 0){
            Nouveau->suivant = Courant;
            if (Courant != NULL){
                Courant->precedent = Nouveau;
            }
            l_c->premier = Nouveau;
        }
        else {
            for (unsigned int i = 1; i != point_insertion; i++){
                Courant = Courant->suivant;
            }
            Nouveau->suivant = Courant->suivant;
            Courant->suivant = Nouveau;
            Nouveau->precedent = Courant;
            if (Nouveau->suivant != NULL){
                Nouveau->suivant->precedent = Nouveau;
            }
        }
        if(point_insertion == l_c->taille){
            l_c->dernier = Nouveau;
        }
        l_c->taille++;
    }
}

Figure2D* supprimerDansListe (ListeChainee* sdl, unsigned int point_suppression)
{
    if (sdl != NULL && sdl->premier != NULL && point_suppression < sdl->taille){

        Noeud* Courant = sdl->premier;
        Noeud* NoeudASupp;
        Figure2D* retour;

        if (point_suppression == 0){
            sdl->premier = Courant->suivant;
            sdl->premier->precedent = NULL;
            retour = Courant->contenu;
            detruireNoeud(Courant);
        }
        else {
            for (unsigned int i = 1; i != point_suppression; i++){
                Courant = Courant->suivant;
            }
            NoeudASupp = Courant->suivant;
            retour = NoeudASupp->contenu;
            Courant->suivant = NoeudASupp->suivant;
            if (NoeudASupp->suivant != NULL){
                NoeudASupp->suivant->precedent = Courant;
            }
            detruireNoeud(NoeudASupp);
        }
        if (point_suppression == sdl->taille-1){
            sdl->dernier = Courant;
        }
        sdl->taille--;

        return retour;
    }

    return 0;
}

void afficherListe (ListeChainee* a_l)
{
    if (a_l){
        printf("Dessin : %s \n\n", a_l->nom);

        Noeud* temp = a_l->premier;

        while (temp != NULL){
            printf_Figure2D(temp->contenu);

//            printf("courant : %p   |   precedent : %p   |   suivant : %p \n\n", temp,temp->precedent, temp->suivant);

            temp = temp->suivant;
        }
    }
}

void ajouterPoint (ListeChainee* des, double x, double y, double rouge, double vert, double bleu)
{
    Figure2D* F2D = creerPoint(x, y, rouge, vert, bleu);

    insererDansListe (des, F2D, des->taille);
}

void ajouterSegment (ListeChainee* des, double departX, double departY, double arriveeX, double arriveeY, double rouge, double vert, double bleu)
{
    Figure2D* F2D = creerSegment(departX, departY, arriveeX, arriveeY, rouge, vert, bleu);

    insererDansListe (des, F2D, des->taille);
}

void ajouterRectangle (ListeChainee* des, double Ax, double Ay, double Bx, double By, double dimension, double rouge, double vert, double bleu)
{
    Figure2D* F2D = creerRectangle(Ax, Ay, Bx, By, dimension, rouge, vert, bleu);

    insererDansListe (des, F2D, des->taille);
}

void ajouterCercle (ListeChainee* des, double centre_X, double centre_Y, double rayon, double rouge, double vert, double bleu)
{
    Figure2D* F2D = creerCercle(centre_X, centre_Y, rayon, rouge, vert, bleu);

    insererDansListe (des, F2D, des->taille);
}

void ajouterArcDeCercle (ListeChainee* des, double centre_X, double centre_Y, double rayon, double angleDepart, double angleArrivee, double rouge, double vert, double bleu)
{
    Figure2D* F2D = creerArcDeCercle(centre_X, centre_Y, rayon, angleDepart, angleArrivee, rouge, vert, bleu);

    insererDansListe (des, F2D, des->taille);
}
