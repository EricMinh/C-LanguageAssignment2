#include "fileOpCl.h"

int main(int argc, const char * argv[]) {

	FILE * fin;
	FILE * fout;
	int n;
	int c;

	int charCounter, spacePos, spacePrint;
	charCounter = spacePos = spacePrint = 0;

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
