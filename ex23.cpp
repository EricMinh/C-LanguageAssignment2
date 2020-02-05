//Author: Eric Minh Hanh Nguyen
//This program folds input lines after the last nonblank character before the nth column of input...
//...with segments of blank characters not being folded.
//This program requires the fileOpCl.h to be present and was tested valid on Visual Studio 2017
//Command Prompt Format: program.exe inputfile.txt outputfile.txt (optional int value)
//DISCLAIMER: Should any problem in testing ensue, author can provide testing on personal computer

#include "fileOpCl.h"

int main(int argc, const char * argv[]) {

	FILE * fin;
	FILE * fout;
	int n;
	int c;

	bool ok = openfiles(argc, argv, &fin, &fout, &n);

	if (ok == false) {

		return 0;

	}

	while ((c = fgetc(fin)) != EOF) {

		if (c == '\"') {

			fputc(c, fout);
			c = fgetc(fin);

			if (c != EOF)
			{
				fputc(c, fout);
				while (c != '\"')
				{
					if (c == '\\') {

						c = fgetc(fin);
						fputc(c, fout);

					}
					c = fgetc(fin);
					fputc(c, fout);
				}
			}

		}
		else if (c == '\'') {

			fputc(c, fout);
			c = fgetc(fin);
			if (c != EOF)
			{
				fputc(c, fout);
				while (c != '\'')
				{
					if (c == '\\') {

						c = fgetc(fin);
						fputc(c, fout);

					}
					c = fgetc(fin);
					fputc(c, fout);
				}
			}

		}
		else if (c == '/') {

			c = fgetc(fin);
			if (c != EOF && c == '/') {

				while (c != '\n' && c != EOF)
				{
					c = fgetc(fin);
				}

			}
			else if (c != EOF && c == '*') {

				while (c != '/' && c != EOF)
				{
					c = fgetc(fin);
				}

			}

		}
		else {

			fputc(c, fout);

		}


	}

	closefiles(fin, fout);

	return 0;
}
