#include <stdio.h>
int main() {

	FILE *orig, *cpy;
	char a;

	orig = fopen("Employee.txt", "r");
	cpy = fopen("File Copy.txt", "w");

     a = fgetc(orig);                                       //if we put input before fputc, the eof char would be printed once.
	while (a != EOF) {                                     //to prevent that, we take first value outside loop
          fputc (a, cpy);
          a = fgetc(orig);
	}

	fclose(orig);
	fclose(cpy);

	return 0;
}
