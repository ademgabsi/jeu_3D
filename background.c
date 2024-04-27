#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "background.h"

void initBckg (background * b, char url[]){  b->img = IMG_Load (url); 
 b->bckg.x = 0; 
 b->bckg.y = 0; 
 b->bckg.w = b->img->w; 
 b->bckg.h = b->img->h; 
 printf("%d",b->bckg.w);
 
 b->b2.x = 0; 
 b->b2.y = 0; 
 b->b2.w = b->img->w; 
 b->b2.h = b->img->h; 
 
 b->b3.x = 350; 
 b->b3.y = 0; 
 b->b3.w = b->img->w; 
 b->b3.h = b->img->h; 
 
} 
void showBckg1 (SDL_Surface * screen, background b){  
SDL_BlitSurface (b.img,&(b.bckg) , screen, &(b.b2)); } 
void showBckg2 (SDL_Surface * screen, background b){  
SDL_BlitSurface (b.img, &(b.bckg), screen, &(b.b3)); } 

void scrollToLeft (background * b){ 
 if (b->bckg.x != 0)
 b->bckg.x-=20; 
} 
void scrollToRight (background * b){ 
 if (b->bckg.x <2400) 
 b->bckg.x+=20; 
}
void scrollToUp (background * b){ 
 if (b->bckg.h + b->bckg.y != b->bckg.h) 
 b->bckg.y-=20;
}
void scrollToDown (background * b){ 
  if (b->bckg.y<2400) 
 b->bckg.y+=20; 
}

