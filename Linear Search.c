#include <stdio.h>
int swap(int *a, int *b) {                          //function to swap two numbers.
    int k;                                          //use pointers as value change in function is not reflected outside of it.
    k=*b;
    *b=*a;
    *a=k;
}
int main() {
    int orig[] = {11, 9, 8, 7, 2, 5, 4, 3, 2, 7};
    int len = 10;
    int num, count = 0;
    printf("Enter the number that you want to find. ");
    scanf("%d", &num);
    for(int i = 0; i < len; i++) {
        if (num == orig[i]) {
            printf("Found %d at position %d.\n", num, i+1);
            count += 1;                                     //number of times that we have found num.
        }
    }
    if (count == 0)
        printf("Number not present in the array.\n");
}
