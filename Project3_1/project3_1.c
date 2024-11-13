#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 10

void printDay(int day[], int month);
void makeArr(int arr[], int len);
void printArr(int arr[], int len);
void matrixDiff(int a[], int b[], int c[]);
int maxNum(int arr[], int len);
int minNum(int arr[], int len);
int search(int arr[], int len, int value);

int main(void) {
	srand(time(NULL));

	int day[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int i = 0; i < 12; i++) printDay(day, i);
	printf("\n");

	int a[LEN], b[LEN], c[LEN];
	makeArr(a, LEN); makeArr(b, LEN);
	matrixDiff(a, b, c);
	printArr(a, LEN); printArr(b, LEN); printArr(c, LEN);
	printf("\n");

	int max = maxNum(a, LEN), min = minNum(a, LEN);
	printf("최대값 : %d, 최소값 : %d\n\n", max, min);

	int find, pos; scanf("%d", &find);
	pos = search(a, LEN, find);
	printf("%d의 위치 : %d\n\n", find, pos);

	return 0;
}

void printDay(int day[], int month) { printf("%d월은 %d일까지 있습니다.\n", month, day[month]); }

void makeArr(int arr[], int len) { for (int i = 0; i < LEN; i++) arr[i] = rand() % 100 + 1; }

void printArr(int arr[], int len) {
	for (int i = 0; i < len; i++) printf("%3d ", arr[i]);
	printf("\n");
}

void matrixDiff(int a[], int b[], int c[]) { for (int i = 0; i < 10; i++) c[i] = a[i] - b[i]; }

int maxNum(int arr[], int len) {
	int max = arr[0];
	for (int i = 1; i < len; i++) if (max < arr[i]) max = arr[i];
	return max;
}
int minNum(int arr[], int len) {
	int min = arr[0];
	for (int i = 1; i < len; i++) if (min > arr[i]) min = arr[i];
	return min;
}

int search(int arr[], int len, int value) {
	for (int i = 0; i < len; i++) if (arr[i] == value) return i;
	return -1;
}