#include <stdio.h>

void printarr(int *a, int n) {
     for (int i = 0; i < n; i++)
          printf("%d\n", a[i]);
}

int main() {

     int key;
	int nums[10] = {2, 4, 1, 7, 3, 8, 3, 6, 13, 5};

	for (int i = 1; i < 10; i++) {

          key = nums[i];
          for (int j = i-1; j >= 0; j--) {
               if (key < nums[j]) {
                    nums[j+1] = nums[j];
                    nums[j] = key;
               }
               else
                    break;
          }
	}

	printarr(nums, 10);

}
