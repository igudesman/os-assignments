#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char const *argv[]) {

	if(argc < 2) {
		printf("File path not mentioned\n");
		exit(0);
	}

	const char *filepath = argv[1];
	int fd = open("./ex1.txt", O_RDWR);

	if(fd < 0) {
		printf("\n\"%s \" could not open\n", filepath);
		exit(1);
	}

	struct stat statbuf;
	int err = fstat(fd, &statbuf);

	if(err < 0) {
		printf("\n\"%s \" could not open\n", filepath);
		exit(2);
	}


	char* text = "This is a good day";
	int textsize = strlen(text) + 1;
	ftruncate(fd, textsize);

	char *ptr = mmap(0, textsize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	for (size_t i = 0; i < textsize-1; i++) {
		ptr[i] = text[i];
	}
	ptr[textsize-1] = '\0';
	printf("%s\n", ptr);
	msync(ptr, textsize, MS_SYNC);
	munmap(ptr, textsize);

	close(fd);
	return 0;
}