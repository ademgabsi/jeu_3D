#ifndef enemy_H_INCLUDED
#define enemy_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct Ennemi
	{
        SDL_Surface *sprite;
        SDL_Rect pos;
        int direction;
        SDL_Rect pos_sp;

	}Ennemi;

void initEnnemi(Ennemi*e);    
void afficherEnnemi(Ennemi e, SDL_Surface * screen);
void animerEnnemi( Ennemi * e);
void deplacer( Ennemi * e,int paa);
int collision( SDL_Rect E, SDL_Rect p) ;
void deplacerIA(Ennemi * E, SDL_Rect posPerso);




#endif 
