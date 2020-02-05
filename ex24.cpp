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

	printf("%d, %d, %d, %d, %d, %d\n", lp, rp, ls, rs, lb, rb);

	if (lp == rp && ls == rs && lb == rb)
	{
		printf("Valid Syntax\n");
	}

	closefiles(fin, fout);

	return 0;
}
