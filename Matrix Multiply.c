#include <stdio.h>
#include <stdlib.h>

int matinput(int row, int column, int *matrix) {                                //function to take input into a matrix
     for (int i=0; i<(row*column); i++) {
          scanf("%d", matrix++);
     }
}

int printmat(int row, int column, int *matrix) {                                //function to print a matrix
     for(int i = 0; i < row; i++) {
          printf("\n");
          for (int j = 0; j < column; j++) {
               printf("%-3d ", *matrix++);
          }
	}
	printf("\n");
}

int main() {

     int m1, m2, n1, n2;                                                        //vars for rows, columns

     printf("Enter Number of Rows in the First Matrix ");
     scanf("%d", &m1);
     printf("Enter Number of Columns in the First Matrix ");
     scanf("%d", &n1);
     printf("\nEnter Number of Rows in the Second Matrix ");
     scanf("%d", &m2);
     printf("Enter Number of Columns in the Second Matrix ");
     scanf("%d", &n2);

     if (n1 != m2) {                                                            //code to check the validity of multiplication operation
          printf("\nThese Matrices CANNOT be multiplied, fool.\n");
          exit(0);
     }

	int mat1[m1][n1];                                                          //declaring matrices
	int mat2[m2][n2];
	int mult[m1][n2];

     printf("\nEnter First Matrix \n");
	matinput(m1, n1, mat1);
     printf("\nEnter Second Matrix \n");
	matinput(m2, n2, mat2);


     for(int i = 0; i < m1; i++) {                                              //initializing matrix to 0
          for (int j = 0; j < n2; j++) {
               mult[i][j] = 0;
          }
     }

     for(int i = 0; i < m1; i++) {                                              //code to multiply the two matrices
          for (int j = 0; j < n2; j++) {
               for (int k = 0; k < m2; k++) {
                    mult[i][j] += mat1[i][k] * mat2[k][j];
               }
          }
	}
	printf("\n");

	printmat(m1, n1, mat1);
	printmat(m2, n2, mat2);

	printmat(m1, n2, mult);
}
