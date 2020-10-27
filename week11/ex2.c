#include <stdio.h>
#include <unistd.h>
#include <string.h>


int main() {
    char buf[5];
    int m = setvbuf(stdout, buf, _IOLBF, 5*sizeof(char));

    printf("H");
    sleep(1);
    printf("e");
    sleep(1);
    printf("l");
    sleep(1);
    printf("l");
    sleep(1);
    printf("o");
    sleep(1);
    printf("\n");

    for (int i = 0; i < strlen(buf); i++) {
        printf("%c", (buf+i));
    }
    return 0;
}