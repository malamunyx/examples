#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 * Given an array of integers, records the size, and length
 * of each tokem.
 * */

int main(void) {
	int arr[10] = {0, 1, 1, 0, 1, 1, 1, 0, 0, 1};

	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	int idx = 0;
	int len = 0;

	for (int i = 0; i < 10; i++) {
		if (arr[i]) { // If len is zero or 1, it does not matter, we increment from zero or 2.
			++len;
		} else if (len && !arr[i]) {
			printf("[index %d]\ttoken found: len(%d)\n", idx++, len);
			len = 0;
		}
	}

	if (len) {
		printf("[index %d]\ttoken found: len(%d)\n", idx, len);
	}

	return 0;
}
