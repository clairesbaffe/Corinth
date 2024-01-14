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

void Placement_des(S_joueur T[], int Lancer[], S_plat Plateau[])
{
    int i,j;
    for(i=0; i<6; i++)                  //initialisation du plateau
    {
        Plateau[i].nb_des_blancs=0;
        Plateau[i].nb_des_jaunes=0;
    }

    for(i=0; i<6; i++)                  //associer initialement une valeur de dé à chaque case du plateau
        Plateau[i].valeur_des=i+1;

    for(i=0; i<9; i++)                  //trier les dés blancs et les placer sur le plateau
    {
        for(j=0; j<6; j++)
        {
            if(Lancer[i]==j+1)
                Plateau[j].nb_des_blancs++;
        }
    }
    for(i=9; i<9+T[0].nb_des_jaunes; i++)   //trier les dés jaunes et les placer sur le plateau
    {
        for(j=0; j<6; j++)
        {
            if(Lancer[i]==j+1)
                Plateau[j].nb_des_jaunes++;
        }
    }

    for(i=0; i<6; i++)                      //à chaque case du plateau : donner une valeur à la variable nb_des_total
        Plateau[i].nb_des_total=Plateau[i].nb_des_blancs+Plateau[i].nb_des_jaunes;


    //assurer des des sur le quartier chevres et faire monter les des a partir du quartir chevres
    for(i=0; i<Plateau[5].valeur_des; i++)
    {
        j=i+1;
        if(Plateau[i].nb_des_total==0)
        {
            while(Plateau[i].nb_des_total==0)
            {
                if(j<Plateau[5].valeur_des)
                {
                    Plateau[i]=Plateau[j];
                    Plateau[j].nb_des_blancs=0;
                    Plateau[j].nb_des_jaunes=0;
                    Plateau[j].nb_des_total=0;
                    Plateau[j].valeur_des=0;
                    j++;
                }
            }
        }
    }

    i=4;
    while(Plateau[5].nb_des_total==0)   //assurer des des sur le quartier or
    {
        Plateau[5]=Plateau[i];
        Plateau[i].nb_des_blancs=0;
        Plateau[i].nb_des_jaunes=0;
        Plateau[i].nb_des_total=0;
        Plateau[i].valeur_des=0;
        i--;
    }

}






int choisir_plateau(S_plat Plateau[], S_joueur T[], int j)
{
    char menu[6][22]= {"   Quartier chèvres  ","   Quartier 1        ","   Quartier 2        ",
                       "   Quartier 3        ","   Quartier 4        ","   Quartier or       "
                      };
    int choix=0; // numéro de l'option choisie dans le menu
    int frappe=0; //permet de stocker le code de la touche clavier
    int i;
//    int k=0;

    printf("\n%s, choisis une case du plateau\n\n",T[j].nom);
    printf(" _____________________  Plateau  ______________________\n");
    printf("|                                                      |\n");
    printf("|                                                      |\n");
    for(i=0; i<6; i++)
        printf("|%s :    %d dés de valeur %d          |\n",menu[i],Plateau[i].nb_des_total,Plateau[i].valeur_des);
    printf("|                                                      |\n");
    printf("|______________________________________________________|\n");

    Positionner_Curseur(0,50);
    color(0,15);
    printf("|%s :    %d dés de valeur %d          |\n",menu[0],Plateau[0].nb_des_total,Plateau[0].valeur_des);
    color(15,0);
    Positionner_Curseur(0,60);
    printf("\n");

    while(frappe!=13) // tant qu'on a pas appuyer sur la touche ECHAP
    {
        if (kbhit()) //si on a appuyer sur une touche du clavier
        {
            frappe=getch(); // on récupère le code de la touche sur laquelle on a appuyée
            if(frappe==72) //72 est le code de la flèche directionnelle vers le haut
            {
                Positionner_Curseur(0,choix+50); // positionne le curseur au choix courant
                color(15,0); // met la couleur du texte en blanc et celle du fond en noir

                printf("|%s :    %d dés de valeur %d          |\n",menu[choix],Plateau[choix].nb_des_total,Plateau[choix].valeur_des);


                choix--; // on décrémebte le numéro de l'option
                if(choix==-1)
                    choix=5; // les options sont numérotées de 0 à 5
                Positionner_Curseur(0,choix+50);// positionne le curseur au choix juste dessus du précédent
                color(0,15);// met la couleur du texte en noir et celle du fond en blanc
                printf("|%s :    %d dés de valeur %d          |\n",menu[choix],Plateau[choix].nb_des_total,Plateau[choix].valeur_des);// On réaffiche le nouveau choix  avec les couleurs préalablement choisies, une manière de le séléctionner
                color(15,0);
            }
            if(frappe==80) //80 est le code de la flèche directionnelle vers le bas
            {
                Positionner_Curseur(0,choix+50);
                color(15,0);

                printf("|%s :    %d dés de valeur %d          |\n",menu[choix],Plateau[choix].nb_des_total,Plateau[choix].valeur_des);

                choix++;
                if(choix==6)
                    choix=0;
                Positionner_Curseur(0,choix+50);
                color(0,15);
                printf("|%s :    %d dés de valeur %d          |\n",menu[choix],Plateau[choix].nb_des_total,Plateau[choix].valeur_des);
                color(15,0);
            }
        }
        Positionner_Curseur(0,60);
    }
    choix++;
    switch (choix)
    {
    case 1 :
    {
        Quartier_chevres(Plateau,T,choix,j);
        Sleep(2000);
    }
    break;
    case 2 :
    {
        Marchandises(Plateau,T,choix,j);
        Sleep(2000);
    }
    break;
    case 3:
    {
        Marchandises(Plateau,T,choix,j);
        Sleep(2000);
    }
    break;
    case 4:
    {
        Marchandises(Plateau,T,choix,j);
        Sleep(2000);
    }
    break;
    case 5:
    {
        Marchandises(Plateau,T,choix,j);
        Sleep(2000);
    }
    break;
    case 6:
    {
        Quartier_or(Plateau,T,choix,j);
        Sleep(2000);
    }
    break;

    default :
        printf("Choix invalide ! merci de taper une valeur entre 1 et 6 ! \n");
        system("PAUSE");
        break;
    }
    return choix-1;
    choix=0;
    frappe=0;
}
