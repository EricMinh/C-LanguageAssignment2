#include <stdio.h>
#include <stdlib.h>

bool openfiles(int argc, const char * argv[], FILE ** pfin, FILE ** pfout, int * n) {

	if (argc != 3 && argc != 4) {

		fprintf(stderr, "Usage: program.exe inputFile outputFile n");
		return false;
	}

	errno_t errIn = fopen_s(pfin, argv[1], "r");
	errno_t errOut = fopen_s(pfout, argv[2], "w");

	if (argc == 4) {

		*n = atoi(argv[3]);

	}
	else {

		*n = 8;

	}
	return true;

}

void closefiles(FILE * pfin, FILE * pfout) {

	fclose(pfin);
	fclose(pfout);

}
