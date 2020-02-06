//Author: Eric Minh Hanh Nguyen
//This program removes tabs and replaces them with spaces that take up the exact space used by said tabs
//This program requires the fileOpCl.h to be present and was tested valid on Visual Studio 2017
//Command Prompt Format: program.exe inputfile.txt outputfile.txt (optional int value)
//DISCLAIMER: Should any problem in testing ensue, author can provide testing on personal computer

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
	
	if (ok == false) {
		
		return 0;
		
	}

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
