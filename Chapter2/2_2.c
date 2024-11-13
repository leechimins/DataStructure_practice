#include "chapter2.h"

int power_recur(int x, int n) {
	if (n == 0) return 1;
	else if (n % 2 == 0) return power_recur(x * x, n / 2);
	else return x * power_recur(x * x, (n - 1) / 2);
}

int power_iter(int x, int n) {
	int result = x;
	while (n > 1) {
		result *= x;
		if (n % 2) result *= x;
		x *= x;
		n /= 2;
	}
	return result;
}