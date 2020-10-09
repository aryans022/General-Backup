#include <stdio.h>
int main() {
     int n;
     float sum = 0, average;
     printf("Enter total number of terms. ");
     scanf("%d", &n);
	int a[n];
	for(int i=0; i<n; i++) {
          printf("Enter term %d ", i+1);
          scanf("%d", &a[i]);
          sum += a[i];
	}
	average = sum/n;
	printf("The average of the numbers is %f", average);
}
