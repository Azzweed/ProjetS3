#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Constantes.h"
#include "fonctions.h"

#include "fonctions.c"





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
  SDL_Surface *ecran, *temp, *grass, *castle ,*sprite ,*door ,*doorclose ,*key , *mob ,*mob2 ,*coeur , *coeur2 ,*hudkey , *ladder;
  SDL_Rect HUD;
  SDL_Rect mobPosition;
  SDL_Rect mobPosition1;
  SDL_Rect mobPosition2;
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
    
  /* sprite de l'echelle */
  temp  = SDL_LoadBMP("ladder.bmp");
  ladder = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
    
  /* sprite de la clee */
    
  temp  = SDL_LoadBMP("key.bmp");
  key = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
    
  temp  = SDL_LoadBMP("hudkey.bmp");
  hudkey = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
    
  /* sprite des monstres */
    
  temp  = SDL_LoadBMP("mob.bmp");
  mob = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
    
  temp  = SDL_LoadBMP("mob2.bmp");
  mob2 = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
    
  /* sprite de la porte */
    
  temp  = SDL_LoadBMP("door.bmp");
  door = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
    
  temp  = SDL_LoadBMP("doorclose.bmp");
  doorclose = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

    
  /* Zones de map interdites au personnage */
  temp  = SDL_LoadBMP("castleCenter.bmp");
  castle = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
    
  /* sprite personnage */
  temp   = SDL_LoadBMP("sprite.bmp");
  sprite = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
    
  /* sprite vie */
    
  temp   = SDL_LoadBMP("coeurplein.bmp");
  coeur = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
    
  temp   = SDL_LoadBMP("coeurvide.bmp");
  coeur2 = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
    
  HUD.x=950;
  HUD.y=0;
  SDL_BlitSurface(coeur2, NULL, ecran, &HUD);
  HUD.x=900;
  SDL_BlitSurface(coeur, NULL, ecran, &HUD);
  HUD.x=850;
  SDL_BlitSurface(coeur, NULL, ecran, &HUD);

    

    
  int newmap = 1;
  int gameover = 0;
  int level=0;
  int keys = 0;
  int mobdir1 = 0;
  int mobdir2 = 0;
  int mobdir3 = 0;
  int vie = 3;
  int saut = 0;

    
    
 
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
	  mobPosition.x = 200;
	  mobPosition.y = 400;
	  mobPosition1.x = 250;
	  mobPosition1.y = 650;
	  mobPosition2.x = 400;
	  mobPosition2.y = 150;
	  newmap=0;
	  keys=0;
	}
      }
      if (level==1){
	fichier = fopen("map1.txt", "r");
	if (newmap==1){
	  spritePosition.x = 50;
	  spritePosition.y = 50;
	  mobPosition.x = 400;
	  mobPosition.y = 450;
	  mobPosition1.x = 250;
	  mobPosition1.y = 650;
	  mobPosition2.x = 400;
	  mobPosition2.y = 150;
	  newmap=0;
	  keys=0;
	}
      }
      if (level==2){
	fichier = fopen("map2.txt", "r");
	if (newmap==1){
	  spritePosition.x = 500;
	  spritePosition.y = 350;
	  mobPosition.x = 100;
	  mobPosition.y = 400;
	  mobPosition1.x = 250;
	  mobPosition1.y = 650;
	  mobPosition2.x = 450;
	  mobPosition2.y = 50;
	  newmap=0;
	  keys=0;
	}
      }
      if (level==3){
	fichier = fopen("map3.txt", "r");
	if (newmap==1){
	  spritePosition.x = 350;
	  spritePosition.y = 400;
	  mobPosition.x = 100;
	  mobPosition.y = 300;
	  mobPosition1.x = 250;
	  mobPosition1.y = 650;
	  mobPosition2.x = 500;
	  mobPosition2.y = 150;
	  newmap=0;
	  keys=0;
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
      for (int z=0; z<300; z++)
	{
	  y=z/20;
	  x=z%20;
	  position.x = x * SOIL_SIZE;
          position.y = y * SOIL_SIZE;
	  
	  switch(fondMap[z])
	    {
	    
	    case '#' : 
	      SDL_BlitSurface(castle, NULL, ecran, &position);
	      for (int i=0; i<50 ;i++)
		{
		  for (int j=0; j<50 ;j++)
		    {
		      map[50*x+i][50*y+j]=1;
		    }
		}
	      break;
	  
	    case '%' : 
	      
	      if (keys == 0)
		{
		  SDL_BlitSurface(doorclose, NULL, ecran, &position);
		}
	      else
		{
		  SDL_BlitSurface(door, NULL, ecran, &position);
		}

	      for (int i=0; i<50 ;i++)
		{
		  for (int j=0; j<50 ;j++)
		    {
		      map[50*x+i][50*y+j]=2;
		    }
		}
	      break;
		
	    case '-' : 
	       	  
	      
	      SDL_BlitSurface(grass, NULL, ecran, &position);
		      
	      if (keys == 0)
		{
		  SDL_BlitSurface(key, NULL, ecran, &position);
		}
	       


	      
	      for (int i=0; i<50 ;i++)
		{
		  for (int j=0; j<50 ;j++)
		    {
		      map[50*x+i][50*y+j]=3;
		    }
		}
	      break;
	      
	    case '=' : 

		
	      SDL_BlitSurface(grass, NULL, ecran, &position);
	      
	      SDL_BlitSurface(ladder, NULL, ecran, &position);
	      

	      for (int i=0; i<50 ;i++)
		{
		  for (int j=0; j<50 ;j++)
		    {
		      map[50*x+i][50*y+j]=4;
		    }
		}
	      break;
	      
	    default :
	       
	      SDL_BlitSurface(grass, NULL, ecran, &position);
	      for (int i=0; i<50 ;i++)
		{
		  for (int j=0; j<50 ;j++)
		    {
		      map[50*x+i][50*y+j]=0;
		    }
		}
	    }
	}


      /* handle mob mouvement */

      /* 1er monstre */
	
      if (mouvementmob(mobPosition.x,mobPosition.y,map,mobdir1)==-1)
	{
	  mobPosition.x -=1;
	  SDL_BlitSurface(mob, NULL, ecran, &mobPosition);
	}
		
      if (mouvementmob(mobPosition.x,mobPosition.y,map,mobdir1)==1)
	{
	  mobPosition.x +=1;
	  SDL_BlitSurface(mob2, NULL, ecran, &mobPosition);
	}
      if (mouvementmob(mobPosition.x,mobPosition.y,map,mobdir1)==0)
	{
	  mobdir1+=1;
	  
	  if (mobdir1 == 2)
	    {
	      mobdir1 = 0;
	    }
	}
	
	
      /* 2nd monstre */
	
      if (mouvementmob(mobPosition1.x,mobPosition1.y,map,mobdir2)==-1)
	{
	  mobPosition1.x -=1;
	  SDL_BlitSurface(mob, NULL, ecran, &mobPosition1);
	}
		
      if (mouvementmob(mobPosition1.x,mobPosition1.y,map,mobdir2)==1)
	{
	  mobPosition1.x +=1;
	  SDL_BlitSurface(mob2, NULL, ecran, &mobPosition1);
	}
      if (mouvementmob(mobPosition1.x,mobPosition1.y,map,mobdir2)==0)
	{
	  mobdir2+=1;
	  
	  if (mobdir2 == 2)
	    {
	      mobdir2 = 0;
	    }
	}
	
	

    
      /* 3eme monstre */
	
      if (mouvementmob(mobPosition2.x,mobPosition2.y,map,mobdir3)==-1)
	{
	  mobPosition2.x -=1;
	  SDL_BlitSurface(mob, NULL, ecran, &mobPosition2);
	}
		
      if (mouvementmob(mobPosition2.x,mobPosition2.y,map,mobdir3)==1)
	{
	  mobPosition2.x +=1;
	  SDL_BlitSurface(mob2, NULL, ecran, &mobPosition2);
	}
      if (mouvementmob(mobPosition2.x,mobPosition2.y,map,mobdir3)==0)
	{
	  mobdir3+=1;
	  
	  if (mobdir3 == 2)
	    {
	      mobdir3 = 0;
	    }
	}
	
	
    
      /* handle sprite movement */
      Uint8 *keystate;
      keystate = SDL_GetKeyState(NULL);
      
      
      
      
      
      

      if (keystate[SDLK_LEFT] ) {
	  
	temp   = SDL_LoadBMP("spriteleft.bmp");
	sprite = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
	  
	if (collisionGauche(spritePosition.x-5,spritePosition.y,map)==0)
	  {
	    spritePosition.x -= 5;
	  }

      }
	  
	  
	  
      if (keystate[SDLK_RIGHT] ) {
	  
	temp   = SDL_LoadBMP("spriteright.bmp");
	sprite = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
	
	if (collisionDroite(spritePosition.x+5,spritePosition.y,map)==0)
	  {
            spritePosition.x += 5;
	  }

      }
	
	
      if (keystate[SDLK_UP] ) {

	
	  
	  
	if (saut < 90)
	  {
	  
	    
	    if (collisionHaut(spritePosition.x,spritePosition.y-1,map)==1)
	    {
	      saut = 90;
	    }
	    
	    if (map[spritePosition.x+15][spritePosition.y+49]==4)
	    {
	      saut = 0;
	    }
	    
	      
	      
	      
	    if (collisionHaut(spritePosition.x,spritePosition.y-5,map)==0)
	      {
		spritePosition.y -= 5;
		saut  += 5;

	      }
	    
	    
	    else
	      
	      {
		while (collisionHaut(spritePosition.x,spritePosition.y-1,map)==0)
	      
		  {
		    spritePosition.y -= 1;
		    saut +=1;
		  }
	      }
	  }
	  
	  else
	  
	  {

	  
	    
	    
	    if ( collisionBas(spritePosition.x,spritePosition.y,map)==0)
	      {
		spritePosition.y += 5;
	    
		while (collisionBas(spritePosition.x,spritePosition.y-1,map)==1)
		  {
		    spritePosition.y -= 1;
		  }
	      }
	    else
	      {
		saut = 0;
	      }
	  }
      
      }
	  
	else
	  
	  {
	    if (map[spritePosition.x+15][spritePosition.y+49]==4)
	    {
	      if (keystate[SDLK_DOWN])
		
	      {
	      if ( collisionBas(spritePosition.x,spritePosition.y,map)==0)
		{
		  spritePosition.y += 5;
	      
		  while (collisionBas(spritePosition.x,spritePosition.y-1,map)==1)
		    {
		      spritePosition.y -= 1;
		    }
		}
	      }
	    }

	  else{
	    if ( collisionBas(spritePosition.x,spritePosition.y,map)==0)
	      {
		spritePosition.y += 5;
	    
		while (collisionBas(spritePosition.x,spritePosition.y-1,map)==1)
		  {
		    spritePosition.y -= 1;
		  }
	      }
	    else
	      {
		saut = 0;
	      }
	  }
	  }
      
	  
	  


      colorkey = SDL_MapRGB(ecran->format ,255 ,255,255);
      SDL_SetColorKey(sprite,SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
      SDL_SetColorKey(mob,SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
      SDL_SetColorKey(mob2,SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
      SDL_SetColorKey(coeur,SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
      SDL_SetColorKey(coeur2,SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
      SDL_SetColorKey(hudkey,SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
      SDL_SetColorKey(key,SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
      SDL_SetColorKey(ladder,SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
        
      /* draw the sprite */
      SDL_BlitSurface(sprite, NULL, ecran, &spritePosition);
	
      /*affichage du HUD */
      if (vie == 3)
	{
	  HUD.x=900;
	  HUD.y=0;
	  SDL_BlitSurface(coeur, NULL, ecran, &HUD);
	  HUD.x=850;
	  SDL_BlitSurface(coeur, NULL, ecran, &HUD);
	  HUD.x=800;
	  SDL_BlitSurface(coeur, NULL, ecran, &HUD);
	}
      if (vie == 2)
	{
	  HUD.x=900;
	  HUD.y=0;
	  SDL_BlitSurface(coeur2, NULL, ecran, &HUD);
	  HUD.x=850;
	  SDL_BlitSurface(coeur, NULL, ecran, &HUD);
	  HUD.x=800;
	  SDL_BlitSurface(coeur, NULL, ecran, &HUD);
	}
      if (vie == 1)
	{
	  HUD.x=900;
	  HUD.y=0;
	  SDL_BlitSurface(coeur2, NULL, ecran, &HUD);
	  HUD.x=850;
	  SDL_BlitSurface(coeur2, NULL, ecran, &HUD);
	  HUD.x=800;
	  SDL_BlitSurface(coeur, NULL, ecran, &HUD);
	}
      if (vie == 0)
	{
	  HUD.x=900;
	  HUD.y=0;
	  SDL_BlitSurface(coeur2, NULL, ecran, &HUD);
	  HUD.x=850;
	  SDL_BlitSurface(coeur2, NULL, ecran, &HUD);
	  HUD.x=800;
	  SDL_BlitSurface(coeur2, NULL, ecran, &HUD);
	}
      if (keys == 1)
	{
	  HUD.x=50;
	  HUD.y=0;
	  SDL_BlitSurface(hudkey, NULL, ecran, &HUD);
	  
	}
	
	

      /* update the screen */
      SDL_UpdateRect(ecran,0,0,0,0);
	
      temp   = SDL_LoadBMP("sprite.bmp");
      sprite = SDL_DisplayFormat(temp);
      SDL_FreeSurface(temp);
	
      if (
	  (collisionmob(spritePosition.x ,spritePosition.y ,mobPosition.x,mobPosition.y)==1)
	|(collisionmob(spritePosition.x ,spritePosition.y ,mobPosition1.x,mobPosition1.y)==1)
	|(collisionmob(spritePosition.x ,spritePosition.y ,mobPosition2.x,mobPosition2.y)==1))
      {
	vie -= 1;
	newmap = 1;
      }
	
      if (map[spritePosition.x][spritePosition.y+5]==3){
	keys = 1;
	  
      }
	
      if ((map[spritePosition.x][spritePosition.y+5]==2) & (keys == 1)){
	if ((level ==3) )
	  {
	    gameover=1;
	  }
	level+=1;
	newmap=1;


	
      }
      if (vie == 0 )
      {
	gameover =1;
      }
    }


  /* Libération des pointeurs */
  SDL_FreeSurface(key);
  SDL_FreeSurface(ladder);
  SDL_FreeSurface(grass);
  SDL_FreeSurface(door);
  SDL_FreeSurface(doorclose);
  SDL_FreeSurface(castle);
  SDL_FreeSurface(coeur);
  SDL_FreeSurface(coeur2);
  SDL_FreeSurface(sprite);
  SDL_Quit();

  return 0;
}
