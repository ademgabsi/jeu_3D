#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "enigme.h"
#include <time.h>
#include <string.h>


enigme initEnigme(enigmeData ed,timer *t)
{
  enigme e;int i;
  e.f = fopen("enigme.txt", "r");
 e.back = IMG_Load("sm/background.jpg");

  
 t->pos_sprite.x=0; 
t->pos_sprite.y=0;
t->pos_sprite.w=(885/6);
t->pos_sprite.h=(313/2); 

t->pos_clock.x=990;
t->pos_clock.y=150;
t->pos_clock.w=155;
t->pos_clock.h=155;

t->sprite=IMG_Load("sm/clock.png");  
       


   e.pos_back.x=0;
   e.pos_back.y=0;
   e.pos_back.w=1200;
   e.pos_back.h=900;

   e.pos_quest.x=300;
   e.pos_quest.y=120;
   e.pos_quest.w=534;
   e.pos_quest.h=544;
  
   e.pos_c1.x=430;
   e.pos_c1.y=200;
   e.pos_c1.w=313;
   e.pos_c1.h=114;

   e.pos_c2.x=530;
   e.pos_c2.y=400;
   e.pos_c2.w=313;
   e.pos_c2.h=114;

   e.pos_c3.x=630;
   e.pos_c3.y=600;
   e.pos_c3.w=313;
   e.pos_c3.h=114;


 return e;
}


void afficher_Enigme (SDL_Surface *screen, enigme e){
  
  SDL_BlitSurface(e.back, NULL, screen, &e.pos_back);
  SDL_BlitSurface(e.quest, NULL, screen, &e.pos_quest);
  SDL_BlitSurface(e.c1, NULL, screen, &e.pos_c1);
  SDL_BlitSurface(e.c2, NULL, screen, &e.pos_c2);
  SDL_BlitSurface(e.c3, NULL, screen, &e.pos_c3);

}

int randomize(){
int pos;
srand(time(NULL));
pos=rand()%(4-0+1)+0;
return pos;
}


enigmeData generateEnigme(enigme *e)
{
  enigmeData ed[5];
  enigmeData edata;
  int i;
  
  int pos = randomize();printf(" %d",pos);
  for (i = 0; i < 5; i++)
  {
    fscanf(e->f,"%s\n",ed[i].quest);
    fscanf(e->f,"1)%s 2)%s 3)%s -%s\n",ed[i].c1, ed[i].c2, ed[i].c3, ed[i].x);
  }
   strcpy(edata.quest,ed[pos].quest);
  strcpy (edata.c1 ,ed[pos].c1);
      strcpy(edata.c2 ,ed[pos].c2);
        strcpy(edata.c3 ,ed[pos].c3);
          strcpy(edata.x ,ed[pos].x);
  e->quest=IMG_Load(edata.quest);
       e->c1=IMG_Load(edata.c1);
       e->c2=IMG_Load(edata.c2);
       e->c3=IMG_Load(edata.c3);        
  return edata;
}


void liberer_enigme(enigme e)
{
SDL_FreeSurface(e.back);
SDL_FreeSurface(e.quest);
SDL_FreeSurface(e.c1);
SDL_FreeSurface(e.c2);
SDL_FreeSurface(e.c3);
}

void animation_clock(SDL_Surface* screen,timer *t)
{
SDL_BlitSurface(t->sprite,&t->pos_sprite,screen,&t->pos_clock);SDL_Delay(300);

if(t->pos_sprite.x==775)
  {t->pos_sprite.x=0;
   if(t->pos_sprite.y==0)    
     {t->pos_sprite.y=173;}
     else t->pos_sprite.y=0;
  }
 
 else
   t->pos_sprite.x+=155;  

}


int resolutionEnigme (enigmeData ed , SDL_Event event,int *done, int *continuer ){
int resultat=0;
while (SDL_PollEvent(&event)){

switch(event.type)
{
case SDL_QUIT: 
 *done=1;
*continuer=1;
 break;
case SDL_KEYDOWN:
 switch ( event.key.keysym.sym)
{

case SDLK_ESCAPE:
*done=1;
*continuer=1;
break;

case SDLK_a:
if(strcmp (ed.c1, ed.x) == 0){


resultat=1;
}
else resultat=2;
*done=1;
break;

case SDLK_b:

resultat=1;


*done=1;
break;

case SDLK_c:
 if(strcmp (ed.c3, ed.x) == 0){

    resultat=1;

  }
 else resultat=2;
*done=1;
 break;
 
return resultat;
}  
case SDL_MOUSEBUTTONDOWN:
	            if (event.motion.x >=90  && event.motion.x <=500 && event.motion.y >= 313 && event.motion.y <=114)
	            {
	                if (strcmp (ed.c1, ed.x) == 0)
	                {
	                    resultat=1;
	                    
	      
	                }
	                else {
	                    resultat=2;
			 
	                }
			  *done=1; 
	            }
if (event.motion.x >= 70 && event.motion.x <= 305 && event.motion.y >= 335 && event.motion.y <= 395)
	            {
	                if (strcmp (ed.c2, ed.x) == 0)
	                {
	                    resultat=1;
	                    
	      		
	                }
	                else {
	                    resultat=2;
			   
	                }
			*done=1; 
	            }
if (event.motion.x >= 70 && event.motion.x <= 305 && event.motion.y >= 415 && event.motion.y <= 460)
	            {
	                if (strcmp (ed.c3, ed.x) == 0)
	                {
	                    resultat=1;
	                    
	      		 
	                }
	                else {
	                    resultat=2;
			   
	                }
			 *done=1;
	            }

	            break;
}  
}  

return resultat;
}


