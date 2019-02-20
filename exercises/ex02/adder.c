#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* This function gets numbers from the user and stores them in an array
	nums: array of ints
	count: how many numbers have been input
*/
#define num_digits 10
#define num_inputs 30

void getNums(int* nums, int *count) {
	char num[num_digits];
	while (!feof(stdin)) {
		fgets(num, num_digits, stdin);
		if (strlen(num) > num_digits-2) {
			fprintf(stderr, "that number is too big!\n");
			exit(-1);
		}
		int val = atoi(num);
		if (val == 0) {
			fprintf(stderr, "that's not right\n");
			exit(-1);
		}
		nums[*count] = val;
		(*count)++;
		if (*count > num_inputs) {
			fprintf(stderr, "Error: Too many numbers! :(\n");
      		exit(-1);
		}
	}
}

int main() {
	int nums[num_inputs];
	int count = 0;
	getNums(nums, &count);
	int sum = 0;
	for (int i = 0; i < count-1; i++) {
		sum += nums[i];
	}
	printf("%d\n", sum);
	return 0;
}
