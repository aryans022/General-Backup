#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 3

int** matmul(int mat1[MAX][MAX], int mat2[MAX][MAX]) {

     int **mul = (int**)malloc(MAX*sizeof(int *));
     for (int i = 0; i < MAX; i++) {
          mul[i] = (int*)malloc(MAX*sizeof(int));
     }

     for (int i = 0; i < MAX; i++) {
          for (int j = 0; j < MAX; j++) {
               mul[i][j] = 0;
               for (int k = 0; k < MAX; k++) {
                    mul[i][j] += mat1[i][k]*mat2[k][j];
               }
          }
     }

     return mul;

}

int main() {

     int mat1[MAX][MAX] = {{1, 2, 3}, {2, 3, 4}, {3, 4, 5}};
     int mat2[MAX][MAX] = {{1, 1, 1}, {2, 3, 1}, {2, 1, 3}};;
     int **mult;

     mult = matmul(mat1, mat2);

     for (int i = 0; i < MAX; i++) {
          for (int j = 0; j < MAX; j++) {
               printf("%d ", mult[i][j]);
          }
          printf("\n");
     }
}
