#ifndef INITIALISATION_H_INCLUDED
#define INITIALISATION_H_INCLUDED

int nb_joueurs();
void Init(S_joueur T[], int i);
void Reinitialisation_case(S_plat Plateau[], int plat);
void Reinitialisation_partie(S_joueur T[], int nb);

//intendant
void ini_bonus(S_joueur T[], int j);
void ini_etat(S_joueur T[], int j);
void ini_pos(S_joueur T[], int j);

#endif // INITIALISATION_H_INCLUDED
