#ifndef QUARTIER_H_INCLUDED
#define QUARTIER_H_INCLUDED

void Quartier_chevres(S_plat Plateau[],S_joueur T[], int plat, int j);
void Quartier_or(S_plat Plateau[],S_joueur T[], int plat, int j);

void Marchandises(S_plat Plateau[],S_joueur T[], int plat, int j);
void Livraison(S_joueur T[], int plat, int nb, int j);

int verif_echoppe_commencee(S_joueur j, int plat);
int choisir_echoppe(S_joueur j, int plat, int nb);
void remplir_echoppe(int *nb_marchandises_act,int *nb_marchandises_max,int *statut,int plat,int *nb,int choix);

void Bonus_echoppe(S_joueur T[], int j, int plat);
void Bonus_quartier(S_joueur T[],int j,int nb);

#endif // QUARTIER_H_INCLUDED
