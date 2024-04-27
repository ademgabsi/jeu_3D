
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "minimap.h"
#include "image.h"
#include "texte.h"
#include "background.h"
#include <time.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>

void initminimap( minimap * m,char fn [],char fp[],char fe[]){

initBckg (&m->mb,fn);
initPlayer0(&m->mp,fp,100,50);
initPlayer0(&m->me,fe,300,60);}

void MAJMinimap(SDL_Rect posJoueur , minimap * m, SDL_Rect camera, int redimensionnement){
SDL_Rect pos_joueurABS,pos_e;
  pos_joueurABS.x = 0;
  pos_joueurABS.y = 0;
  pos_joueurABS.x = (posJoueur.x + camera.x);
  pos_joueurABS.y = (posJoueur.y + camera.y );
  m->mp.pos1.x=(pos_joueurABS.x * redimensionnement/100)+1;
  if (posJoueur.x<430)
  {m->mp.pos1.y=(pos_joueurABS.y * redimensionnement/100)-300;}
  else
  {m->mp.pos1.y=(pos_joueurABS.y* redimensionnement/100)-250;}
  }


void afficherminimap (minimap m, SDL_Surface * screen){

showBckg1 ( screen,m.mb);
afficher(m.mp,screen);
afficher(m.me,screen);}


void initialiser_temps(temps *t){
 t->texte = NULL; 
 t->position.x=1050;
   t->position.y=10;
     t->police = NULL;
  t->police = TTF_OpenFont("times new roman.ttf", 50);
    strcpy( t->entree,"");
(t->secondesEcoulees)=0;
time(&(t->t1));} 


void afficher_temps( temps *t ,SDL_Surface *screen){
   SDL_Color couleurBlanche= {125, 125, 125};
    	time(&(t->t2));
		t->secondesEcoulees = t->t2 - t->t1;
        t->min=((t->secondesEcoulees/60)%60);
	t->sec= ((t->secondesEcoulees)%60);
	 sprintf(t->entree,"%02d:%02d",t->min,t->sec);
        t->texte = TTF_RenderText_Solid(t->police, t->entree, couleurBlanche);
SDL_BlitSurface(t->texte, NULL, screen, &(t->position)); 
}

void free_temps(temps *t,SDL_Surface *ecran)
{SDL_FreeSurface(t->texte);
 TTF_CloseFont(t->police);}
SDL_Color GetPixel(SDL_Surface *pSurface ,int x,int y){
    SDL_Color color;
    Uint32 col=0;
    char *pPosition = (char *) pSurface -> pixels;
    pPosition+=(pSurface->pitch *y);
    pPosition+=(pSurface ->format->BytesPerPixel *x);
    memcpy (&col,pPosition,pSurface ->format ->BytesPerPixel);
SDL_GetRGB(col,pSurface -> format,&color.r ,&color.g ,&color.b);
return (color);}


int collision_pright(SDL_Surface *mask , SDL_Rect pos_joueur )
{  SDL_Color col,colp;
SDL_Rect pos[8];
int collision = 0;
int i,w,h;
col.r=0;
col.g=0;
col.b=0;
w=44;
h=70;

pos[5].x = pos_joueur.x +w;
pos[5].y = pos_joueur.y;

pos[6].x = pos_joueur.x +w;
pos[6].y = pos_joueur.y+ h/2;

pos[7].x = pos_joueur.x +w;
pos[7].y = pos_joueur.y +h;
for (i =5;(i < 8)&&(collision == 0); i++)
{
    colp = GetPixel(mask,pos[i].x ,pos[i].y);
    if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b))
    collision = 1;
}return (collision);}


int collision_pleft(SDL_Surface *mask, SDL_Rect pos_joueur)
{SDL_Color col,colp;
SDL_Rect pos[8];
int collision = 0;
int i,w,h;
col.r=0;
col.g=0;
col.b=0;

w=44;
h=70;

pos[0].x = pos_joueur.x;
pos[0].y = pos_joueur.y;

pos[1].x = pos_joueur.x;
pos[1].y = pos_joueur.y + h /2;

pos[2].x = pos_joueur.x;
pos[2].y = pos_joueur.y + h;

for (i =0;(i < 3)&&(collision == 0); i++)
{
col = GetPixel(mask,pos[i].x ,pos[i].y);
if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b))
collision = 1;
}return (collision);}


int collision_pup(SDL_Surface *mask, SDL_Rect pos_joueur)
{
SDL_Color col,colp;
SDL_Rect pos;
int collision = 0;
int i,w,h;
col.r=0;
col.g=0;
col.b=0;

w=44;
h=70;

pos.x = pos_joueur.x + w/2;
pos.y = pos_joueur.y;

col = GetPixel(mask,pos.x ,pos.y);
if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b))   collision = 1;
return (collision);}


int collision_pdown(SDL_Surface *mask, SDL_Rect pos_joueur){
SDL_Color col,colp;
SDL_Rect pos;
int collision = 0;
int i,w,h;
col.r=0;
col.g=0;
col.b=0;

w=44;
h=70;

pos.x = pos_joueur.x+ w /2;
pos.y = pos_joueur.y +h;

col = GetPixel(mask,pos.x ,pos.y);
if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b)) collision = 1;
return (collision);}


void enregistrer(SDL_Surface *s,char nomjoueur[]){
SDL_Event oe;
Text nom;
int confirmer=0,i=0;
char c[20];
strcpy(c,"");
Image Backg;
initPlayer(&Backg,"playername.png");
afficher(Backg,s);
SDL_Flip(s);
 initText(&nom,280,315,0,0,0,"times new roman.ttf",50);
 while(confirmer!=1){
 while( SDL_PollEvent(&oe))
         switch (oe.type)
        { case SDL_QUIT:	confirmer=1;break;
        
         case SDL_KEYDOWN: switch(oe.key.keysym.sym){
         case SDLK_RETURN: confirmer=1;break;
          case SDLK_a :strcat(nomjoueur ,"a");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_z :strcat(nomjoueur ,"z");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_e :strcat(nomjoueur ,"e");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_r :strcat(nomjoueur ,"r");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_t :strcat(nomjoueur ,"t");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_y :strcat(nomjoueur ,"y");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_u :strcat(nomjoueur ,"u");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_i :strcat(nomjoueur ,"i");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_o :strcat(nomjoueur ,"o");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_p :strcat(nomjoueur ,"p");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_q :strcat(nomjoueur ,"q");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_s :strcat(nomjoueur ,"s");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_d :strcat(nomjoueur ,"d");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_f :strcat(nomjoueur ,"f");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_g :strcat(nomjoueur ,"g");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_h :strcat(nomjoueur ,"h");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_j :strcat(nomjoueur ,"j");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_k :strcat(nomjoueur ,"k");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_l :strcat(nomjoueur ,"l");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_m :strcat(nomjoueur ,"m");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_w :strcat(nomjoueur ,"w");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_x :strcat(nomjoueur ,"x");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_c :strcat(nomjoueur ,"c");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_v :strcat(nomjoueur ,"v");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_b :strcat(nomjoueur ,"b");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_n :strcat(nomjoueur ,"n");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_0 :strcat(nomjoueur ,"0");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_1 :strcat(nomjoueur ,"1");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_2 :strcat(nomjoueur ,"2");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_3 :strcat(nomjoueur ,"3");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_4 :strcat(nomjoueur ,"4");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_5 :strcat(nomjoueur ,"5");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_6 :strcat(nomjoueur ,"6");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_7 :strcat(nomjoueur ,"7");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_8 :strcat(nomjoueur ,"8");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_9 :strcat(nomjoueur ,"9");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_BACKSPACE:strcat(nomjoueur ,"_ _");displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          case SDLK_DELETE:strcpy(nomjoueur,"");afficher(Backg,s);displayText(nom,s,nomjoueur);SDL_Flip(s);continue;
          } break;
          }
          }
 freeText(nom);
 liberer(Backg);
 SDL_Flip(s);
}

void sauvegarder( int score, char nomjoueur[], char nomfichier[]){
FILE *f=fopen(nomfichier,"a");
if(f==NULL) printf("erreur fichier");
else{fprintf(f,"%d %s \n",score,nomjoueur);}
fclose(f);
}

void meilleur( char nomfichier[], int *score, char nomjoueur[]){
int ts;
char tn[20];
FILE *f=fopen(nomfichier,"r");
if(f==NULL) printf("erreur fichier");
else   {fscanf(f,"%d %s",&ts,tn); fclose(f);}
if(ts<=*score){ f=fopen(nomfichier,"w");
fprintf(f,"%d %s \n",*score,nomjoueur);
fclose(f);}}


void liberermini(minimap *m){SDL_FreeSurface(m->mb.img);liberer(m->mp);liberer(m->me);}


void xo(int *score,SDL_Surface *s){
SDL_Event event;
Mix_Chunk * son=NULL;
int i,j,win=0,lose=0,tie=0,m[3][3]={{0,0,0},{0,0,0},{0,0,0}};
Image Backg,o,x;
initBackground(&Backg,"R.34f7355be1e177b20cdf90fccab71f.jpg");
afficher(Backg,s);
SDL_Flip(s);
srand(time(NULL));
while(win!=1&&lose!=1&&tie!=1){
 while( SDL_PollEvent(&event))
         switch (event.type)
        { case SDL_QUIT:*score-=10;Mix_PlayChannel( -1, son, 0 );	lose=1;break;
        
          case SDL_MOUSEBUTTONUP:
         
/**/if((event.motion.x>=0 && event.motion.x<=400) && (event.motion.y>=0 && event.motion.y<=266)&&(m[0][0]==0))
       {initPlayerx(&x,"ox(1).jpg", 0, 0);afficher(x,s);SDL_Flip(s);m[0][0]=1;
        if ((m[1][0]==1&&m[2][0]==1) || (m[1][1]==1&&m[2][2]==1) || (m[0][1]==1&&m[0][2]==1)) {*score+=10; win=1;break;}
        else {i=rand() % (3);j=rand() % (3);while(m[i][j]!=0) {i=rand() % (3);j=rand() % (3);}
        SDL_Delay(1500);initPlayerx(&x,"ox.jpg", j, i);afficher(x,s);SDL_Flip(s);m[i][j]=2;
if((m[0][0]==2&&m[1][0]==2&&m[2][0]==2)||(m[1][1]==2&&m[2][2]==2&&m[0][0]==2)||(m[0][1]==2&&m[0][2]==2&&m[0][0]==2)||(m[1][1]==2&&m[2][0]==2&&m[0][2]==2)||(m[1][2]==2&&m[0][2]==2&&m[2][2]==2)||(m[1][1]==2&&m[1][0]==2&&m[1][2]==2)||(m[2][0]==2&&m[2][1]==2&&m[2][2]==2)||(m[1][1]==2&&m[0][1]==2&&m[2][1]==2))  {*score-=10; lose=1;break;}} }
/**/else if((event.motion.x>=0 && event.motion.x<=400) && (event.motion.y>=266 && event.motion.y<=532)&&(m[1][0]==0))
       {initPlayerx(&x,"ox(1).jpg", 0, 1);afficher(x,s);SDL_Flip(s);m[1][0]=1;
        if ((m[0][0]==1&&m[2][0]==1) || (m[1][1]==1&&m[1][2]==1) ) {*score+=10; win=1;break;}
        else {i=rand() % (3);j=rand() % (3);while(m[i][j]!=0) {i=rand() % (3);j=rand() % (3);}
        SDL_Delay(1500);initPlayerx(&x,"ox.jpg", j, i);afficher(x,s);SDL_Flip(s);m[i][j]=2;
if((m[0][0]==2&&m[1][0]==2&&m[2][0]==2)||(m[1][1]==2&&m[2][2]==2&&m[0][0]==2)||(m[0][1]==2&&m[0][2]==2&&m[0][0]==2)||(m[1][1]==2&&m[2][0]==2&&m[0][2]==2)||(m[1][2]==2&&m[0][2]==2&&m[2][2]==2)||(m[1][1]==2&&m[1][0]==2&&m[1][2]==2)||(m[2][0]==2&&m[2][1]==2&&m[2][2]==2)||(m[1][1]==2&&m[0][1]==2&&m[2][1]==2))  {*score-=10; lose=1;break;}} }
/**/else if((event.motion.x>=0 && event.motion.x<=400) && (event.motion.y>=532 && event.motion.y<=798)&&(m[2][0]==0))
       {initPlayerx(&x,"ox(1).jpg", 0, 2);afficher(x,s);SDL_Flip(s);m[2][0]=1;
        if ((m[1][0]==1&&m[0][0]==1) || (m[1][1]==1&&m[0][2]==1) || (m[2][1]==1&&m[2][2]==1)) {*score+=10; win=1;break;}
        else {i=rand() % (3);j=rand() % (3);while(m[i][j]!=0) {i=rand() % (3);j=rand() % (3);}
        SDL_Delay(1500);initPlayerx(&x,"ox.jpg", j, i);afficher(x,s);SDL_Flip(s);m[i][j]=2;
if((m[0][0]==2&&m[1][0]==2&&m[2][0]==2)||(m[1][1]==2&&m[2][2]==2&&m[0][0]==2)||(m[0][1]==2&&m[0][2]==2&&m[0][0]==2)||(m[1][1]==2&&m[2][0]==2&&m[0][2]==2)||(m[1][2]==2&&m[0][2]==2&&m[2][2]==2)||(m[1][1]==2&&m[1][0]==2&&m[1][2]==2)||(m[2][0]==2&&m[2][1]==2&&m[2][2]==2)||(m[1][1]==2&&m[0][1]==2&&m[2][1]==2))  {*score-=10; lose=1;break;}} }
/**/else if((event.motion.x>=400 && event.motion.x<=800) && (event.motion.y>=0 && event.motion.y<=266)&&(m[0][1]==0))
       {initPlayerx(&x,"ox(1).jpg", 1, 0);afficher(x,s);SDL_Flip(s);m[0][1]=1;
        if ((m[0][0]==1&&m[0][2]==1) || (m[1][1]==1&&m[2][1]==1) ) {*score+=10; win=1;break;}
        else {i=rand() % (3);j=rand() % (3);while(m[i][j]!=0) {i=rand() % (3);j=rand() % (3);}
        SDL_Delay(1500);initPlayerx(&x,"ox.jpg", j, i);afficher(x,s);SDL_Flip(s);m[i][j]=2;
if((m[0][0]==2&&m[1][0]==2&&m[2][0]==2)||(m[1][1]==2&&m[2][2]==2&&m[0][0]==2)||(m[0][1]==2&&m[0][2]==2&&m[0][0]==2)||(m[1][1]==2&&m[2][0]==2&&m[0][2]==2)||(m[1][2]==2&&m[0][2]==2&&m[2][2]==2)||(m[1][1]==2&&m[1][0]==2&&m[1][2]==2)||(m[2][0]==2&&m[2][1]==2&&m[2][2]==2)||(m[1][1]==2&&m[0][1]==2&&m[2][1]==2))  {*score-=10; lose=1;break;}} }
/**/else if((event.motion.x>=400 && event.motion.x<=800) && (event.motion.y>=266 && event.motion.y<=532)&&(m[1][1]==0))
{initPlayerx(&x,"ox(1).jpg", 1, 1);afficher(x,s);SDL_Flip(s);m[1][1]=1;
        if ((m[1][0]==1&&m[1][2]==1) || (m[0][0]==1&&m[2][2]==1) || (m[0][1]==1&&m[2][1]==1)||(m[0][2]==1&&m[2][0])==2) {*score+=10; win=1;break;}
        else {i=rand() % (3);j=rand() % (3);while(m[i][j]!=0) {i=rand() % (3);j=rand() % (3);}
        SDL_Delay(1500);initPlayerx(&x,"ox.jpg", j, i);afficher(x,s);SDL_Flip(s);m[i][j]=2;
if((m[0][0]==2&&m[1][0]==2&&m[2][0]==2)||(m[1][1]==2&&m[2][2]==2&&m[0][0]==2)||(m[0][1]==2&&m[0][2]==2&&m[0][0]==2)||(m[1][1]==2&&m[2][0]==2&&m[0][2]==2)||(m[1][2]==2&&m[0][2]==2&&m[2][2]==2)||(m[1][1]==2&&m[1][0]==2&&m[1][2]==2)||(m[2][0]==2&&m[2][1]==2&&m[2][2]==2)||(m[1][1]==2&&m[0][1]==2&&m[2][1]==2))  {*score-=10; lose=1;break;}} }
/**/else if((event.motion.x>=400 && event.motion.x<=800) && (event.motion.y>=532 && event.motion.y<=798)&&(m[2][1]==0))
{initPlayerx(&x,"ox(1).jpg", 1, 2);afficher(x,s);SDL_Flip(s);m[2][1]=1;
        if ((m[2][0]==1&&m[2][2]==1) || (m[1][1]==1&&m[0][1]==1)) {*score+=10; win=1;break;}
        else {i=rand() % (3);j=rand() % (3);while(m[i][j]!=0) {i=rand() % (3);j=rand() % (3);}
        SDL_Delay(1500);initPlayerx(&x,"ox.jpg", j, i);afficher(x,s);SDL_Flip(s);m[i][j]=2;
if((m[0][0]==2&&m[1][0]==2&&m[2][0]==2)||(m[1][1]==2&&m[2][2]==2&&m[0][0]==2)||(m[0][1]==2&&m[0][2]==2&&m[0][0]==2)||(m[1][1]==2&&m[2][0]==2&&m[0][2]==2)||(m[1][2]==2&&m[0][2]==2&&m[2][2]==2)||(m[1][1]==2&&m[1][0]==2&&m[1][2]==2)||(m[2][0]==2&&m[2][1]==2&&m[2][2]==2)||(m[1][1]==2&&m[0][1]==2&&m[2][1]==2))  {*score-=10; lose=1;break;}} }
/**/else if((event.motion.x>=800 && event.motion.x<=1200) && (event.motion.y>=0 && event.motion.y<=266)&&(m[0][2]==0))
{initPlayerx(&x,"ox(1).jpg", 2, 0);afficher(x,s);SDL_Flip(s);m[0][2]=1;
        if ((m[2][0]==1&&m[1][1]==1) || (m[0][0]==1&&m[0][1]==1)||(m[1][2]==1&&m[2][2]==1)) {*score+=10; win=1;break;}
        else {i=rand() % (3);j=rand() % (3);while(m[i][j]!=0) {i=rand() % (3);j=rand() % (3);}
        SDL_Delay(1500);initPlayerx(&x,"ox.jpg", j, i);afficher(x,s);SDL_Flip(s);m[i][j]=2;
if((m[0][0]==2&&m[1][0]==2&&m[2][0]==2)||(m[1][1]==2&&m[2][2]==2&&m[0][0]==2)||(m[0][1]==2&&m[0][2]==2&&m[0][0]==2)||(m[1][1]==2&&m[2][0]==2&&m[0][2]==2)||(m[1][2]==2&&m[0][2]==2&&m[2][2]==2)||(m[1][1]==2&&m[1][0]==2&&m[1][2]==2)||(m[2][0]==2&&m[2][1]==2&&m[2][2]==2)||(m[1][1]==2&&m[0][1]==2&&m[2][1]==2))  {*score-=10; lose=1;break;}} }
/**/else if((event.motion.x>=800 && event.motion.x<=1200) && (event.motion.y>=266 && event.motion.y<=532)&&(m[1][2]==0))
{initPlayerx(&x,"ox(1).jpg", 2, 1);afficher(x,s);SDL_Flip(s);m[1][2]=1;
        if ((m[0][2]==1&&m[2][2]==1) || (m[1][1]==1&&m[1][0]==1)) {*score+=10; win=1;break;}
        else {i=rand() % (3);j=rand() % (3);while(m[i][j]!=0) {i=rand() % (3);j=rand() % (3);}
        SDL_Delay(1500);initPlayerx(&x,"ox.jpg", j, i);afficher(x,s);SDL_Flip(s);m[i][j]=2;
if((m[0][0]==2&&m[1][0]==2&&m[2][0]==2)||(m[1][1]==2&&m[2][2]==2&&m[0][0]==2)||(m[0][1]==2&&m[0][2]==2&&m[0][0]==2)||(m[1][1]==2&&m[2][0]==2&&m[0][2]==2)||(m[1][2]==2&&m[0][2]==2&&m[2][2]==2)||(m[1][1]==2&&m[1][0]==2&&m[1][2]==2)||(m[2][0]==2&&m[2][1]==2&&m[2][2]==2)||(m[1][1]==2&&m[0][1]==2&&m[2][1]==2))  {*score-=10; lose=1;break;}} }
/**/else if((event.motion.x>=800 && event.motion.x<=1200) && (event.motion.y>=532 && event.motion.y<=798)&&(m[2][2]==0))
{initPlayerx(&x,"ox(1).jpg", 2, 2);afficher(x,s);SDL_Flip(s);m[2][2]=1;
        if ((m[2][0]==1&&m[2][1]==1) || (m[1][1]==1&&m[0][0]==1)||(m[0][2]&&m[1][2])) {*score+=10; win=1;break;}
        else {i=rand() % (3);j=rand() % (3);while(m[i][j]!=0) {i=rand() % (3);j=rand() % (3);}
        SDL_Delay(1500);initPlayerx(&x,"ox.jpg", j, i);afficher(x,s);SDL_Flip(s);m[i][j]=2;
if((m[0][0]==2&&m[1][0]==2&&m[2][0]==2)||(m[1][1]==2&&m[2][2]==2&&m[0][0]==2)||(m[0][1]==2&&m[0][2]==2&&m[0][0]==2)||(m[1][1]==2&&m[2][0]==2&&m[0][2]==2)||(m[1][2]==2&&m[0][2]==2&&m[2][2]==2)||(m[1][1]==2&&m[1][0]==2&&m[1][2]==2)||(m[2][0]==2&&m[2][1]==2&&m[2][2]==2)||(m[1][1]==2&&m[0][1]==2&&m[2][1]==2))  {*score-=10; lose=1;break;}}} 
else  tie=1;break;}}
liberer(x);
liberer(Backg);
   
   Mix_FreeChunk(son);
 
}
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       



