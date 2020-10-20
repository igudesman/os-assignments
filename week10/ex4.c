#include <stdio.h>
#include <stdlib.h>

struct Record {
	char inode[10];
	int count;
	char names[10][10];
};

int main() {
	system("ls -i >> result.txt");
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	struct Record records[100];
	int empty = 0;

	fp = fopen("result.txt", "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, fp)) != -1) {
		// printf("Retrieved line of length %zu:\n", read);
		int i = 0;
		char inode[100];
		char name[100];
		while (line[i] != ' ') {
			inode[i] = line[i];
			i++;
		}
		i++;
		int k = 0;
		while (line[i] != '\0') {
			name[k] = line[i];
			k++;
			i++;
		}

		int status = 0;
		for (int j=0; j < empty; j++) {
			if (strcmp(inode, records[j].inode) == 0){
				records[j].count += 1;
				strcpy(records[j].names[records[j].count], name);
				status = 1;
				break;
			}
		}

		if (status != 1) {
			int in = 0;
			while (inode[in] != '\0') {
				records[empty].inode[in] = inode[in];
				in++;
			}
			records[empty].count = 0;
			strcpy(records[empty].names[records[empty].count], name);
			empty++; 
		}

		// printf("%s\n", inode);
		// printf("%s\n", name);
	}
	remove("result.txt");

	for (int z=0; z < 10; z++) {
		if (records[z].count != 0) {
			int r = 0;
			while (records[z].inode[r] != '\0') {
				printf("%c", records[z].inode[r]);
				r++;
			}
			printf(": \n");
			for (int l=0; l < 10; l++) {
				printf("%s", records[z].names[l]);
			}
		}
		printf("\n");
	}
}