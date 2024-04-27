
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "texte.h"
#include "image.h"
#include "option.h"
#include "jouer.h"
int main(int argc,char* argv[])
{
    TTF_Init();

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){printf("erreur:%s",SDL_GetError());return 1;}
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS,1024)==-1){printf("%s",Mix_GetError());}

    int done=0,i=0,e=0,amara=-1,sound=3;
    SDL_Surface *screen=NULL,*ss=NULL;
    Image Backg,ng,setting,credit,quit,NG,SETTING,CREDIT,QUIT,BACKG;
    Text t,grpn;
    SDL_Event event;
    Mix_Music *music=NULL;
    Mix_Chunk * son=NULL,*is=NULL;

    SDL_WM_SetCaption("the game", NULL);

    screen = SDL_SetVideoMode ( 1204,800,32, SDL_SWSURFACE|SDL_HWSURFACE |SDL_DOUBLEBUF /*| SDL_RESIZABLE*/) ;
   
    initText(&t,400,450,255,255,255,"times new roman.ttf",50);
    initText(&grpn,100,700,255,255,255,"ArsenicaTrial-Bold.ttf",50);
    initBackground(&Backg,"aaa.png");
    initPlayer(&credit,"341741972_934024451133512_1966059168580262053_n.png");

    initPlayer(&ng,"play.png");
    initPlayer(&setting,"setting.png");
    initPlayer(&quit,"quit.png");
    initPlayer(&NG,"plays.png");
    initPlayer(&SETTING,"settings.png");
    initPlayer(&QUIT,"quits.png");
    music=Mix_LoadMUS("5dmti.mp3");
    son= Mix_LoadWAV( "maybe-next-time-huh.wav" );
    is=Mix_LoadWAV( "HMNHart_Heartbeat 2 (ID 0244)_BSB.wav");
    Uint8 volume1=0;
    Uint8 volume2=32;
    Uint8 volume3=128;
    displayText(t,screen,"the Freedom fighters presents ...");
    afficher(credit,screen);
    SDL_Flip(screen);
    SDL_Delay(3000); 
    Mix_PlayMusic(music,-1);
    
    while(done!=1)
    {afficher(Backg,screen);
    afficher(credit,screen);
        if(i==1) afficher(NG,screen);else  afficher(ng,screen);
        if(i==2) afficher(SETTING,screen);else afficher(setting,screen);
        if(i==3) afficher(QUIT,screen);else afficher(quit,screen);
        displayText(grpn,screen,"\nThe Freedom fighters\n");
        while( SDL_PollEvent(&event))
            switch (event.type)
            {case SDL_QUIT:done=1;break;
             case SDL_MOUSEBUTTONUP:
             switch(e){
             case 0:  if((event.motion.x>=460 && event.motion.x<=757) && (event.motion.y>=410 && event.motion.y<=470) )
               
                jouer(music);
                else  if((event.motion.x>=460 && event.motion.x<=749) && (event.motion.y>=499 && event.motion.y<=558) )
                foption(screen,&Backg,&ng,&setting,&credit,&quit, &NG,&SETTING,&CREDIT,&QUIT,&sound,&BACKG,&e);
                else  if((event.motion.x>=460 && event.motion.x<=757) && (event.motion.y>=586 && event.motion.y<=644) ){done=1;break;}
             case 1: if((event.motion.x>=730 && event.motion.x<=1205) && (event.motion.y>=551 && event.motion.y<=632) )
               
               jouer(music);
                else  if((event.motion.x>=730 && event.motion.x<=1205) && (event.motion.y>=674 && event.motion.y<=750) )
                foption(screen,&Backg,&ng,&setting,&credit,&quit, &NG,&SETTING,&CREDIT,&QUIT,&sound,&BACKG,&e);
                else  if((event.motion.x>=730 && event.motion.x<=1205) && (event.motion.y>=790 && event.motion.y<=868) ){done=1;break;}}
            case SDL_MOUSEMOTION:
            switch(e){
            case 0: if((event.motion.x>=460 && event.motion.x<=757) &&  (event.motion.y>=410 && event.motion.y<=470) ){i=1;afficher(NG,screen);Mix_PlayChannel(-1,is,0);}
                else if((event.motion.x>=460 && event.motion.x<=749) && (event.motion.y>=499 && event.motion.y<=558) ){i=2;afficher(SETTING,screen);Mix_PlayChannel(-1,is,0);}
                else if((event.motion.x>=460 && event.motion.x<=757) && (event.motion.y>=586 && event.motion.y<=644) ){i=3;afficher(QUIT,screen);Mix_PlayChannel(-1,is,0);}
                else  i=0;break;
            case 1: if((event.motion.x>=730 && event.motion.x<=1205) &&  (event.motion.y>=551 && event.motion.y<=632) ){i=1;afficher(NG,screen);Mix_PlayChannel(-1,is,0);}
                else if((event.motion.x>=730 && event.motion.x<=1205) && (event.motion.y>=674 && event.motion.y<=750) ){i=2;afficher(SETTING,screen);Mix_PlayChannel(-1,is,0);}
                else if((event.motion.x>=730 && event.motion.x<=1205) && (event.motion.y>=790 && event.motion.y<=868) ){i=3;afficher(QUIT,screen);Mix_PlayChannel(-1,is,0);}
                else  i=0;break;}
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
               {case SDLK_p:
               jouer(music);
               break;
                case SDLK_s:foption(screen,&Backg,&ng,&setting,&credit,&quit, &NG,&SETTING,&CREDIT,&QUIT,&sound,&BACKG,&e);
                case SDLK_h:if(sound!=3)sound++;if(sound==3)Mix_VolumeMusic(volume3);else if(sound==2)Mix_VolumeMusic(volume2);else if(sound==1)Mix_VolumeMusic(volume1);break;
                case SDLK_b:if(sound!=0)sound--;if(sound==3)Mix_VolumeMusic(volume3);else if(sound==2)Mix_VolumeMusic(volume2);else if(sound==1)Mix_VolumeMusic(volume1);break;     
                case SDLK_f:e=1;screen = SDL_SetVideoMode ( 1920, 1080,32, SDL_SWSURFACE|SDL_HWSURFACE |SDL_DOUBLEBUF | SDL_RESIZABLE) ;
                 initBackground(&Backg,"backgroundf.png");initPlayer(&credit,"logo1f.png");initPlayer(&ng,"playf.png");initPlayer(&setting,"settingf.png");
                 initPlayer(&quit,"quitf.png");initPlayer(&NG,"playsf.png");initPlayer(&SETTING,"settingsf.png");initPlayer(&QUIT,"quitsf.png");
                 initBackground(&BACKG,"museum-madness(1).png");break;
                case SDLK_n:e=0;screen = SDL_SetVideoMode ( 1204,800,32, SDL_SWSURFACE|SDL_HWSURFACE |SDL_DOUBLEBUF | SDL_RESIZABLE) ;
                 initBackground(&Backg,"background.png");initPlayer(&credit,"logo1.png");initPlayer(&ng,"play.png");initPlayer(&setting,"setting.png");
                 initPlayer(&quit,"quit.png"); initPlayer(&NG,"plays.png");initPlayer(&SETTING,"settings.png");initPlayer(&QUIT,"quits.png");
                 initBackground(&BACKG,"museum-madness.png");break;
                case SDLK_UP:i--; if(i<=0) {afficher(QUIT,screen); i=3;amara=0;}
                                  else if(i==2){afficher(SETTING,screen);amara=2;}
                                  else if(i==1){afficher(NG,screen);amara=1;}break;
                case SDLK_DOWN:i++;if(i==1){afficher(NG,screen);amara=1;}
                                   else if (i==2){afficher(SETTING,screen);amara=2;}
                                   else if (i==3){afficher(QUIT,screen);amara=0;}
                                   else if(i>3) i=0;break;
                case SDLK_RETURN: if(amara==1)
                jouer(music);
                                  else if(amara==2) foption(screen,&Backg,&ng,&setting,&credit,&quit, &NG,&SETTING,&CREDIT,&QUIT,&sound,&BACKG,&e);
                                  else if (amara==0) done=1;break;
                case SDLK_q:done=1;break;}break;}SDL_Flip(screen);}
   
    liberer(BACKG);
    liberer(NG);
    liberer(SETTING);
    liberer(CREDIT);
    liberer(QUIT);
    liberer(ng);
    liberer(setting);
    liberer(credit);
    liberer(quit);
    liberer(Backg);
    SDL_FreeSurface(screen);
    TTF_Quit();
    Mix_FreeChunk(son);
    Mix_FreeMusic(music);
    SDL_Quit();
}



