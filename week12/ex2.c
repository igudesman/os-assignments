#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

// usage: ./ex2 -a file1 file2 ...

int append(int length, char *files[]) {



    int BUF_SIZE = 4096;

    ssize_t bytesRead, writeStatus;

    int inputFd, writeFd;
    char buffer[BUF_SIZE];

    memset(buffer, 0, sizeof(buffer));

    inputFd = 0;

    while ((bytesRead = read(inputFd, buffer, BUF_SIZE)) > 0) {
        fprintf(stdout, "%s", buffer);
        for (int i=0; i<length; i++) {
            FILE * new = fopen(files[i], "a");
            fprintf(new, "%s", buffer);
            fclose(new);
        }

        memset(buffer, 0, sizeof(buffer));
    }
    return 0;
}


int main(int argc, char *argv[]) {
    // Don't run anything if the filename isn't passed in via command line argument
    if (argc <= 1) {
        fprintf(stderr, "usage: %s [-a] [file...]\n", argv[0]);
        return 1;
    }

    char *file_names[argc];
    int files = 0;
    int executableOptions = -1;

    while ((executableOptions = getopt(argc, argv, "a:")) != -1) {
        switch(executableOptions) {
            case 'a':
                break;
            default:
                fprintf(stderr, "usage: %s [-a] [file...]\n", argv[0]);
                return 1;
        }
    }

    int count = 0;
    while (strcmp(argv[count], "-a") != 0) {
        count++;
    }
    count++;

    files = argc - count;

    for (int i=0; i<files; i++) {
        file_names[i] = argv[i+count];
    }

    append(files, file_names);

    return 0;
}