#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX(a, b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101
#define MAX_TERMS 101
#define MAX_ROWS 100
#define MAX_COLS 100
#define ROWS 3
#define COLS 3

//! 3_1
typedef struct {
	int degree;
	double coef[MAX_DEGREE];
} polynomial;

void execute1();
polynomial polyAdd1(polynomial a, polynomial b);
void printPoly(polynomial p);

//! 3_2
typedef struct {
	double coef;
	int expon;
} polynomial2;

char compare(int a, int b);
void attach(double coef, int expon);
void polyAdd2(int aS, int aE, int bS, int bE, int* cS, int* cE);
void printPoly2(int s, int e);

//! 3_3
void matrixTranspose(int a[ROWS][COLS], int b[COLS][ROWS]);
void matrixPrint(int a[ROWS][COLS]);

//! 3_4
typedef struct {
	int row;
	int col;
	int value;
} element;

typedef struct {
	element data[MAX_TERMS];
	int rows;
	int cols;
	int terms;
} SparseMatrix;
SparseMatrix matrixTranspose2(SparseMatrix a);
void matrixPrint2(SparseMatrix a);

//! quiz3_1
SparseMatrix addMatrix(SparseMatrix a, SparseMatrix b);
int isSamePos(element x, element y);

//! exercise3_1
int insert(int arr[], int loc, int value);