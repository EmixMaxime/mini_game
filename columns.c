#include "columns.h"
#include "variables.h"
#include "click.h"
#include <stdlib.h>
#include <stdio.h>

void * fillColumns (Columns columns[]) {
  int width = LARGEUR_FOND;

  int i;
  // Au tout début on part du début de la grille + le padding
  int x1 = GRID_POSITION_X + GRID_PADDING;

  for (i = 0; i < COLUMNS_NUMBER; i++) {
    x1 = x1 + CLICABLE_COLUMN_MARGIN;
    int x2 = x1 + TOKEN_WIDTH;
    Columns column = { x1, x2, i };
    columns[i] = column;
    // On met à jour le x1
    x1 = x2;
  }

  return columns;
}

void printTermColumns (Columns columns[]) {
  int i;

  for (i = 0; i < COLUMNS_NUMBER; i++) {
    printf("Info sur colonnes n°%d : x1 = %d x2 = %d \n", i, columns[i].x1, columns[i].x2);
  }
}

/**
 * Aide visuelle pour le développement
 * @param columns [description]
 * @param window  [description]
 */
void printColumns (Columns columns[], SDL_Surface *window) {
  int i;
  Uint32 white = SDL_MapRGB(window->format, 255, 255, 255);
  Uint32 black = SDL_MapRGB(window->format, 0, 0, 0);

  for (i = 0; i < COLUMNS_NUMBER; i++) {
    // SDL_HWSURFACE = allocation sur la mémoire vidéo (carte graphique 3D)
    // La largeur de la surface (en pixels), La hauteur de la surface (en pixels), Le nombre de couleurs (en bits / pixel), ...
    SDL_Surface *column = SDL_CreateRGBSurface(SDL_HWSURFACE, COLUMN_WIDTH, 100, 32, 0, 0, 0, 0);

    Uint32 color;

    /*
    if (i % 2 == 0) {
        color = black;
    } else {
        color = white;
    } */

    color = i % 2 == 0 ? white : black;

    SDL_FillRect(column, NULL, color);

    SDL_Rect cord;
    cord.x = columns[i].x1;
    cord.y = 0;

    SDL_BlitSurface(column, NULL, window, &cord);
  }
}

void * whereIsCord (int x, Columns columns[]) {
  int i = 0;

  for (i = 0; i < COLUMNS_NUMBER; i++) {
    if ( x >= columns[i].x1 && x <= columns[i].x2) {
      return &columns[i];
    }
  }
  
  return NULL;
}