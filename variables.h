// Si vous voulez voir pourquoi je fais ça :
// Le problème : http://stackoverflow.com/questions/5430019/redefinition-errors-in-h-files
// la solution : https://en.wikipedia.org/wiki/Include_guard (merci wikipedia qui n'est pas toujours nul pour les sujet info)
#ifndef VARIABLES_H
#define VARIABLES_H

/**
 * Utilisation des defines :
 * Ce sont des directives de préprocesseur, elles ne prennent pas de place en mémoire!
 * (contrairement à const int lol = 1)
 */
#define LARGEUR_FENETRE 1280
#define HAUTEUR_FENETRE 720

// Largeur de la grille (l'image)
#define LARGEUR_FOND 739
#define COLUMNS_NUMBER 7

#define GRID_POSITION_X ((LARGEUR_FENETRE /2) - (LARGEUR_FOND /2))

#define COLUMN_WIDTH (LARGEUR_FOND / COLUMNS_NUMBER)

#define CLICABLE_WIDTH (COLUMN_WIDTH * COLUMNS_NUMBER)
#define CLICABLE_HEIGHT 70

#define CLICABLE_COLUMN_MARGIN 5 // les block de jetons sont espacé de 5px
// la grille a 10px left/right de padding (le font bleu)
#define GRID_PADDING 10
#define TOKEN_WIDTH 97

#define CLICABLE_Y1 0
#define CLICABLE_Y2 (CLICABLE_Y1 + CLICABLE_HEIGHT)

typedef struct Coordinates Coordinates;
struct Coordinates {
  int x;
  int y;
};

#endif // VARIABLES_H
