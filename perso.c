#include "perso.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include<SDL/SDL_ttf.h>
#include<stdio.h>
#include<stdlib.h>


int collisionBB(SDL_Rect *perso,SDL_Rect bloc)
{
    if(perso->x + perso->w > bloc.x && perso->x < bloc.x + bloc.w && perso->y + perso->h > bloc.y && perso->y < bloc.y + bloc.h)
    {
      
        return 1;
    }

    else
    {
      
        return 0;
    }
}

void gravity(SDL_Rect *perso, SDL_Rect bloc, int direction)
{
    if(collisionBB(perso,bloc)!=1)
    {
      
        perso->y=perso->y+40;
    }
}


void animperso (int *i ,Perso *p)
{
 char ch[20];
   (*i)++;
   if(*i>7)*i=1;
   sprintf(ch,"Marche %d.png",*i);
   p->sprite = IMG_Load(ch);                
}
void animpersoleft (int *i ,Perso *p)
{
 char ch[20];
   
   (*i)++;
   if(*i>7)*i=1;
   sprintf(ch,"MarcheL %d.png",*i);
   p->sprite = IMG_Load(ch);
               
}
                

void animpersojump(int *i ,Perso *p)
{char ch[20];
 (* i)++; if(*i==9) *i=1;
   sprintf(ch,"Jump %d.png",*i);
   p->sprite = IMG_Load(ch);
   
}



