#include "fileOpCl.h"

#define TABSPACE 8

int main(int argc, const char * argv[]) {

	FILE * fin;
	FILE * fout;
	int n;
	int c;

	int charCounter, modResult, blankCounter, tabCounter;
	charCounter = modResult = blankCounter = tabCounter =0;

	char carryOver;

	bool ok = openfiles(argc, argv, &fin, &fout, &n);

	while ((c = fgetc(fin)) != EOF) {

		if (c == ' ') {

			modResult = charCounter % TABSPACE;
			while (c == ' ') {

				modResult++;
				blankCounter++;
				c = fgetc(fin);
				charCounter++;

				if (c == '\n') {

					charCounter = -1;

				}

			}
			carryOver = c;

			tabCounter = modResult / TABSPACE;
			modResult = modResult % TABSPACE;

			if (tabCounter > 0) {

				while (tabCounter > 0) {

					fputc('\t', fout);
					tabCounter--;

				}

				while (modResult > 0) {

					fputc(' ', fout);
					modResult--;

				}

				blankCounter = 0;

			}
			else {

				while (blankCounter > 0) {

					fputc(' ', fout);
					blankCounter--;

				}

			}

			if (c != EOF) {
				fputc(carryOver, fout);
				charCounter++;
			}

		}
		else {

			if (c == '\n') {

				charCounter = -1;

			}

			fputc(c, fout);
			charCounter++;

		}

	}

	closefiles(fin, fout);

	return 0;
}
