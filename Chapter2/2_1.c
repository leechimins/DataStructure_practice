#include "chapter2.h"

int factorial_recur(int n) {
	if (n <= 1) return 1;
	return (n * factorial_recur(n - 1));
}

int factorial_iter(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++)
		result *= i;
	return result;
}