#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"
#include "minimap.h"
#include "enemie.h"
#include "background.h"
#include "engmetxt.h"
#include "jouer.h"
#include <stdio.h>
#include <stdlib.h>
#include "texte.h"
#include "image.h"
#include "engmei.h"
int arduinoWriteData(int x);
int arduinoReadData(int *x);
int checkCollidsionBoundingBox(SDL_Rect a, SDL_Rect b);
void jouer(Mix_Music *music)
{
int directionSDL=0; 
int directionArduino=0; 
char received;
int collisionRightSide = 0;
int collisionLeftSide = 0;
system("stty -F /dev/ttyUSB0 9600 -parenb cs8 -cstopb");
if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS,1024)==-1){printf("%s",Mix_GetError());}
TTF_Init();
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *screen=NULL , *mask=NULL; 
Mix_Chunk * l=NULL,*w=NULL,*tie=NULL;
char nomjoueur[20];
int continuer=1,score=0,as=0,i=0,paa=0,direction=0;
strcpy(nomjoueur,"");
screen=SDL_SetVideoMode (1200,800,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

temps t;
minimap m;
Ennemi E ;
Perso p;
background b;
SDL_Rect posperso,camera,ground,posMarioRel;
SDL_Event event;
l= Mix_LoadWAV( "VOXLaff_Rire horrible 13 (ID 2103)_LS.wav" );
w= Mix_LoadWAV( "gbi2b-4wpw3(1).wav" );
tie= Mix_LoadWAV( "maybe-next-time-huh.wav" );
enregistrer(screen, nomjoueur);
xo(&score,screen);
Mix_FreeMusic(music);as==score;
if(as==score) Mix_PlayChannel( -1, tie, 0 );else if(as<score) Mix_PlayChannel( -1, w, 0 ); else Mix_PlayChannel( -1, l, 0 );
initBckg (&b, "bggs.png");
showBckg1 (screen, b); 
SDL_Flip (screen);
initEnnemi(&E);
initialiser_temps(&t);
initminimap(&m,"bgp1.png","si.png","index(1).png"); 
posperso.x=0;
posperso.y=400;
p.sprite = IMG_Load("Marche 1.png");
    ground.x=0;
    ground.y=685;
    ground.w=45;
    ground.h=0;
    posMarioRel.x = -50;
    posMarioRel.y = 0;
camera.x=0;
camera.y=0;
camera.w=1204;
camera.h=800;
SDL_EnableKeyRepeat(100,10);////
while(continuer)
{    gravity(&posperso,ground,directionSDL);
while(SDL_PollEvent(&event)){
		switch(event.type){
		case SDL_QUIT:	continuer=0;break;
		
		case SDL_KEYDOWN:switch (event.key.keysym.sym){
                case SDLK_LEFT:directionSDL=2;posperso.x-=5;animpersoleft(&i,&p);E.pos.x+=20;paa-20;scrollToLeft(&b);arduinoWriteData(2);break;
                case SDLK_RIGHT:directionSDL = 1;posperso.x+=5;animperso(&i,&p);E.pos.x-=20;paa+=20;scrollToRight(&b);printf("%d / %d \n",posperso.x,posperso.y);arduinoWriteData(1);break;
                case SDLK_UP:directionSDL=0;if((posperso.x<915)&&(posperso.x>900)&&((posperso.y==600 )||(posperso.y<=640))){posperso.y-=5;scrollToUp (&b);}
                            else{if((posperso.x==40) && (posperso.y==600) ) {ground.x=200;ground.y=715;ground.w=85;ground.h=0;}
                                 else if((posperso.x>=245) && (posperso.x<=265) &&(posperso.y==620)) {ground.x=270; ground.y=575;ground.w=500;}
                                 else if(posperso.x>=125 && posperso.x<=135 && posperso.y==600 && directionSDL==2) {ground.x=140;ground.y=373;ground.w=200;}
                                 posperso.x = posperso.x+170;posperso.y = posperso.y-300;animpersojump(&i,&p);}
                            
                           
			
			  SDL_Delay(10);SDL_Flip(screen);arduinoWriteData(0);break;  
                case SDLK_DOWN:directionSDL=0;
                {posperso.y+=1;scrollToDown (&b);arduinoWriteData(0);}break;  
            }break;        } } 
           
            
            arduinoWriteData(directionSDL);  
switch(received){
case 0: directionArduino=0 ;
break;
case 1:directionArduino=1 ;
break;
case 2:directionArduino=2; 
break;
} 
as=score;
if (paa==100) {paa++; enigmes(&score);if(as==score) Mix_PlayChannel( -1, tie, 0 );else if(as<score) Mix_PlayChannel( -1, w, 0 ); else Mix_PlayChannel( -1, l, 0 );} 
if((posperso.x==615) && (posperso.y==480) ){ground.x=600;ground.y=685;ground.w=1000;} as=score;  
if (paa==1341){enigmei(&score);paa++; if(as==score) Mix_PlayChannel( -1, tie, 0 );else if(as<score) Mix_PlayChannel( -1, w, 0 ); else Mix_PlayChannel( -1, l, 0 );} 
MAJMinimap(posperso,&m,camera,63);
showBckg1 (screen, b); 
afficherminimap(m,screen);

SDL_BlitSurface(p.sprite,NULL,screen,&posperso);
 deplacer(&E,paa);
    animerEnnemi(&E);
    deplacerIA(&E,posperso);
    afficherEnnemi(E,screen);
    
afficher_temps(&t,screen);
SDL_Flip(screen);
SDL_Delay(50);
}sauvegarder(  score,  nomjoueur, "saves.txt");
meilleur( "meilleur.txt", &score,  nomjoueur);
music=Mix_LoadMUS("5dmti.mp3");Mix_PlayMusic(music,-1);
Mix_FreeChunk(w);Mix_FreeChunk(l);Mix_FreeChunk(tie);
}
int arduinoWriteData(int x)
{
    char chemin[]="/dev/ttyUSB0";
    FILE*f;

    f=fopen(chemin,"w");
    if(f == NULL)
        return(-1);

    fprintf(f,"%d",x);
    fclose(f);

    return(0);
}

int arduinoReadData(int *x)
{
    char chemin[]="/dev/ttyUSB0";
    FILE*f;
    char c;
    f=fopen(chemin,"r");

    if(f == NULL)
        return(-1);

    fscanf(f,"%d",x);

    fclose(f);

    return(0);
}
