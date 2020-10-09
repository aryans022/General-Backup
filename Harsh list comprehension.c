#include <stdio.h>

int main() {

	int x, y, z, n;
	scanf("%d %d %d %d", &x, &y, &z, &n);
	int i = 0, j = 0, k = 0;

	for (int i = 0; i <= x; i++) {
          for (int j = 0; j <= y; j++) {
               for (int k = 0; k <= z; k++) {

                    if (i+j+k != n) {
                         printf("%d %d %d\n", i, j, k);
                    }

               }
          }
	}
}
