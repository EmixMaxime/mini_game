#ifndef CHECK_H
#define CHECK_H

#include <stdbool.h> // compilateur C99 : http://stackoverflow.com/questions/1921539/using-boolean-values-in-c
#include "variables.h"

/**
 * Vérifie sur l'axe des X si l'utilisateur a 4 jetons gagnés
 * @param  tokenType
 * @param  column    À partir de quelle colonne je vérifie ? (ex un jeton tombe sur la colonne n°2, alors je vérifie à partir de la n°2)
 * @return          True si l'utilisateur gagne, false si la partie continue
 */
bool checkHorizontal (int tokenType, int column, int line, int grid[COLUMNS_NUMBER][LINES_NUMBER]);

bool checkVertical (int tokenType, int column, int line, int grid[COLUMNS_NUMBER][LINES_NUMBER]);



#endif // CHECK_H