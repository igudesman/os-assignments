#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
/*
Result for a 32-bit length count value:
	
	10 frames:
	HITS: 10
	MISSES: 991
	HIT RATIO: 0.009990
	MISS RATIO: 0.990010

	50 frames:
	HITS: 51
	MISSES: 950
	HIT RATIO: 0.050949
	MISS RATIO: 0.949051

	100 frames:
	HITS: 94
	MISSES: 907
	HIT RATIO: 0.093906
	MISS RATIO: 0.906094

*/


// shifting all bits and modifying the last referenced value
void modify_counters(int* arr, int* values, int size, int last_accessed) {
	for (int i=0; i<size; i++) {
		arr[i] = arr[i] >> 1;
		if (values[i] == last_accessed) {
			arr[i] |= (1 << 31); // where (31+1) is the number of bits in the count value
		}
	}
}

// checking if the incoming value is contained in the table
bool is_present(int* values, int new_value, int N) {
	for (int i=0; i<N; i++) {
		if (values[i] == new_value) {
			return true;
		}
	}
	return false;
}

// checking if there is a free room and returning its index if unoccupied cell exists and -1 otherwise  
int is_full(int *page_values, int N) {
	for (int i=0; i<N; i++) {
		if (page_values[i] == -1) {
			return i;
		}
	}
	return -1;
}

// searching for an element in the table with the smallest count value and replacing it with the incoming element
void swap(int* values, int* counters, int new_value, int N) {
	int min_index = 0;
	for (int i=0; i<N; i++) {
		if (counters[i] < counters[min_index]) {
			min_index = i;
		}
	}
	values[min_index] = new_value;
	counters[min_index] = 0;
}

int main() {
	int N; // the length of the table
	int hits = 0; // the total number of hits
	int misses = 0; // the total number of misses
	scanf("%d", &N);
	int* counters = (int *)calloc(N, sizeof(int)); // array with count values for each table element

	// initializing page table with -1 values
	int* page_values = (int *)calloc(N, sizeof(int));
	for (int i=0; i<N; i++) {
		page_values[i] = -1;
	}

	// reading integers from input.txt
	FILE* file = fopen("input.txt", "r");
	int page_reference;
	while(!feof(file)) {
		fscanf(file, "%d", &page_reference);
		if (is_present(page_values, page_reference, N)) {
			modify_counters(counters, page_values, N, page_reference);
			hits += 1;
		} else {
			// if there is at least one free room
			int index = is_full(page_values, N);
			if (index != -1) {
				page_values[index] = page_reference;
				modify_counters(counters, page_values, N, page_reference);
			//otherwise swap one of the element
			} else {
				swap(page_values, counters, page_reference, N);
				modify_counters(counters, page_values, N, page_reference);
			}
			misses += 1;
		}
	}

	printf("HITS: %d\n", hits);
	printf("MISSES: %d\n", misses);
	printf("HIT RATIO: %f\n", (float)hits / (misses+hits));
	printf("MISS RATIO: %f\n", (float)misses / (misses+hits));
	return 0;
}