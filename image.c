#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "image.h"
#define SCREEN_W 1204
#define SCREEN_H 800
void initPlayer(Image *A,char fn[])
{A->img = IMG_Load(fn);
if (A->img==NULL)return;
A->pos1.x=0;
A->pos1.y=0;                
A->pos1.w=A->img->w;
A->pos1.h=A->img->h;

A->pos2.x=0;
A->pos2.y=0;
A->pos2.w=A->img->w;
A->pos2.h=A->img->h;;
}
void initPlayer0(Image *A,char fn[],int x,int y)
{A->img = IMG_Load(fn);
if (A->img==NULL)return;
A->pos1.x=x;
A->pos1.y=y;                
A->pos1.w=A->img->w;
A->pos1.h=A->img->h;

A->pos2.x=0;
A->pos2.y=0;
A->pos2.w=A->img->w;
A->pos2.h=A->img->h;;
}
void initPlayerx(Image *A,char fn[],int x,int y)
{A->img = IMG_Load(fn);
switch (x){case 0:x=0;break;case 1:x=450;break;case 2: x=800;break;}
switch (y){case 0:y=0;break;case 1:y=266;break;case 2: y=532;break;}
if (A->img==NULL)return;
A->pos1.x=x;
A->pos1.y=y;                
A->pos1.w=A->img->w;
A->pos1.h=A->img->h;

A->pos2.x=0;
A->pos2.y=0;
A->pos2.w=A->img->w;
A->pos2.h=A->img->h;;
}
void initBackground(Image *Backg, char fn [])
{   Backg->img = IMG_Load(fn); 
if (Backg->img==NULL)
{printf("unable to load %s \n",SDL_GetError());return;}
Backg->pos1.x=0;
Backg->pos1.y=0;
Backg->pos2.x=0;
Backg->pos2.y=0;
Backg->pos2.w=(SCREEN_W);
Backg->pos2.h=(SCREEN_H);
} 
void liberer(Image A)  //changement !!!!
{ SDL_FreeSurface(A.img);}
void afficher(Image p,SDL_Surface *screen)
{SDL_BlitSurface(p.img,&p.pos2,screen,&p.pos1);}

