#include <stdio.h>

int main() {
	int x = 5;
	int y = x + 1; // when optimized using -O2, this does not actually add 1 to
					// its value, but without it does print out 6
    printf("%d\n", y);
    return 0;
}
