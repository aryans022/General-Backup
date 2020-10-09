#include <stdio.h>
int main() {
	int n, largest = 0;
     printf("Enter total number of terms. ");
     scanf("%d", &n);
	int a[n];
     printf("Enter term 1 ");
     scanf("%d", &a[0]);
     largest = a[0];
	for (int i=1; i<n; i++) {
          printf("Enter term %d ", i+1);
          scanf("%d", &a[i]);
          if (a[i]>largest)
               largest = a[i];
	}
	printf("The largest number is %d", largest);

}
