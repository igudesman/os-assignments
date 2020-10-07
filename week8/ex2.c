#include <stdlib.h>
#include <string.h>
/*
As we can see in the column si when the operating system needs data from the disk, 
it exchanges a portion of data in main memory with a portion of data on the disk.
*/
void alloc(int delay) {
	unsigned long long size = 1024 * 1024 * 10;
	int i = 10;
	while (i > 0) {
		int* arr = (int *)malloc(size);
		memset(arr, 0, size);
		system("vmstat 1");
		sleep(delay);
		i--;
	}
}

int main() {
	alloc(1);
	return 0;
}