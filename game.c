#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"jeux.h"
#include <time.h>
void  game1(SDL_Surface *ecran)
{
char chrono[16];
  TTF_Font *police;
  int  t1=0, t2=0;
  SDL_Surface  *texte =  NULL;
  SDL_Color noir = {255,255,180,0}, rouge = {100,0,0};
SDL_Surface *fond=NULL;
SDL_Rect position;
perso perso ;
ennemis ennemi ;
int continuer = 1;
map map;
enigme e;
int d;
position.x=250;
position.y=275;
fond=IMG_Load("xb.png");
SDL_Surface* pSurface=NULL;
pSurface= IMG_Load("back1masque.png");
vie vie;
SDL_Event event;
SDL_Surface *collisionMap =NULL;
SDL_Rect camera = { 0, 0, 1200, 600 },post;
anubis anubis;
int q,w=10;
srand(time(NULL)) ;


int x=0,y=1;

camera.x=0;
camera.y=0;
post.x=600;
post.y=10;
		SDL_Rect tempsPos;
		SDL_Surface* T;

SDL_Init(SDL_INIT_VIDEO| SDL_INIT_TIMER );
  TTF_Init(); 

ecran = SDL_SetVideoMode(1200,600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF );  

  police = TTF_OpenFont("Takota.ttf", 50);
   
 
    
    SDL_Delay(10); 
 initialiserennemi(&ennemi);
initialiserperso(&perso);
initialiseranubis(&anubis);
initialiserfond(&map);
SDL_EnableKeyRepeat(20,20);
initialiservie(&vie);
init_enigme(&e) ;
int touche=0;
SDL_EnableKeyRepeat(300,10);
SDL_ShowCursor(SDL_DISABLE);
SDL_LockSurface;
int score=200;
int touche1=0;
while (continuer)
{ 
 
 t2 = SDL_GetTicks();       //Minute       //Seconde   //Dixieme
    sprintf(chrono, "%d:%d", t2/1000/60%60, t2/1000%60);
    texte = TTF_RenderText_Shaded(police, chrono, rouge,noir);

d=direction(event,&continuer);
x = mouv(d,x);
y=splitennemi(y);
camera =scrolling(d,camera,perso);
perso=mouvement(perso, d,camera);
ennemi=mouvennemi(ennemi,d,camera,&q,&w,&y);
collisionennemi(&perso,&ennemi,&camera,&vie);

//collision(&perso,pSurface,d);


if(collision_Parfaite(pSurface,perso,5,d)==1)
{camera.x=camera.x-10;
 if(d==4)
perso.position.y-=30;
}





/*if(camera.x==2000&&touche==0)
{

touche=1;

enigme1(&ecran,&vie.nb,&score);
}

if(camera.x==2500&&touche1==0)
{
touche1=1;
enigme1(&ecran,&vie.nb,&score);
}*/
afficherfond(map,camera,ecran);
afficheranubis(anubis ,ecran,camera);
afficherperso(perso,ecran,x);
affichervie(&vie,ecran);
DrawScore(ecran,&score,police);
SDL_BlitSurface(texte, NULL, ecran,&post);
   
afficherennemi(ennemi,ecran,y);

SDL_Flip(ecran);
SDL_Delay(80);
}

//free(&map,&perso);
TTF_Quit();
SDL_Quit();
}


void game2(SDL_Surface *ecran,int save) 
{
char chrono[16];
  TTF_Font *police;
  int  t1=0, t2=0;
  SDL_Surface  *texte =  NULL;
  SDL_Color noir = {255,255,180,0}, rouge = {100,0,0};

SDL_Surface *fond=NULL,*ecran2=NULL;
SDL_Rect position;
perso perso ;
ennemis ennemi ;
int continuer = 1;
map map, map1;
enigme e;
int d;
position.x=250;
position.y=275;
fond=IMG_Load("xb.png");
SDL_Surface* pSurface=NULL;
pSurface= IMG_Load("back1masque.png");
vie vie;
SDL_Event event;
SDL_Surface *collisionMap =NULL;
SDL_Rect camera = { 3350, 0 , 1300, 400 }, post ,camera2 = {3350, 0 ,1300,400} ;
anubis anubis;
int q,w=10;
srand(time(NULL)) ;

int touche=0;

int score=200;
int touche1=0;
int x=0,y=1;
post.x=600;

post.y=10;
	
SDL_Rect tempsPos;
		SDL_Surface* T;

SDL_Init(SDL_INIT_VIDEO| SDL_INIT_TIMER );
  TTF_Init(); 

ecran = SDL_SetVideoMode(1300,800, 32, SDL_HWSURFACE | SDL_DOUBLEBUF );  

  police = TTF_OpenFont("Takota.ttf", 50);
   
 if(save==1)
{ 
FILE* f=fopen("savedgame.txt","r");
fscanf(f,"%hd %hd %hd %d  \n",&perso.position.x,&perso.position.y,&camera.x,&score);
 fclose(f);}
 
    SDL_Delay(10); 
 initialiserennemi(&ennemi);
initialiserperso(&perso);
initialiseranubis(&anubis);
initialiserfond(&map);
initialiserfond2(&map1);
SDL_EnableKeyRepeat(20,20);
initialiservie(&vie);
init_enigme(&e);

SDL_EnableKeyRepeat(300,10);
while (continuer)
{ 

 t2 = SDL_GetTicks();       //Minute       //Seconde   //Dixieme
    sprintf(chrono, "%d:%d", t2/1000/60%60, t2/1000%60);
    texte = TTF_RenderText_Shaded(police, chrono, rouge,noir);

d=direction(event,&continuer);
x = mouv(d,x);
y=splitennemi(y);

perso=mouvement(perso, d,camera);
camera =scrolling(d,camera,perso);


//collision(&perso,pSurface,d);
if(camera.x==2000&&touche==0)
{

touche=1;

enigme1(&ecran,&vie.nb,&score);
}

if(camera.x==2500&&touche1==0)
{
touche1=1;
enigme1(&ecran,&vie.nb,&score);
}
afficherfond(map,camera,ecran);
afficherfond2(map1, camera2,ecran);
afficheranubis(anubis ,ecran,camera);
afficherperso(perso,ecran,x);
affichervie(&vie,ecran);
DrawScore(ecran,&score,police);
SDL_BlitSurface(texte, NULL, ecran,&post);
   
afficherennemi(ennemi,ecran,y);

SDL_WaitEvent(&event);
switch(event.type)
{

case SDL_KEYDOWN:

            switch (event.key.keysym.sym)
            {
 		case SDLK_ESCAPE:
		  
    
 continuer=quitscreen(&ecran,perso,camera,score);
break;

}
}
SDL_Flip(ecran);
SDL_Delay(80);

}
//free(&map,&perso);
TTF_Quit();
SDL_Quit();


}





