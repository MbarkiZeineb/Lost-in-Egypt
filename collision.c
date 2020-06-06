/**
* @file collision.c
 * @brief collision 
 * @ author Mbarki Zeineb 
 * @ version 0.1 
  *@ date juin 06 , 2020
*/


#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_rotozoom.h>
#include "jeux.h"
#include <time.h>
SDL_Color  GetPixel ( SDL_Surface* pSurface, int x , int y)
{
    SDL_Color color;
    Uint32 col = 0 ;
    if (x >= 0 && y >= 0)
    {
        //determine position
        char* pPosition = ( char* ) pSurface->pixels ;

        //offset by y
        pPosition += ( pSurface->pitch * y ) ;

        //offset by x
        pPosition += ( pSurface->format->BytesPerPixel * x ) ;

        //copy pixel data
        memcpy ( &col , pPosition , pSurface->format->BytesPerPixel ) ;

        //convert color
    }
    SDL_GetRGB ( col , pSurface->format , &color.r , &color.g , &color.b ) ;
    return ( color ) ;
}

int collision_Parfaite(SDL_Surface *calque,perso perso,int decalage,int d)
{

  SDL_Color col;
  if(d==1)//imin
  {
    col=GetPixel(calque,perso.position.x+perso.image0->w +decalage,perso.position.y+(perso.image0->h/2));
  }
else  if(d==2)//issarr
  {
    col=GetPixel(calque,perso.position.x +decalage,perso.position.y+(perso.image0->h/2));
  }
else  if(d==3)//lfou9
  {
    col=GetPixel(calque,perso.position.x+(perso.image0->w/2)+decalage ,perso.position.y);
  }
else  if(d==4)//louta
  {
    col=GetPixel(calque,perso.position.x+(perso.image0->w/2) +decalage,perso.position.y+perso.image0->h);
  }
  printf("%d    %d   %d\n",col.r,col.b,col.g );
if ((col.r==0)&&(col.b==0)&&(col.g==0))
{
  return 1;
}
else return 0;
}
void collisionennemi(perso *perso,ennemis *ennemi,SDL_Rect *camera,vie *vie)
{

if((((perso->position.x+perso->image0->w > ennemi->position.x)&&(perso->position.x+perso->image0->w < ennemi->position.x+ennemi->fond1->w))||((perso->position.x < ennemi->position.x+ennemi->fond1->w)&&(perso->position.x > ennemi->position.x)))/*&&perso->position.y==255*/)
if(perso->position.y==ennemi->position.y)
{
SDL_Delay(100);
ennemi->position.x = 500 ;
perso->position.x = 2 ;
perso->position.y = 300 ;
camera->x=0;

vie->nb--;
}
}






