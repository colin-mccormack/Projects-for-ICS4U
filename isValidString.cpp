#include <stdio.h>
#include <stdlib.h>

/*
	A valid string must have between minChars and maxChars
	characters inclusive AND each character must be between
	minChar and maxChar. If the string is valid return 1,
	otherwise return 0.
	
	By Colin on 9/27/2021
*/
int  isValidString (char *s, int minChar, int maxChar,
					int minChars, int maxChars){
	// your code goes here
	
	int i = 0;
	
	//If string[i] is valid
		//if minChars < i < maxChars
			//if minChar < s[i] < maxChars
				//i++
				//printf ("%i <= %i <= %i AND %c <= %c <= %c\n", minChars, i, maxChars, minChar, s[i], maxChar);
		
	while (s[i]) {
		if ((minChars <= i) && (i <= maxChars) && (minChar <= s[i]) && (i <= maxChar)) {
			i++;
		} else {
			return 0;
		}
	}
	
	return 1;
	
}

int main(){
	char s[80];
	char min;
	char max;
	int minChars;
	int maxChars;
	

	while (1){		// here is an infinite loop in C ... 1 is always TRUE
		printf ("Enter the smallest valid character: ");
		scanf ("%c", &min);
		fflush(stdin);
		
		printf ("Enter the largest valid character: ");
		scanf ("%c", &max);
		fflush(stdin);
		
		printf ("Enter the minimum number of characters in a valid string: ");
		scanf ("%i", &minChars);
		fflush(stdin);
		
		printf ("Enter the maximum number of characters in a valid string: ");
		scanf ("%i", &maxChars);
		fflush(stdin);

		printf ("\nA valid string contains between %i and %i characters inclusive.\n",
				minChars, maxChars);
		printf ("Characters in a valid string are between '%c' and '%c' inclusive.\n\n",
				min, max);
		printf ("Enter a valid string: ");
		scanf("%s", &s);
		fflush(stdin);
		
		if (isValidString (s, min, max, minChars, maxChars))
			printf ("\"%s\" is a valid string.\n\n",s);
		else
			printf ("\"%s\" is not a valid string.\n\n", s);
		
		// Since each part of the selection statement requires a single
		// statement, I do not need curly braces {}
		system ("pause");	
		system ("cls");
	}
		
	return 0;
}
