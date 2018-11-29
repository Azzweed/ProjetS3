#include <stdio.h>
#include <stdlib.h>


#include "Constantes.h"
#include "fonctions.h"


int collisionDroite(int posx , int posy , int map[][750])        
{
  if ((map[posx+35][posy+1]==1) | (map[posx+35][posy+49]==1))
  {
    return 1;
  } 
  return 0;
}



int collisionGauche(int posx , int posy , int map[][750])         
{
  
  if ((map[posx][posy+1]==1) | (map[posx][posy+49]==1))
  {
    return 1;
  } 
  return 0;
}


int collisionHaut(int posx , int posy , int map[][750])
{
  if ((map[posx][posy]==1) | (map[posx+35][posy]==1))
  {
    return 1;
  }
  return 0;
  
}

int collisionBas(int posx , int posy , int map[][750])
{
  if ((map[posx][posy+51]==1) | (map[posx+35][posy+51]==1))
  {
    return 1;
  }
  return 0;
  
}

int mouvementmob(int posx , int posy , int map[][750] , int direction)
{
  if ((collisionGauche(posx-1 , posy,map)==0) & (direction == 0))
  {
    return -1;
  }
  
  if ((collisionDroite(posx+16,posy,map)==0) & (direction == 1))
  {
    return 1;
  }
  
  return 0;
  
}






























