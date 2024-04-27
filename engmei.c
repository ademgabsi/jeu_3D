#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "enigme.h"
#include <time.h>

int enigmei(int *score)
{enigmeData edata;enigme e;int done=0,continuer=0,reponse_vrai=-1;timer t;int time=0;
 SDL_Surface*screen;SDL_Event event;SDL_Surface*win,*lose;SDL_Rect poswin;
screen=SDL_SetVideoMode(1204,800,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

e=initEnigme(edata,&t);

win=IMG_Load("sm/win.jpg");
lose=IMG_Load("sm/sorry.jpg");
poswin.x=0;
poswin.y=0;
poswin.w=1204;
poswin.h=800;
edata=generateEnigme(&e);
 
  while(!done && time<12)
  {
    
         reponse_vrai=resolutionEnigme(edata,event,&done,&continuer);
       

     
      

    afficher_Enigme(screen,e);
    animation_clock(screen,&t);
    
    SDL_Flip(screen);
    
   time++;
  }
   printf("%d",reponse_vrai);
   time=0;
   
    {
        if(reponse_vrai==1)
          {SDL_BlitSurface(win,NULL,screen,&poswin);}
        else
          {SDL_BlitSurface(lose,NULL,screen,&poswin);}
          time++;
           SDL_Flip(screen);
          SDL_Delay(5000);
          SDL_Flip(screen);
          
    }
liberer_enigme(e);
SDL_FreeSurface(t.sprite);




    return 0; 
}
