#include <stdio.h>
#include "chapter2.h"

int main(void) {
	int n = 0;
	double f = 0;

	n = factorial_recur(4); printf("factorial_recur(4)\t%d\n", n);
	n = factorial_iter(4); printf("factorial_iter(4)\t%d\n", n);
	
	n = sub_recur(10); printf("sub_recur(10)\t%d\n", n);
	n = sub_iter(10); printf("sub_iter(10)\t%d\n", n);
	
	n = power_recur(2, 7); printf("power_recur(2, 7)\t%d\n", n);
	n = power_iter(2, 7); printf("power_iter(2, 7)\t%d\n", n);
	
	n = fibo_recur(6); printf("fibo_recur(6)\t%d\n", n);
	n = fibo_iter(6); printf("fibo_iter(6)\t%d\n", n);
	
	hanoiTower(4, 'A', 'B', 'C');

	n = sum1(10); printf("sum1(10)\t%d\n", n);
	f = sum2(3); printf("sum2(3)\t\t%lf\n", f);
	
	n = binomialCoefficient(5, 2); printf("binomialCoefficient(5, 2)\t%d\n", n);
	
	n = ackermann_recur(1, 2); printf("ackermann_recur(1, 2)\t%d\n", n);
	n = ackermann_recur(3, 3); printf("ackermann_recur(3, 3)\t%d\n", n);

	n = ackermann_recur(2, 3); printf("ackermann_recur(1, 2)\t%d\n", n);

	return 0;
}