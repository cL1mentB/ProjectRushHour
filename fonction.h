#ifndef _FONCTION_H_
#define _FONCTION_H_
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

/*générateur de nbre aléatoire*/
int nbre_aleatoire(int a);



/*type booléen*/
typedef enum 
{
    true,
    false
}Bool;



/*definition du type véhicule*/

typedef struct Vehicule Vehicule;
struct Vehicule
{
    char nom ;
    int type; /* 2 pour une voiture et 3 pour un camion */
    int position; 
    int direction; /* 0 pour vertical et 1 pour horizontal*/
};



/*Element de la liste contenant les vehicules*/
typedef struct Element 
{
    struct Vehicule vehicule;
    struct Element *suivant;

}Element, *List;




typedef struct Tab Tab;
struct Tab
{
    int i;
    Bool vide;
    Bool videHori[2]; /*booléen sur les cases hirzontal*/
    Bool videVerti[2]; /*booléen sur les cases vertical*/
};




/*-------------------------------------------------------------*/
/*définition */




/* création d'une liste*/
List new_liste(void);
/* Liste vide ? */
Bool emptylist(List liste);

/*renvoie la taille de la liste*/
int liste_length(List liste);

/* affiche la liste*/
void print_liste(List liste);

/*Ajout d'un élément en tete de liste*/
List insertTete(List liste, Vehicule vehicule);



/*------------------------------------------------------------*/
/* prototype */




int empty_case(char *plateau); /*nombre de case vide*/

void print_plateau(char *plateau); /*affichage du plateau*/
void nb_double_empty(char *plateau); /*calcul le nombre de 2 cases cote à cote vide */
void nb_triple_empty(char *plateau); /*calcul le nombre de 3 cases cote à cote vide */
void add_vehiculeR(char *plateau, Vehicule voitureR);  /* ajout d'un vehicule dans le plateau*/

void add_vehicule(char *plateau, Vehicule vehicule);
void add_list(char *plateau, List liste); /* ajoute tout les vehicules de la liste sur le plateau*/
Vehicule add_voiture_aleatoi(char * plateau, char nom_voiture,Tab *tableau_des_cases);
Tab space_pour_voiture(Tab *tableau_des_cases, int nb_alea);
Vehicule add_camion_aleatoi(char *plateau, char nom_voiture, Tab *tableau_des_cases);
Tab space_pour_camion(Tab *tableau_des_cases, int nb_alea);

List create_liste_vehicule(void); /*créer une liste de véhicule afin de les placer sur le plateau*/

/*déplacement d'un véhicule dans le plateau*/
void move_vehicule(List liste_des_vehicules, int nv_position, char nom_vehicule, char * plateau, Tab * tableau_des_cases);
#endif