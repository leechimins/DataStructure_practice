#include "chapter3.h"

SparseMatrix addMatrix(SparseMatrix a, SparseMatrix b) {
	SparseMatrix result;
	int i = 0, j = 0, k = 0;
	while (i <= a.terms && j <= b.terms)
		if (isSamePos(a.data[i], b.data[j]) == 0) {
			result.data[k].row = a.data[i].row;
			result.data[k].col = a.data[i].col;
			result.data[k++].value = a.data[i++].value + b.data[j++].value;
		}
		else if (isSamePos(a.data[i], b.data[j]) > 0) {
			result.data[k].row = b.data[j].row;
			result.data[k].col = b.data[j].col;
			result.data[k++].value = b.data[j++].value;
		}
		else {
			result.data[k].row = a.data[i].row;
			result.data[k].col = a.data[i].col;
			result.data[k++].value = a.data[i++].value;
		}
	result.rows = k - 1;
	result.cols = k - 1;
	result.terms = k;

	return result;
}

int isSamePos(element x, element y) {
	if (x.row == y.row) {
		if (x.col == y.col) return 0;
		if (x.col > y.col) return 1;
		return -1;
	}
	if (x.row > y.row) return 2;
	return -2;
}