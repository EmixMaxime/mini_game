#include "click.h"
#include "variables.h"
#include <stdbool.h>
#include <stdlib.h> // pour le exit
#include <stdio.h> // Défini le stderr / fprintf

/**
 * Je donne un x,y et une Zone définie, il me retourne true si (x,y) appartiennent à cette zone
 * Pratique pour les événements souris ectect
 * @param  x    
 * @param  y    
 * @param  zone la zone où je veux vérifier que mon x,y soit dedans
 * @return      
 */
bool isClicableZone (int x, int y, Zone zone) {
  // J'ignore les x du zone.bottom
  if ( (y >= zone.top.y && y <= zone.bottom.y) && x >= zone.top.x1 && x <= zone.top.x2) {
  	printf("Good click (%d, %d) \n", x, y);
    return true;
  }

  return false;
}

/**
 * Je donne une zone, il me la remplie grâce à x1,x2 y1,y2
 * @param  zone [description]
 * @return      [description]
 */
// void * createClicableZone (Zone *zone) {
//     // Ca part du x1 de la première colonne au x2 de la dernière colonne
//     int x1 = GRID_POSITION_X;
//     int x2 = GRID_POSITION_X + CLICABLE_WIDTH;

//     (*zone).top.x1 = x1;
//     (*zone).top.x2 = x2;
//     (*zone).top.y = CLICABLE_Y1;

//     (*zone).bottom.x1 = x1;
//     (*zone).bottom.x1 = x2;
//     (*zone).bottom.y = CLICABLE_Y2;

//     // printf("Information sur la zone clicable \n");
//     // printf("top : x1 = %d x2 = %d y = %d \n", x1, x2, (*zone).top.y);
//     // printf("bottom : x1 = %d x2 = %d y = %d \n", x1, x2, (*zone).bottom.y);
    
//     return zone;
// }

void createClicableZone (int x1, int x2, int y1, int y2, Zone *zone) {
  (*zone).top.x1 = x1;
  (*zone).top.x2 = x2;
  (*zone).top.y = y1;

  (*zone).bottom.x1 = x1;
  (*zone).bottom.x1 = x2;
  (*zone).bottom.y = y2;
}
