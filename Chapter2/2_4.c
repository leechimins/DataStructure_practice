#include <stdio.h>
#include "chapter2.h"

//! from�� �׿��ִ� n���� ������ tmp�� ����� to�� �ű��.
void hanoiTower(int n, char from, char tmp, char to) {
	if (n == 1) printf("01 : %c > %c\n", from, to);
	else {
		hanoiTower(n - 1, from, to, tmp);
		printf("%02d : %c > %c\n", n, from, to);
		hanoiTower(n - 1, tmp, from, to);
	}
}