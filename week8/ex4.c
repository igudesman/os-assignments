#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>

int getrusage(int who, struct rusage*usage);


void alloc(int delay) {
	unsigned long long size = 1024 * 1024 * 10;
	struct rusage* memory = malloc(sizeof(struct rusage));
	while (1) {
		getrusage(RUSAGE_SELF, memory);
		int* arr = (int *)malloc(size);
		memset(arr, 0, size);
		printf("%ld\n", memory->ru_maxrss);
		sleep(delay);
	}
}

int main() {
	alloc(1);
	return 0;
}