#ifndef perso__h
#define perso__h

#include <SDL/SDL_image.h>
#include<SDL/SDL.h>
#include<SDL/SDL_ttf.h>

typedef struct
{
    SDL_Surface *img,*sprite;
    SDL_Rect posMap;
}Perso;

SDL_Surface *LOAD_IMG(char fileName[20]);
void Init_Map(Perso *map);
void Draw_MiniMap(Perso map, SDL_Surface *Screen);
int collisionBB(SDL_Rect *perso,SDL_Rect bloc);
void gravity(SDL_Rect *perso, SDL_Rect bloc, int direction);
void animperso (int *i,Perso *p);
void animpersoleft(int *i ,Perso *p);
void animpersojump(int *i,Perso *p);

#endif
