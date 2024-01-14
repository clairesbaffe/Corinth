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

void Manche(S_joueur T[], int cpt_tour, int i)
{
    system("cls");
    int j;
    int k=0;
    int frappe=0;
    int Lancer[12];
    S_plat Plateau[6];
    printf("\nMANCHE %d\n\n",cpt_tour);
    printf("Au tour de %s de lancer les dés\n\n",T[0].nom);
    Nb_des_jaunes(T);
    Valeur_des(Lancer,T);
    Placement_des(T,Lancer,Plateau);
    for(j=0; j<i; j++)
    {
        afficher_joueur(T[j],Plateau);
        printf("\n\nAppuis sur la touche ""ENTRER"" pour passer\n");
        while(frappe!=13)
        {
            if (kbhit()) //si on a appuyer sur une touche du clavier
                frappe=getch(); // on récupère le code de la touche sur laquelle on a appuyée
            if(frappe==13)
                k=choisir_plateau(Plateau,T,j);
        }
        frappe=0;
        if(j==0)
            Supprimer_des_jaunes(T,Lancer,Plateau,j);
        Reinitialisation_case(Plateau,k);
        Demande_batiment(T,j);
    }
}



void Supprimer_des_jaunes(S_joueur T[], int Lancer[], S_plat Plateau[], int j)
{
    int k=T[j].nb_des_jaunes+T[j].nb_des_jaunes_permanent;
    if(k>0)
    {
        Lancer[9]=0;
        if(k>1)
        {
            Lancer[10]=0;
            if(k>2)
                Lancer[11]=0;
        }
        Placement_des(T,Lancer,Plateau);
    }
}






void Decompte_pts(S_joueur T[],int j)
{
    int i,k;
    if(T[j].nb_or%2==1)
        T[j].nb_or--;
    T[j].nb_or=T[j].nb_or/2;

    if(T[j].nb_chevres%2==1)
        T[j].nb_chevres--;
    T[j].nb_chevres=T[j].nb_chevres/2;

    if(T[j].batiments[0].statut==1)
    {
        k=3;
        for(i=1;i<4;i++)
        {
            if(T[j].batiments[i].statut==1)
                k=k+3;
        }
    }
    T[j].cpt_pts=T[j].cpt_pts+T[j].nb_or+T[j].nb_chevres+k;
}



void afficher_gagnant(S_joueur T[], int nb)
{
    int i,j,k;
    int pts=0;
    for(i=0;i<nb;i++)
    {
        for(j=0;j<nb;j++)
        {
            if(T[j].cpt_pts>pts)
            {
                k=j;
                pts=T[j].cpt_pts;
            }

        }
        printf("\n%de : %s",i+1,T[k].nom);
        T[k].cpt_pts=0;
        pts=0;
    }
}
