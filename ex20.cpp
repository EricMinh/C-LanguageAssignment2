#include "fileOpCl.h"

#define TABSPACE 8

int main(int argc, const char * argv[]) {

	FILE * fin;
	FILE * fout;
	int n;
	int c;

	int charCounter, modResult;
	charCounter = modResult = 0;

	bool ok = openfiles(argc, argv, &fin, &fout, &n);

	while ((c = fgetc(fin)) != EOF) {

		if (c == '\t') {

			modResult = charCounter % TABSPACE;
			modResult = TABSPACE - modResult;

			while (modResult > 0) {

				fputc(' ', fout);
				charCounter++;
				modResult--;

			}

		}
		else {

			fputc(c, fout);
			charCounter++;

		}

	}

	closefiles(fin, fout);

	return 0;
}
