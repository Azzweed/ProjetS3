
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Constantes.h"

int collisionDroite(int posx , int posy , int map[][750]);       /* gere les collisions a droite du sprite (renvoit 1 si collision) */
int collisionGauche(int posx , int posy , int map[][750]);       /* gere les collisions a gauche du sprite (renvoit 1 si collision) */
int collisionHaut(int posx , int posy , int map[][750]);         /* gere les collisions au dessus du sprite (renvoit 1 si collision) */
int collisionBas(int posx , int posy , int map[][750]);          /* gere les collisions en dessous du sprite (renvoit 1 si collision) */

int mouvementmob(int posx , int posy , int map[][750] , int direction); 	 /* gere le deplacement des monstres (retourne 1 ou -1 selon la direction que le monstre doit prendre)
								            les monstres font des deplacements droite/gauche seulement , retourne 0 si la direction doit changer)*/
								         
int collisionmob(int posx ,int posy ,int posxmob ,int posymob);     /*revoit 1 si le personnage entre en contact avec un monstre , renvoit 0 sinon */