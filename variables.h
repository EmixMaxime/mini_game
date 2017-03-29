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

#define GRID_POSITION_X ( (LARGEUR_FENETRE /2) - (LARGEUR_FOND /2) )

#define COLUMN_WIDTH (LARGEUR_FOND / COLUMNS_NUMBER)

typedef struct Coordinates Coordinates;
struct Coordinates {
  int x;
  int y;
};

typedef struct Zone Zone;
struct Zone {
	Coordinates top;
	Coordinates bottom;
};