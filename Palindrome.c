#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char a[300];
    scanf("%s", &a);
    int x = 0;
    int y = strlen(a) - 1;
    while (y > x)
    {
        if (a[x++] != a[y--])
        {
            printf("not a palindrome");
            exit(0);
        }
    }
    printf("is a palindrome\n");
}
