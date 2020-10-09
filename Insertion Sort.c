#include <stdio.h>
void printarr(int c[], int l) {
    int j;
    for(j = 0; j < l; j++)
        printf("%d\n", c[j]);
}
int main() {
    int orig[]={11, 9, 8, 7, 7, 5, 4, 3, 2, 2};
    int n = 10;
    int i, current, j;
    for (i = 1; i < n; i++) {
        current = orig[i];
        j = i - 1;
        while (j >= 0 && orig[j] > current) {
            orig[j + 1] = orig[j];
            j = j - 1;
        }
        orig[j + 1] = current;
    }
    printarr(orig, n);
    return 0;
}
