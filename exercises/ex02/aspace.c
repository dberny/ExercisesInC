/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>
void printvar ();

int var1;

int main ()
{
    int var2 = 5;
    void *p = malloc(128);
    char *s = "Hello, World";
	void *larger = malloc(128);
	void *rand = malloc(10);
	void *rand2 = malloc(10);

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("p points to %p\n", p);
    printf ("s points to %p\n", s);
	printf ("second malloc points to %p\n", larger);

	printf ("\nrand points to %p\n", rand);
	printf ("rand2 points to %p\n", rand2);


	printvar();
    return 0;
}

void printvar() {
	void *local = malloc(64);
	printf ("Address of local var is %p\n", local);
}
