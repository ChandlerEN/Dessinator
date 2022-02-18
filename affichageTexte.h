/***********************************************************************/
/* Projet Dessinator                                                   */
/*---------------------------------------------------------------------*/
/* Module : affichageTexte.h                                           */
/* Numéro de version : 0.1                                             */
/* Date : 20/12/2020                                                   */
/* Auteurs : Chandler NGUYEN                                           */
/*---------------------------------------------------------------------*/
/* Ce module contient la signature des fonctions d'affichage dans la   */
/* qui permettront de visualiser le contenu des champs des éléments    */
/* qu'on manipulera par la suite.                                      */
/***********************************************************************/


#ifndef AFFICHAGETEXTE_H_INCLUDED
#define AFFICHAGETEXTE_H_INCLUDED

#include "types.h"

void printf_Point2D (Point2D p);

void printf_Segment2D (Segment2D s);

void printf_Rectangle2D (Rectangle2D r);

void printf_Cercle2D (Cercle2D c);

void printf_Arc2D (Arc2D a);

void printf_Figure2D (Figure2D* f);

#endif // AFFICHAGETEXTE_H_INCLUDED
