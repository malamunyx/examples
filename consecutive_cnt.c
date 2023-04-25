#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 * Counts and records each run length of non-zero integers
 * */

int main(void) {
	int arr[20] = {14, 14, 14, 12, 11, 9, 8, 0, 0, 5, 5, 4, 4, 4, 0, 2, 2, 1, 1, 0};

	for (int i = 0; i < 20; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	int word_count = 0;
	int idx = 0;
	while (idx < 20) {
		int cursor = arr[idx];
		
		int rlen = 1;
		while ((++idx < 20) && (arr[idx] == cursor)) {
			++rlen;
		}

		if (cursor != 0) {
			printf("Product $%d:\t%d orders\n", cursor, rlen);
			++word_count;
		} 
	}

	printf("BUY Levels: %d\n", word_count);


	return 0;
}

