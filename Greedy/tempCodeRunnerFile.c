#include <stdio.h>

int main() {
	// char c[2] = "I";
	// printf("/n%c", c[3]);
	// printf("/n%s", c);

    char *s1 = "hello", *s2 = "hello";
    if (s1 == s2) {
        printf("same");
    } else {
        printf("diff");
    }
	return 0;
}