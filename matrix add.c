#include <stdio.h>
int main() {
     int n = 3, m = 3, sum = 0;

     printf("Enter Number of Rows in the Matrices ");
     scanf("%d", &n);
     printf("Enter Number of Columns in the Matrices ");
     scanf("%d", &m);

	int m1[m][n];
	int m2[m][n];

     printf("Enter First Matrix \n");
	for(int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
               scanf("%d", &m1[j][i]);
          }
	}
     printf("Enter Second Matrix \n");
	for(int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
               scanf("%d", &m2[j][i]);
          }
	}

     printf("Sum of the Matrices = \n");
	for(int i = 0; i < n; i++) {
          printf("\n");
          for (int j = 0; j < m; j++) {
               sum = m1[j][i] + m2[j][i];
               printf("%-3d ", sum);
          }
	}
}
