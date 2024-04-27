#ifndef MINIMAP_H
#define MINIMAP_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "image.h"
#include "background.h"
#include <time.h>
#include <SDL/SDL_ttf.h>
typedef struct temps
{int min, sec;
char entree[100]; 
int secondesEcoulees; 
SDL_Surface *texte;
SDL_Rect position;
TTF_Font *police ;
SDL_Color couleurBlanche;
time_t t1,t2; 
}temps;
void initialiser_temps(temps *t);
void afficher_temps(temps *t, SDL_Surface *ecran);
void free_temps(temps *t,SDL_Surface *ecran);
typedef struct {
 background mb;

Image mp;
Image me;
} minimap;
void initminimap( minimap * m,char fn[],char fp[],char fe[]);
void MAJMinimap(SDL_Rect posJoueur , minimap * m, SDL_Rect camera, int redimensionnement);
void afficherminimap (minimap m, SDL_Surface * screen);
void liberermini(minimap *m);

SDL_Color GetPixel(SDL_Surface *pSurface ,int x,int y);
int collision_pright(SDL_Surface *mask , SDL_Rect pos_joueur );
int collision_pleft(SDL_Surface *mask, SDL_Rect pos_joueur);
int collision_pup(SDL_Surface *mask, SDL_Rect pos_joueur);
int collision_pdown(SDL_Surface *mask, SDL_Rect pos_joueur);


void enregistrer(SDL_Surface *s,char nomjoueur[]);
void sauvegarder( int score, char nomjoueur[], char nomfichier[]); 
void meilleur( char nomfichier[], int *score, char nomjoueur[]); 

void xo(int *score,SDL_Surface *s); 
#endif
