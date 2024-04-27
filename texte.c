#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "texte.h"
void initText(Text *A,int x, int y, int r,int g, int b,char fn[],int t ){
A->position.x=x;
A->position.y=y;
A->textColor.r=r;
A->textColor.g=g;
A->textColor.b=b;
A->font = TTF_OpenFont(fn,t);}
void freeText(Text A){
SDL_FreeSurface(A.surfaceTexte);}
void displayText(Text t,SDL_Surface *screen,char msg[]){
t.surfaceTexte = TTF_RenderText_Solid(t.font,msg,t.textColor);
SDL_BlitSurface(t.surfaceTexte,NULL , screen , &t.position);}

