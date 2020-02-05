#include "fileOpCl.h"
#include <ctype.h>

#define SPACESIZE 100

int main(int argc, const char * argv[]) {

	FILE * fin;
	FILE * fout;
	int n;
	int c;

	int charCounter, spacePos, spacePrint;
	charCounter = spacePos = spacePrint = 0;

	char spaceList[SPACESIZE];

	bool check;
	bool ok = openfiles(argc, argv, &fin, &fout, &n);

	if (ok == false) {

		return 0;

	}

	n--;
	while ((c = fgetc(fin)) != EOF) {

		if (isspace(c)) {

			while (isspace(c)) {

				charCounter++;
				spaceList[spacePos] = c;
				spacePos++;

				if (charCounter == n && check == true) {

					check = false;
					charCounter = 0;
					fputc('\n', fout);

				}
				else if (charCounter == n && check == false) {

					charCounter = 0;

				}
				
				c = fgetc(fin);
			}

			while (spacePrint < spacePos) {

				fputc(spaceList[spacePrint], fout);
				spacePrint++;

			}

			if (c != EOF) {

				check = true;
				charCounter++;
				fputc(c, fout);

				if (charCounter == n) {

					check = false;
					charCounter = 0;
					fputc('\n', fout);

				}

			}

		}
		else {

			check = true;
			charCounter++;
			fputc(c, fout);

			if (charCounter == n) {

				check = false;
				charCounter = 0;
				fputc('\n', fout);

			}

		}

	}

	closefiles(fin, fout);

	return 0;
}
