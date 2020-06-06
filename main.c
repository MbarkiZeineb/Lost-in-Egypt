/**
* @file main.c
* @brief Testing Program.
* @author c Team
* @version 0.1 
* @date mai 06 , 2015
*
*
*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_rotozoom.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include"jeux.h"
#include"perso.c"
#include"perso2.c"
#include"ennemi.c"
#include"fonction.c"
#include"enigf.c"
#include"menu.c"
#include"menupause.c"
#include"game.c"
#include"vie.c"
#include"finjeux.c"
#include"collision.c"

int main(int argc, char * argv[]) 
{ SDL_Surface *ecran=NULL;

int continuer = 1;
ecran = SDL_SetVideoMode(1200, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_Event event;
while (continuer)
{
SDL_WaitEvent(&event);
switch(event.type)
{
case SDL_QUIT:
continuer = 0;
}
coat (ecran);
menu(ecran);

}




}

