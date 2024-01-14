#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "declarations.h"
#include "initialisation.h"
#include "manches.h"
#include "parametres.h"
#include "plateau.h"
#include "affichage.h"
#include "quartier.h"
#include "intendant.h"
#include "batiments.h"


int main()
{
    SetConsoleOutputCP(1252); //permet d'afficher les accents

    int nb=nb_joueurs();
    int cpt_tour,i;
    S_joueur T[nb];
    S_joueur temp;
    printf("\nMode %d Joueurs\n\n",nb);
    Init(T,nb);

    if(nb==3)
    {
        for(cpt_tour=1; cpt_tour<18+1; cpt_tour++)
        {
            Manche(T,cpt_tour,nb);
            Reinitialisation_partie(T,nb);
            temp=T[0];
            T[0]=T[1];
            T[1]=T[2];
            T[2]=temp;
        }
    }
    if(nb==4)
    {
        for(cpt_tour=1; cpt_tour<16+1; cpt_tour++)
        {
            Manche(T,cpt_tour,nb);
            Reinitialisation_partie(T,nb);
            temp=T[0];
            T[0]=T[1];
            T[1]=T[2];
            T[2]=T[3];
            T[3]=temp;
        }
    }

    for(i=0;i<nb;i++)
        Decompte_pts(T,i);

    afficher_gagnant(T,nb);

    return 0;
}
