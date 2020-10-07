#include <stdlib.h>
#include <string.h>

/*
In the ex3.txt we can see the usage of CPU 
and memory of ex2 process.
*/

void alloc() {
	unsigned long long size = 1024 * 1024 * 10;
	int i = 1;
	while (i > 0) {
		int* arr = (int *)malloc(size);
		memset(arr, 0, size);
		i--;
	}
}

int main() {
	alloc();
	return 0;
}