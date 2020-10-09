#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int l, int m, int u) {                  //merges arrays in sorted order

     int i, j, k;

     int n1, n2;                                            //number of elements in each temp array
     n1 = m - l + 1;
     n2 = u - m;

     int b[n1];
     int c[n2];

     for (int x = 0; x < n1; x++)                           //copying data to temp arrays
          b[x] = a[l+x];
     for (int y = 0; y < n2; y++)
          c[y] = a[m+y+1];

     i = 0;                                                 //array counters
     j = 0;
     k = l;

     /*k=l so that arr starts filling from the position of the lowermost element
       currently supplied to the function. That is, if l = 2, u = 5, arr starts
       filling from arr[2] to arr[5].
     */

     while (i < n1 && j < n2) {                             //sort arr in ascending order till either i=n1 or j=n2
          if(b[i] <= c[j]) {
               a[k] = b[i];
               i++;
          }
          else {
               a[k] = c[j];
               j++;
          }
          k++;
     }

     while (i < n1)                                         //fill up leftover elements from either left or right array.
    {
        a[k] = b[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = c[j];
        j++;
        k++;
    }
}

int mergesort(int *a, int low, int up) {                    //divides into multiple arrays

     int mid = (low + up - 1)/2;

     if (low < up) {
          mergesort(a, low, mid);                           //first half
          mergesort(a, mid+1, up);                          //second half

          merge(a, low, mid, up);
     }
}

//test case
int main() {

	int arr[] = {42, 46, 12, 42, 56, 23, 76};
	int n = sizeof(arr)/sizeof(int);

	mergesort(arr, 0, n-1);

	for (int i = 0; i < n; i++) {
          printf("%d ", arr[i]);
	}

	printf("\n");

}
