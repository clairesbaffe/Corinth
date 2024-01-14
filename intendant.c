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

void Intendant(int pas, S_joueur T[], int j)
{
    afficher_i(T[j]);
    depla(&pas,T,j);
    bonusj(T,j);
}



void depla(int *valD,S_joueur J[], int j)
{
    int i=0;
    int ndp=0;
    char direct[7];
    char droite[7]= {'d','r','o','i','t','e','\0'};
    char gauche[7]= {'g','a','u','c','h','e','\0'};
    char Droite[7]= {'D','r','o','i','t','e','\0'};
    char Gauche[7]= {'G','a','u','c','h','e','\0'};
    char haut[5]= {'h','a','u','t','\0'};
    char Haut[5]= {'H','a','u','t','\0'};
    char Bas[4]= {'B','a','s','\0'};
    char bas[4]= {'b','a','s','\0'};


    if(J[j].batiments[2].statut == 1)
    {
        ndp=Bat_intendant();
        i=i+ndp;
    }

    while (i<*valD)
    {
        if( J[j].Intendant.Tab[(J[j].Intendant.position_a)+1][J[j].Intendant.position_b].etat==1 && J[j].Intendant.Tab[(J[j].Intendant.position_a)-1][J[j].Intendant.position_b].etat==1 && J[j].Intendant.Tab[J[j].Intendant.position_a][(J[j].Intendant.position_b)+1].etat==1 && J[j].Intendant.Tab[J[j].Intendant.position_a][(J[j].Intendant.position_b)-1].etat==1 )
        {
            i=*valD;
            printf("Aucune direction disponible! Vous êtes bloqué");
            Sleep(2000);
            i=10;

        }
        else
        {
            printf("%s Choisir une direction \n",J[j].nom);
            scanf("%s",direct);
            if (strcmp(direct,droite)==0 || strcmp(direct,Droite)==0)
            {
                if(((J[j].Intendant.position_b)+1)<6 && ((J[j].Intendant.position_b)+1)>0)
                {
                    if(J[j].Intendant.Tab[J[j].Intendant.position_a][(J[j].Intendant.position_b)+1].etat==0)
                    {
                        (J[j].Intendant.position_b)=(J[j].Intendant.position_b)+1;
                        i++;
                        J[j].Intendant.Tab[J[j].Intendant.position_a][J[j].Intendant.position_b].etat=1;

                        printf("\n");
                    }
                    else
                    {

                        printf("case deja jouée, choisir autre direction \n");
                        Sleep(2000);

                    }

                }
                else
                {
                    printf("deplacement hors plateau \n");
                    Sleep(2000);
                }

            }
            else
            {
                if (strcmp(direct,gauche)==0 || strcmp(direct,Gauche)==0)
                {
                    if(((J[j].Intendant.position_b)-1)<6 && ((J[j].Intendant.position_b)-1)>0)
                    {
                        if(J[j].Intendant.Tab[J[j].Intendant.position_a][(J[j].Intendant.position_b)-1].etat==0)
                        {
                            (J[j].Intendant.position_b)=(J[j].Intendant.position_b)-1;
                            i++;
                            J[j].Intendant.Tab[J[j].Intendant.position_a][J[j].Intendant.position_b].etat=1;

                        }
                        else
                        {
                            printf("case deja jouée, choisir autre direction \n");
                            Sleep(2000);
                        }
                    }
                    else
                        printf("deplacement hors plateau \n");
                       Sleep(2000);

                }
                else
                {


                    if (strcmp(direct,bas)==0 || strcmp(direct,Bas)==0)
                    {
                        if(((J[j].Intendant.position_a)+1)<6 && ((J[j].Intendant.position_a)+1)>0)
                        {
                            if(J[j].Intendant.Tab[(J[j].Intendant.position_a)+1][J[j].Intendant.position_b].etat==0)
                            {
                                (J[j].Intendant.position_a)=(J[j].Intendant.position_a)+1;
                                i++;
                               J[j].Intendant.Tab[J[j].Intendant.position_a][J[j].Intendant.position_b].etat=1;

                            }
                            else
                            {
                                printf("case deja jouée, choisir autre direction \n");
                                Sleep(2000);
                            }
                        }
                        else
                        {
                            printf("deplacement hors plateau \n");
                            Sleep(2000);
                        }

                    }
                    else
                    {
                        if (strcmp(direct,haut)==0 || strcmp(direct,Haut)==0)
                        {
                            if(((J[j].Intendant.position_a)-1)<6 && ((J[j].Intendant.position_a)-1)>0)
                            {
                                if(J[j].Intendant.Tab[(J[j].Intendant.position_a)-1][J[j].Intendant.position_b].etat==0)
                                {
                                    (J[j].Intendant.position_a)=(J[j].Intendant.position_a)-1;
                                    i++;
                                    J[j].Intendant.Tab[J[j].Intendant.position_a][J[j].Intendant.position_b].etat=1;

                                }
                                else
                                {
                                    printf("case deja jouée, choisir autre direction \n");
                                    Sleep(2000);
                                }
                            }
                            else
                            {
                                printf("deplacement hors plateau \n");
                                Sleep(2000);
                            }

                        }
                        else
                        {
                            printf("mot non reconnu, reesayer \n");
                            Sleep(2000);
                        }
                    }
                }
            }



        }
        system("cls");
        afficher_i(J[j]);
    }
    J[j].Intendant.nba=(J[j].Intendant.nba)+1;
}





void bonusj(S_joueur T[], int j)
{
    int i,k;
    if (T[j].Intendant.Tab[T[j].Intendant.position_a][T[j].Intendant.position_b].Bonus==1)
        T[j].nb_or++;
        //+1 or

    if (T[j].Intendant.Tab[T[j].Intendant.position_a][T[j].Intendant.position_b].Bonus==2)
        T[j].nb_or=T[j].nb_or+2;
        //+2 or

    if (T[j].Intendant.Tab[T[j].Intendant.position_a][T[j].Intendant.position_b].Bonus==3)
        T[j].nb_chevres++;
        //+1 chèvre

    if (T[j].Intendant.Tab[T[j].Intendant.position_a][T[j].Intendant.position_b].Bonus==4)
        T[j].nb_chevres=T[j].nb_chevres+2;
        //+2 chèvres

    if (T[j].Intendant.Tab[T[j].Intendant.position_a][T[j].Intendant.position_b].Bonus==5)
    {
        i=1;
        k=0;
        Livraison(T,k,i,j);
    }
        //+1 quartier vert

    if (T[j].Intendant.Tab[T[j].Intendant.position_a][T[j].Intendant.position_b].Bonus==6)
    {
        i=2;
        k=0;
        Livraison(T,k,i,j);
    }
        //+2 quartier vert
    if (T[j].Intendant.Tab[T[j].Intendant.position_a][T[j].Intendant.position_b].Bonus==7)
    {
        i=1;
        k=1;
        Livraison(T,k,i,j);
    }
        //+1 quartier violet
    if (T[j].Intendant.Tab[T[j].Intendant.position_a][T[j].Intendant.position_b].Bonus==8)
    {
        i=1;
        k=2;
        Livraison(T,k,i,j);
    }
        //+1 quartier violet
    if (T[j].Intendant.Tab[T[j].Intendant.position_a][T[j].Intendant.position_b].Bonus==9)
    {
        i=1;
        k=3;
        Livraison(T,k,i,j);
    }
        //+1 quartier orange
    if (T[j].Intendant.Tab[T[j].Intendant.position_a][T[j].Intendant.position_b].Bonus==10)
        T[j].nb_des_jaunes_permanent++;
        //+1 dé jaune

    if (T[j].Intendant.Tab[T[j].Intendant.position_a][T[j].Intendant.position_b].Bonus==11)
        T[j].Intendant.pts++;

    if (T[j].Intendant.Tab[T[j].Intendant.position_a][T[j].Intendant.position_b].Bonus==12)
    {
        T[j].Intendant.nba=T[j].Intendant.nba+T[j].Intendant.pts;
        T[j].Intendant.pts=0;
        T[j].cpt_pts=T[j].cpt_pts+T[j].Intendant.nba;
    }
}
