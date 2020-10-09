#include <stdio.h>

int main() {

	int x;
	scanf("%d", &x);
	int bx[64], i;

	for (i = 0; x != 0; i++) {
          printf("%d\n", x);
          bx[i] = x%2;
          x = x/2;

          if (x == 1) {
               printf("danda");
          }
	}
}
