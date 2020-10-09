#include <stdio.h>
int swap(int *a, int *b) {                  //function to swap two numbers.
    int k;                                  //use pointers as value change in function is not reflected outside of it.
    k=*b;
    *b=*a;
    *a=k;
}
void printarr(int c[], int l) {             //function to print array.
    int j;
    for(j = 0; j < l; j++)
        printf("%d\n", c[j]);
}
int main() {
    int orig[]={11, 9, 8, 5, 7, 5, 4, 3, 2, 8};
    for (int j = 0; j < 9; j++) {           //number of iterations.
        for (int i = 0; i < 9; i++) {       //single iteration of swapping, i.e. the heaviest number falls to the bottom.
            if (orig[i] > orig[i+1])
                swap(&orig[i], &orig[i+1]);
        }
    }
    printarr(orig, 10);
}
