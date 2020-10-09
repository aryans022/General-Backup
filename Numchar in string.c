#include <stdio.h>
int main() {
     int len = 0;
	char str[200];
	printf("Enter a String ");
	scanf("%s", &str);
	while (1) {
          if (str[len] == '\0')
               break;
          len++;
	}
	printf("%d", len);
}
