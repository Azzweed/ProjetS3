#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Taille de l'écran */
#define SCREEN_WIDTH  1000
#define SCREEN_HEIGHT 750
#define SOIL_SIZE 50
#define CHAR_SIZE 50
#define TAILLE_MAX 300
#define SPRITE_SIZE   50

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

int collision(int x, int y, int x2, int y2){
  if (x==x2) || (y==y2){
    return 1;
  }else{
    return 0;
  }
}

int main(int argc, char* argv[])
{
    SDL_Surface *ecran, *temp, *grass, *castle ,*sprite;
    
    SDL_Rect spritePosition, position;
    int colorkey;
  
    /* Initialisation SDL */
    SDL_Init(SDL_INIT_VIDEO);
    
    
    /* Création de la fenetre */
    ecran = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
    
    /* Zone de map ou le personnage peut se déplacer */
    temp  = SDL_LoadBMP("grassCenter.bmp");
    grass = SDL_DisplayFormat(temp);
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
    spritePosition.x = 50;
    spritePosition.y = 50;
    
    colorkey = SDL_MapRGB(ecran->format ,255 ,255,255);
    SDL_SetColorKey(sprite,SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
    
    
    int gameover = 0;
    int level=3;
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
	    }
	    if (level==1){
	      fichier = fopen("map1.txt", "r");
	    }
	    if (level==2){
	      fichier = fopen("map2.txt", "r");
	    }
	    if (level==3){
	      fichier = fopen("map3.txt", "r");
	    }
	    if (level >3){
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
	/* Tracé du background en foction des # */
	int x=0;
	int y=0;
	for (int z=0; z<300; z++){
	  y=z/20;
	  x=z%20;
	  position.x = x * SOIL_SIZE;
          position.y = y * SOIL_SIZE;
	  if (fondMap[z]=='#'){
	    SDL_BlitSurface(castle, NULL, ecran, &position);
	  }
	  else{
	    SDL_BlitSurface(grass, NULL, ecran, &position);
	  };
	}
        
        
    
        /* handle sprite movement */
	Uint8 *keystate;
        keystate = SDL_GetKeyState(NULL);

        if (keystate[SDLK_LEFT] ) {
            spritePosition.x -= 4;
        }
        if (keystate[SDLK_RIGHT] ) {
            spritePosition.x += 4;
        }
        if (keystate[SDLK_UP] ) {
            spritePosition.y -= 4;
        }
        if (keystate[SDLK_DOWN] ) {
            spritePosition.y += 4;
        }
        
        /* collide with edges of screen */
        if (spritePosition.x < SPRITE_SIZE) {
            spritePosition.x = SPRITE_SIZE;
        } else if (spritePosition.x > SCREEN_WIDTH - (2*(SPRITE_SIZE-7))) {
            spritePosition.x = SCREEN_WIDTH - (2*(SPRITE_SIZE-7));
        }

        if (spritePosition.y < SPRITE_SIZE) {
            spritePosition.y = SPRITE_SIZE;
        } else if (spritePosition.y > SCREEN_HEIGHT - (2*SPRITE_SIZE)) {
            spritePosition.y = SCREEN_HEIGHT - (2*SPRITE_SIZE);
        }
        
        
        /* draw the sprite */
        SDL_BlitSurface(sprite, NULL, ecran, &spritePosition);

        /* update the screen */
        SDL_UpdateRect(ecran,0,0,0,0);
	
    }


    /* Libération des pointeurs */
    SDL_FreeSurface(grass);
    SDL_FreeSurface(castle);
    SDL_FreeSurface(sprite);
    SDL_Quit();

    return 0;
}