#include <stdio.h>

int colinDiv (int a, int b) {
	int result = 0;
	
	while (a<=b) {
		result++;
		b=b-a;
	}
	return result;
}

int main() {
	int result = colinDiv (9,80);
	printf ("%i", result);
}
