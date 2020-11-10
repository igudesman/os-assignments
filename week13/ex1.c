#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool completed(int *A, int *C, int *R, int i, int n, int m) {

	for (int j=0; j<m; j++) {
		if (A[j] < R[i*m+j]) {
			return false;
		}
	}

	for (int j=0; j<m; j++) {
		A[j] += C[i*m+j];
	}

	return true;
}

int main() {

	FILE *fp;
	int n, m;
	fp = fopen("input.txt", "r");

	fscanf(fp, "%d", &n);
	fscanf(fp, "%d", &m);

	int *E = malloc(m * sizeof(int));
	int *A = malloc(m * sizeof(int));
	int *C = malloc(n*m * sizeof(int));
	int *R = malloc(n*m * sizeof(int));
	bool *states = malloc(n * sizeof(bool));

	for (int i=0; i<n; i++) {
		states[i] = false;
	}

	for (int i=0; i<m; i++) {
		fscanf(fp, "%d", (E+i));
	}

	for (int i=0; i<m; i++) {
		fscanf(fp, "%d", (A+i));
	}

	for (int i=0; i<n*m; i++) {
		fscanf(fp, "%d", (C+i));
	}

	for (int i=0; i<n*m; i++) {
		fscanf(fp, "%d", (R+i));
	}


	bool atLeastOneCompleted = true;

	while(atLeastOneCompleted) {
		atLeastOneCompleted = false;
		for (int i=0; i<n; i++) {
			if (states[i] == false  && completed(A, C, R, i, n, m)) {
				printf("Process %d completed\n", i);
				printf("Available: ");
				for (int j=0; j<m; j++) {
					printf("%d ", A[j]);
				}
				printf("\n");
				atLeastOneCompleted = true;
				states[i] = true;
			}
		}
	}

	bool allCompleted = true;
	for (int i=0; i<n; i++) {
		if (states[i]) {
			continue;
		}
		allCompleted = false;
		break;
	}

	printf("\nSUMMARY\n");

	if (allCompleted) {
		printf("%s\n", "No deadlock");
	} else {
		for (int i=0; i<n; i++) {
			if (!states[i]) {
				printf("Process %d is deadlocked\n", i);
			}
		}
	}
	fclose(fp);
	return 0;
}