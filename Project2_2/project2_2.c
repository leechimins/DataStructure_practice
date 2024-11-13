#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int screen[10][10] = { { 2,2,2,2,2,2,2,2,2,2 }, { 2,2,2,0,0,0,0,2,2,2 },
					{ 2,2,2,2,0,0,0,2,2,2 }, { 2,2,2,2,0,0,0,2,2,2 },
					{ 2,2,2,2,0,0,0,0,2,2 }, { 2,2,2,2,0,2,2,2,2,2 },
					{ 2,2,2,2,0,2,2,2,2,2 }, { 2,2,2,2,0,2,2,2,2,2 },
					{ 2,2,2,2,2,2,2,2,2,2 }, { 2,2,2,2,2,2,2,2,2,2 } };

int readPixel(int x, int y);
void writePixel(int x, int y, int color);
void fill(int x, int y);
void printPixel();

int main(void) {
	printPixel();
	printf("\n");
	fill(4, 4);
	printPixel();

	return 0;
}
int readPixel(int x, int y) { return screen[x][y]; }
void writePixel(int x, int y, int color) { screen[x][y] = color; }
void fill(int x, int y) {
	if (readPixel(x, y) == 0) {
		writePixel(x, y, 1);
		fill(x + 1, y);
		fill(x - 1, y);
		fill(x, y + 1);
		fill(x, y - 1);
	}
}
void printPixel() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			printf("%d ", screen[i][j]);
		printf("\n");
	}
}