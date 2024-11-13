#include "chapter2.h"

int fibo_recur(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return (fibo_recur(n - 1) + fibo_recur(n - 2));
}

int fibo_iter(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;

	int n1 = 0, n2 = 1, result = 0;
	for (int i = 2; i <= n; i++) {
		result = n1 + n2;
		n1 = n2;
		n2 = result;
	}
	return result;
}