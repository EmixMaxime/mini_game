#include "check.h"
#include "variables.h"
#include <stdbool.h> // compilateur C99 : http://stackoverflow.com/questions/1921539/using-boolean-values-in-c
#include <stdlib.h>
#include <stdio.h>


int debugGrid (int grid[COLUMNS_NUMBER][LINES_NUMBER]) {
	int i; // for columns
	int j; // for lines
	for (j = 0; j < LINES_NUMBER; j++) {
    printf("|-------------|\n");
    printf("|");
		for (i = 0; i < COLUMNS_NUMBER; i++) {
			// printf("Column : %d, line : %d, value : %d", i, j, grid[i][j]);
      printf("%d", grid[i][j]);
      printf("|");
		}
    printf("\n");
	}
	printf("|-------------|\n");
	// printf("|-|-|-|-|-|-|\n");

}

bool checkHorizontal (int tokenType, int column, int line, int grid[COLUMNS_NUMBER][LINES_NUMBER]) {
	// vers la droite :
	int acc = 0; // MIND BLOWWWWWWWWWWWWWWWWWWWWWN

	int possibleTranslateRight = LAST_CASE_COLUMN - column;

	printf("Je suis à la colonne %d (et ligne %d), je peux partir de %d cases vers la droite pour vérifier les alignements \n", column, line, possibleTranslateRight);

	// On peut aller vers la droite
	if (possibleTranslateRight >= 1) {
		int k = 0;
		int analysCase = column + k;

		while (k < possibleTranslateRight && grid[analysCase][line] == tokenType) {
			acc++;
			k++;
			printf("Je suis à la ligne %d, j'analyse la colonne %d, le jeton sur cette ligne est de type : %d et mon jeton est de type %d. Le nb de jetons alignés augmente et passe à %d \n", line, analysCase, grid[analysCase][line], tokenType, acc);

			analysCase = column + k;
		}

	}

	// On peut et on doit aller à gauche
	if (acc < 4) {
		if (column > 0) {
			int k = 0;
			int analysCase = column - k;

			while (k > 0 && grid[analysCase][column] == tokenType) {
				acc++;
				k--;
				analysCase = column - k;
			}
		}
	}

	printf("Jetons alignés horizontalement %d \n", acc);

	if (acc == 4) {
		return true;
	}

	if (acc > 4) {
		printf("Oula, il y a plus de 4 jetons alignés (%d jetons), tu as dû foiré quelque pars! \n", acc);
	}

	return false;

}

bool checkVertical (int tokenType, int column, int line, int grid[COLUMNS_NUMBER][LINES_NUMBER]) {
	int acc = 1;

	// vers le bas
	int possibleTranslateTop = LAST_CASE_LINE - line;

	printf("Je suis à la ligne %d, je peux partir de %d cases vers le haut pour vérifier les alignements \n", line, possibleTranslateTop);

	// On peut aller vers le haut
	if (possibleTranslateTop >= 1) {
		int k = 0;
		int analysCase = line + k;

		while (k < possibleTranslateTop && grid[column][analysCase] == tokenType) {
			acc++;
			k++;
			printf("Je suis à la colonne %d, j'analyse la ligne %d, le jeton sur cette ligne est de type : %d et mon jeton est de type %d. Le nb de jetons alignés augmente et passe à %d \n", column, analysCase, grid[column][analysCase], tokenType, acc);

			analysCase = line + k;
		}
	}

	// vers le bas
	if (line > 0) {
		int k = 0;
		int analysCase = line - k;

		while (k > 0 && grid[column][analysCase] == tokenType) {
			acc++;
			k--;

			analysCase = line - k;
		}

	}

	printf("Jetons alignés veticalement %d \n", acc);

	if (acc == 4) {
		return true;
	}

	if (acc > 4) {
		printf("Oula, il y a plus de 4 jetons alignés (%d jetons), tu as dû foiré quelque pars! \n", acc);
	}

	return false;

}