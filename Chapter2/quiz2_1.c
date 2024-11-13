#include "chapter2.h"

int sub_recur(int n) {
	if (n < 0) return 0;
	return n + sub_recur(n - 3);
}

int sub_iter(int n) {
	int result = 0;
	for (int i = n; i > 0; i -= 3)
		result += i;
	return result;
}