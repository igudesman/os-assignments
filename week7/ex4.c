#include <stdlib.h>
#include <stdio.h>


void print_arr(void *arr, int size) {
	for (int i=0; i<size; i++) {
		printf("%d ", *((int*)(arr+i)));
	}
	printf("\n");
}


void *new_realloc(void* arr, int size, int current_size) {
	int *new_arr = malloc(size*sizeof(void*));
	if (arr == NULL) {
		return new_arr;
	}

	if (size == 0) {
		free(arr);
		return NULL;
	} else if (size > current_size) {
		//memcpy(new_arr, arr, size);
		for (int i=0; i<current_size; i++) {
			*(new_arr+i) = ((int*)arr)[i];
		}
		for (int i=current_size; i<size; i++) {
			new_arr[i] = (int*)NULL;
		}
	} else {
		//memcpy(new_arr, arr, size);
		for (int i=0; i<size; i++) {
			new_arr[i] = ((int*)arr)[i];
		}
	}
	free(arr);
	return new_arr;
}


int main() {
	int N = 5;
	int current_size = N;
	int *arr = malloc(N*sizeof(char));

	print_arr(arr, N);

	while (1) {
		current_size = N;
		printf("Enter new array size: ");
		scanf("%d", &N);

		arr = new_realloc(arr, N, current_size);
		print_arr(arr, N);
	}

	return 0;
}