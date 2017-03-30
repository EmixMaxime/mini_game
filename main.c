#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL/SDL.h>

#include "columns.h"
#include "variables.h"
#include "click.h"
#include "tokens.h"

#include <SDL/SDL_mixer.h>

/**
 * buildWindow  Création / "customisation" et ouverture de la fenêtre
 * @return Un pointeur sur la fenêtre de type SDL_Surface
 */
void * buildWindow (char windowTitle[]) {

  // <!> Doit être effecuté avant ouverture de la fenêtre. Ajout de l'icône, NULL = pas de transparence
  SDL_WM_SetIcon(SDL_LoadBMP("icone.bmp"), NULL);

  /**
   * SDL_SetVideoMode = ouvre la fenêtre (c'est en mémoire, en réaliter c'est création de la fenêtre)
   * 32 = le nb de bits pour coder les couleurs
   * SDL_DOUBLEBUF = on bufferise les formes géométriques avant de les envoyer sur l'écran (grâce au SDL_Flip)
   * ainsi l'utilisateur n'a aucune gêne lié au travaille sur ces formes.
   */
  SDL_Surface *window = SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

  if (window == NULL) {
    fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  // Nom de la fenêtre, Nom de l'icône (nous sommes obligé d'envoyer NULL en c)
  SDL_WM_SetCaption(windowTitle, NULL);

  // window->format récupère le nb de bits défini pour coder nos couleurs (ici 32 parce qu'on a un spécimen qui a un écran 4K)
  Uint32 white = SDL_MapRGB(window->format, 255, 255, 255);

  // SDL_FillRect = permet de colorer une surface avec une couleur unie.
  // Ça tombe bien, window est de type SDL_Surface !
  // Pourquoi ce NULL en 2e param? Parce qu'on souhaite colorer TOUTE la surface
  SDL_FillRect(window, NULL, white);


  SDL_Flip(window); // Mise à jour de l'écran (on applique nos modifications faite en mémoire sur l'écran)


  return window;
}

void * buildGrid (SDL_Surface *window) {
  SDL_Surface *imageDeFond = SDL_LoadBMP("grille.bmp");
  SDL_Rect positionFond;

  positionFond.x = GRID_POSITION_X;
  positionFond.y = 0;

  // Permet de blitter une surface, c'est à dire la coller à l'écran
  // Quoi coller ? Partiellement ? (NULL = FULL), *Où (il attend un pointeur, donc on envoie l'adresse) ? Et les coordonnéss stockés dans une variable de type SDL_Rect
  SDL_BlitSurface(imageDeFond, NULL, window, &positionFond);

  return imageDeFond;
}

int main (int argc, char *argv[]) {

  // La première chose à faire : initialiser SDL
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_VIDEO) == -1) {
    fprintf(stderr, "Erreur d'initialisation de la SDL \n");
    exit(EXIT_FAILURE);
  }

  // Rappel : j'ai 7 colonnes de xxx pidels
  //
  SDL_Surface *window = buildWindow("Puissance 4");
  SDL_Surface *imageDeFond = buildGrid(window);

  Columns columns[COLUMNS_NUMBER];

  fillColumns(columns);
  printTermColumns(columns);
  printColumns(columns, window);

  Zone zone;
  createClicableZone(GRID_POSITION_X, GRID_POSITION_X + CLICABLE_WIDTH, CLICABLE_Y1, CLICABLE_Y2, &zone);

  int continuer = 1;

  SDL_Event event;

  /**
   * Création / placement des jetons de base
   */
  SDL_Rect positionPionJaune, positionPionRouge;
  positionPionJaune.x = 0; positionPionJaune.y = 0;
  positionPionRouge.x = 0; positionPionRouge.y = 0;

  SDL_Surface *pionDeJeuRouge = creerBaseJeton(false, window, positionPionRouge);
  SDL_Surface *pionDeJeuJaune = creerBaseJeton(true, window, positionPionJaune);

  bool typeJeton = true; // Par défaut c'est le jeton jaune

    while (continuer) {
        SDL_WaitEvent(&event);
        switch(event.type) {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym){
                    case SDLK_ESCAPE:
                        continuer = 0;
                        break;
                }
            // = clique
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT) {
                    SDL_Surface *pion = NULL;
                    SDL_Rect position;
                    if (typeJeton == true) {
                        pion = pionDeJeuJaune;
                        position = positionPionJaune;
                        typeJeton = false;
                    } else {
                        pion = pionDeJeuRouge;
                        position = positionPionRouge;
                        typeJeton = true;
                    }
                    dupliquerJeton(event, window, pion, position, zone, columns);
                }
                break;
        }
        //SDL_BlitSurface(pionDeJeu, NULL, ecran, &positionPion);
        SDL_Flip(window);
    }

    // Comme notre surface a été allouée manuellement
    SDL_FreeSurface(pionDeJeuJaune);
    SDL_FreeSurface(pionDeJeuRouge);
    SDL_FreeSurface(imageDeFond);

    SDL_Quit();

    return EXIT_SUCCESS;
}


/* while(pas gagné ou pas match nul){
    if(type==true){
        afficher pion jaune sur la gauche
        pouvoir deplacer pion jaune
        type = false;
    }else{
        affiche pion rouge sur la gauche
        pouvoir deplacer le pion rouge
        type = true;v
    }
}*/
