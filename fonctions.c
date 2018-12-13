#include <stdio.h>
#include <stdlib.h>


#include "Constantes.h"
#include "fonctions.h"


int collisionDroite(int posx , int posy , int map[][SCREEN_HEIGHT])        
{
  if ((map[posx+SPRITE_SIZE][posy+1]==1) | (map[posx+SPRITE_SIZE][posy+49]==1))
  {
    return 1;
  } 
  return 0;
}



int collisionGauche(int posx , int posy , int map[][SCREEN_HEIGHT])         
{
  
  if ((map[posx][posy+1]==1) | (map[posx][posy+49]==1))
  {
    return 1;
  } 
  return 0;
}


int collisionHaut(int posx , int posy , int map[][SCREEN_HEIGHT])
{
  if ((map[posx][posy]==1) | (map[posx+35][posy]==1))
  {
    return 1;
  }
  return 0;
  
}

int collisionBas(int posx , int posy , int map[][SCREEN_HEIGHT])
{
  if ((map[posx][posy+51]==1) | (map[posx+SPRITE_SIZE][posy+51]==1))
  {
    return 1;
  }
  return 0;
  
}

int mouvementmob(int posx , int posy , int map[][SCREEN_HEIGHT] , int direction)
{
  if ((collisionGauche(posx-1 , posy,map)==0) & (direction == 0) & (collisionGauche(posx-1 , posy+20,map)==1))
  {
    return -1;
  }
  
  if ((collisionDroite(posx+16,posy,map)==0) & (direction == 1) & (collisionDroite(posx+16 , posy+20,map)==1))
  {
    return 1;
  }
  
  return 0;
  
}



int collisionmob(int posx ,int posy ,int posxmob ,int posymob)
{
  if ((posx >= posxmob) & (posx <= posxmob+MOB_SIZE) & (posy >= posymob) & (posy <= posymob+MOB_SIZE))
  {
    
     return 1; 
     
  }
  
  
  if ((posx+35 >= posxmob) & (posx+35 <= posxmob+MOB_SIZE) & (posy >= posymob) & (posy <= posymob+MOB_SIZE))
    
    {
      return 1;  
    }
    
  
  
  if ((posx >= posxmob) & (posx <= posxmob+MOB_SIZE) & (posy+50 >= posymob) & (posy+50 <= posymob+MOB_SIZE))
    {
      return 1;  
    }
    
  
  
  if ((posx+35 >= posxmob) & (posx+35 <= posxmob+MOB_SIZE) & (posy+50 >= posymob) & (posy+50 <= posymob+MOB_SIZE))
    
    {
      return 1;  
    }
    
  
  return 0;

  
}






























