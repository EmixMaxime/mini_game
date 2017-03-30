#include "click.h"
#include "variables.h"
#include <stdbool.h>
#include <stdlib.h> // pour le exit
#include <stdio.h> // Défini le stderr / fprintf

bool isClicableZone (int x, int y, Zone zone) {
  // Le y est comprit entre le y du top et y du bas
  if ( (y >= zone.top.y && y <= zone.bottom.y) && x >= zone.top.x1 && x <= zone.top.x2) {
  	printf("Good click (%d, %d) \n", x, y);
    return true;
  }

  // fprintf(stderr, "Le click (%d,%d) n'est pas dans la zone de 'clicabilitey", x, y);

  return false;
}

void * createClicableZone (Zone *zone) {
    // Ca part du x1 de la première colonne au x2 de la dernière colonne
    int x1 = GRID_POSITION_X;
    int x2 = GRID_POSITION_X + CLICABLE_WIDTH;

    (*zone).top.x1 = x1;
    (*zone).top.x2 = x2;
    (*zone).top.y = CLICABLE_Y1;

    (*zone).bottom.x1 = x1;
    (*zone).bottom.x1 = x2;
    (*zone).bottom.y = CLICABLE_Y2;

    // printf("Information sur la zone clicable \n");
    // printf("top : x1 = %d x2 = %d y = %d \n", x1, x2, (*zone).top.y);
    // printf("bottom : x1 = %d x2 = %d y = %d \n", x1, x2, (*zone).bottom.y);
    
    //fflush(stdout); // Prints to screen or whatever your standard out is


    return zone;
}
