#ifndef Texte_H
#define Texte_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

typedef struct{
SDL_Rect position;
TTF_Font *font;
SDL_Surface * surfaceTexte;
SDL_Color textColor;
}Text;
void initText(Text *A,int x, int y, int r,int g, int b,char fn[],int t );
void freeText(Text A);
void displayText(Text t,SDL_Surface *screen,char msg[]);

#endif
