#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>


int main(int argc, char const *argv[]) {
    int src = open("ex1.txt", O_RDWR);

    struct stat statbuf;
    int err = fstat(src, &statbuf);

    char *s = mmap(0, statbuf.st_size, PROT_READ | PROT_WRITE | PROT_EXEC | PROT_NONE,
                             MAP_SHARED | MAP_ANONYMOUS, src, 0);
    int dest = open("ex1.memcpy.txt", O_RDWR | O_CREAT);
    ftruncate(dest, statbuf.st_size);
    char *d = mmap(0, statbuf.st_size, PROT_READ | PROT_WRITE | PROT_EXEC | PROT_NONE,
                             MAP_SHARED | MAP_ANONYMOUS, dest, 0);
    memcpy(d, s, statbuf.st_size);
    close(dest);
    close(src);
    return 0;
}