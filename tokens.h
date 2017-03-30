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

void dupliquerJeton (SDL_Event event, SDL_Surface *window,  SDL_Surface *token, SDL_Rect positionToken, Zone zone, Columns columns[], int grid[COLUMNS_NUMBER][LINES_NUMBER]);

/**
 * 
 * @param  columnNumber La colonne où l'utilisateur souhaite insérer son jeton
 * @param  tokenType    Le type du jeton à insérer (0 ou 1)    
 * @param  grid         La grille de jeu (rappel: grid est un pointeur, équivalent : int* grid)
 * @return              Le numéro de la ligne où le jeton est tombé
 * 
 */
int putToken (int columnNumber, int tokenType, int grid[COLUMNS_NUMBER][LINES_NUMBER]);

#endif // TOKENS_H
