#include "./function.h"
#include <SDL/SDL.h>

void * creerBaseJeton (bool type, SDL_Surface *ecran, SDL_Rect positionPion) {
    SDL_Surface *pionDeJeu = NULL;

    if(type == true){
        pionDeJeu = SDL_LoadBMP("jaune.bmp");
    } else {
        pionDeJeu = SDL_LoadBMP("rouge.bmp");
    }

    // Transparence du fond de l'image (le fond est toujours blanc)
    SDL_SetColorKey(pionDeJeu, SDL_SRCCOLORKEY, SDL_MapRGB(pionDeJeu->format, 255, 255, 255));
    
    // Affichage image
    SDL_BlitSurface(pionDeJeu, NULL, ecran, &positionPion);

    return pionDeJeu;
}

void dupliquerJeton (SDL_Event event, SDL_Surface *ecran,  SDL_Surface *pionDeJeu, SDL_Rect positionPion) {
    // Je vais avoir 7 colonnes avec les x debut/fin : 100 - 200
    // Si je clique dans 150 je suis dans colonne n°1 et je prends ses coordonnées en X !!
    positionPion.x = event.button.x - ( pionDeJeu->w /2);
    positionPion.y = event.button.y - ( pionDeJeu->h /2);

    SDL_BlitSurface(pionDeJeu, NULL, ecran, &positionPion);
    // SDL_Flip(ecran);
}

