#include "chapter3.h"

polynomial2 terms[MAX_TERMS] = { {8,3}, {7,1}, {1,0}, {10,3}, {3,2}, {1,0} };
int avail = 6;

char compare(int a, int b) {
	if (a > b) return 1;
	else if (a == b) return 0;
	else return -1;
}

void attach(double coef, int expon) {
	if (avail > MAX_TERMS) { printf("항의 개수가 너무 많습니다.\n"); return; }
	terms[avail].coef = coef;
	terms[avail].expon = expon;
	avail++;
}

void polyAdd2(int aS, int aE, int bS, int bE, int* cS, int* cE) {
	double tempcoef;
	*cS = avail;

	while (aS <= aE && bS <= bE)
		switch (compare(terms[aS].expon, terms[bS].expon))
		{
		case 1:
			attach(terms[aS].coef, terms[aS].expon); aS++; break;
		case 0:
			tempcoef = terms[aS].coef + terms[bS].coef;
			if (tempcoef) attach(tempcoef, terms[aS].expon); aS++; bS++; break;
		case -1:
			attach(terms[bS].coef, terms[bS].expon); bS++; break;
		default:
			printf("error\n"); break;
		}
	while (aS++ <= aE) attach(terms[aS].coef, terms[aS].expon);
	while (bS++ <= bE) attach(terms[bS].coef, terms[bS].expon);

	*cE = avail - 1;
}

void printPoly2(int s, int e) {
	for (int i = s; i < e; i++) printf("%.1fx^%d + ", terms[i].coef, terms[i].expon);
	printf("%.1fx^%d\n", terms[e].coef, terms[e].expon);
}