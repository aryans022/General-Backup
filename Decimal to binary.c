#include <stdio.h>
int main() {
	long long int dec, bin, a[16], i = 0;
	printf("Enter a Number ");
	scanf("%d", &dec);
     printf("%d = ", dec);
     for (int i=0; dec>0; i++) {
          a[i] = dec%2;
          dec = dec/2;
     }
	for(int j=15; j>=0; j--) {
          if (a[j] == 0 || a[j]==1)
               printf("%d", a[j]);
	}
}
