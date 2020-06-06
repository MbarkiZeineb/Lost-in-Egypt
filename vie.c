#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_rotozoom.h>
#include "jeux.h"
#include <time.h>
void affichervie(vie *vie , SDL_Surface *ecran)
{
if(vie->nb==3)
{
SDL_BlitSurface(vie->fond1,NULL, ecran,&vie->position);

}
if(vie->nb==2)
{
SDL_BlitSurface(vie->fond2,NULL, ecran,&vie->position);
 
}
if(vie->nb==1)
{
SDL_BlitSurface(vie->fond3,NULL, ecran,&vie->position);

}
if(vie->nb==0)
{
menu(ecran);

}


}

void initialiservie2(vie *vie)
{
vie->nb=3;
vie->position.x =0;
vie->position.y = 400;
vie->fond1 = IMG_Load("vie/vie11.png");
vie->fond2 = IMG_Load("vie/vie22.png");
vie->fond3 = IMG_Load("vie/vie33.png");
}

 void initialiservie(vie *vie)
{
vie->nb=3;
vie->position.x =0;
vie->position.y = 0;
vie->fond1 = IMG_Load("vie/vie1.png");
vie->fond2 = IMG_Load("vie/vie2.png");
vie->fond3 = IMG_Load("vie/vie3.png");
}
