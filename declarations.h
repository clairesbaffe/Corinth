#ifndef DECLARATIONS_H_INCLUDED
#define DECLARATIONS_H_INCLUDED

#define DIM 30

//intendant
struct Casee
{
    int etat;
    int Bonus;
};
typedef struct Casee case_i;

struct Intendant
{
    int position_a;
    int position_b;
    int pts; //points issue de +1
    int batiment;
    int nba;        //nombre d'arrêts
    case_i Tab[7][7];
};
typedef struct Intendant S_Intendant;









struct Plateau
{
    int valeur_des;
    int nb_des_blancs;
    int nb_des_jaunes;
    int nb_des_total;
    int statut;         //0 pour pas de des ; 1 pour il y a des
};
typedef struct Plateau S_plat;


struct Batiments
{
    int statut; //0 pour pas construit ; 1 pour construit
    char nom[DIM];
    int prix_or;
    int prix_chevres;
};
typedef struct Batiments S_bat;




struct Echoppe
{
    int nb_pts;
    int nb_marchandises_max;
    int nb_marchandises_act;
    int statut; //0 pour vide, 1 pour terminé
};
typedef struct Echoppe S_echoppe;




struct Quartier
{
    S_echoppe echoppe[4];
    int statut; //0 pour non terminé, 1 pour terminé
    int pts_bonus;  //si 1e à remplir le quartier
};
typedef struct Quartier S_quartier;








struct Joueur
{
    char nom[DIM];
    int cpt_pts;
    int nb_or;
    int nb_chevres;
    int nb_des_jaunes;
    int nb_des_jaunes_permanent;
    S_quartier quartier[4];          //quartiers bleu et orange
    S_bat batiments[4]; //0:temple ; 1:entrepot ; 2:etable ; 3:magasin
    S_Intendant Intendant;
};
typedef struct Joueur S_joueur;

#endif // DECLARATIONS_H_INCLUDED
