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

void afficher_echoppes(S_joueur j, int plat)
{
    int i;
    for(i=0; i<4; i++)
    {
        if(j.quartier[plat-2].echoppe[i].nb_marchandises_max>0)
        {
            switch(plat)
            {
            case 2 :
                color(2,0);
                break;
            case 3 :
                color(5,0);
                break;
            case 4 :
                color(3,0);
                break;
            case 5 :
                color(12,0);
                break;
            }
            if(j.quartier[plat-2].echoppe[i].statut==1 || j.quartier[plat-2].echoppe[i].statut==2)
                printf("\nEchoppe %d complète",i+1);
            else
                printf("\nEchoppe %d : %d marchandises actuellement, %d marchandises max, %d points bonus",i+1,j.quartier[plat-2].echoppe[i].nb_marchandises_act,j.quartier[plat-2].echoppe[i].nb_marchandises_max,j.quartier[plat-2].echoppe[i].nb_pts);
        }
        color(15,0);
    }
}



void afficher_joueur(S_joueur j,S_plat Plateau[])
{
    system("cls");


    int i;
    printf("Profil de %s :\n\n",j.nom);
    printf("Nombre de chèvres : %d\nNombre de pièces d'or : %d\nNombre de dés jaunes : %d\nPoints : %d",j.nb_chevres,j.nb_or,j.nb_des_jaunes+j.nb_des_jaunes_permanent,j.cpt_pts);
    for(i=0; i<4; i++)
    {
        switch(i)
        {
        case 0 :
            color(2,0);
            break;
        case 1 :
            color(5,0);
            break;
        case 2 :
            color(3,0);
            break;
        case 3 :
            color(12,0);
            break;
        }
        printf("\n\nQuartier %d :",i+1);
        afficher_echoppes(j,i+2);
        color(15,0);
    }
    printf("\n");
    afficher_batiments(j);
    printf("\n");
    afficher_i(j);
}

















void afficher_batiments(S_joueur j)
{
    int i;
    printf("\n");
    for(i=0; i<4; i++)
    {
        if(j.batiments[i].statut==1)
            printf("%d.%s construit\n",i+1,j.batiments[i].nom);
        else
            printf("%d.%s non construit, coûte %d or et %d chèvres\n",i+1,j.batiments[i].nom,j.batiments[i].prix_or,j.batiments[i].prix_chevres);
    }
}


//Intendant
void afficher_i(S_joueur T)
{
    int i;
    int j;
    for(i=0; i<7; i++)
    {
        for (j=0; j<7; j++)
        {
            if (T.Intendant.Tab[i][j].etat==1)
            {
                color(0,0);
                printf("  %d  ",T.Intendant.Tab[i][j].etat);
                color(15,0);
            }
            else
            {
                switch(T.Intendant.Tab[i][j].Bonus)
                {
                case 0 :
                {
                    color(0,0);
                    printf("  %d  ",T.Intendant.Tab[i][j].etat);
                    color(15,0);
                }
                break;
                case 1 :
                {
                    color(14,14);
                    printf("  %d  ",T.Intendant.Tab[i][j].etat);
                    color(15,0);
                }
                break;
                case 2 :
                {
                    color(6,6);
                    printf("  %d  ",T.Intendant.Tab[i][j].etat);
                    color(15,0);
                }
                break;
                case 3 :
                {
                    color(7,7);
                    printf("  %d  ",T.Intendant.Tab[i][j].etat);
                    color(15,0);
                }
                break;
                case 4 :
                {
                    color(8,8);
                    printf("  %d  ",T.Intendant.Tab[i][j].etat);
                    color(15,0);
                }
                break;
                case 5 :
                {
                    color(2,2);
                    printf("  %d  ",T.Intendant.Tab[i][j].etat);
                    color(15,0);
                }
                break;
                case 6 :
                {
                    color(10,10);
                    printf("  %d  ",T.Intendant.Tab[i][j].etat);
                    color(15,0);
                }
                break;
                case 7 :
                {
                    color(5,5);
                    printf("  %d  ",T.Intendant.Tab[i][j].etat);
                    color(15,0);
                }
                break;
                case 8 :
                {
                    color(3,3);
                    printf("  %d  ",T.Intendant.Tab[i][j].etat);
                    color(15,0);
                }
                break;
                case 9 :
                {
                    color(12,12);
                    printf("  %d  ",T.Intendant.Tab[i][j].etat);
                    color(15,0);
                }
                break;
                case 10 :
                {
                    color(15,15);
                    printf("  %d  ",T.Intendant.Tab[i][j].etat);
                    color(15,0);
                }
                break;
                case 11 :
                {
                    color(1,1);
                    printf("  %d  ",T.Intendant.Tab[i][j].etat);
                    color(15,0);
                }
                break;
                case 12 :
                {
                    color(9,9);
                    printf("  %d  ",T.Intendant.Tab[i][j].etat);
                    color(15,0);
                }
                break;

                }


            }
        }
        printf("\n");
    }
}

