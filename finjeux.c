#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_rotozoom.h>
#include "jeux.h"
#include <time.h>
void finjeu (SDL_Surface *screen)
{
		SDL_Surface *T[126];
		int i; char ch[200]; 
  screen = SDL_SetVideoMode(1200, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
		for (i=0; i<=126;i++)
		{	
			sprintf (ch, "endgame/image%d.jpg", i+1);
			T[i]= IMG_Load(ch);
		}

		for(i=1;i<=116;i++)
		{	SDL_BlitSurface(T[i],NULL, screen,NULL);	
		SDL_Flip(screen);
		SDL_Delay(500);
		}
   menu(screen);
}
void coat (SDL_Surface *screen)
{   if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) {
      printf("%s", Mix_GetError());
     }
    Mix_Music * musique;
    musique = Mix_LoadMUS("stage1.mp3");
   
    Mix_PlayMusic(musique,-1);
		SDL_Surface *T[51];
		int i; char ch[100]; 
  screen = SDL_SetVideoMode(1200, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
		for (i=1; i<=51;i++)
		{	
			sprintf (ch, "coat/image%d.png", i+1);
			T[i]= IMG_Load(ch);
		}

		for(i=1;i<=51;i++)
		{	SDL_BlitSurface(T[i],NULL, screen,NULL);
			
		SDL_Flip(screen);
		if (i==51)
			{SDL_Delay(2000);
                         }
			else 
				SDL_Delay(500);
		}
 
}
