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



void Quartier_chevres(S_plat Plateau[],S_joueur T[], int plat, int j)
{
    char menu[4][30]= {"Récupérer","chèvres","Bouger l'intendant de","pas"};
    int choix=0; // numéro de l'option choisie dans le menu
    int frappe=0; //permet de stocker le code de la touche clavier


    printf("%s %d %s                                   \n",menu[0],Plateau[plat-1].nb_des_total,menu[1]);
    printf("%s %d %s                           \n",menu[2],Plateau[plat-1].valeur_des,menu[3]);


    Positionner_Curseur(0,60);
    color(0,15);
    printf("%s %d %s                                   \n",menu[0],Plateau[plat-1].nb_des_total,menu[1]);
    color(15,0);
    Positionner_Curseur(0,63);
    printf("\n");

    while(frappe!=13) // tant qu'on a pas appuyer sur la touche ECHAP
    {
        if (kbhit()) //si on a appuyer sur une touche du clavier
        {
            frappe=getch(); // on récupère le code de la touche sur laquelle on a appuyée
            if(frappe==72) //75 est le code de la flèche directionnelle vers le haut
            {
                Positionner_Curseur(0,choix+60); // positionne le curseur au choix courant
                color(15,0); // met la couleur du texte en blanc et celle du fond en noir

                if(choix==0)
                    printf("%s %d %s                                   \n",menu[0],Plateau[plat-1].nb_des_total,menu[1]);
                else
                    printf("%s %d %s                           \n",menu[2],Plateau[plat-1].valeur_des,menu[3]);


                choix--; // on décrémebte le numéro de l'option
                if(choix==-1)
                    choix=1; // les options sont numérotées de 0 à 5
                Positionner_Curseur(0,choix+60);// positionne le curseur au choix juste dessus du précédent
                color(0,15);// met la couleur du texte en noir et celle du fond en blanc


                if(choix==0)
                    printf("%s %d %s                                   \n",menu[0],Plateau[plat-1].nb_des_total,menu[1]);
                else
                    printf("%s %d %s                           \n",menu[2],Plateau[plat-1].valeur_des,menu[3]);// On réaffiche le nouveau choix  avec les couleurs préalablement choisies, une manière de le séléctionner


                color(15,0);
            }
            if(frappe==80) //80 est le code de la flèche directionnelle vers le bas
            {
                Positionner_Curseur(0,choix+60);
                color(15,0);


                if(choix==0)
                    printf("%s %d %s                                   \n",menu[0],Plateau[plat-1].nb_des_total,menu[1]);
                else
                    printf("%s %d %s                           \n",menu[2],Plateau[plat-1].valeur_des,menu[3]);


                choix++;
                if(choix==2)
                    choix=0;
                Positionner_Curseur(0,choix+60);
                color(0,15);



                if(choix==0)
                    printf("%s %d %s                                   \n",menu[0],Plateau[plat-1].nb_des_total,menu[1]);
                else
                    printf("%s %d %s                           \n",menu[2],Plateau[plat-1].valeur_des,menu[3]);



                color(15,0);
            }
        }
        Positionner_Curseur(0,63);
    }
    choix++;
    switch (choix)
    {
    case 1 :
    {
        T[j].nb_chevres=T[j].nb_chevres+Plateau[plat-1].nb_des_total;
        printf("\nTu as à présent %d chèvres\n",T[j].nb_chevres);
    }
    break;
    case 2 :
        Intendant(Plateau[plat-1].valeur_des,T,j);
        break;

    default :
        printf("Choix invalide ! merci de taper une valeur entre 1 et 6 ! \n");
        system("PAUSE");
        break;
    }
    choix=0;
    frappe=0;
}


void Quartier_or(S_plat Plateau[],S_joueur T[], int plat, int j)
{
    char menu[4][30]= {"Récupérer","or","Bouger l'intendant de","pas"};
    int choix=0; // numéro de l'option choisie dans le menu
    int frappe=0; //permet de stocker le code de la touche clavier


    printf("%s %d %s                                   \n",menu[0],Plateau[plat-1].nb_des_total,menu[1]);
    printf("%s %d %s                           \n",menu[2],Plateau[plat-1].valeur_des,menu[3]);


    Positionner_Curseur(0,60);
    color(0,15);
    printf("%s %d %s                                   \n",menu[0],Plateau[plat-1].nb_des_total,menu[1]);
    color(15,0);
    Positionner_Curseur(0,63);
    printf("\n");

    while(frappe!=13) // tant qu'on a pas appuyer sur la touche ECHAP
    {
        if (kbhit()) //si on a appuyer sur une touche du clavier
        {
            frappe=getch(); // on récupère le code de la touche sur laquelle on a appuyée
            if(frappe==72) //75 est le code de la flèche directionnelle vers le haut
            {
                Positionner_Curseur(0,choix+60); // positionne le curseur au choix courant
                color(15,0); // met la couleur du texte en blanc et celle du fond en noir

                if(choix==0)
                    printf("%s %d %s                                   \n",menu[0],Plateau[plat-1].nb_des_total,menu[1]);
                else
                    printf("%s %d %s                           \n",menu[2],Plateau[plat-1].valeur_des,menu[3]);


                choix--; // on décrémebte le numéro de l'option
                if(choix==-1)
                    choix=1; // les options sont numérotées de 0 à 5
                Positionner_Curseur(0,choix+60);// positionne le curseur au choix juste dessus du précédent
                color(0,15);// met la couleur du texte en noir et celle du fond en blanc


                if(choix==0)
                    printf("%s %d %s                                   \n",menu[0],Plateau[plat-1].nb_des_total,menu[1]);
                else
                    printf("%s %d %s                           \n",menu[2],Plateau[plat-1].valeur_des,menu[3]);// On réaffiche le nouveau choix  avec les couleurs préalablement choisies, une manière de le séléctionner


                color(15,0);
            }
            if(frappe==80) //80 est le code de la flèche directionnelle vers le bas
            {
                Positionner_Curseur(0,choix+60);
                color(15,0);


                if(choix==0)
                    printf("%s %d %s                                   \n",menu[0],Plateau[plat-1].nb_des_total,menu[1]);
                else
                    printf("%s %d %s                           \n",menu[2],Plateau[plat-1].valeur_des,menu[3]);


                choix++;
                if(choix==2)
                    choix=0;
                Positionner_Curseur(0,choix+60);
                color(0,15);



                if(choix==0)
                    printf("%s %d %s                                   \n",menu[0],Plateau[plat-1].nb_des_total,menu[1]);
                else
                    printf("%s %d %s                           \n",menu[2],Plateau[plat-1].valeur_des,menu[3]);



                color(15,0);
            }
        }
        Positionner_Curseur(0,63);
    }
    choix++;
    switch (choix)
    {
    case 1 :
    {
        if(T[j].batiments[3].statut==1)
            Plateau[plat-1].nb_des_total=Plateau[plat-1].nb_des_total+2;
        T[j].nb_or=T[j].nb_or+Plateau[plat-1].nb_des_total;
        printf("\nTu as à présent %d or\n",T[j].nb_or);
    }
    break;
    case 2 :
        Intendant(Plateau[plat-1].valeur_des,T,j);
        break;

    default :
        printf("Choix invalide ! merci de taper une valeur entre 1 et 6 ! \n");
        system("PAUSE");
        break;
    }
    choix=0;
    frappe=0;
}



void Marchandises(S_plat Plateau[],S_joueur T[], int plat, int j)
{
    char menu[4][30]= {"Livrer","marchandises","Bouger l'intendant de","pas"};
    int choix=0; // numéro de l'option choisie dans le menu
    int frappe=0; //permet de stocker le code de la touche clavier


    printf("%s %d %s                                   \n",menu[0],Plateau[plat-1].nb_des_total,menu[1]);
    printf("%s %d %s                           \n",menu[2],Plateau[plat-1].valeur_des,menu[3]);


    Positionner_Curseur(0,60);
    color(0,15);
    printf("%s %d %s                                   \n",menu[0],Plateau[plat-1].nb_des_total,menu[1]);
    color(15,0);
    Positionner_Curseur(0,63);
    printf("\n");

    while(frappe!=13) // tant qu'on a pas appuyer sur la touche ECHAP
    {
        if (kbhit()) //si on a appuyer sur une touche du clavier
        {
            frappe=getch(); // on récupère le code de la touche sur laquelle on a appuyée
            if(frappe==72) //75 est le code de la flèche directionnelle vers le haut
            {
                Positionner_Curseur(0,choix+60); // positionne le curseur au choix courant
                color(15,0); // met la couleur du texte en blanc et celle du fond en noir

                if(choix==0)
                    printf("%s %d %s                                   \n",menu[0],Plateau[plat-1].nb_des_total,menu[1]);
                else
                    printf("%s %d %s                           \n",menu[2],Plateau[plat-1].valeur_des,menu[3]);


                choix--; // on décrémebte le numéro de l'option
                if(choix==-1)
                    choix=1; // les options sont numérotées de 0 à 5
                Positionner_Curseur(0,choix+60);// positionne le curseur au choix juste dessus du précédent
                color(0,15);// met la couleur du texte en noir et celle du fond en blanc


                if(choix==0)
                    printf("%s %d %s                                   \n",menu[0],Plateau[plat-1].nb_des_total,menu[1]);
                else
                    printf("%s %d %s                           \n",menu[2],Plateau[plat-1].valeur_des,menu[3]);// On réaffiche le nouveau choix  avec les couleurs préalablement choisies, une manière de le séléctionner


                color(15,0);
            }
            if(frappe==80) //80 est le code de la flèche directionnelle vers le bas
            {
                Positionner_Curseur(0,choix+60);
                color(15,0);


                if(choix==0)
                    printf("%s %d %s                                   \n",menu[0],Plateau[plat-1].nb_des_total,menu[1]);
                else
                    printf("%s %d %s                           \n",menu[2],Plateau[plat-1].valeur_des,menu[3]);


                choix++;
                if(choix==2)
                    choix=0;
                Positionner_Curseur(0,choix+60);
                color(0,15);



                if(choix==0)
                    printf("%s %d %s                                   \n",menu[0],Plateau[plat-1].nb_des_total,menu[1]);
                else
                    printf("%s %d %s                           \n",menu[2],Plateau[plat-1].valeur_des,menu[3]);


                color(15,0);
            }
        }
        Positionner_Curseur(0,63);
    }
    choix++;

    switch (choix)
    {
    case 1 :
    {
        if(T[j].batiments[1].statut==1)
            Plateau[plat-1].nb_des_total++;
        Livraison(T,plat,Plateau[plat-1].nb_des_total,j);
    }
    break;
    case 2 :
        Intendant(Plateau[plat-1].valeur_des,T,j);
        break;

    default :
        printf("Choix invalide ! merci de taper une valeur entre 1 et 6 ! \n");
        system("PAUSE");
        break;
    }
    choix=0;
    frappe=0;
}

void Livraison(S_joueur T[], int plat, int nb, int j)
{
    //-1 : aucune échoppe commencée
    // autre nb : nb de l'échoppe commencée
    int i,m;
    for(i=0; i<4; i++)
    {
        if(T[j].quartier[plat-2].echoppe[i].statut==1 || T[j].quartier[plat-2].echoppe[i].statut==2)
            m++;
    }
    if(m<4)
    {
        while(nb>0)
        {
            int k=verif_echoppe_commencee(T[j],plat);  //vérifier si il existe une échoppe commencée, elle est prioritaire sur les autres échoppes
            int choix;
            if(k==-1)
            {
                choix=choisir_echoppe(T[j],plat,nb);
                remplir_echoppe(&T[j].quartier[plat-2].echoppe[choix].nb_marchandises_act,&T[j].quartier[plat-2].echoppe[choix].nb_marchandises_max,&T[j].quartier[plat-2].echoppe[choix].statut,plat,&nb,choix);  //ne pas faire choix-1
            }
            else
            {
                remplir_echoppe(&T[j].quartier[plat-2].echoppe[k].nb_marchandises_act,&T[j].quartier[plat-2].echoppe[k].nb_marchandises_max,&T[j].quartier[plat-2].echoppe[k].statut,plat,&nb,k);      //ne pas faire k-1
            }
            Bonus_echoppe(T,j,plat);
        }
    }
}


int verif_echoppe_commencee(S_joueur j, int plat)
{
    int i,m;
    int k=0;
    for(i=0; i<4; i++)
    {
        if(j.quartier[plat-2].echoppe[i].nb_marchandises_act!=0 && j.quartier[plat-2].echoppe[i].nb_marchandises_act<j.quartier[plat-2].echoppe[i].nb_marchandises_max)
            m=i;
        else
            k++;
    }
    if(k==4)
        return -1;
    else
        return m;
}



int choisir_echoppe(S_joueur j, int plat, int nb)
{
    int choix;
    int continuer=0;
    afficher_echoppes(j,plat);
    printf("\nLivrer %d marchandises dans quelle échoppe ? ",nb);
    scanf("%d",&choix);
    while(continuer==0)
    {
        if(j.quartier[plat-2].echoppe[choix-1].statut==1 || j.quartier[plat-2].echoppe[choix-1].statut==2 || choix<1 || choix>4)
        {
            printf("Cette échoppe est pleine ! Choisis une autre échoppe : ");
            scanf("%d",&choix);
        }
        else
            continuer=1;
    }
    return choix-1;
}



void remplir_echoppe(int *nb_marchandises_act,int *nb_marchandises_max,int *statut,int plat,int *nb,int choix)
{
    while(*statut!=1 && *nb>0)
    {
        *nb_marchandises_act=*nb_marchandises_act+1;
        *nb=*nb-1;
        if(*nb_marchandises_act==*nb_marchandises_max)
            *statut=1;
    }
}


void Bonus_echoppe(S_joueur T[], int j, int plat)
{
    int i;
    for(i=0; i<4; i++)
    {
        if(T[j].quartier[plat-2].echoppe[i].statut==1)
        {
            T[j].cpt_pts=T[j].cpt_pts+T[j].quartier[plat-2].echoppe[i].nb_pts;
            T[j].quartier[plat-2].echoppe[i].statut=2;
        }
    }
}


void Bonus_quartier(S_joueur T[],int j,int nb)
{
    int i,k,n;
    int m=0;
    for(i=0; i<4; i++)
    {
        for(k=0; k<4; k++)
        {
            if(T[j].quartier[i].echoppe[k].statut==2)
                m++;
        }
        if(m==4)
        {
            T[j].cpt_pts=T[j].cpt_pts+T[j].quartier[i].pts_bonus;
            for(n=0; n<nb; n++)
                T[n].quartier[i].pts_bonus=0;
        }
    }
}
