#include <stdio.h>
#include <stdlib.h>


void print_arr(int *arr, int size) {
	for (int i=0; i<size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}


int main() {
	int N;
	scanf("%d", &N);

	int *arr = calloc(N, sizeof(int));
	// checking that arr is not NULL
	if (arr == NULL) {
		return 0;
	}
	// filling arr with incrementing values starting from 0
	for (int i=0; i<N; i++) {
		arr[i] = i;
	}
	print_arr(arr, N);
	// deallocating memory for arr
	free(arr);
	return 0;
}