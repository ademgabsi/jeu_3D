#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "texte.h"
#include "image.h"
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
void foption(SDL_Surface *s,Image *Backm,Image *ng,Image *setting,Image *credit,Image *quit,Image *NG,Image *SETTING,Image *CREDIT,Image *QUIT,int *sound,Image *BACKG,int *e)
{Image backg,bar,best;
Text fullscreenmsg,returnmsg,volumemsg;
SDL_Event oe;
int option=0,tn;
char chaine[20],ts[20];
 if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS,1024)==-1){printf("%s",Mix_GetError());}
    initBackground(&backg,"backoption.png");
    initBackground(&bar,"fulloption(2).png");
    initBackground(&best,"letter.jpg");
    initText(&fullscreenmsg,130,100,0,0,0,"times new roman.ttf",50);
   
    initText(&returnmsg,130,520,0,0,0,"ArsenicaTrial-Bold.ttf",50);
    Uint8 volume1=0;
    Uint8 volume2=32;
    Uint8 volume3=128;
    FILE *f=fopen("meilleur.txt","r");
if(f==NULL) printf("erreur fichier");
else 
fgets(chaine,20,f);
fclose(f);
    while(option!=1)
    {afficher(backg,s);
  
    while( SDL_PollEvent(&oe))
         switch (oe.type)
        {case SDL_QUIT:option=1;break;
         case SDL_KEYDOWN:
         switch(oe.key.keysym.sym)
        {case SDLK_f:(*e)=1;s = SDL_SetVideoMode ( 1920, 1080,32, SDL_SWSURFACE|SDL_HWSURFACE |SDL_DOUBLEBUF | SDL_RESIZABLE) ;
                    initBackground(&(*Backm),"backgroundf.png");initPlayer(&(*credit),"logo1f.png");initPlayer(&(*ng),"playf.png");initPlayer(&(*setting),"settingf.png");
                    initPlayer(&(*quit),"quitf.png");initPlayer(&(*NG),"playsf.png");initPlayer(&(*SETTING),"settingsf.png");initPlayer(&(*QUIT),"quitsf.png");  
                   initBackground(&backg,"fulloption(2).png"); initBackground(&(*BACKG),"museum-madness(1).png");break;
         case SDLK_n:(*e)=0;s = SDL_SetVideoMode ( 1204,800,32, SDL_SWSURFACE|SDL_HWSURFACE |SDL_DOUBLEBUF | SDL_RESIZABLE) ;
                    initBackground(&(*Backm),"background.png");initPlayer(&(*credit),"logo1.png");initPlayer(&(*ng),"play.png");initPlayer(&(*setting),"setting.png");
                    initPlayer(&(*quit),"quit.png"); initPlayer(&(*NG),"plays.png");initPlayer(&(*SETTING),"settings.png");initPlayer(&(*QUIT),"quits.png");
                    initBackground(&backg,"fulloption(1).png");initBackground(&(*BACKG),"museum-madness.png");break;
         case SDLK_h:if((*sound)!=3)(*sound)++;if((*sound)==3) Mix_VolumeMusic(volume3);else if((*sound)==2) Mix_VolumeMusic(volume2);else if((*sound)==1) Mix_VolumeMusic(volume1);break;
         case SDLK_b:if((*sound)!=0)(*sound)--;if((*sound)==3) Mix_VolumeMusic(volume3);else if((*sound)==2) Mix_VolumeMusic(volume2);else if((*sound)==1) Mix_VolumeMusic(volume1);break; 
         case SDLK_m: afficher(best,s); displayText(fullscreenmsg,s,chaine);  displayText(returnmsg,s,"press 'r' to return to menu");SDL_Flip(s); SDL_Delay(5000); break;     
         case SDLK_r:option=1 ;break;}
      
         case SDL_MOUSEBUTTONUP:if((oe.motion.x>=417 && oe.motion.x<=784) && (oe.motion.y>=485 && oe.motion.y<=545)&&((*e)==0) ){option=1;break;}
         else if((oe.motion.x>=663 && oe.motion.x<=1259) && (oe.motion.y>=646 && oe.motion.y<=743)&&((*e)==1) ){option=1;break;}
         else  if((oe.motion.x>=839 && oe.motion.x<=882) && (oe.motion.y>=270 && oe.motion.y<=309) )
        { if((*sound)!=3)(*sound)++;if((*sound)==3) Mix_VolumeMusic(volume3);else if((*sound)==2) Mix_VolumeMusic(volume2);else if((*sound)==1) Mix_VolumeMusic(volume1);break;}
        else  if((oe.motion.x>=926 && oe.motion.x<=965) && (oe.motion.y>=273 && oe.motion.y<=312) )
        {if((*sound)!=0)(*sound)--;if((*sound)==3) Mix_VolumeMusic(volume3);else if((*sound)==2) Mix_VolumeMusic(volume2);else if((*sound)==1) Mix_VolumeMusic(volume1);break;}
        else  if((oe.motion.x>=842 && oe.motion.x<=881) && (oe.motion.y>=309 && oe.motion.y<=434) )
         {(*e)=1;s = SDL_SetVideoMode ( 1920, 1080,32, SDL_SWSURFACE|SDL_HWSURFACE |SDL_DOUBLEBUF | SDL_RESIZABLE) ;
                    initBackground(&(*Backm),"backgroundf.png");initPlayer(&(*credit),"logo1f.png");initPlayer(&(*ng),"playf.png");initPlayer(&(*setting),"settingf.png");
                    initPlayer(&(*quit),"quitf.png");initPlayer(&(*NG),"playsf.png");initPlayer(&(*SETTING),"settingsf.png");initPlayer(&(*QUIT),"quitsf.png");  
                   initBackground(&backg,"fulloption(2).png"); initBackground(&(*BACKG),"museum-madness(1).png");}
         else  if((oe.motion.x>=1481 && oe.motion.x<=1550) && (oe.motion.y>=534 && oe.motion.y<=585) )
         {(*e)=0;s = SDL_SetVideoMode ( 1204,800,32, SDL_SWSURFACE|SDL_HWSURFACE |SDL_DOUBLEBUF | SDL_RESIZABLE) ;
                    initBackground(&(*Backm),"background.png");initPlayer(&(*credit),"logo1.png");initPlayer(&(*ng),"play.png");initPlayer(&(*setting),"setting.png");
                    initPlayer(&(*quit),"quit.png"); initPlayer(&(*NG),"plays.png");initPlayer(&(*SETTING),"settings.png");initPlayer(&(*QUIT),"quits.png");
                    initBackground(&backg,"fulloption(1).png");initBackground(&(*BACKG),"museum-madness.png");  }   
         else if  ((oe.motion.x>=900 && oe.motion.x<=1117) && (oe.motion.y>=665 && oe.motion.y<=705) )
         {afficher(best,s); displayText(fullscreenmsg,s,chaine);  displayText(returnmsg,s,"press 'r' to return to menu");SDL_Flip(s); SDL_Delay(5000); break; }
           break;}SDL_Flip(s);}
    liberer(bar);
    liberer(backg);}
