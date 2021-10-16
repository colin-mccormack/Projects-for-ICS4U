#include <stdio.h>

void deleteLessThanRecursive (int *A, int *nA, int x, int counter, int checked) {
	//While counter is less than number of elements
	while (counter < *nA) {
		printf ("Checking %i since it's less than A[%i]\n", A[counter], *nA);
		//Check if current array element is less than lowest
		if (A[counter] < x) {
			printf ("Number needs to be removed : %i\n", A[counter]);
			printf ("Value of checked : %i, value of element length : %i\n", checked, *nA);
			//while counter is less than number of elements
			//check if next element is valid
			//if yes than move it and cursor to current position
			//else increment cursor and call function again
			//error : after moving a value forwards into the spot of an invalid entry, the program then keeps the value
			while(checked <= *nA) {
				//check next element
				//if element next element is also greater than x 
				if (A[checked] >= x) {
					printf ("Moving index\n");
					//make current element next element
					printf ("Current element value = %i\n", A[checked]);
					A[counter] = A[checked];
					//reduce number of valid elements in array
					*nA = *nA-1;
					//tell counter not to check what has already been checked
					printf ("Current element value = %i out of %i\n\n", A[counter], *nA);
					//after this it shouldn't be checking value of just accesed element
					break;
				//else call function again
				} else {
					printf ("Using recursion\n");
					checked++;
					//pass all current parameters to function
					deleteLessThanRecursive(A, nA, x, counter, checked);
					break;
				}
			}
		} else {
			//else increment counter
			counter++;
			checked++;
		}
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
	
	deleteLessThanRecursive(marks, &nA, x, i, 1);
	
	for (int j = 0; j < nA; j++) {
		printf (" %i ", marks[j]);
	}
	
}
