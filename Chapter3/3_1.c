#include "chapter3.h"

void execute1() {
	polynomial x = { 2, { -7,0,2 } };
	polynomial y = { 2, { 7,5,-9 } };
	polynomial z;

	printPoly(x);
	printPoly(y);
	z = polyAdd1(x, y);
	printf("--------------------------------------------------\n");
	printPoly(z);
}

polynomial polyAdd1(polynomial a, polynomial b) {
	polynomial c;
	int aPos = 0, bPos = 0, cPos = 0;
	int degreeA = a.degree, degreeB = b.degree;
	c.degree = MAX(a.degree, b.degree);

	if (degreeA == degreeB) {
		double result = a.coef[aPos] + b.coef[bPos];
		if (-0.0001 < result && result < 0.0001) {
			c.degree--;
			degreeA--; degreeB--;
			aPos++; bPos++;
		}
	}

	while (aPos <= a.degree && bPos <= b.degree)
		if (degreeA > degreeB) {
			c.coef[cPos++] = a.coef[aPos++];
			degreeA--;
		}
		else if (degreeA == degreeB) {
			c.coef[cPos++] = a.coef[aPos++] + b.coef[bPos++];
			degreeA--; degreeB--;
		}
		else {
			c.coef[cPos++] = b.coef[bPos++];
			degreeB--;
		}
	return c;
}

void printPoly(polynomial p) {
	for (int i = p.degree; i > 0; i--) printf("%.1fx^%d + ", p.coef[p.degree - i], i);
	printf("%.1f\n", p.coef[p.degree]);
}