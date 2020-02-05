//Author: Eric Minh Hanh Nguyen
//This program checks syntax by matching sure all parentheses, square brackets, and braces match...
//...while ignoring comments, quotes/double quotes, and escape sequences.
//This program requires the fileOpCl.h to be present and was tested valid on Visual Studio 2017
//Command Prompt Format: program.exe inputfile.txt outputfile.txt (optional int value)
//DISCLAIMER: Should any problem in testing ensue, author can provide testing on personal computer

#include "fileOpCl.h"

int main(int argc, const char * argv[]) {

	FILE * fin;
	FILE * fout;
	int n;
	int c;

	int lp, rp, ls, rs, lb, rb;
	lp = rp = ls = rs = lb = rb = 0;

	bool ok = openfiles(argc, argv, &fin, &fout, &n);

	if (ok == false) {

		return 0;

	}

	while ((c = fgetc(fin)) != EOF) {

		if (c == '\"') {

			c = fgetc(fin);
			if (c != EOF)
			{
				while (c != '\"')
				{
					if (c == '\\') {

						c = fgetc(fin);

					}
					c = fgetc(fin);
				}
			}
		}
		else if (c == '\'') {

			c = fgetc(fin);
			if (c != EOF)
			{
				while (c != '\'')
				{
					if (c == '\\') {

						c = fgetc(fin);

					}
					c = fgetc(fin);
				}
			}
		}
		else if (c == '/') {

			c = fgetc(fin);
			if (c != EOF && c == '/') {

				while (c != '\n' && c != EOF) {
					c = fgetc(fin);
				}
			}
			else if (c != EOF && c == '*') {

				while (c != '/' && c != EOF) {
					c = fgetc(fin);
				}
			}
		}
		else {

			if (c == '(') { lp++; }
			else if (c == ')') { rp++; }
			else if (c == '[') { ls++; }
			else if (c == ']') { rs++; }
			else if (c == '{') { lb++; fputc(c, fout); }
			else if (c == '}') { rb++; fputc(c, fout); }
		}
	}

	printf("\n%d left parentheses, %d right parentheses\n", lp, rp);
	printf("%dleft square brackets, %d right square brackets\n", ls, rs);
	printf("%d left braces, %d right braces\n", lb, rb);

	if (lp == rp && ls == rs && lb == rb)
	{
		printf("\nValid Syntax\n");
	}

	closefiles(fin, fout);

	return 0;
}
