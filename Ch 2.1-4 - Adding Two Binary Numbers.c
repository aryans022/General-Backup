#include <stdio.h>

int main() {

	int a[8] = {1, 1, 0, 0, 1, 1, 1, 1};
	int b[8] = {1, 1, 0, 0, 0, 0, 1, 0};
	int c[9];
	int carry = 0;

	for (int i = 7; i >= 0; i--) {
          c[i + 1] = (a[i] + b[i] + carry) % 2;
          carry = (a[i] + b[i] + carry) / 2;
	}

	c[0] = carry;

	for (int i = 0; i < 9; i++) {
          printf("%d", c[i]);
	}
}
