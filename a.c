#include <stdio.h>
int main() {
     int n = 3, m = 3;
     printf("Enter Number of Rows in the Matrices ");
     scanf("%d", &n);
     printf("Enter Number of Columns in the Matrices ");
     scanf("%d", &m);
	int m1[m][n];
	int m2[m][n];
	for(int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
               m1[j][i] = getche();
               puts(' ')
          }
	}
	for(int i = 0; i < n; i++) {
          printf("\n");
          for (int j = 0; j < m; j++) {
               printf("%-3d ", m1[j][i]);
          }
	}
}
