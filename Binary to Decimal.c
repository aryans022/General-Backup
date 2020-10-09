#include <stdio.h>
#include <stdlib.h>
int main() {
	int bin, dec = 0, pow = 1, rem;
	printf("Enter Binary Number ");
	scanf("%d", &bin);
	while (bin > 0) {
	rem = bin % 10;
	if (rem != 1 && rem != 0) {
          printf("YOU HAD ONE FUCKING JOB!!!");
          exit(0);
	}
	if (rem == 1)
          dec += pow;
     bin /= 10;
     pow *= 2;
	}
	printf("%d ", dec);
}
