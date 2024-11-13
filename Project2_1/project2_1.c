#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define LV 5
#define WD 40
char screen[LV][WD];

void drawTree(int row, int left, int right);
void init();
void display();

int main(void) {
	init();
	drawTree(0, 0, WD);
	display();

	return 0;
}

void drawTree(int row, int left, int right) {
	if ((right - left) < 4) return;
	int mid = (right + left) / 2;
	screen[row][mid] = 'X';
	drawTree(row + 1, left, mid);
	drawTree(row + 1, mid, right);
}
void init() {
	for (int i = 0; i < LV; i++)
		for (int j = 0; j < WD; j++)
			screen[i][j] = '-';
}
void display() {
	for (int i = 0; i < LV; i++) {
		for (int j = 0; j < WD; j++)
			printf("%c", screen[i][j]);
		printf("\n");
	}
}