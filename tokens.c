#include "tokens.h"
#include <SDL/SDL.h>
#include "variables.h"
#include "click.h"
#include <stdlib.h> // pour le exit
#include <stdio.h> // Défini le stderr / fprintf

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

void dupliquerJeton (SDL_Event event, SDL_Surface *window,  SDL_Surface *token, SDL_Rect positionToken, Zone zone, Columns columns[]) {

    int eventX = event.button.x;
    int eventY = event.button.y;

    bool okay = isClicableZone(eventX, eventY, zone);
    Columns *column = whereIsCord(eventX, columns);

    if (column == NULL) {
        return;
    }

    printf("J'ai cliqué dans la zone %d", (*column).number);
    int x1Zone = (*column).x1;
    int x2Zone = (*column).x2;
    int middle = x1Zone;
    printf(" (%d,%d) middle = %d \n", x1Zone, x2Zone, middle);

    // printf("OHHHHHHHHHHHHHHH \n");
    // fflush(stdout); // Prints to screen or whatever your standard out is

    if (okay) {
        positionToken.x = middle;
        // positionToken.y = 0 - ( token->h /2);
        positionToken.y = 0;

        SDL_BlitSurface(token, NULL, window, &positionToken);
    }
}

