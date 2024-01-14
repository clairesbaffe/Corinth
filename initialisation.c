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

int nb_joueurs()
{
    int nb;
    while(nb<3 || nb>4)
    {
        printf("Le Corinth se joue à 3 ou 4 joueurs. Combien êtes-vous ? ");
        scanf("%d",&nb);
    }
    return nb;
}

void Init(S_joueur T[], int i)
{
    int j,k,l;
    for(j=0; j<i; j++)
    {
        printf("Nom du joueur %d : ",j+1);
        scanf("%s",T[j].nom);


        T[j].cpt_pts=0;
        T[j].nb_or=1;
        T[j].nb_chevres=1;
        T[j].nb_des_jaunes=0;
        T[j].nb_des_jaunes_permanent=0;


        //intendant
        ini_etat(T,j);
        ini_bonus(T,j);
        ini_pos(T,j);


        for(k=0; k<4; k++)
        {

            T[j].quartier[k].statut=0;//aucun quartier terminé
            for(l=0; l<4; l++)
            {
                T[j].quartier[k].echoppe[l].nb_marchandises_act=0;//pas de marchandises dans les échoppes
                T[j].quartier[k].echoppe[l].statut=0;//échoppe pas commencée ; rappel : 0 pour pas commencé, 1 pour terminé
            }
        }
        T[j].quartier[0].echoppe[0].nb_marchandises_max=2;        //nb de marchandises max et du nb de pts bonus(pour échoppe terminée) dans chaque échoppe
        T[j].quartier[0].echoppe[0].nb_pts=1;
        T[j].quartier[0].echoppe[1].nb_marchandises_max=3;
        T[j].quartier[0].echoppe[1].nb_pts=2;
        T[j].quartier[0].echoppe[2].nb_marchandises_max=3;
        T[j].quartier[0].echoppe[2].nb_pts=3;
        T[j].quartier[0].echoppe[3].nb_marchandises_max=5;
        T[j].quartier[0].echoppe[3].nb_pts=6;

        T[j].quartier[1].echoppe[0].nb_marchandises_max=2;
        T[j].quartier[1].echoppe[0].nb_pts=2;
        T[j].quartier[1].echoppe[1].nb_marchandises_max=3;
        T[j].quartier[1].echoppe[1].nb_pts=3;
        T[j].quartier[1].echoppe[2].nb_marchandises_max=3;
        T[j].quartier[1].echoppe[2].nb_pts=4;
        T[j].quartier[1].echoppe[3].nb_marchandises_max=4;
        T[j].quartier[1].echoppe[3].nb_pts=6;

        T[j].quartier[2].echoppe[0].nb_marchandises_max=2;
        T[j].quartier[2].echoppe[0].nb_pts=3;
        T[j].quartier[2].echoppe[1].nb_marchandises_max=3;
        T[j].quartier[2].echoppe[1].nb_pts=5;
        T[j].quartier[2].echoppe[2].nb_marchandises_max=4;
        T[j].quartier[2].echoppe[2].nb_pts=8;
        T[j].quartier[2].echoppe[3].nb_marchandises_max=0;//echoppe non existante
        T[j].quartier[2].echoppe[3].nb_pts=0;
        T[j].quartier[2].echoppe[3].statut=2;

        T[j].quartier[3].echoppe[0].nb_marchandises_max=2;
        T[j].quartier[3].echoppe[0].nb_pts=4;
        T[j].quartier[3].echoppe[1].nb_marchandises_max=2;
        T[j].quartier[3].echoppe[1].nb_pts=5;
        T[j].quartier[3].echoppe[2].nb_marchandises_max=4;
        T[j].quartier[3].echoppe[2].nb_pts=10;
        T[j].quartier[3].echoppe[3].nb_marchandises_max=0;//echoppe non existante
        T[j].quartier[3].echoppe[3].nb_pts=0;
        T[j].quartier[3].echoppe[3].statut=2;

        T[j].quartier[0].pts_bonus=5;      //nb de pts bonus (pour quartier terminé, uniquement pour le 1e joueur ayant terminé le quartier) dans chaque quartier
        T[j].quartier[1].pts_bonus=4;
        T[j].quartier[2].pts_bonus=3;
        T[j].quartier[3].pts_bonus=0;

        for(k=0; k<4; k++)
            T[j].batiments[k].statut=0;            //aucun batiment construit

        T[j].batiments[0].nom[0]='T';
        T[j].batiments[0].nom[1]='e';
        T[j].batiments[0].nom[2]='m';
        T[j].batiments[0].nom[3]='p';
        T[j].batiments[0].nom[4]='l';
        T[j].batiments[0].nom[5]='e';
        T[j].batiments[0].nom[6]='\0';
        T[j].batiments[0].prix_or=3;
        T[j].batiments[0].prix_chevres=3;

        T[j].batiments[1].nom[0]='E';
        T[j].batiments[1].nom[1]='n';
        T[j].batiments[1].nom[2]='t';
        T[j].batiments[1].nom[3]='r';
        T[j].batiments[1].nom[4]='e';
        T[j].batiments[1].nom[5]='p';
        T[j].batiments[1].nom[6]='o';
        T[j].batiments[1].nom[7]='t';
        T[j].batiments[1].nom[8]='\0';
        T[j].batiments[1].prix_or=4;
        T[j].batiments[1].prix_chevres=4;

        T[j].batiments[2].nom[0]='E';
        T[j].batiments[2].nom[1]='t';
        T[j].batiments[2].nom[2]='a';
        T[j].batiments[2].nom[3]='b';
        T[j].batiments[2].nom[4]='l';
        T[j].batiments[2].nom[5]='e';
        T[j].batiments[2].nom[6]='\0';
        T[j].batiments[2].prix_or=2;
        T[j].batiments[2].prix_chevres=1;

        T[j].batiments[3].nom[0]='M';
        T[j].batiments[3].nom[1]='a';
        T[j].batiments[3].nom[2]='g';
        T[j].batiments[3].nom[3]='a';
        T[j].batiments[3].nom[4]='s';
        T[j].batiments[3].nom[5]='i';
        T[j].batiments[3].nom[6]='n';
        T[j].batiments[3].nom[7]='\0';
        T[j].batiments[3].prix_or=0;
        T[j].batiments[3].prix_chevres=2;
    }
}

void Reinitialisation_case(S_plat Plateau[], int plat)
{
    Plateau[plat].nb_des_blancs=0;
    Plateau[plat].nb_des_jaunes=0;
    Plateau[plat].nb_des_total=0;
    Plateau[plat].valeur_des=0;
}


void Reinitialisation_partie(S_joueur T[], int nb)
{
    int i;
    for(i=0; i<nb; i++)
    {
        T[i].nb_des_jaunes=0;
        Bonus_quartier(T,i,nb);
    }
}


//intendant

//0= case depart
//1= 1 piece
//2= 2 pieces
//3= 1 chevre
//4= 2 chevres
//5= 1 bonus vert
//6= 2 bonus verts
//7= bonus violet
//8= bonus bleu
//9= bonus orange
//10= dé jaune
//11=  +1
//12= case pts
//13= case exterieur

void ini_bonus(S_joueur T[], int j)
{

    T[j].Intendant.Tab[0][0].Bonus=13;
    T[j].Intendant.Tab[0][1].Bonus=13;
    T[j].Intendant.Tab[0][2].Bonus=13;
    T[j].Intendant.Tab[0][3].Bonus=13;
    T[j].Intendant.Tab[0][4].Bonus=13;
    T[j].Intendant.Tab[0][5].Bonus=13;
    T[j].Intendant.Tab[0][6].Bonus=13;

    T[j].Intendant.Tab[1][0].Bonus=13;
    T[j].Intendant.Tab[1][1].Bonus=12;
    T[j].Intendant.Tab[1][2].Bonus=10;
    T[j].Intendant.Tab[1][3].Bonus=8;
    T[j].Intendant.Tab[1][4].Bonus=11;
    T[j].Intendant.Tab[1][5].Bonus=12;
    T[j].Intendant.Tab[1][6].Bonus=13;

    T[j].Intendant.Tab[2][0].Bonus=13;
    T[j].Intendant.Tab[2][1].Bonus=9;
    T[j].Intendant.Tab[2][2].Bonus=5;
    T[j].Intendant.Tab[2][3].Bonus=4;
    T[j].Intendant.Tab[2][4].Bonus=10;
    T[j].Intendant.Tab[2][5].Bonus=6;
    T[j].Intendant.Tab[2][6].Bonus=13;

    T[j].Intendant.Tab[3][0].Bonus=13;
    T[j].Intendant.Tab[3][1].Bonus=11;
    T[j].Intendant.Tab[3][2].Bonus=7;
    T[j].Intendant.Tab[3][3].Bonus=0;
    T[j].Intendant.Tab[3][4].Bonus=1;
    T[j].Intendant.Tab[3][5].Bonus=11;
    T[j].Intendant.Tab[3][6].Bonus=13;

    T[j].Intendant.Tab[4][0].Bonus=13;
    T[j].Intendant.Tab[4][1].Bonus=6;
    T[j].Intendant.Tab[4][2].Bonus=2;
    T[j].Intendant.Tab[4][3].Bonus=10;
    T[j].Intendant.Tab[4][4].Bonus=7;
    T[j].Intendant.Tab[4][5].Bonus=8;
    T[j].Intendant.Tab[4][6].Bonus=13;

    T[j].Intendant.Tab[5][0].Bonus=13;
    T[j].Intendant.Tab[5][1].Bonus=12;
    T[j].Intendant.Tab[5][2].Bonus=3;
    T[j].Intendant.Tab[5][3].Bonus=11;
    T[j].Intendant.Tab[5][4].Bonus=4;
    T[j].Intendant.Tab[5][5].Bonus=9;
    T[j].Intendant.Tab[5][6].Bonus=13;

    T[j].Intendant.Tab[6][0].Bonus=13;
    T[j].Intendant.Tab[6][1].Bonus=13;
    T[j].Intendant.Tab[6][2].Bonus=13;
    T[j].Intendant.Tab[6][3].Bonus=13;
    T[j].Intendant.Tab[6][4].Bonus=13;
    T[j].Intendant.Tab[6][5].Bonus=13;
    T[j].Intendant.Tab[6][6].Bonus=13;
}


void ini_etat(S_joueur T[], int j)
{
    T[j].Intendant.Tab[0][0].etat=1;
    T[j].Intendant.Tab[0][1].etat=1;
    T[j].Intendant.Tab[0][2].etat=1;
    T[j].Intendant.Tab[0][3].etat=1;
    T[j].Intendant.Tab[0][4].etat=1;
    T[j].Intendant.Tab[0][5].etat=1;
    T[j].Intendant.Tab[0][6].etat=1;

    T[j].Intendant.Tab[1][0].etat=1;
    T[j].Intendant.Tab[1][1].etat=0;
    T[j].Intendant.Tab[1][2].etat=0;
    T[j].Intendant.Tab[1][3].etat=0;
    T[j].Intendant.Tab[1][4].etat=0;
    T[j].Intendant.Tab[1][5].etat=0;
    T[j].Intendant.Tab[1][6].etat=1;

    T[j].Intendant.Tab[2][0].etat=1;
    T[j].Intendant.Tab[2][1].etat=0;
    T[j].Intendant.Tab[2][2].etat=0;
    T[j].Intendant.Tab[2][3].etat=0;
    T[j].Intendant.Tab[2][4].etat=0;
    T[j].Intendant.Tab[2][5].etat=0;
    T[j].Intendant.Tab[2][6].etat=1;


    T[j].Intendant.Tab[3][0].etat=1;
    T[j].Intendant.Tab[3][1].etat=0;
    T[j].Intendant.Tab[3][2].etat=0;
    T[j].Intendant.Tab[3][3].etat=1;
    T[j].Intendant.Tab[3][4].etat=0;
    T[j].Intendant.Tab[3][5].etat=0;
    T[j].Intendant.Tab[3][6].etat=1;

    T[j].Intendant.Tab[4][0].etat=1;
    T[j].Intendant.Tab[4][1].etat=0;
    T[j].Intendant.Tab[4][2].etat=0;
    T[j].Intendant.Tab[4][3].etat=0;
    T[j].Intendant.Tab[4][4].etat=0;
    T[j].Intendant.Tab[4][5].etat=0;
    T[j].Intendant.Tab[4][6].etat=1;

    T[j].Intendant.Tab[5][0].etat=1;
    T[j].Intendant.Tab[5][1].etat=0;
    T[j].Intendant.Tab[5][2].etat=0;
    T[j].Intendant.Tab[5][3].etat=0;
    T[j].Intendant.Tab[5][4].etat=0;
    T[j].Intendant.Tab[5][5].etat=0;
    T[j].Intendant.Tab[5][6].etat=1;

    T[j].Intendant.Tab[6][0].etat=1;
    T[j].Intendant.Tab[6][1].etat=1;
    T[j].Intendant.Tab[6][2].etat=1;
    T[j].Intendant.Tab[6][3].etat=1;
    T[j].Intendant.Tab[6][4].etat=1;
    T[j].Intendant.Tab[6][5].etat=1;
    T[j].Intendant.Tab[6][6].etat=1;
}


void ini_pos(S_joueur T[], int j)
{
    T[j].Intendant.position_a=3;
    T[j].Intendant.position_b=3;
}
