#include "variables.h"
#include "grid.h"

void initializeGrid (int grid[COLUMNS_NUMBER][LINES_NUMBER]) {
	int i; // Pour les column
	int j; // Pour les lines

	for (i = 0; i < COLUMNS_NUMBER; i++ ) {
		for (j = 0; j < LINES_NUMBER; j++) {
			grid[i][j] = 0;
		}
	}
}