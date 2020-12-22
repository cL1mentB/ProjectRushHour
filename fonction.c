#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "fonction.h"
#include <time.h>

/*générateur de nombre aléatoire*/
int nbre_aleatoire(int a)
{
    srand(time(NULL));
    int nb_aleatoire = rand()%a;
    return nb_aleatoire;
}

/* création d'une liste*/
List new_liste(void){
    return NULL;
}

/* Liste vide ? */
Bool emptylist(List liste){
    if(liste == NULL){
        return true;
    }
    return false;
}


/*renvoie la taille de la liste*/
int liste_length(List liste){
    int size  = 0;
    if(emptylist(liste) == true){
        return size;
    }

    while(liste != NULL){
        ++size;
        liste = liste->suivant;
    }

    return size;
}


/* affiche la liste*/
void print_liste(List liste){
    if(emptylist(liste)==true){
        printf("la liste est vide");
        return;
    }
    while(liste != NULL){
        printf("[%c,%d,%d,%d] -> ", liste->vehicule.nom, liste->vehicule.type, liste->vehicule.position, liste->vehicule.direction );
        liste = liste->suivant;
    }
    printf("NULL");
    printf("\n");
    return;
}

/*Ajout d'un élément en tete de liste*/
List insertTete(List liste, Vehicule vehicule){
    Element *nouveau ;
    nouveau = malloc(sizeof(*nouveau));

    if(nouveau == NULL){
        fprintf(stderr, "Erreur : problème allocation dynamique.\n");
    }

    nouveau->vehicule = vehicule;
    
    /*print_liste(liste);*/

    if(emptylist(liste) == true){
        nouveau->suivant = NULL;
        
    }
    else{
        nouveau->suivant = liste;
    }

    return nouveau;

}



/*implémentation des fonctions*/

void print_plateau(char *plateau)
{
    for(int i =0; i<6; i++){
            for(int j =0; j<6; j++){
                printf("| %c ",plateau[6*i+j]);
               
            }
            printf("|");
            printf("\n");
        }
}

int empty_case(char * plateau)
{
    int nb_empty_case = 0;
    for (int i =0; i<9; i++)
    {
        if(plateau[i]=='O')
        {
            nb_empty_case++;
        }
    }
    return nb_empty_case;
}

/* ajoute tout les vehicules de la liste sur le plateau*/
void add_list(char *plateau, List liste)
{
    if(emptylist(liste)==true){
        printf("la liste est vide, il n'a rien à ajouter au tableau\n");
        return;
    }

    while(liste != NULL){
        add_vehicule(plateau, liste->vehicule);
        liste = liste->suivant;
    }
    printf("\n");
    return;
}


void add_vehiculeR(char *plateau, Vehicule voitureR)
{/* on suppose que le vehicule est une voiture*/
    if(voitureR.direction == 1)
    {
        plateau[voitureR.position] = voitureR.nom;
        plateau[voitureR.position+1] = voitureR.nom;
    }
    else{
        plateau[voitureR.position] = voitureR.nom;
        plateau[voitureR.position + 3] = voitureR.nom;
    }
    return;
}


void add_vehicule(char *plateau, Vehicule vehicule)
{
    
    if(vehicule.type == 2){ 
        if(vehicule.direction == 0){             /*vertical et voiture*/
            plateau[vehicule.position] = vehicule.nom;
            plateau[vehicule.position+3] = vehicule.nom;
        }
        else{                                /*horizontal et voiture*/
            plateau[vehicule.position]=vehicule.nom;  
            plateau[vehicule.position+1] = vehicule.nom;
            
        }

    }

    else{
        if(vehicule.direction == 0){             /*vertical et camion*/
            plateau[vehicule.position] = vehicule.nom;
            plateau[vehicule.position+3] = vehicule.nom;
            plateau[vehicule.position+6] = vehicule.nom;
        }
        else{                               /*horizontal et camion*/
            plateau[vehicule.position]=vehicule.nom;
            plateau[vehicule.position+1] = vehicule.nom;
            plateau[vehicule.position+2] = vehicule.nom;

        }

    }

}


/*void add_voiture_aleatoi(char * plateau, char nom_voiture)
{
    Vehicule voiture;
    voiture.nom = nom_voiture;
    voiture.type = 2;
    int nb_alea = nbre_aleatoire(8); 
    while((plateau[nb_alea] != 'O') && (((((nb_alea+1)%3 != 0) && (plateau[nb_alea+1] == 'O')) || ((plateau[nb_alea+3] == 'O')) && (nb_alea<6))))
    {
        nb_alea = nbre_aleatoire(8);
    }
    voiture.position = nb_alea;
    if((plateau[nb_alea+1] == 'O') && ((nb_alea+1)%3 != 0))
    {
        plateau[nb_alea] = nom_voiture;
        plateau[nb_alea+1] = nom_voiture;
        voiture.direction = 1;
    }
    
    else
    {
        plateau[nb_alea] = nom_voiture;
        plateau[nb_alea+3] = nom_voiture;
        voiture.direction = 0;
    }
    

}*//* ça marche pas top !! */


/*void add_voiture_aleatoi(char *plateau,char nom_voiture)
{

    Vehicule voiture;
    voiture.nom = nom_voiture;
    voiture.type = 2;
    int nb_alea = nbre_aleatoire(8); 
    while((plateau[nb_alea] != 'O') && (((((nb_alea+1)%3 != 0) && (plateau[nb_alea+1] == 'O')) || ((plateau[nb_alea+3] == 'O')) && (nb_alea<6))))
    {
        nb_alea = nbre_aleatoire(8);
    }
    voiture.position = nb_alea;
    if((plateau[nb_alea+1] == 'O') && ((nb_alea+1)%3 != 0))
    {
        plateau[nb_alea] = nom_voiture;
        plateau[nb_alea+1] = nom_voiture;
        voiture.direction = 1;
    }
    
    else
    {
        plateau[nb_alea] = nom_voiture;
        plateau[nb_alea+3] = nom_voiture;
        voiture.direction = 0;
    }
    

}*/




Tab space_pour_voiture(Tab *tableau_des_cases, int nb_alea)
{
    int i = 0;

    
    if(nb_alea == 1)/* voiture horizontal ==> voiture.direction = 1*/
    {
        while((((i+1)%6 == 0) || ((tableau_des_cases[i].vide == false) || (tableau_des_cases[i].videHori[0]== false))))
        {     
            i++;
        }
        
        return tableau_des_cases[i];
    }
    else /*voiture vertical  ==>  voiture.direction = 0*/
    {
        while(((((i)>=30) || ((tableau_des_cases[i].vide == false) || (tableau_des_cases[i].videVerti[0]== false)))))
        {         
            i++;
            
        }
        
        return tableau_des_cases[i];
    }
    
}

Vehicule add_voiture_aleatoi(char *plateau, char nom_voiture, Tab *tableau_des_cases)
{


    /*List liste_des_vehicules;*/
    Vehicule voiture;
    voiture.nom = nom_voiture;
    int nb_alea = rand()%2; 
    voiture.direction = nb_alea;
    voiture.type = 2;
    
    Tab place = space_pour_voiture(tableau_des_cases, nb_alea);
    voiture.position = place.i;
    if(nb_alea == 1)
    {

        plateau[place.i] = nom_voiture;
        plateau[place.i +1] = nom_voiture;
        tableau_des_cases[place.i].vide = false;
        tableau_des_cases[place.i].videHori[0] = false;
        tableau_des_cases[place.i+1].vide = false;
        if(place.i>1)
        {
            tableau_des_cases[place.i-1].videHori[0]=false;
            tableau_des_cases[place.i-1].videHori[1]=false;

        }
        if(place.i>2)
        {
            tableau_des_cases[place.i-2].videHori[1]=false;
        }
        if(place.i>5)
        {
            tableau_des_cases[place.i-5].videVerti[0] = false;
        }
        if(place.i>6)
        {
            tableau_des_cases[place.i-6].videVerti[0] = false;
        }
        if(place.i>11)
        {
            tableau_des_cases[place.i-11].videVerti[1] = false;
        }
        if(place.i>12)
        {
            tableau_des_cases[place.i-12].videVerti[1] = false;
        }

    }
    else
    {
    
        plateau[place.i] = nom_voiture;
        plateau[place.i+6] = nom_voiture;
        tableau_des_cases[place.i].vide = false;
        tableau_des_cases[place.i].videVerti[0] = false;
        tableau_des_cases[place.i+6].vide = false;
        tableau_des_cases[place.i+5].videHori[0] = false;
        tableau_des_cases[place.i+4].videHori[1] = false;
        if(place.i>1){
            tableau_des_cases[place.i-1].videHori[0] = false;
        }
        if(place.i>2)
        {
            tableau_des_cases[place.i-2].videHori[1] = false;
        }
        if(place.i>12)
        {
            tableau_des_cases[place.i-12].videVerti[1] = false;
        }
        if(place.i>6)
        {
            tableau_des_cases[place.i-6].videVerti[0] = false;
            tableau_des_cases[place.i-6].videVerti[1] = false;
        }

        
        
    }
    
    return voiture;
}


Tab space_pour_camion(Tab *tableau_des_cases, int nb_alea)
{
    int i = 0;

    
    if(nb_alea == 1)/* voiture horizontal ==> voiture.direction = 1*/
    {
        while((((i+2)%6 == 0) || (i+1)%6 == 0) || ((tableau_des_cases[i].vide == false) || (tableau_des_cases[i].videHori[0]== false) || (tableau_des_cases[i].videHori[1]== false) ))
        {     
            i++;
        }
        
        return tableau_des_cases[i];
    }
    else /*voiture vertical  ==>  voiture.direction = 0*/
    {
        while(((  ((i)>=24) || ((tableau_des_cases[i].vide == false) || (tableau_des_cases[i].videVerti[0]== false) || (tableau_des_cases[i].videVerti[1]== false))  )))
        {         
            i++;
            
        }
        
        return tableau_des_cases[i];
    }
    
}



Vehicule add_camion_aleatoi(char *plateau, char nom_camion, Tab *tableau_des_cases)
{


    /*List liste_des_vehicules;*/
    Vehicule camion;
    camion.nom = nom_camion;
    int nb_alea = rand()%2; 
    camion.direction = nb_alea;
    camion.type = 2;
    
    Tab place = space_pour_camion(tableau_des_cases, nb_alea);
    camion.position = place.i;
    if(nb_alea == 1)
    {

        plateau[place.i] = nom_camion;
        plateau[place.i +1] = nom_camion;
        plateau[place.i +2] = nom_camion;
        tableau_des_cases[place.i].vide = false;
        tableau_des_cases[place.i].videHori[0] = false;
        tableau_des_cases[place.i].videHori[1] = false;
        tableau_des_cases[place.i+1].vide = false;
        tableau_des_cases[place.i+1].videHori[0] = false;
        tableau_des_cases[place.i+2].vide = false;
        if(place.i>1)
        {
            tableau_des_cases[place.i-1].videHori[0]=false;
            tableau_des_cases[place.i-1].videHori[1]=false;

        }
        if(place.i>2)
        {
            tableau_des_cases[place.i-2].videHori[1]=false;
        }
        if(place.i>4)
        {
            tableau_des_cases[place.i-4].videVerti[0] = false;
        }
        if(place.i>5)
        {
            tableau_des_cases[place.i-5].videVerti[0] = false;
        }
        if(place.i>6)
        {
            tableau_des_cases[place.i-6].videVerti[0] = false;
        }
        if(place.i>10)
        {
            tableau_des_cases[place.i-10].videVerti[1] = false;
        }
        if(place.i>11)
        {
            tableau_des_cases[place.i-11].videVerti[1] = false;
        }
        if(place.i>12)
        {
            tableau_des_cases[place.i-12].videVerti[1] = false;
        }

    }
    else
    {
    
        plateau[place.i] = nom_camion;
        plateau[place.i+6] = nom_camion;
        plateau[place.i+12] = nom_camion;
        tableau_des_cases[place.i].vide = false;
        tableau_des_cases[place.i].videVerti[0] = false;
        tableau_des_cases[place.i].videVerti[1] = false;
        tableau_des_cases[place.i+6].vide = false;
        tableau_des_cases[place.i+6].videVerti[0] = false;
        tableau_des_cases[place.i+5].videHori[0] = false;
        tableau_des_cases[place.i+4].videHori[1] = false;
        tableau_des_cases[place.i+10].videHori[1] = false;
        tableau_des_cases[place.i+11].videHori[0] = false;
        if(place.i>1){
            tableau_des_cases[place.i-1].videHori[0] = false;
        }
        if(place.i>2)
        {
            tableau_des_cases[place.i-2].videHori[1] = false;
        }
        if(place.i>12)
        {
            tableau_des_cases[place.i-12].videVerti[1] = false;
        }
        if(place.i>6)
        {
            tableau_des_cases[place.i-6].videVerti[0] = false;
            tableau_des_cases[place.i-6].videVerti[1] = false;
        }

        
        
    }
    
    return camion;
}

void move_vehicule(List liste_des_vehicules, int nv_position, char nom_vehicule, char * plateau, Tab * tableau_des_cases)
{
    
    if(emptylist(liste_des_vehicules) == true){

        return;
    }
 
    Element *tmp;
    tmp = liste_des_vehicules;
   
    while(tmp->vehicule.nom != nom_vehicule){
        tmp = tmp->suivant;
    }
    /* nv_position = {1,2,3,4} : 1 = droite, 2 = gauche, 3 = haut, 4 = bas */
    /*camion ou voiture ? */
    if(tmp->vehicule.type==2)
    {
        if(nv_position = 1)
        {
            tmp->vehicule.position = tmp->vehicule.position+1;
            plateau[tmp->vehicule.position+1] = tmp->vehicule.nom;
            plateau[tmp->vehicule.position-1] = ' ';
            tableau_des_cases[tmp->vehicule.position+1]

        }
        
        return;
    }
        
}
