#include <stdbool.h>
#include <SDL/SDL.h>

// Ça nous permet d'utiliser le type Columns sans le mot clef "struct"
typedef struct Columns Columns;

/**
 * DEFINITION À METTRE, MAIS JE FATIGUE : I NEED COFFEEEEEEEEEEE
 */
struct Columns {
	int x1; // beginning
	int x2; // end
	int number;
};

/**
 * Permet de créer une nouvelle structure de donnés contenant les informations à propos nos colonnes sur notre grille.
 * x1 = le début de la colonne, x2 = la fin. Très pratique pour aligner correctement les jetons lors du clique dans une zone :-)
 * @return [description]
 */
void * fillColumns (Columns columns[]);

void printColumns (Columns columns[], SDL_Surface *window);