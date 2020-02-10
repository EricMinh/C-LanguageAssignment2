//Author: Eric Minh Hanh Nguyen
//This program removes spaces and replaces them exactly with minimal tabs and spaces needed
//This program requires the fileOpCl.h to be present and was tested valid on Visual Studio 2017
//Command Prompt Format: program.exe inputfile.txt outputfile.txt (optional int value)
//DISCLAIMER: Should any problem in testing ensue, author can provide testing on personal computer

#include "fileOpCl.h"

#define TABSPACE 8

int main(int argc, const char * argv[]) {

	FILE * fin, * fout;
	int n, c, charCounter, modResult, blankCounter, tabCounter;
	charCounter = modResult = blankCounter = tabCounter = 0;

	char carryOver;

	bool ok = openfiles(argc, argv, &fin, &fout, &n);
	
	if (ok == false) { return 0; }

	while ((c = fgetc(fin)) != EOF) {

		if (c == ' ') {

			blankCounter = 0;
			modResult = charCounter % TABSPACE;
			charCounter++;

			while (c == ' ') {

				modResult++;
				blankCounter++;
				c = fgetc(fin);
				charCounter++;

				if (c == '\n') { charCounter = 0; }

			}
			carryOver = c;

			tabCounter = modResult / TABSPACE;
			modResult = modResult % TABSPACE;

			if (tabCounter > 0) {

				while (tabCounter-- > 0) { fputc('\t', fout); }
				while (modResult-- > 0) { fputc(' ', fout); }
				blankCounter = 0;

			}
			else { while (blankCounter-- > 0) { fputc(' ', fout); } }

			if (c != EOF) { fputc(carryOver, fout); }
		}
		else {

			fputc(c, fout);
			charCounter++;

			if (c == '\n') { charCounter = 0; }

		}

	}

	closefiles(fin, fout);

	return 0;
}
