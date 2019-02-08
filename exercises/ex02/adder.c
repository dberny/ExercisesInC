#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* This function gets numbers from the user and stores them in an array
	nums: array of ints
	count: how many numbers have been input
*/
void getNums(int* nums, int *count) {
	char num[10];
	while (!feof(stdin)) {
		fgets(num, 10, stdin);
		if (strlen(num) > 8) {
			fprintf(stderr, "that number is too big!\n");
			continue;
		}
		int val = atoi(num);
		if (val == 0) {
			fprintf(stderr, "that's not right\n");
		}
		nums[*count] = val;
		(*count)++;
		if (*count > 30) {
			fprintf(stderr, "Error: Too many numbers! :(\n");
      		exit(-1);
		}
	}
}

int main() {
	int nums[30];
	int count = 0;
	getNums(nums, &count);
	int sum = 0;
	for (int i = 0; i < count-1; i++) {
		sum += nums[i];
	}
	printf("%d\n", sum);
	return 0;
}
