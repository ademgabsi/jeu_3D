#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "fct.h"
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
int piocherMot(char *motPioche)
{

    FILE* dico = NULL; 
    int nombreMots = 0, numMotChoisi = 0, i = 0;
    int caractereLu = 0;
    dico = fopen("dico.txt", "r"); 
    if (dico == NULL)
    {
        printf("\nImpossible de charger le dictionnaire de mots");
    }
    do
    {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            nombreMots++;
    } while(caractereLu != EOF);
    numMotChoisi = nombreAleatoire(nombreMots); 
    rewind(dico);
    while (numMotChoisi > 0)
    {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            numMotChoisi--;
    }
    fgets(motPioche, 100, dico);
    motPioche[strlen(motPioche) - 1] = '\0';
    fclose(dico);
    return strlen(motPioche);
}
int nombreAleatoire(int nombreMax)
{
    srand(time(NULL));
    return (rand() % nombreMax);
}



int gagne(int lettreTrouvee[], long tailleMot)
{
    long i = 0;
    int joueurGagne = 1;
    for (i = 0 ; i < tailleMot ; i++)
    {
        if (lettreTrouvee[i] == 0)
            joueurGagne = 0;
    }
    return joueurGagne;
}
int rechercheLettre(char lettre, char motSecret[],int nombre)
{
    long i = 0;
    // On parcourt motSecret pour vérifier si la lettre proposée y est
    for (i = 0 ;i<nombre; i++)
    {
        if (lettre == motSecret[i]) // Si la lettre y est
        {
            fprintf(stderr,"%c\n",lettre);
            return i;
        }
        else{
             	fprintf(stderr,"%s et %d \n",motSecret,nombre);      
        }
       
    
}
return -1;
}

int verifier_reponse(char *m1,char *m2,int nombre){
 int i;
 
 for(i=0;i<nombre;i++){
     if(m1[i]!=m2[i]){
      return 0;   
     }
 }
 return 1;
}
