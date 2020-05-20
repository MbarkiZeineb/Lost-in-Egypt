#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "jeux.h"
#include <time.h>
void afficherfond2(map map,SDL_Rect camera,SDL_Surface *ecran)
{
SDL_BlitSurface(map.fond,&camera, ecran,&map.position);
}

void afficherfond3(map map,SDL_Rect camera,SDL_Surface *ecran)
{
SDL_BlitSurface(map.fond,&camera, ecran,&map.position);
}
void initialiserfond3(map *map)
{
map->position.x = 0 ;
map->position.y = 0 ;
map->position.w = 0 ;
map->position.h = 400 ;
map->fond = IMG_Load("back2.png");
}
void initialiserfond2(map *map)
{
map->position.x =0 ;
map->position.y = 400 ;
map->position.w =1300 ;
map->position.h = 400 ;
map->fond = IMG_Load("back2.png");
}
SDL_Rect scrolling2(int d,SDL_Rect camera,perso pers)
{
if(camera.x<=0) camera.x=0;
if(camera.x>=8000) camera.x=8000;
if(d==1&&pers.position.x>=600)
{
camera.x=camera.x+20;
}
if(d==2&&pers.position.x<=600)
{
camera.x=camera.x-20;
}
}
int direction2(SDL_Event event,int *continuer)
{
int d;
SDL_PollEvent(&event);
switch(event.type)
    {
        case SDL_QUIT:
            *continuer = 0;
  		break;
	case SDL_KEYDOWN:

            switch (event.key.keysym.sym)
            {
 		case SDLK_ESCAPE:
		    continuer=0;
			break ;

		case SDLK_q :
		d=2;	
                    	break ;

		case SDLK_d :
		d=1; 
			break ;

		case SDLK_z :
		d=3;	
                    	break ;

		case SDLK_s :
		d=4; 
			break ;
	    }
		break;
    }
return d;
} 
