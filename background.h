#ifndef BACKGROUND_H_
#define BACKGROUND_H_
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#define CAMERA_W 100
#define CAMERA_H 200

struct background
{
SDL_Rect b3;
 SDL_Rect b2; 
 SDL_Rect bckg;  
 SDL_Surface *img;  
}; 

typedef struct background background; 

void initBckg (background * b, char url[]); 
void showBckg1 (SDL_Surface * screen, background b); 
void showBckg2 (SDL_Surface * screen, background b);
void scrollToLeft (background * b); 
void scrollToRight (background * b); 

void scrollToUp (background * b);
void scrollToDown (background * b);
#endif
