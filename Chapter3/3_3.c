#include "chapter3.h"

int matrix[MAX_ROWS][MAX_COLS];

void matrixTranspose(int a[ROWS][COLS], int b[COLS][ROWS]) {
	for (int r = 0; r < ROWS; r++)
		for (int c = 0; c < COLS; c++)
			b[c][r] = a[r][c];
}

void matrixPrint(int a[ROWS][COLS]) {
	printf("====================\n");
	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < COLS; c++)
			printf("%2d ", a[r][c]);
		printf("\n");
	}
	printf("====================\n");
}