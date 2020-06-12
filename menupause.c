
/**
* @file menupause.c 
* @ author mbarki Zeineb
* @brief menupause
* @ version 1.0
* @ date juin 06 , 2020
*/
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_rotozoom.h>
#include"jeux.h"
#include <time.h>
 /**
* @brief choose one or two player
* @param ecran screen 
*@return nothing
*/
 void oneortwo(SDL_Surface **ecran)
{
SDL_Surface* aff2=IMG_Load("menu/oneplayer.png");
	SDL_Surface* aff3=IMG_Load("menu/twoplayers.png");
	SDL_Surface* aff1=IMG_Load("menu/players.png");
	SDL_Surface* bg=IMG_Load("menu/masr.png");
     
	
            SDL_Rect pq;
	*ecran = SDL_SetVideoMode(1000,700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF );  
          
	 pq.x=220;
         pq.y=420;
        SDL_BlitSurface(bg,NULL, *ecran,NULL);
       SDL_BlitSurface(aff1,NULL, *ecran,&pq);
	
	 int continuer=1;
	SDL_Flip(*ecran);
	SDL_Event event;
	while(continuer)
	{SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_MOUSEMOTION : 
			{
				if(event.motion.x>230 && event.motion.x<452 && event.motion.y>420 && event.motion.y<504)
				{
					SDL_BlitSurface(bg,NULL, *ecran,NULL);
					  SDL_BlitSurface(aff3,NULL, *ecran,&pq);
	                             
	
					
					SDL_Flip(*ecran);
				}
                                 else 
				{
					SDL_BlitSurface(bg,NULL,* ecran,NULL);
				        SDL_BlitSurface(aff1,NULL,* ecran,&pq);
	                             
	
					SDL_Flip(*ecran);
				}
				 if(event.motion.x>521 && event.motion.x<743 && event.motion.y>420 && event.motion.y<504)
				{
					SDL_BlitSurface(bg,NULL, *ecran,NULL);
					  SDL_BlitSurface(aff2,NULL, *ecran,&pq);
	                         SDL_Flip(*ecran);
	
				}
				else 
				{
					SDL_BlitSurface(bg,NULL,* ecran,NULL);
				        SDL_BlitSurface(aff1,NULL,* ecran,&pq);
	                             
	
					SDL_Flip(*ecran);
				}
			}
			break;
			case SDL_KEYDOWN :
			{
				if(event.key.keysym.sym==SDLK_q)
				{
					continuer=0;
				}
			}
			break;
			case SDL_MOUSEBUTTONDOWN :
			{
				if(event.button.x>230 && event.button.x<452 && event.button.y>420 && event.button.y<504)
				{
					 game2(*ecran,0); 	
                                      
				}
				else if(event.button.x>521 && event.button.x<743 && event.button.y>420 && event.button.y<504)
				{
				   player(ecran);
                                            
				}
			}
			break;
		}
	}
}
/**
* @brief  to choose a player 
* @param ecran screen 
*@return nothing
*/
void player(SDL_Surface **ecran)
{
SDL_Surface* aff2=IMG_Load("player1.png");
	SDL_Surface* aff3=IMG_Load("player2.png");
	SDL_Surface* bg=IMG_Load("menu/masr.png");
     
	
            SDL_Rect p1,p2;
	*ecran = SDL_SetVideoMode(1000,700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF );  
          
	
         p1.x=220;
         p1.y=420;
          p2.x=521;
         p2.y=420;
        SDL_BlitSurface(bg,NULL, *ecran,NULL);
        SDL_BlitSurface(aff2,NULL, *ecran,&p1);
        SDL_BlitSurface(aff3,NULL, *ecran,&p2);
	 int continuer=1;
	SDL_Flip(*ecran);
	SDL_Event event;
	while(continuer)
	{SDL_WaitEvent(&event);
		switch(event.type)
		{
		case SDL_KEYDOWN :
			{
				if(event.key.keysym.sym==SDLK_q)
				{
					exit(0);
				}
			}
			break;
			case SDL_MOUSEBUTTONDOWN :
			{
				if(event.button.x>230 && event.button.x<452 && event.button.y>420 && event.button.y<504)
				{
                                       game1p2(*ecran,0);
                                      
				}
				else if(event.button.x>521 && event.button.x<743 && event.button.y>420 && event.button.y<504)
				{
				    game1(*ecran,0); 	
                                      
				}
			}
			break;
		


}
	}






}
/**
* @brief  to load a saved game or start a new game 
* @param ecran screen 
*@return nothing
*/
  void newgame(SDL_Surface **ecran)
{
SDL_Surface* aff3=IMG_Load("menu/newgame.png");
	SDL_Surface* aff2=IMG_Load("menu/loadgame.png");
	SDL_Surface* aff1=IMG_Load("menu/game.png");
	SDL_Surface* bg=IMG_Load("menu/masr.png");
     
	
            SDL_Rect pq;
	*ecran = SDL_SetVideoMode(1000,700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF );  
          int p;
	 pq.x=220;
         pq.y=420;
        SDL_BlitSurface(bg,NULL, *ecran,NULL);
       SDL_BlitSurface(aff1,NULL, *ecran,&pq);
	
	 int continuer=1;
	SDL_Flip(*ecran);
	SDL_Event event;
	while(continuer)
	{SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_MOUSEMOTION : 
			{
				if(event.motion.x>230 && event.motion.x<452 && event.motion.y>420 && event.motion.y<504)
				{
					SDL_BlitSurface(bg,NULL, *ecran,NULL);
					  SDL_BlitSurface(aff2,NULL, *ecran,&pq);
	                             
	
					
					SDL_Flip(*ecran);
				} 
                                    else 
				{
					SDL_BlitSurface(bg,NULL,* ecran,NULL);
				        SDL_BlitSurface(aff1,NULL,* ecran,&pq);
	                             
	
					SDL_Flip(*ecran);
				}
				if(event.motion.x>521 && event.motion.x<743 && event.motion.y>420 && event.motion.y<504)
				{
					SDL_BlitSurface(bg,NULL, *ecran,NULL);
					  SDL_BlitSurface(aff3,NULL, *ecran,&pq);
	                         
	                                      SDL_Flip(*ecran);
				}
				else 
				{
					SDL_BlitSurface(bg,NULL,* ecran,NULL);
				        SDL_BlitSurface(aff1,NULL,* ecran,&pq);
	                             
	
					SDL_Flip(*ecran);
				}
			}
			break;
			case SDL_KEYDOWN :
			{
				if(event.key.keysym.sym==SDLK_q)
				{
					continuer=0;
				}
			}
			break;
			case SDL_MOUSEBUTTONDOWN :
			{
				if(event.button.x>230 && event.button.x<452 && event.button.y>420 && event.button.y<504)
				{
					oneortwo(ecran);
                                      
				}
				else if(event.button.x>521 && event.button.x<743 && event.button.y>420 && event.button.y<504)
				{
					FILE* f=fopen("savedgame.txt","r");
                               fscanf(f,"%d   \n",&p);
                             fclose(f);
                            if(p==1)
                             game1(*ecran,0);
                             else
                              game1p2(*ecran,0);
				}
			}
			break;
		}
	}
}

/**
* @brief quit screen with save it or not  
* @param ecran screen
  @param p personnage 
  @param camera  position camera
  @param score score
  @ param p which character 
*@return nothing
*/			

    
int  quitscreen(SDL_Surface **ecran,perso P,SDL_Rect camera,int  score ,int p )
{
	SDL_Surface* aff2=IMG_Load("menu/quit2.png");
	SDL_Surface* aff3=IMG_Load("menu/quit3.png");
	SDL_Surface* aff1=IMG_Load("menu/quit1.png");
	SDL_Surface* question=IMG_Load("menu/question.png");
        SDL_Surface* bg=IMG_Load("q.png");
	FILE* f=NULL;
            SDL_Rect pquestion,pq;
	
          pquestion.x=250;
          pquestion.y=250;
          
	 pq.x=220;
         pq.y=420;
        SDL_BlitSurface(bg,NULL, *ecran,NULL);
       SDL_BlitSurface(aff1,NULL, *ecran,&pq);
	SDL_BlitSurface(question,NULL, *ecran,&pquestion);
	 int continuer=1;
	SDL_Flip(*ecran);
	SDL_Event event;
	while(continuer)
	{SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_MOUSEMOTION : 
			{
				if(event.motion.x>230 && event.motion.x<452 && event.motion.y>420 && event.motion.y<504)
				{
					SDL_BlitSurface(bg,NULL, *ecran,NULL);
					  SDL_BlitSurface(aff2,NULL, *ecran,&pq);
	                              SDL_BlitSurface(question,NULL, *ecran,&pquestion);
	
					
					SDL_Flip(*ecran);
				}
				else if(event.motion.x>521 && event.motion.x<743 && event.motion.y>420 && event.motion.y<504)
				{
					SDL_BlitSurface(bg,NULL, *ecran,NULL);
					  SDL_BlitSurface(aff3,NULL, *ecran,&pq);
	                         SDL_BlitSurface(question,NULL, *ecran,&pquestion);
	
				}
				else 
				{
					SDL_BlitSurface(bg,NULL,* ecran,NULL);
				        SDL_BlitSurface(aff1,NULL,* ecran,&pq);
	                              SDL_BlitSurface(question,NULL,* ecran,&pquestion);
	
					SDL_Flip(*ecran);
				}
			}
			break;
			case SDL_KEYDOWN :
			{
				if(event.key.keysym.sym==SDLK_q)
				{
					continuer=0;
				}
			}
			break;
			case SDL_MOUSEBUTTONDOWN :
			{
				if(event.button.x>230 && event.button.x<452 && event.button.y>420 && event.button.y<504)
				{
					continuer=0;
                                       menu(*ecran);
				}
				else if(event.button.x>521 && event.button.x<743 && event.button.y>420 && event.button.y<504)
				{
					f=fopen("savedgame.txt","w");
	                             fprintf(f," %hd %hd %hd %hd  %hd   \n",p,P.position.x,P.position.y,camera.x,score);
				
					fclose(f);
					
				   continuer=0;
                                 menu(*ecran);
					
				}
			}
			break;
		}
	}
}


