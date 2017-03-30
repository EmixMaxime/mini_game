#ifndef TOKENS_H
#define TOKENS_H

#include <stdbool.h>
#include <SDL/SDL.h>
#include "variables.h"
#include "click.h"
#include "columns.h"

/**
 *
 * @param type : Pour le jeton jaune = true, jeton rouge = false
 *
 */
void * creerBaseJeton (bool type, SDL_Surface *ecran, SDL_Rect positionPion);

void dupliquerJeton (SDL_Event event, SDL_Surface *window,  SDL_Surface *token, SDL_Rect positionToken, Zone zone, Columns columns[]);

#endif // TOKENS_H
