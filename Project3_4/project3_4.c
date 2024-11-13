#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_arr(int arr[][20]);
int check_arr(int arr[][20]);
void diraction(int move[], int dir);
int can_move(int pos[], int move[]);

int main(void) {
	srand(time(NULL));

	int tile[20][20] = { 0 };
	int dir = -1, maxMove = 1000, totalMove = 0, flag = 0;
	int pos[2] = { 10,10 }, move[2] = { 0,0 };

	while (++totalMove < maxMove) {
		dir = rand() % 8;
		diraction(move, dir);
		if (can_move(pos, move)) {
			pos[0] += move[0]; pos[1] += move[1];
			tile[pos[0]][pos[1]] = 1;
		}
		if (check_arr(tile)) { flag = 1; break; }
	}

	if (flag) printf("%d회만에 성공했습니다.\n", totalMove);
	else {
		print_arr(tile);
		printf("실패했습니다.\n");
	}


	return 0;
}

void print_arr(int arr[][20]) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++)
			if (arr[i][j]) printf("O ");
			else printf(". ");
		printf("\n");
	}
}

int check_arr(int arr[][20]) {
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			if (arr[i][j] == 0) return 0;
	return 1;
}

void diraction(int move[], int dir) {
	switch (dir)
	{
	case 0: case 1: case 7:
		move[1] = -1; break;
	case 3: case 4: case 5:
		move[1] = 1; break;
	case 2: case 6: default:
		move[1] = 0; break;
	}
	switch (dir)
	{
	case 5: case 6: case 7:
		move[0] = -1; break;
	case 1: case 2: case 3:
		move[0] = 1; break;
	case 0: case 4: default:
		move[0] = 0; break;
	}
}

int can_move(int pos[], int move[]) {
	if ((0 <= pos[0] + move[0] && pos[0] + move[0] < 20) && (0 <= pos[1] + move[1] && pos[1] + move[1] < 20))
		return 1;
	return 0;
}