#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 5

void insert(int *arr, int pos, int x);
void del(int *arr, int pos);
void display(int *arr);
void reverse(int *arr);
void sort(int *arr);
int* merge(int *arr1, int *arr2);
int search(int *arr, int x);

void insert(int *arr, int pos, int x) {
     for (int i = MAX-1; i >pos; i--) {
          arr[i] = arr[i-1];
     }
     arr[pos] = x;
}

void del(int *arr, int pos) {
     for (int i = pos; i < MAX; i++) {
          arr[i] = arr[i+1];
     }
     arr[MAX-1] = 0;
}

void display(int *arr) {
     for (int i = 0 ;i < MAX; i++) {
          printf("%d ", arr[i]);
     }
     printf("\n");
}

void reverse(int *arr) {
     for (int i = 0; i < MAX/2; i++) {
          int temp = arr[i];
          arr[i] = arr[MAX-i-1];
          arr[MAX-i-1] = temp;
     }
}

void sort(int *arr) {

     int temp;

     for (int i = 0; i < MAX; i++) {
          for (int j = i+1; j < MAX; j++) {
               if (arr[i] > arr[j]) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
               }
          }
     }
}

int* merge(int *arr1, int *arr2) {

     int *arr = (int*)malloc(MAX*2*sizeof(int));

     int j = 0, k = 0;
     for (int i = 0; i < MAX*2; i++) {

          if (j == MAX) {
               arr[i] = arr2[k];
               k++;
               continue;
          }
          if (k == MAX) {
               arr[i] = arr1[j];
               j++;
               continue;
          }

          if (arr1[j] < arr2[k]) {
               arr[i] = arr1[j];
               j++;
          }
          else {
               arr[i] = arr1[k];
               k++;
          }
     }

     return arr;
}

int search(int *arr, int x) {
     for (int i = 0; i < MAX; i++) {
          if (arr[i] == x) {
               return i;
          }
     }
     return -1;
}

int main() {

     int arr[MAX] = {1, 2, 4, 5};
     int arr1[MAX] = {7, 2, 8, 1, 9};
     int *merged;

     insert(arr, 1, 3);
     display(arr);

     reverse(arr);
     display(arr);

     sort(arr);
     sort(arr1);
     merged = merge(arr, arr1);
     display(arr);
     display(arr1);
     for (int i = 0; i < MAX*2; i++)
          printf("%d ", merged[i]);
     printf("\n");

     del(arr, 1);
     display(arr);

     del(arr, 1);
     display(arr);

     del(arr, 0);
     display(arr);

     printf("%d\n", search(arr, 4));
     printf("%d\n", search(arr, 3));

}
