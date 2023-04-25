#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
	int arr[20] = {0, 1, 1, 2, 2, 0, 1, 1, 3, 3, 3, 0, 0, 1, 1, 1, 2, 3, 3, 3}; 

	for (int i = 0; i < 20; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	/* 
	 * THIS IS A BETTER TOKEN COUNTER.
	 * - IT DOES NOT INCLUDE WORD INCONSISTENCIES
	 * - ARRAY SIZE REMAINS CONSISTENT
	 * */
	
	int word_cnt = 0;
	int prev = arr[0];
	int idx = 0;
	int len = 1;

	for (int i = 1; i < 20; i++) {
		if (prev == arr[i]) { // If len is zero or 1, it does not matter, we increment from zero or 2.
			++len;
		} else if (arr[i] != prev) {
			printf("index %d, word found: len(%d)\n", idx++, len);
			len = 1;
			++word_cnt;
		}
		prev = arr[i];
	}

	if (len) {
		printf("index %d, Word found: len(%d)\n", idx, len);
		++word_cnt;
	}

	printf("Word count: %d\n", word_cnt);


	return 0;
}


	/*
	int arr_tok[11];

	memcpy(arr_tok, arr, 10 * sizeof(int));
	arr_tok[10] = 0;

	int idx = 0;
	int is_one = 0;
	int len = 0;

	for (int i = 10; i >= 0; i--) {

		if (!is_one && arr_tok[i] == 1) {
			is_one = 1;
			len = 1;
		} else if (is_one && arr_tok[i] == 1) {
			++len;
		} else if (is_one && arr_tok[i] == 0) {
			printf("index %d, Word found: len(%d)\n", idx++, len);
			is_one = 0;
			len = 0;
		} 
	}
	if (is_one) {
		printf("Word found: len(%d)\n", len);
		is_one = 0;
		len = 0;
	}
	*/
