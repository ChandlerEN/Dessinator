/***********************************************************************/
/* Projet Dessinator                                                   */
/*---------------------------------------------------------------------*/
/* Module : dessinator.c                                               */
/* Numéro de version : 0.1                                             */
/* Date : 13/06/2021                                                   */
/* Auteurs : Chandler NGUYEN                                           */
/*---------------------------------------------------------------------*/
/* C'est le module principal du projet, il contient la fonction main   */
/* et utilise les éléments définis dans d'autres modules.              */
/***********************************************************************/

#include "affichageTexte.h"
#include "ListeChaine.h"
#include "interfaceGraphique.h"
#include <stdio.h>
#include <stdlib.h>


int main (int argc, char* argv [])
{
    ouvrirLaFenetreGraphique (10, 10, 400, 400, "Dessinator", &argc, &argv);

//    dessiner_Point          (10, 20,                ROUGE );
//    dessiner_Segment        (30, 40, 50, 60,        VERT );
//    dessiner_Rectangle      (70, 80, 90, 100, 50,   BLEU );
//    dessiner_Cercle         (130, 140, 50,          BLANC );
//    dessiner_ArcDeCercle    (160, 170, 50, 0, 45,   MAGENTA );

//    afficherListe (dessin);

    gererLesEvenements ();

//    fermerLaFenetreGraphique ();

    return 0;
}
