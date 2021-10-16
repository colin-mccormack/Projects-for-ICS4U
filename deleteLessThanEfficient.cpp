#include <stdio.h>

void deleteLessThanRecursive (int *A, int *nA, int x, int counter) {
	int base;
	int diff = 0;
	while (counter < *nA) {
		printf ("Checking %i since it's less than A[%i]\n", A[counter], *nA);
		if (A[counter+diff] < x) {
			printf ("Number needs to be removed : %i\n", A[counter]);
			//input here is invalid
			//shift array to the left
			//shift each element until valid element
			base = counter;
			while (base < *nA) {
				if (A[base] > x) {
					A[counter] = A[base];
					//now make counter skip over all useless values on next iteration
					diff = base-counter;
					break;
				}
				else {
					base++;
				}
			}
		}
		counter++;
	}

}


int main () {
	int marks[200] = {3, -17, 8, 71, -43, -68, 31};
	int nA = 7;
	int x = 0;
	int i = 0;
	
	for (int j = 0; j < nA; j++) {
		printf (" %i ", marks[j]);
	}
	
	deleteLessThanRecursive(marks, &nA, x, i);
	
	for (int j = 0; j < nA; j++) {
		printf (" %i ", marks[j]);
	}
	
}
