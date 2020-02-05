//Author: Eric Minh Hanh Nguyen
//This program folds input lines after the last nonblank character before the nth column of input...
//...with segments of blank characters not being folded.
//This program requires the fileOpCl.h to be present and was tested valid on Visual Studio 2017
//Command Prompt Format: program.exe inputfile.txt outputfile.txt (optional int value)
//DISCLAIMER: Should any problem in testing ensue, author can provide testing on personal computer

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
