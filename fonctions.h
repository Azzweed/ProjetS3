
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Constantes.h"

int collisionDroite(int posx , int posy , int map[][750]);       /* gere les collisions a droite du sprite (renvoit 1 si collision) */
int collisionGauche(int posx , int posy , int map[][750]);       /* gere les collisions a gauche du sprite (renvoit 1 si collision) */
int collisionHaut(int posx , int posy , int map[][750]);         /* gere les collisions au dessus du sprite (renvoit 1 si collision) */
int collisionBas(int posx , int posy , int map[][750]);          /* gere les collisions en dessous du sprite (renvoit 1 si collision) */