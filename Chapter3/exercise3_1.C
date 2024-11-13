#include "chapter3.h"

int insert(int arr[], int loc, int value) {
	if (++arr[0] >= 50) return -1;

	for (int i = loc + 1, tmp[2] = { arr[loc], arr[loc + 1] }; i <= arr[0] + 1; i++) {
		arr[i] = tmp[0];
		tmp[0] = tmp[1];
		tmp[1] = arr[i + 1];
	}
	arr[loc] = value;
	return 1;
}