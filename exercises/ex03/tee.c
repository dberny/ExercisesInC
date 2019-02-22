/* Diego Berny - SoftSys Ex03

3. Opening the file to add to it worked fairly easily.
However, figuring out how to call the command line arguments correctly took a solid while.
Also I really have no idea how the -p flag is supposed to work.
If I were to do it again I would probably make the function more robust and
reusable to allow for better piping with other functions.

4. There seems to be a lot more error checking and other extraneous stuff going
on in their code. A lot of it is fairly difficult to parse.

*/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

	char ch;
	int append = 0;
	int diagnose = 0;

	while ((ch = getopt(argc, argv, "ap")) != EOF) {
		switch(ch) {
			case 'a':
				append = 1;
				break;
			case 'p':
				diagnose = 1;
				break;
		}
	}
	argc += optind;
	argv += optind;

	/* This opens the file in append more or write mode,
	depending on whether the flag was set or not */
	FILE *file;
	char *filename = argv[0];
	if (append) {
		if (!(file = fopen(filename, "a"))) {
			fprintf(stderr, "Can't open the append file\n");
			return -1;
		}
	}
	else {
		if (!(file = fopen(filename, "w"))) {
			fprintf(stderr, "Can't open the write file\n");
			return -1;
		}
	}

	if (diagnose) {
		printf("pipe thing\n");
	}

	char buffer[80];
	fgets(buffer, 80, stdin);
	fprintf(file, "%s", buffer);


	return 0;
}
