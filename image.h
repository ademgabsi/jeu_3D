#ifndef IMAGE_H_
#define IMAGE_H_
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#define SCREEN_W 1204
#define SCREEN_H 800
struct Image{
SDL_Rect pos1;
SDL_Rect pos2;
SDL_Surface *img;};
typedef struct Image Image;
void initPlayer(Image *A,char fn[]);
void initPlayer0(Image *A,char fn[],int x,int y);
void initPlayerx(Image *A,char fn[],int x,int y);
void initBackground(Image *Backg, char fn[]);
void liberer(Image A);
void afficher(Image p,SDL_Surface *screen);

#endif
