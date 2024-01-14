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

int Bat_intendant()
{
    int valid=0;
    int rep;
    int nbp;

    printf("Veux-tu ajouter ou enlever des pas de déplacement ? \n 0 pour non \n 1 pour ajouter \n 2 pour enlever \n");
    scanf("%d",&rep);
    while(valid!=1)
    {
        if(rep==1)
        {
            printf("Combien de pas ajouter ? \n");
            scanf("%d",&nbp);
            valid=1;
        }
        else
        {
            if(rep==2)
            {
                printf("Combien de pas enlever ? \n");
                scanf("%d",&nbp);
                valid=1;
            }
            else
            {
                if(rep==0)
                {
                    printf("Pas non modifiés \n");
                    nbp=0;
                    valid=1;
                }
                else
                {
                    printf("Nombre non attribué, choisis un chiffre entre 0 et 2 \n ");
                    scanf("%d",&rep);
                }
            }
        }
    }
    return nbp;
}



void Demande_batiment(S_joueur T[], int j)
{
    char oui[4]= {'o','u','i','\0'};
    char Oui[4]= {'O','u','i','\0'};
//    char non[4]= {'n','o','n','\0'};
    char choix[4];
    int choix2;
    int continuer=0;
    if(T[j].batiments[0].statut==0 || T[j].batiments[1].statut==0 || T[j].batiments[2].statut==0 || T[j].batiments[3].statut==0)
    {
        printf("\nVeux-tu construire un bâtiment ? ");
        scanf("%s",choix);
        if(strcmp(choix,oui)==0 || strcmp(choix,Oui)==0)
        {
            afficher_batiments(T[j]);
            printf("\nConstruire quel bâtiment ? ");
            scanf("%d",&choix2);
            while(continuer==0)
            {
                if(choix2<1 || choix2>4)
                {
                    printf("\nChoix invalide ! Veux-tu toujours construire un bâtiment ? ");
                    scanf("%s",choix);
                    if(strcmp(choix,oui)!=0 && strcmp(choix,Oui)!=0)
                        continuer=1;
                }
                else
                {
                    if(T[j].batiments[choix2-1].statut==0)
                    {
                        if(T[j].nb_or<T[j].batiments[choix2-1].prix_or)
                        {
                            printf("\nTu n'as pas assez d'or pour construire ce bâtiment !");
                            printf("\nVeux-tu toujours construire un bâtiment ? ");
                            scanf("%s",choix);
                            if(strcmp(choix,oui)!=0 && strcmp(choix,Oui)!=0)
                                continuer=1;
                            else
                            {
                                printf("Construire quel bâtiment ? ");
                                scanf("%d",&choix2);
                            }
                        }
                        else
                        {
                            if(T[j].nb_chevres<T[j].batiments[choix2-1].prix_chevres)
                            {
                                printf("\nTu n'as pas assez de chevres pour construire ce bâtiment !");
                                printf("\nVeux-tu toujours construire un bâtiment ? ");
                                scanf("%s",choix);
                                if(strcmp(choix,oui)!=0 && strcmp(choix,Oui)!=0)
                                    continuer=1;
                                else
                                {
                                    printf("Construire quel bâtiment ? ");
                                    scanf("%d",&choix2);
                                }
                            }
                            else
                            {
                                T[j].batiments[choix2-1].statut=1;
                                printf("%s à présent construit ! ",T[j].batiments[choix2-1].nom);
                                printf("Tu as %d or et %d chèvres",T[j].nb_or,T[j].nb_chevres);
                                T[j].nb_or=T[j].nb_or-T[j].batiments[choix2-1].prix_or;
                                T[j].nb_chevres=T[j].nb_chevres-T[j].batiments[choix2-1].prix_chevres;
                                continuer=1;
                            }
                        }
                    }
                    else
                    {
                        printf("\nCe bâtiment est déjà construit !");
                        printf("\nVeux-tu toujours construire un bâtiment ? ");
                        scanf("%s",choix);
                        if(strcmp(choix,oui)!=0 && strcmp(choix,Oui)!=0)
                            continuer=1;
                        else
                        {
                            printf("Construire quel bâtiment ? ");
                            scanf("%d",&choix2);
                        }
                    }
                }
            }
        }
    }
    Sleep(2000);
}
