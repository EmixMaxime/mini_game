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
 * buildWindow  Cr�ation / "customisation" et ouverture de la fen�tre
 * @return Un pointeur sur la fen�tre de type SDL_Surface
 */
void * buildWindow (char windowTitle[]) {

  // <!> Doit �tre effecut� avant ouverture de la fen�tre. Ajout de l'ic�ne, NULL = pas de transparence
  SDL_WM_SetIcon(SDL_LoadBMP("icone.bmp"), NULL);

  /**
   * SDL_SetVideoMode = ouvre la fen�tre (c'est en m�moire, en r�aliter c'est cr�ation de la fen�tre)
   * 32 = le nb de bits pour coder les couleurs
   * SDL_DOUBLEBUF = on bufferise les formes g�om�triques avant de les envoyer sur l'�cran (gr�ce au SDL_Flip)
   * ainsi l'utilisateur n'a aucune g�ne li� au travaille sur ces formes.
   */
  SDL_Surface *window = SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

  if (window == NULL) {
    fprintf(stderr, "Impossible de charger le mode vid�o : %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  // Nom de la fen�tre, Nom de l'ic�ne (nous sommes oblig� d'envoyer NULL en c)
  SDL_WM_SetCaption(windowTitle, NULL);

  // window->format r�cup�re le nb de bits d�fini pour coder nos couleurs (ici 32 parce qu'on a un sp�cimen qui a un �cran 4K)
  Uint32 white = SDL_MapRGB(window->format, 255, 255, 255);

  // SDL_FillRect = permet de colorer une surface avec une couleur unie.
  // �a tombe bien, window est de type SDL_Surface !
  // Pourquoi ce NULL en 2e param? Parce qu'on souhaite colorer TOUTE la surface
  SDL_FillRect(window, NULL, white);


  SDL_Flip(window); // Mise � jour de l'�cran (on applique nos modifications faite en m�moire sur l'�cran)


  return window;
}

void * buildGrid (SDL_Surface *window) {
  SDL_Surface *imageDeFond = SDL_LoadBMP("grille.bmp");
  SDL_Rect positionFond;

  positionFond.x = GRID_POSITION_X;
  positionFond.y = 0;

  // Permet de blitter une surface, c'est � dire la coller � l'�cran
  // Quoi coller ? Partiellement ? (NULL = FULL), *O� (il attend un pointeur, donc on envoie l'adresse) ? Et les coordonn�ss stock�s dans une variable de type SDL_Rect
  SDL_BlitSurface(imageDeFond, NULL, window, &positionFond);

  return imageDeFond;
}

int main (int argc, char *argv[]) {

  // La premi�re chose � faire : initialiser SDL
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
   * Cr�ation / placement des jetons de base
   */
  SDL_Rect positionPionJaune, positionPionRouge;
  positionPionJaune.x = 0; positionPionJaune.y = 0;
  positionPionRouge.x = 0; positionPionRouge.y = 0;

  SDL_Surface *pionDeJeuRouge = creerBaseJeton(false, window, positionPionRouge);
  SDL_Surface *pionDeJeuJaune = creerBaseJeton(true, window, positionPionJaune);

  bool typeJeton = true; // Par d�faut c'est le jeton jaune

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

    // Comme notre surface a �t� allou�e manuellement
    SDL_FreeSurface(pionDeJeuJaune);
    SDL_FreeSurface(pionDeJeuRouge);
    SDL_FreeSurface(imageDeFond);

    SDL_Quit();

    return EXIT_SUCCESS;
}


/* while(pas gagn� ou pas match nul){
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
