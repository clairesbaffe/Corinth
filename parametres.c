#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#include "declarations.h"
#include "initialisation.h"
#include "manches.h"
#include "parametres.h"
#include "plateau.h"
#include "affichage.h"
#include "quartier.h"
#include "intendant.h"
#include "batiments.h"

void Nb_des_jaunes(S_joueur T[])
{
    char oui[4]= {'o','u','i','\0'};
    char Oui[4]= {'O','u','i','\0'};
//    char non[4]= {'n','o','n','\0'};
    char choix[4];

    if(T[0].nb_des_jaunes+T[0].nb_des_jaunes_permanent<3)
    {
        printf("Tu es sur le point de lancer 9 d�s blancs et %d d�s jaunes. Tu as %d or. Veux-tu un d� jaune de plus pour 1 or ? ",T[0].nb_des_jaunes+T[0].nb_des_jaunes_permanent,T[0].nb_or);
        scanf("%s",choix);
        if(strcmp(choix,oui)==0 || strcmp(choix,Oui)==0)
        {
            do
            {
                if(T[0].nb_des_jaunes+T[0].nb_des_jaunes_permanent==3)
                {
                    printf("Tu as atteint le nombre maximal de d�s, tu lances 9 d�s blancs et 3 d�s jaunes.\n\n");
                    choix[0]='n';
                    choix[1]='o';
                    choix[2]='n';
                    choix[3]='\0';
                }
                else
                {
                    if(T[0].nb_or<1)
                    {
                        printf("Tu n'as pas assez d'or pour acheter un d� jaune de plus.\n\n");
                        choix[0]='n';
                        choix[1]='o';
                        choix[2]='n';
                        choix[3]='\0';
                    }
                    else
                    {
                        T[0].nb_des_jaunes++;
                        T[0].nb_or--;
                        printf("Tu as � pr�sent %d d�s jaunes et %d or.",T[0].nb_des_jaunes+T[0].nb_des_jaunes_permanent,T[0].nb_or);
                        printf("\nVeux-tu un d� jaune de plus pour 1 or ? ");
                        scanf("%s",choix);
                    }


                }
            }
            while(strcmp(choix,oui)==0 || strcmp(choix,Oui)==0);
        }
        else
            printf("Tu lances 9 d�s blancs et %d d�s jaunes.\n\n",T[0].nb_des_jaunes+T[0].nb_des_jaunes_permanent);
    }
    else
        printf("Tu lances 9 d�s blancs et %d d�s jaunes.\n\n",T[0].nb_des_jaunes+T[0].nb_des_jaunes_permanent);
    Sleep(2000);
}


void Valeur_des(int Lancer[], S_joueur T[])
{
    srand(time(NULL));
    int i;
    printf("\n");
    for(i=0; i<9+T[0].nb_des_jaunes+T[0].nb_des_jaunes_permanent; i++)
        Lancer[i]=(rand()%6)+1;
    printf("\n\n");
}















void color(int couleurDuTexte, int couleurDuFond)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurDuFond*16+couleurDuTexte);
}
// 0.Noir
// 1.Bleu fonc
// 2.Vert fonc
// 3.Turquoise
// 4.Rouge fonc
// 5.Violet
// 6.Vert caca d'oie
// 7.Gris clair
// 8.Gris fonc
// 9.Bleu fluo
// 10.Vert fluo
// 11.Turquoise
// 12.Rouge fluo
// 13.Violet 2
// 14.Jaune
// 15.Blanc


void Positionner_Curseur(int x, int y)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);//permet de d�clarer la variable "hstdout" qui fait r�f�r�nce � la console
    COORD pos; // COORD est un type structur� d�fini dans la biblioth�que windows.h
    pos.X=x;// num�ro de la colonne
    pos.Y=y;// num�ro de la ligne
    SetConsoleCursorPosition(hStdout, pos); //on positionne le curseur aux coordonn�es "pos"
}
