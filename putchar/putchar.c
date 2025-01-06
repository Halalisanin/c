#include <stdio.h>
int main() {
	char *str = "Hello, World!\n";
		while (*str) {
			putchar(*str++);
		}
	return 0;
}
