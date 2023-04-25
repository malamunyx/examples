#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
	//int arr[20] = {0, 1, 1, 2, 2, 0, 1, 1, 3, 3, 3, 0, 0, 1, 1, 1, 2, 3, 3, 3}; 
	//int arr[20] = {0, 1, 1, 2, 2, 0, 4, 4, 4, 5, 5, 0, 0, 8, 9, 11, 12, 14, 14, 14}; 
	int arr[20] = {14, 14, 14, 12, 11, 9, 8, 0, 0, 5, 5, 4, 4, 4, 0, 2, 2, 1, 1, 0};

	for (int i = 0; i < 20; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");


	/* 
	 * THIS IS A BETTER TOKEN COUNTER.
	 * - IT DOES NOT INCLUDE WORD INCONSISTENCIES
	 * - ARRAY SIZE REMAINS CONSISTENT
	 * */
	
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
		} //else {
			//printf("Zero Runlen:\t%d\n", rlen);
		//}
	}

	printf("BUY Levels: %d\n", word_count);


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
