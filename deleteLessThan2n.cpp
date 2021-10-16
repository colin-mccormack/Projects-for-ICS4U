#include <stdio.h>

/*
Implement algorithm for moving array elements at time omplexcity 0(n)
Remove all elements less than to shift

By : Colin
Date : 9/29/2021

*/
void deleteLessThan (int *A, int *nA, int x) {

    int counter = 0;
    int valid = 0;

	while (counter < *nA) {
		if (A[counter] > x) {
            counter++;
		} else {
            //A[valid] = A[counter];
            //valid++;
		    //counter++;
		    
		    deleteLessThan (A, &nA, x)
        }
	}

    *nA = *nA - (*nA - valid);

}


int main () {
	int marks[200] = {3, -17, 8, 71, -43, -68, 31, -10, 100};
	int nA = 9;
    int x = 0;
	
	for (int j = 0; j < nA; j++) {
		printf (" %i ", marks[j]);
	}
	
	deleteLessThan(marks, &nA, x);

	printf ("\n\n");

	for (int j = 0; j < nA; j++) {
		printf (" %i ", marks[j]);
	}
	
}
