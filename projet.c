#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "fonction.h"
#include <time.h>



int main(){

    srand(time(NULL));

    List liste_des_vehicules = new_liste();
  
    Tab tableau_des_cases[36];
    


    char plateau[6][6] = {{' ',' ',' ',' ',' ',' '},
                          {' ',' ',' ',' ',' ',' '},
                          {' ','R','R',' ',' ',' '},
                          {' ',' ',' ',' ',' ',' '},
                          {' ',' ',' ',' ',' ',' '},
                          {' ',' ',' ',' ',' ',' '}}; 
    /*plateau de jeu dans lequel sera positionné des vehicules*/

    for(int i = 0; i<36; i++)
    {
        tableau_des_cases[i].i = i;
        tableau_des_cases[i].vide = true;
        tableau_des_cases[i].videHori[0] = true;
        tableau_des_cases[i].videHori[1] = true;
        tableau_des_cases[i].videVerti[0] = true;
        tableau_des_cases[i].videVerti[1] = true;
        
    }

    tableau_des_cases[13].vide = false;
    tableau_des_cases[13].videHori[0] = false;
    tableau_des_cases[14].vide = false;
    tableau_des_cases[12].videHori[0]=false;
    tableau_des_cases[12].videHori[1]=false;
    tableau_des_cases[10].videHori[1]=false;
    tableau_des_cases[10].videVerti[0] = false;
    tableau_des_cases[7].videVerti[0] = false;
    tableau_des_cases[8].videVerti[0] = false;
    tableau_des_cases[2].videVerti[1] = false;
    tableau_des_cases[1].videVerti[1] = false;
        
    char nom_vehicule[12] = {'A','B','C','Z','E','F','N','H','I','K','L','M'};
    for (int i = 0; i<12; i++)
    {  
        Vehicule vehicule;
        if(rand()%2 ==1){
            vehicule = add_camion_aleatoi(&(plateau[0][0]),nom_vehicule[i],&(tableau_des_cases[0]));
            liste_des_vehicules = insertTete(liste_des_vehicules, vehicule);
        }
        else
        {
            vehicule = add_voiture_aleatoi(&(plateau[0][0]),nom_vehicule[i],&(tableau_des_cases[0]));
            liste_des_vehicules = insertTete(liste_des_vehicules, vehicule);
        }
        
    }

    print_plateau(&(plateau[0][0]));

    int nv_position;
    char nom ;
    print_liste(liste_des_vehicules);
    printf("nom de la voiture :  \n");
    scanf("%c",&nom);
    printf("la nouvelle position : 1 \n");
    scanf("%d",&nv_position); 

    move_vehicule(liste_des_vehicules, nv_position, nom , &(plateau[0][0]), &(tableau_des_cases[0]) );

    print_plateau(&(plateau[0][0]));

    return 0;
}