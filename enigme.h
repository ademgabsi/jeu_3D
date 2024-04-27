#ifndef ENIGME_H
#define ENIGME_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

typedef struct{
  SDL_Surface * back;
  SDL_Surface *quest;
  SDL_Surface* c1;
  SDL_Surface* c2;
  SDL_Surface* c3;
  
  SDL_Rect pos_back;
  SDL_Rect pos_quest;
  SDL_Rect pos_c1;
  SDL_Rect pos_c2;
  SDL_Rect pos_c3;
  FILE * f;
}enigme;


typedef struct {
  char quest [400];
  char c1[50];
 char c2[50];
 char c3[50];
 char x [50];
}enigmeData;

typedef struct{
  SDL_Surface* sprite;/*!<Rectangle*/
  SDL_Rect pos_sprite;/*!< Surface. */
  SDL_Rect pos_clock;/*!< Surface. */
}timer;

enigme initEnigme(enigmeData ed,timer *t);
void afficher_Enigme ( SDL_Surface *screen, enigme e);

void animation_clock(SDL_Surface* screen,timer *t);
int randomize();
enigmeData generateEnigme(enigme *e);
void liberer_enigme(enigme e);
int resolutionEnigme (enigmeData ed , SDL_Event event,int *done, int *continuer );
#endif
