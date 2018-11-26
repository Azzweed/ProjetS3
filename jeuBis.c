#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Constantes.h"








void HandleEvent(SDL_Event event,
        int *quit, int level)
{
    switch (event.type) {
	/* Quitter */  
	case SDL_QUIT:
	    *quit = 1;
	    break;

	/* Gestion des evenements */
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
	      case SDLK_ESCAPE:
		    *quit = 1;
	      case SDLK_q:
                    *quit = 1;
	      case SDLK_p:
		    level+=1;
	      default: break;
            }
	      default: break;
    }
}




int main(int argc, char* argv[])
{
    SDL_Surface *ecran, *temp, *grass, *castle ,*sprite ,*door;
    
    SDL_Rect spritePosition;
    int map[SCREEN_WIDTH][SCREEN_HEIGHT];
    int colorkey;

  
    /* Initialisation SDL */
    SDL_Init(SDL_INIT_VIDEO);
    
    
    /* Création de la fenetre */
    ecran = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
    
    /* Zone de map ou le personnage peut se déplacer */
    temp  = SDL_LoadBMP("grassCenter.bmp");
    grass = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);
    
    
    temp  = SDL_LoadBMP("door.bmp");
    door = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);

    
    /* Zones de map interdites au personnage */
    temp  = SDL_LoadBMP("castleCenter.bmp");
    castle = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);
    
    /* load sprite */
    temp   = SDL_LoadBMP("sprite.bmp");
    sprite = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);
    
    /* set sprite position */
    spritePosition.x = 700;
    spritePosition.y = 50;
    

    
    int newmap = 1;
    int gameover = 0;
    int level=0;
    while (!gameover)
    {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
            HandleEvent(event, &gameover, level);
        }
        /* Récupération du background dans un tableau */


	
	    FILE* fichier;
	    char intermediare[300] = "";
	    char fondMap[TAILLE_MAX] = "";
	    
	    if (level==0){
	      fichier = fopen("map0.txt", "r");
	      if (newmap==1){
		spritePosition.x = 50;
		spritePosition.y = 650;
		newmap=0;
	      }
	    }
	    if (level==1){
	      fichier = fopen("map1.txt", "r");
	      	      if (newmap==1){
		spritePosition.x = 50;
		spritePosition.y = 50;
		newmap=0;
	      }
	    }
	    if (level==2){
	      fichier = fopen("map2.txt", "r");
	      if (newmap==1){
		spritePosition.x = 500;
		spritePosition.y = 350;
		newmap=0;
	      }
	    }
	    if (level==3){
	      fichier = fopen("map3.txt", "r");
	      if (newmap==1){
		spritePosition.x = 350;
		spritePosition.y = 400;
		newmap=0;
	      }

	      
	    }
	    if (level > 3){
	      level=0;
	    }
	    if(fichier != NULL)
	    {
	      for (int i=0; i<15; i++){
	      fgets(intermediare, TAILLE_MAX, fichier);
	      for (int j=0; j<20; j++){
		fondMap[20*
		i+j]=intermediare[j];
	      }
	    }
	    fclose(fichier);
	   }

	
	
	SDL_Rect position;
	/* Tracé du background en fonction des # */
	int x=0;
	int y=0;
	for (int z=0; z<300; z++){
	  y=z/20;
	  x=z%20;
	  position.x = x * SOIL_SIZE;
          position.y = y * SOIL_SIZE;
	  if (fondMap[z]=='#'){
	    SDL_BlitSurface(castle, NULL, ecran, &position);
	    for (int i=0; i<50 ;i++){
	      for (int j=0; j<50 ;j++){
		map[50*x+i][50*y+j]=1;
	      }
	    }
	  }
	  else{
	    if (fondMap[z]=='%'){
	      SDL_BlitSurface(door, NULL, ecran, &position);
	      
	      for (int i=0; i<50 ;i++){
		for (int j=0; j<50 ;j++){
		  map[50*x+i][50*y+j]=2;
		}  
	      }
	    }
	    else{
	      SDL_BlitSurface(grass, NULL, ecran, &position);
	      for (int i=0; i<50 ;i++){
		for (int j=0; j<50 ;j++){
		  map[50*x+i][50*y+j]=0;
		}
	      }
	    }
	    
	  }
	
	}
	
	
    

	

	
        
    
    
        /* handle sprite movement */
	Uint8 *keystate;
        keystate = SDL_GetKeyState(NULL);

        if (keystate[SDLK_LEFT] ) {
	  
	  temp   = SDL_LoadBMP("spriteleft.bmp");
	  sprite = SDL_DisplayFormat(temp);
	  SDL_FreeSurface(temp);
	  if ((map[spritePosition.x-6][spritePosition.y+1]!=1) & (map[spritePosition.x-6][spritePosition.y+49]!=1))
	    {
	      spritePosition.x -= 5;
	    }

	  
	  }
	
        
        if (keystate[SDLK_RIGHT] ) {
	  
	temp   = SDL_LoadBMP("spriteright.bmp");
	sprite = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
	
	  if ((map[spritePosition.x+40][spritePosition.y+1]!=1) & (map[spritePosition.x+40][spritePosition.y+49]!=1))
	  {
            spritePosition.x += 5;
	  }


	}
	
	
        if (keystate[SDLK_UP] ) {
	  if ((map[spritePosition.x][spritePosition.y-5]!=1) & (map[spritePosition.x+35][spritePosition.y-5]!=1))
	  {
            spritePosition.y -= 5;
	  }
	}
	
	else
    
	  {
	  
	    if ((map[spritePosition.x][spritePosition.y+51]!=1) & (map[spritePosition.x+35][spritePosition.y+51]!=1))
	      {
	      spritePosition.y += 10;
	      }
	   }
	

	colorkey = SDL_MapRGB(ecran->format ,255 ,255,255);
	SDL_SetColorKey(sprite,SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);


        
        /* draw the sprite */
        SDL_BlitSurface(sprite, NULL, ecran, &spritePosition);

        /* update the screen */
        SDL_UpdateRect(ecran,0,0,0,0);
	
	temp   = SDL_LoadBMP("sprite.bmp");
	sprite = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
	
	if (map[spritePosition.x][spritePosition.y]==2){
	  if (level ==3)
	  {
	    gameover=1;
	  }
	  level+=1;
	  newmap=1;

	
	}
    }


    /* Libération des pointeurs */
    SDL_FreeSurface(grass);
    SDL_FreeSurface(door);
    SDL_FreeSurface(castle);
    SDL_FreeSurface(sprite);
    SDL_Quit();

    return 0;
}