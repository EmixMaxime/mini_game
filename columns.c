#include "columns.h"
#include "variables.h"

void * fillColumns (Columns columns[]) {
  int width = LARGEUR_FOND;

  int i;
  // Au tout début on part du début de la grille
  int x1 = GRID_POSITION_X;
  for (i = 0; i < COLUMNS_NUMBER; i++) {
    int x2 = x1 + COLUMN_WIDTH;
    Columns column = { x1, x2, i };
    columns[i] = column;
    // On met à jour le x1
    x1 = x2;
  }

  return columns;
}

void printColumns (Columns columns[], SDL_Surface *window) {
  int i;
  for (i = 0; i < COLUMNS_NUMBER; i++) {
    // SDL_HWSURFACE = allocation sur la mémoire vidéo (carte graphique 3D)
    // La largeur de la surface (en pixels), La hauteur de la surface (en pixels), Le nombre de couleurs (en bits / pixel), ...
    SDL_Surface *column = SDL_CreateRGBSurface(SDL_HWSURFACE, COLUMN_WIDTH, 100, 32, 0, 0, 0, 0);

    SDL_FillRect(column, NULL, SDL_MapRGB(column->format, 0, 0, 0));

    SDL_Rect cord;
    cord.x = columns[i].x1;
    cord.y = 0;

    SDL_BlitSurface(column, NULL, window, &cord);
  }
}