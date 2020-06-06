#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_rotozoom.h>
#include "jeux.h"
#include <time.h>
void afficherfond1(map *map,SDL_Rect camera,SDL_Surface *ecran)
{
SDL_BlitSurface(map->fond,&camera, ecran,NULL);
SDL_BlitSurface(map->imagemini,NULL,ecran,&map->posmini);
SDL_BlitSurface(map->imagenokta,NULL,ecran,&map->posnokta);
}
void afficherfond(map map,SDL_Rect camera,SDL_Surface *ecran)
{
SDL_BlitSurface(map.fond,&camera, ecran,NULL);

}
SDL_Rect scrolling(int d,SDL_Rect camera,perso pers)
{
if(camera.x<=0) camera.x=0;
if(camera.x>=7000) camera.x=7000;
if(d==1&&pers.position.x>=600)
{
camera.x=camera.x+20;
}
if(d==2&&pers.position.x<=600)
{
camera.x=camera.x-20;
}
 
return camera ;
}

void initialiserfond(map *map)
{
map->position.x = 0 ;
map->position.y = 0 ;
map->position.w = 0 ;
map->position.h = 400 ;
map->fond = IMG_Load("back1.png");
map->imagemini=IMG_Load("mini.png");
map->imagenokta=IMG_Load("point.png");
map->posmini.x=20;
map->posmini.y=500;


map->posnokta.x=30;
map->posnokta.y=560;

}

void initialiserfond4(map *map)
{
map->position.x = 0 ;
map->position.y = 0 ;
map->position.w = 0 ;
map->position.h = 400 ;
map->fond = IMG_Load("back3.png");
}
void DrawScore1(SDL_Surface *screen, int* score,TTF_Font *police)
{   SDL_Surface *fond1;
        char actualScore[100];
        SDL_Color color;
        color.r = 255 ;
        color.g = 255 ;
        color.b = 255 ;
        sprintf (actualScore," score :%d",*score);
        SDL_Rect pospoints;
        pospoints.x=350;
        pospoints.y=400;
        fond1 = TTF_RenderText_Blended(police,actualScore,color);
        SDL_BlitSurface	(fond1,NULL,screen,&pospoints);
}
void DrawScore(SDL_Surface *screen, int* score,TTF_Font *police)
{   SDL_Surface *fond1;
        char actualScore[100];
        SDL_Color color;
        color.r = 255 ;
        color.g = 255 ;
        color.b = 255 ;
        sprintf (actualScore," score :%d",*score);
        SDL_Rect pospoints;
        pospoints.x=350;
        pospoints.y=10;
        fond1 = TTF_RenderText_Blended(police,actualScore,color);
        SDL_BlitSurface	(fond1,NULL,screen,&pospoints);
      
}






