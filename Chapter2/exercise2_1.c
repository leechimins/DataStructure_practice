#include <stdio.h>
#include "chapter2.h"

int sum1(int n) {
	if (n == 1) return 1;
	return n + sum1(n - 1);
}

double sum2(int n) {
	if (n == 1) return 1.0;
	return ((1.0 / n) + sum2(n - 1));
}

int binomialCoefficient(int n, int k) {
	if (k == 0 || k == n) return 1;
	return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
}

int ackermann_recur(int m, int n) {
	if (m == 0) return n + 1;
	if (n == 0) return ackermann_recur(m - 1, 1);
	return ackermann_recur(m - 1, ackermann_recur(m, n - 1));
}

int ackermann_iter(int m, int n) {
	return 0;
}