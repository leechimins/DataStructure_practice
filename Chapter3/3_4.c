#include "chapter3.h"

SparseMatrix matrixTranspose2(SparseMatrix a) {
	SparseMatrix b;
	int bindex;
	b.rows = a.cols;
	b.cols = a.rows;
	b.terms = a.terms;

	if (a.terms > 0) {
		bindex = 0;
		for (int c = 0; c < a.cols; c++)
			for (int i = 0; i < a.terms; i++)
				if (a.data[i].col == c) {
					b.data[bindex].row = a.data[i].col;
					b.data[bindex].col = a.data[i].row;
					b.data[bindex].value = a.data[i].value;
					bindex++;
				}
	}
	return b;
}

void matrixPrint2(SparseMatrix a) {
	printf("====================\n");
	for (int i = 0; i < a.terms; i++)
		printf("(%2d, %2d, %2d)\n", a.data[i].row, a.data[i].col, a.data[i].value);
	printf("====================\n");
}