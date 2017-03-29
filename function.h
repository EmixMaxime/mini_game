#include <stdbool.h>
#include <SDL/SDL.h>
/**
 *
 * @param type : Pour le jeton jaune = true, jeton rouge = false
 *
 */
void * creerBaseJeton (bool type, SDL_Surface *ecran, SDL_Rect positionPion);

void dupliquerJeton (SDL_Event event, SDL_Surface *ecran,  SDL_Surface *pionDeJeu, SDL_Rect positionPion);
